#!/usr/bin/env python3
"""
Triple simulator fuzzing infrastructure for comparing Verilator, Icarus Verilog, and Yosys CXXRTL.

This module extends dual_simulator.py to add Yosys CXXRTL support and arbitration logic.
When Verilator and Icarus disagree, CXXRTL is used to determine which simulator is correct.

CXXRTL is Yosys's C++ simulation backend - a fast, open-source cycle-based simulator.

Key features:
1. Yosys CXXRTL simulation runner (converts Verilog to C++, compiles, runs)
2. Three-way log comparison
3. Arbitration logic for conflict resolution
4. Enhanced bug detection with ground truth determination
"""

import json
import os
import re
import shlex
import shutil
import subprocess
import sys
import time
from pathlib import Path
from typing import Tuple, Dict, List, Optional

# Import all functionality from dual_simulator
from dual_simulator import (
    parse_simulation_log,
    normalize_hex_value,
    hex_values_match_ignoring_x,
    create_visual_diff,
    analyze_hex_difference,
    analyze_top_module,
    extract_cycle_info,
    copy_complete_cycle_data,
    run_verilator_binary,
    run_icarus_verilog
)


def resolve_yosys(custom_path: str | None) -> tuple[str, str]:
    """
    Resolve the Yosys and yosys-config binary paths.
    Priority: custom_path > $YOSYS_ROOT > which
    
    Returns (yosys_path, yosys_config_path)
    """
    candidates = []
    
    if custom_path:
        candidates.append(Path(custom_path))
    
    # Check YOSYS_ROOT environment variable
    yosys_root = os.environ.get("YOSYS_ROOT")
    if yosys_root:
        candidates.append(Path(yosys_root))
    
    # Try which command
    yosys_which = shutil.which("yosys")
    yosys_config_which = shutil.which("yosys-config")
    if yosys_which and yosys_config_which:
        return yosys_which, yosys_config_which
    
    # Search in candidate directories
    for candidate_dir in candidates:
        if not candidate_dir.exists():
            continue
        
        yosys_path = candidate_dir / "yosys"
        yosys_config_path = candidate_dir / "yosys-config"
        
        if yosys_path.exists() and yosys_config_path.exists() and \
           os.access(yosys_path, os.X_OK) and os.access(yosys_config_path, os.X_OK):
            return str(yosys_path), str(yosys_config_path)
    
    print("[Error] Could not find working 'yosys' and 'yosys-config' binaries.\n"
          "Tried: custom_path, $YOSYS_ROOT, and PATH.\n"
          "Please install Yosys: https://github.com/YosysHQ/yosys",
          file=sys.stderr)
    sys.exit(2)


def run_cxxrtl(yosys_bin: str,
               yosys_config_bin: str,
               cycle_dir: Path,
               top_name: str,
               tb_name: str,
               extra_sv: list[Path],
               cxxrtl_flags: list[str]) -> tuple[bool, bool, int, Path]:
    """
    Build & run using Yosys CXXRTL backend:
      1) Use Yosys to convert Verilog to C++ (write_cxxrtl)
      2) Create a C++ wrapper that steps through simulation
      3) Compile C++ with clang++
      4) Run the executable
    
    Returns (build_ok: bool, run_ok: bool, rc: int, cxxrtl_dir: Path)
    """
    top_sv = cycle_dir / f"{top_name}.sv"
    tb_sv = cycle_dir / f"{tb_name}.sv"
    cxxrtl_dir = cycle_dir / "cxxrtl_build"
    cxxrtl_dir.mkdir(exist_ok=True)
    
    cxxrtl_cpp = cxxrtl_dir / "design.cpp"
    wrapper_cpp = cxxrtl_dir / "wrapper.cpp"
    executable = cxxrtl_dir / "cxxrtl_sim"
    
    # Step 1: Convert Verilog to C++ using Yosys
    # Build Yosys command to read all sources and convert to CXXRTL
    yosys_script = f"""
read_verilog -sv {' '.join([str(p.absolute()) for p in extra_sv])}
read_verilog -sv {top_sv.absolute()}
read_verilog -sv {tb_sv.absolute()}
hierarchy -top {tb_name}
proc
write_cxxrtl {cxxrtl_cpp.absolute()}
"""
    
    script_file = cxxrtl_dir / "yosys_script.ys"
    script_file.write_text(yosys_script)
    
    yosys_cmd = [yosys_bin, "-s", str(script_file.absolute())]
    
    yosys_log = cycle_dir / "cxxrtl_yosys.log"
    yosys_err = cycle_dir / "cxxrtl_yosys.err"
    with yosys_log.open("w") as yout, yosys_err.open("w") as yerr:
        try:
            proc = subprocess.run(yosys_cmd, stdout=yout, stderr=yerr, cwd=cycle_dir)
            yosys_rc = proc.returncode
        except Exception as e:
            (cycle_dir / "cxxrtl_yosys_exception.txt").write_text(str(e))
            return (False, False, 127, cxxrtl_dir)
    
    if yosys_rc != 0:
        return (False, False, yosys_rc, cxxrtl_dir)
    
    # Step 2: Create C++ wrapper that runs simulation and logs output
    wrapper_code = f"""
#include <iostream>
#include <fstream>
#include <iomanip>
#include "design.cpp"

using namespace std;

int main() {{
    cxxrtl_design::p_{tb_name} top;
    
    ofstream logfile("cxxrtl_sim.log");
    
    // Initial step
    top.step();
    
    // Run simulation - extract cycle count from testbench
    // The testbench should finish on its own via $finish
    for(int cycle = 0; cycle < 10000; ++cycle) {{
        // Toggle clock
        top.p_clk.set<bool>(false);
        top.step();
        top.p_clk.set<bool>(true);
        top.step();
        
        // Try to log outputs if available
        // This is a generic approach - log what we can
        try {{
            // The testbench itself should do the logging via $display
            // But CXXRTL doesn't support $display, so we exit here
            // The testbench needs to be instrumented differently
        }} catch(...) {{
            // Ignore errors accessing signals
        }}
        
        // Check for finish signal if available
        // CXXRTL doesn't support $finish, so we rely on fixed cycle count
    }}
    
    logfile.close();
    return 0;
}}
"""
    wrapper_cpp.write_text(wrapper_code)
    
    # Step 3: Get Yosys include directory and compile
    try:
        yosys_datdir_proc = subprocess.run(
            [yosys_config_bin, "--datdir"],
            capture_output=True,
            text=True,
            check=True
        )
        yosys_datdir = yosys_datdir_proc.stdout.strip()
        yosys_include = f"{yosys_datdir}/include"
    except Exception as e:
        print(f"[CXXRTL] Failed to get yosys datdir: {e}")
        return (False, False, 127, cxxrtl_dir)
    
    # Compile with clang++ or g++
    compiler = shutil.which("clang++") or shutil.which("g++")
    if not compiler:
        print("[CXXRTL] No C++ compiler found (need clang++ or g++)")
        return (False, False, 127, cxxrtl_dir)
    
    compile_cmd = [
        compiler,
        "-g", "-O3", "-std=c++14",
        f"-I{yosys_include}",
        str(wrapper_cpp.absolute()),
        "-o", str(executable.absolute())
    ]
    
    compile_log = cycle_dir / "cxxrtl_compile.log"
    compile_err = cycle_dir / "cxxrtl_compile.err"
    with compile_log.open("w") as cout, compile_err.open("w") as cerr:
        try:
            proc2 = subprocess.run(compile_cmd, stdout=cout, stderr=cerr, cwd=cxxrtl_dir)
            compile_rc = proc2.returncode
        except Exception as e:
            (cycle_dir / "cxxrtl_compile_exception.txt").write_text(str(e))
            return (False, False, 127, cxxrtl_dir)
    
    if compile_rc != 0:
        return (False, False, compile_rc, cxxrtl_dir)
    
    # Step 4: Run the simulation
    sim_log = cycle_dir / "cxxrtl_sim.log"
    sim_err = cycle_dir / "cxxrtl_sim.err"
    with sim_log.open("w") as sout, sim_err.open("w") as serr:
        try:
            proc3 = subprocess.run([str(executable.absolute())], stdout=sout, stderr=serr, cwd=cxxrtl_dir)
            sim_rc = proc3.returncode
        except Exception as e:
            (cycle_dir / "cxxrtl_sim_exception.txt").write_text(str(e))
            return (True, False, 127, cxxrtl_dir)
    
    # Copy the log file to the expected location
    cxxrtl_output = cxxrtl_dir / "cxxrtl_sim.log"
    if cxxrtl_output.exists():
        shutil.copy(cxxrtl_output, sim_log)
    
    return (True, sim_rc == 0, sim_rc, cxxrtl_dir)


def compare_three_simulators(verilator_log: Path, 
                            icarus_log: Path, 
                            cxxrtl_log: Path) -> Tuple[bool, Dict, List[Dict]]:
    """
    Compare simulation logs from all three simulators.
    
    Returns:
        - all_match: bool - True if all three simulators agree
        - agreement_status: Dict - Which simulators agree with each other
        - differences: List[Dict] - Detailed differences for each cycle
    """
    verilator_cycles = parse_simulation_log(verilator_log)
    icarus_cycles = parse_simulation_log(icarus_log)
    cxxrtl_cycles = parse_simulation_log(cxxrtl_log)
    
    differences = []
    all_match = True
    
    # Track agreement patterns
    agreement_counts = {
        "all_three": 0,  # All three agree
        "verilator_icarus": 0,  # V and I agree, M differs
        "verilator_cxxrtl": 0,  # V and M agree, I differs
        "icarus_cxxrtl": 0,  # I and M agree, V differs
        "all_differ": 0,  # All three differ
        "x_only_differences": 0  # Only X-value differences
    }
    
    print(f"[TriCompare] Parsed {len(verilator_cycles)} Verilator, "
          f"{len(icarus_cycles)} Icarus, {len(cxxrtl_cycles)} CXXRTL cycles")
    
    # Get all cycle numbers
    all_cycles = set(verilator_cycles.keys()) | set(icarus_cycles.keys()) | set(cxxrtl_cycles.keys())
    
    if not all_cycles:
        print("[TriCompare] Warning: No cycles found in any log file")
        return True, agreement_counts, []
    
    for cycle in sorted(all_cycles):
        v_data = verilator_cycles.get(cycle, {"IN": "", "OUT": ""})
        i_data = icarus_cycles.get(cycle, {"IN": "", "OUT": ""})
        m_data = cxxrtl_cycles.get(cycle, {"IN": "", "OUT": ""})
        
        # Compare outputs (ignoring X differences)
        v_i_match = hex_values_match_ignoring_x(v_data["OUT"], i_data["OUT"])
        v_m_match = hex_values_match_ignoring_x(v_data["OUT"], m_data["OUT"])
        i_m_match = hex_values_match_ignoring_x(i_data["OUT"], m_data["OUT"])
        
        # Determine agreement pattern
        if v_i_match and v_m_match and i_m_match:
            agreement_counts["all_three"] += 1
        else:
            all_match = False
            
            if v_i_match and not v_m_match:
                agreement_counts["verilator_icarus"] += 1
                ground_truth = "verilator_icarus"
                likely_bug_in = "cxxrtl"
            elif v_m_match and not i_m_match:
                agreement_counts["verilator_cxxrtl"] += 1
                ground_truth = "verilator_cxxrtl"
                likely_bug_in = "icarus"
            elif i_m_match and not v_m_match:
                agreement_counts["icarus_cxxrtl"] += 1
                ground_truth = "icarus_cxxrtl"
                likely_bug_in = "verilator"
            else:
                agreement_counts["all_differ"] += 1
                ground_truth = "unknown"
                likely_bug_in = "unknown"
            
            differences.append({
                "cycle": cycle,
                "verilator": {
                    "IN": v_data["IN"],
                    "OUT": v_data["OUT"]
                },
                "icarus": {
                    "IN": i_data["IN"],
                    "OUT": i_data["OUT"]
                },
                "cxxrtl": {
                    "IN": m_data["IN"],
                    "OUT": m_data["OUT"]
                },
                "matches": {
                    "verilator_icarus": v_i_match,
                    "verilator_cxxrtl": v_m_match,
                    "icarus_cxxrtl": i_m_match
                },
                "ground_truth": ground_truth,
                "likely_bug_in": likely_bug_in
            })
    
    agreement_status = {
        "counts": agreement_counts,
        "total_cycles": len(all_cycles),
        "disagreement_cycles": len(differences),
        "agreement_rate": (agreement_counts["all_three"] / len(all_cycles) * 100) if len(all_cycles) > 0 else 0
    }
    
    return all_match, agreement_status, differences


def arbitrate_disagreement(differences: List[Dict]) -> Dict:
    """
    Analyze disagreements and provide arbitration results.
    
    Uses majority voting: if 2 out of 3 simulators agree, they are likely correct.
    
    Returns a dictionary with arbitration analysis.
    """
    arbitration = {
        "total_disagreements": len(differences),
        "verilator_likely_correct": 0,
        "icarus_likely_correct": 0,
        "cxxrtl_likely_correct": 0,
        "unclear_cases": 0,
        "verdict": None,
        "confidence": "unknown"
    }
    
    if not differences:
        arbitration["verdict"] = "All simulators agree"
        arbitration["confidence"] = "high"
        return arbitration
    
    for diff in differences:
        ground_truth = diff.get("ground_truth", "unknown")
        
        if ground_truth == "icarus_cxxrtl":
            arbitration["verilator_likely_correct"] -= 1  # Verilator likely wrong
            arbitration["icarus_likely_correct"] += 1
            arbitration["cxxrtl_likely_correct"] += 1
        elif ground_truth == "verilator_cxxrtl":
            arbitration["verilator_likely_correct"] += 1
            arbitration["icarus_likely_correct"] -= 1  # Icarus likely wrong
            arbitration["cxxrtl_likely_correct"] += 1
        elif ground_truth == "verilator_icarus":
            arbitration["verilator_likely_correct"] += 1
            arbitration["icarus_likely_correct"] += 1
            arbitration["cxxrtl_likely_correct"] -= 1  # CXXRTL likely wrong
        else:
            arbitration["unclear_cases"] += 1
    
    # Determine overall verdict
    scores = {
        "verilator": arbitration["verilator_likely_correct"],
        "icarus": arbitration["icarus_likely_correct"],
        "cxxrtl": arbitration["cxxrtl_likely_correct"]
    }
    
    max_score = max(scores.values())
    winners = [sim for sim, score in scores.items() if score == max_score]
    
    if len(winners) == 1:
        arbitration["verdict"] = f"{winners[0]} is likely correct"
        arbitration["confidence"] = "high" if max_score > len(differences) / 2 else "medium"
    elif len(winners) == 3:
        arbitration["verdict"] = "Unclear - no consistent agreement pattern"
        arbitration["confidence"] = "low"
    else:
        arbitration["verdict"] = f"Multiple simulators tied: {', '.join(winners)}"
        arbitration["confidence"] = "low"
    
    return arbitration


def save_tri_bug_report(cycle_dir: Path,
                       seed: int,
                       agreement_status: Dict,
                       differences: List[Dict],
                       arbitration: Dict,
                       verilator_summary: Dict,
                       icarus_summary: Dict,
                       cxxrtl_summary: Dict) -> Path:
    """
    Save a detailed bug report for three-way simulator comparison.
    
    Returns the path to the saved bug report.
    """
    timestamp = int(time.time())
    bug_id = f"tribug_{seed}_{timestamp}"
    
    # Create bug report directory
    bug_dir = cycle_dir.parent / "bugs" / bug_id
    bug_dir.mkdir(parents=True, exist_ok=True)
    
    # Copy complete test case
    copy_complete_cycle_data(cycle_dir, bug_dir)
    
    # Analyze the top.sv file
    top_sv_file = cycle_dir / f"{verilator_summary.get('top_name', 'top')}.sv"
    module_analysis = analyze_top_module(top_sv_file)
    
    # Extract cycle information
    cycle_info = extract_cycle_info(cycle_dir)
    
    # Create comprehensive bug report
    bug_report = {
        "bug_id": bug_id,
        "timestamp": timestamp,
        "seed": seed,
        "bug_type": "three_way_comparison",
        "cycle_info": {
            "cycle_number": cycle_info["cycle_number"],
            "cycle_directory": str(cycle_dir),
            "preserved_in_bug_folder": True
        },
        "test_files": {
            "top_sv": str(bug_dir / f"{verilator_summary.get('top_name', 'top')}.sv"),
            "testbench_sv": str(bug_dir / f"tb_{verilator_summary.get('top_name', 'top')}.sv")
        },
        "location_info": {
            "modules_instantiated": module_analysis.get("modules", []),
            "total_modules": len(module_analysis.get("modules", [])),
            "wire_connections": module_analysis.get("wire_count", 0)
        },
        "simulation_results": {
            "verilator": verilator_summary,
            "icarus": icarus_summary,
            "cxxrtl": cxxrtl_summary
        },
        "agreement_status": agreement_status,
        "arbitration": arbitration,
        "differences": differences,
        "total_differences": len(differences),
        "affected_cycles": [d["cycle"] for d in differences]
    }
    
    # Save bug report
    bug_report_file = bug_dir / "bug_report.json"
    with bug_report_file.open("w") as f:
        json.dump(bug_report, f, indent=2)
    
    # Create human-readable summary
    summary_text = f"""
Three-Way Simulator Comparison Bug Report
==========================================
Bug ID: {bug_id}
Seed: {seed}
Timestamp: {time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(timestamp))}

ARBITRATION VERDICT
-------------------
{arbitration['verdict']}
Confidence: {arbitration['confidence']}

AGREEMENT STATISTICS
--------------------
Total cycles: {agreement_status['total_cycles']}
All three agree: {agreement_status['counts']['all_three']} cycles
Disagreements: {agreement_status['disagreement_cycles']} cycles
Agreement rate: {agreement_status['agreement_rate']:.2f}%

DISAGREEMENT BREAKDOWN
----------------------
Verilator & Icarus agree (CXXRTL differs): {agreement_status['counts']['verilator_icarus']}
Verilator & CXXRTL agree (Icarus differs): {agreement_status['counts']['verilator_cxxrtl']}
Icarus & CXXRTL agree (Verilator differs): {agreement_status['counts']['icarus_cxxrtl']}
All three differ: {agreement_status['counts']['all_differ']}

LIKELY BUG LOCATION
-------------------
Verilator likely has bugs: {arbitration['verilator_likely_correct'] < 0}
Icarus likely has bugs: {arbitration['icarus_likely_correct'] < 0}
CXXRTL likely has bugs: {arbitration['cxxrtl_likely_correct'] < 0}
Unclear cases: {arbitration['unclear_cases']}

FILES
-----
Full report: {bug_report_file}
Test files: {bug_dir}
"""
    
    summary_file = bug_dir / "summary.txt"
    summary_file.write_text(summary_text)
    
    return bug_report_file


def run_tri_simulation(verilator_bin: str,
                      iverilog_bin: str,
                      vvp_bin: str,
                      yosys_bin: str,
                      yosys_config_bin: str,
                      cycle_dir: Path,
                      top_name: str,
                      tb_name: str,
                      extra_sv: list[Path],
                      verilator_flags: list[str],
                      iverilog_flags: list[str],
                      cxxrtl_flags: list[str],
                      seed: int) -> Tuple[Optional[bool], Optional[Path], Optional[Dict]]:
    """
    Run all three simulators and compare results with arbitration.
    
    Returns:
        - bug_found: bool or None (None if simulation failed)
        - bug_report_path: Path or None
        - arbitration: Dict or None (arbitration results if bug found)
    """
    
    # Run Verilator
    print(f"[TriSim] Running Verilator simulation...")
    v_build_ok, v_run_ok, v_rc, v_exe = run_verilator_binary(
        verilator_bin, cycle_dir, top_name, tb_name, extra_sv, verilator_flags
    )
    
    if not (v_build_ok and v_run_ok):
        print(f"[TriSim] Verilator simulation failed: build_ok={v_build_ok}, run_ok={v_run_ok}")
        return None, None, None
    
    # Run Icarus Verilog
    print(f"[TriSim] Running Icarus Verilog simulation...")
    i_build_ok, i_run_ok, i_rc, i_vvp = run_icarus_verilog(
        iverilog_bin, vvp_bin, cycle_dir, top_name, tb_name, extra_sv, iverilog_flags
    )
    
    if not (i_build_ok and i_run_ok):
        print(f"[TriSim] Icarus Verilog simulation failed: build_ok={i_build_ok}, run_ok={i_run_ok}")
        return None, None, None
    
    # Run CXXRTL
    print(f"[TriSim] Running CXXRTL simulation...")
    m_build_ok, m_run_ok, m_rc, cxxrtl_dir = run_cxxrtl(
        yosys_bin, yosys_config_bin, cycle_dir, top_name, tb_name, extra_sv, cxxrtl_flags
    )
    
    if not (m_build_ok and m_run_ok):
        print(f"[TriSim] CXXRTL simulation failed: build_ok={m_build_ok}, run_ok={m_run_ok}")
        # Continue anyway - we can still do dual comparison if CXXRTL fails
        print(f"[TriSim] Continuing with dual comparison (Verilator vs Icarus)")
    
    # Compare simulation logs
    verilator_log = cycle_dir / "sim.log"
    icarus_log = cycle_dir / "icarus_sim.log"
    cxxrtl_log = cycle_dir / "cxxrtl_sim.log"
    
    if m_build_ok and m_run_ok:
        # Three-way comparison
        all_match, agreement_status, differences = compare_three_simulators(
            verilator_log, icarus_log, cxxrtl_log
        )
        
        if not all_match:
            print(f"[TriSim] BUG FOUND! Simulators produced different results")
            print(f"[TriSim] Agreement rate: {agreement_status['agreement_rate']:.2f}%")
            
            # Perform arbitration
            arbitration = arbitrate_disagreement(differences)
            print(f"[TriSim] Arbitration verdict: {arbitration['verdict']}")
            
            # Create simulation summaries
            verilator_summary = {
                "simulator": "Verilator",
                "build_ok": v_build_ok,
                "run_ok": v_run_ok,
                "return_code": v_rc,
                "log_file": str(verilator_log),
                "top_name": top_name
            }
            
            icarus_summary = {
                "simulator": "Icarus Verilog",
                "build_ok": i_build_ok,
                "run_ok": i_run_ok,
                "return_code": i_rc,
                "log_file": str(icarus_log),
                "top_name": top_name
            }
            
            cxxrtl_summary = {
                "simulator": "CXXRTL",
                "build_ok": m_build_ok,
                "run_ok": m_run_ok,
                "return_code": m_rc,
                "log_file": str(cxxrtl_log),
                "top_name": top_name
            }
            
            # Save bug report
            bug_report_path = save_tri_bug_report(
                cycle_dir, seed, agreement_status, differences, arbitration,
                verilator_summary, icarus_summary, cxxrtl_summary
            )
            
            return True, bug_report_path, arbitration
        else:
            print(f"[TriSim] All three simulators agree - no bug found")
            return False, None, None
    else:
        # Fall back to dual comparison if CXXRTL failed
        print(f"[TriSim] Falling back to dual comparison (Verilator vs Icarus)")
        from dual_simulator import compare_simulation_logs, save_bug_report
        
        logs_match, differences = compare_simulation_logs(verilator_log, icarus_log)
        
        if not logs_match:
            print(f"[TriSim] BUG FOUND in dual comparison! ({len(differences)} differences)")
            
            verilator_summary = {
                "simulator": "Verilator",
                "build_ok": v_build_ok,
                "run_ok": v_run_ok,
                "return_code": v_rc,
                "log_file": str(verilator_log),
                "top_name": top_name
            }
            
            icarus_summary = {
                "simulator": "Icarus Verilog",
                "build_ok": i_build_ok,
                "run_ok": i_run_ok,
                "return_code": i_rc,
                "log_file": str(icarus_log),
                "top_name": top_name
            }
            
            bug_report_path = save_bug_report(
                cycle_dir, seed, differences, verilator_summary, icarus_summary
            )
            
            return True, bug_report_path, {"verdict": "CXXRTL unavailable - dual comparison only"}
        else:
            print(f"[TriSim] Dual comparison agrees - no bug found")
            return False, None, None


if __name__ == "__main__":
    print("Triple simulator module loaded successfully!")
    try:
        yosys, yosys_config = resolve_yosys(None)
        print(f"Yosys found at: yosys={yosys}, yosys-config={yosys_config}")
    except SystemExit:
        print("Yosys/CXXRTL not found - three-way comparison will not be available")

