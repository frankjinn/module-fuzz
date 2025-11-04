#!/usr/bin/env python3
"""
Optimized dual simulator fuzzing infrastructure for comparing Verilator and Icarus Verilog.

This module provides:
1. Icarus Verilog simulation runner
2. Efficient log comparison functions  
3. Bug detection and storage
4. Seed consistency verification
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
from typing import Tuple, Dict, List, Optional, Union


def resolve_icarus(custom_path: str | None) -> str:
    """
    Resolve the iverilog binary path according to the user's environment.
    Priority: custom_path > $IVERILOG > which iverilog
    """
    candidates = []
    if custom_path:
        candidates.append(custom_path)

    env_iverilog = os.environ.get("IVERILOG")
    if env_iverilog:
        candidates.append(env_iverilog)

    which_path = shutil.which("iverilog")
    if which_path:
        candidates.append(which_path)

    for c in candidates:
        if c and Path(c).exists() and os.access(c, os.X_OK):
            return c

    print("[Error] Could not find a working 'iverilog' binary.\n"
          "Tried: custom_path, $IVERILOG, and PATH.",
          file=sys.stderr)
    sys.exit(2)


def run_icarus_verilog(iverilog_bin: str,
                      vvp_bin: str,
                      cycle_dir: Path,
                      top_name: str,
                      tb_name: str,
                      extra_sv: list[Path],
                      iverilog_flags: list[str]) -> tuple[bool, bool, int, Path]:
    """
    Build & run using Icarus Verilog:
      iverilog [flags] -o tb_<top>.vvp [extra_sv...] <top>.sv tb_<top>.sv
      vvp tb_<top>.vvp

    Returns (build_ok: bool, run_ok: bool, rc: int, vvp_path: Path)
    """
    top_sv = cycle_dir / f"{top_name}.sv"
    tb_sv = cycle_dir / f"{tb_name}.sv"
    vvp_file = cycle_dir / f"{tb_name}.vvp"

    # Build command with absolute path for output
    cmd = [iverilog_bin, "-o", str(vvp_file.absolute())]
    
    # Include directories are handled by the main loop
    # Just add the cycle directory itself for generated files
    cmd.extend(["-I", str(cycle_dir.absolute())])
    
    # For Icarus, add all RTL files since include statements were removed from wrappers
    cmd.extend([str(p.absolute()) for p in extra_sv])
    cmd.extend([str(top_sv.absolute()), str(tb_sv.absolute())])
    cmd.extend(iverilog_flags)

    build_log = cycle_dir / "icarus_build.log"
    build_err = cycle_dir / "icarus_build.err"
    with build_log.open("w") as bout, build_err.open("w") as berr:
        try:
            proc = subprocess.run(cmd, stdout=bout, stderr=berr, cwd=cycle_dir)
            build_rc = proc.returncode
        except Exception as e:
            (cycle_dir / "icarus_build_exception.txt").write_text(str(e))
            return (False, False, 127, vvp_file)

    if build_rc != 0:
        return (False, False, build_rc, vvp_file)

    # Run simulation
    sim_log = cycle_dir / "icarus_sim.log"
    sim_err = cycle_dir / "icarus_sim.err"
    with sim_log.open("w") as sout, sim_err.open("w") as serr:
        try:
            # Use absolute path for VVP file
            proc2 = subprocess.run([vvp_bin, str(vvp_file.absolute())], stdout=sout, stderr=serr, cwd=cycle_dir)
            sim_rc = proc2.returncode
        except Exception as e:
            (cycle_dir / "icarus_sim_exception.txt").write_text(str(e))
            return (True, False, 127, vvp_file)

    return (True, sim_rc == 0, sim_rc, vvp_file)


def parse_simulation_log(log_file: Path) -> Dict[int, Dict[str, str]]:
    """
    Optimized simulation log parser with improved regex efficiency.
    
    Handles multiple formats:
    - CYCLE=<num> IN=<hex> OUT=<hex>
    - CYCLE=<num> OUT=<hex>
    - CYCLE=<num> IN=<hex>
    - Different simulators may have different spacing, case, or prefixes
    
    Returns: {cycle_num: {"IN": hex_value, "OUT": hex_value}}
    """
    cycles = {}
    
    if not log_file.exists():
        return cycles
    
    # Compile regex patterns once for better performance
    # Support both "CYCLE" and "CYC" (for CXXRTL), and both "OUT" and "out_flat"
    pattern1 = re.compile(r'(?:CYCLE|CYC)[=\s]*(\d+).*?(?:IN|in_flat)[=\s]*(?:0x)?([0-9a-fA-FXx]+).*?(?:OUT|out_flat)[=\s]*(?:0x)?([0-9a-fA-FXx]+)', re.IGNORECASE)
    pattern2 = re.compile(r'(?:CYCLE|CYC)[=\s]*(\d+).*?(?:OUT|out_flat)[=\s]*(?:0x)?([0-9a-fA-FXx]+)', re.IGNORECASE)
    pattern3 = re.compile(r'(?:CYCLE|CYC)[=\s]*(\d+).*?(?:IN|in_flat)[=\s]*(?:0x)?([0-9a-fA-FXx]+)', re.IGNORECASE)
    pattern4 = re.compile(r'(?:CYCLE|CYC)[=\s]*(\d+)', re.IGNORECASE)
    
    try:
        with log_file.open("r") as f:
            for line_num, line in enumerate(f, 1):
                line = line.strip()
                if not line:
                    continue
                
                # Try patterns in order of likelihood for better performance
                cycle_data = None
                
                # Pattern 1: CYCLE=<num> IN=<hex> OUT=<hex> (most common)
                match = pattern1.search(line)
                if match:
                    cycle_data = {
                        "cycle": int(match.group(1)),
                        "IN": match.group(2).upper(),
                        "OUT": match.group(3).upper()
                    }
                else:
                    # Pattern 2: CYCLE=<num> OUT=<hex> (no input)
                    match = pattern2.search(line)
                    if match and 'IN' not in line.upper():
                        cycle_data = {
                            "cycle": int(match.group(1)),
                            "IN": "",
                            "OUT": match.group(2).upper()
                        }
                    else:
                        # Pattern 3: CYCLE=<num> IN=<hex> (no output)
                        match = pattern3.search(line)
                        if match and 'OUT' not in line.upper():
                            cycle_data = {
                                "cycle": int(match.group(1)),
                                "IN": match.group(2).upper(),
                                "OUT": ""
                            }
                        else:
                            # Pattern 4: Just CYCLE=<num> (no data)
                            match = pattern4.search(line)
                            if match:
                                cycle_data = {
                                    "cycle": int(match.group(1)),
                                    "IN": "",
                                    "OUT": ""
                                }
                
                # Pattern 5: Alternative formats from different simulators
                # Handle formats like "Time: <time> Cycle: <num> Input: <hex> Output: <hex>"
                if not cycle_data:
                    match = re.search(r'(?:Time[:\s]*\d+[^\d]*)?(?:Cycle[:\s]*|C[:\s]*)(\d+)[^\d]*(?:Input[:\s]*|IN[:\s]*|I[:\s]*)([0-9a-fA-F]*)[^\w]*(?:Output[:\s]*|OUT[:\s]*|O[:\s]*)([0-9a-fA-F]*)', line, re.IGNORECASE)
                    if match:
                        cycle_data = {
                            "cycle": int(match.group(1)),
                            "IN": match.group(2).upper() if match.group(2) else "",
                            "OUT": match.group(3).upper() if match.group(3) else ""
                        }
                
                if cycle_data:
                    cycle_num = cycle_data["cycle"]
                    cycles[cycle_num] = {
                        "IN": cycle_data["IN"],
                        "OUT": cycle_data["OUT"]
                    }
                else:
                    # Debug: print unrecognized lines for format analysis
                    if any(keyword in line.upper() for keyword in ['CYCLE', 'TIME', 'INPUT', 'OUTPUT', 'IN', 'OUT']):
                        print(f"[Debug] Unrecognized log format at line {line_num}: {line}")
                        
    except Exception as e:
        print(f"[Warning] Failed to parse log file {log_file}: {e}")
    
    return cycles


def normalize_hex_value(hex_str: str) -> str:
    """
    Normalize hex values for comparison by:
    - Converting to uppercase
    - Removing leading zeros (but keep at least one digit)
    - Handling empty strings
    """
    if not hex_str or hex_str == "":
        return ""
    
    # Remove any non-hex characters and convert to uppercase
    clean_hex = re.sub(r'[^0-9A-Fa-fXx]', '', hex_str).upper()
    
    if not clean_hex:
        return ""
    
    # Remove leading zeros but keep at least one digit (preserve X values)
    if 'X' in clean_hex:
        return clean_hex  # Don't strip leading zeros from X values
    else:
        normalized = clean_hex.lstrip('0') or '0'
        return normalized


def hex_values_match_ignoring_x(hex1: str, hex2: str) -> bool:
    """
    Compare two hex values while ignoring X (unknown) differences.
    Returns True if the values match when ignoring positions where either has X.
    """
    if not hex1 and not hex2:
        return True
    if not hex1 or not hex2:
        return False
    
    # Normalize both values
    norm1 = normalize_hex_value(hex1)
    norm2 = normalize_hex_value(hex2)
    
    # If either is empty after normalization, they must both be empty
    if not norm1 or not norm2:
        return norm1 == norm2
    
    # Pad to same length for comparison
    max_len = max(len(norm1), len(norm2))
    norm1 = norm1.zfill(max_len)
    norm2 = norm2.zfill(max_len)
    
    # Compare character by character, ignoring X positions
    for c1, c2 in zip(norm1, norm2):
        if c1 == 'X' or c2 == 'X':
            continue  # Ignore positions where either has X
        if c1 != c2:
            return False
    
    return True


def remove_x_values(hex_str: str, replacement: str = "_") -> str:
    """
    Remove X values from hex string by replacing them with a placeholder.
    This makes it easier to visually compare the actual values.
    """
    if not hex_str:
        return hex_str
    return hex_str.upper().replace('X', replacement)


def create_visual_diff(str1: str, str2: str, label1: str = "Verilator", label2: str = "Icarus") -> Dict:
    """
    Create a visual diff showing differences between two strings with proper alignment.
    
    Args:
        str1: First string to compare
        str2: Second string to compare  
        label1: Label for first string (default: "Verilator")
        label2: Label for second string (default: "Icarus")
    """
    if not str1 or not str2:
        return {"diff_line": "Cannot create diff - one string is empty"}
    
    # Ensure same length for proper alignment
    max_len = max(len(str1), len(str2))
    aligned1 = str1.ljust(max_len)
    aligned2 = str2.ljust(max_len)
    
    # Create a diff indicator line
    diff_indicators = []
    for c1, c2 in zip(aligned1, aligned2):
        if c1 != c2:
            diff_indicators.append('^')  # Mark differences
        else:
            diff_indicators.append(' ')  # Same characters
    
    # Pad labels to consistent width for alignment
    label1_padded = (label1 + ":").ljust(12)
    label2_padded = (label2 + ":").ljust(12)
    diff_label = "Diff:".ljust(12)
    
    return {
        "formatted_diff": f"{label1_padded}{aligned1}\n{label2_padded}{aligned2}\n{diff_label}{''.join(diff_indicators)}",
        "formatted_lines": [
            f"{label1_padded}{aligned1}",
            f"{label2_padded}{aligned2}",
            f"{diff_label}{''.join(diff_indicators)}"
        ]
    }


def analyze_hex_difference(hex1: str, hex2: str) -> Dict:
    """
    Analyze the specific differences between two hex strings.
    
    Returns detailed analysis of X-value vs real differences.
    """
    analysis = {
        "has_x_differences": False,
        "has_real_differences": False,
        "x_positions": [],
        "real_differences": [],
        "total_positions": 0,
        "explanation": "",
        "x_removed_comparison": {}
    }
    
    if not hex1 or not hex2:
        analysis["explanation"] = "One or both hex strings are empty"
        return analysis
    
    # Normalize and pad
    norm1 = hex1.upper()
    norm2 = hex2.upper()
    max_len = max(len(norm1), len(norm2))
    norm1 = norm1.zfill(max_len)
    norm2 = norm2.zfill(max_len)
    
    analysis["total_positions"] = max_len
    
    # Create X-removed versions for easier comparison
    x_removed1 = remove_x_values(norm1, "_")
    x_removed2 = remove_x_values(norm2, "_")
    
    analysis["x_removed_comparison"] = {
        "verilator_x_removed": x_removed1,
        "icarus_x_removed": x_removed2,
        "visual_diff": create_visual_diff(x_removed1, x_removed2)
    }
    
    # Analyze each position
    for i, (c1, c2) in enumerate(zip(norm1, norm2)):
        if c1 != c2:
            if c1 == 'X' or c2 == 'X':
                analysis["has_x_differences"] = True
                analysis["x_positions"].append({
                    "position": i,
                    "verilator": c1,
                    "icarus": c2
                })
            else:
                analysis["has_real_differences"] = True
                analysis["real_differences"].append({
                    "position": i,
                    "verilator": c1,
                    "icarus": c2
                })
    
    # Generate explanation
    if analysis["has_real_differences"] and analysis["has_x_differences"]:
        analysis["explanation"] = f"Mixed differences: {len(analysis['real_differences'])} real differences and {len(analysis['x_positions'])} X-value differences"
    elif analysis["has_real_differences"]:
        analysis["explanation"] = f"Real simulator differences at {len(analysis['real_differences'])} positions"
    elif analysis["has_x_differences"]:
        analysis["explanation"] = f"Only X-value differences at {len(analysis['x_positions'])} positions (should be filtered)"
    else:
        analysis["explanation"] = "No differences found"
    
    return analysis


def compare_simulation_logs(verilator_log: Path, icarus_log: Path) -> Tuple[bool, List[Dict]]:
    """
    Compare simulation logs from Verilator and Icarus Verilog with robust normalization.
    
    Returns (logs_match: bool, differences: List[Dict])
    """
    verilator_cycles = parse_simulation_log(verilator_log)
    icarus_cycles = parse_simulation_log(icarus_log)
    
    differences = []
    logs_match = True
    
    print(f"[LogCompare] Parsed {len(verilator_cycles)} Verilator cycles, {len(icarus_cycles)} Icarus cycles")
    
    # Get all cycle numbers from both logs
    all_cycles = set(verilator_cycles.keys()) | set(icarus_cycles.keys())
    
    if not all_cycles:
        print("[LogCompare] Warning: No cycles found in either log file")
        return True, []  # No data to compare
    
    for cycle in sorted(all_cycles):
        v_data = verilator_cycles.get(cycle, {"IN": "", "OUT": ""})
        i_data = icarus_cycles.get(cycle, {"IN": "", "OUT": ""})
        
        # Normalize hex values for comparison
        v_in_norm = normalize_hex_value(v_data["IN"])
        v_out_norm = normalize_hex_value(v_data["OUT"])
        i_in_norm = normalize_hex_value(i_data["IN"])
        i_out_norm = normalize_hex_value(i_data["OUT"])
        
        # Compare normalized inputs and outputs, ignoring X differences
        in_match = hex_values_match_ignoring_x(v_data["IN"], i_data["IN"])
        out_match = hex_values_match_ignoring_x(v_data["OUT"], i_data["OUT"])
        
        # Also check exact match for reporting
        exact_in_match = v_in_norm == i_in_norm
        exact_out_match = v_out_norm == i_out_norm
        
        if not in_match or not out_match:
            logs_match = False
            
            # Analyze the type of difference
            difference_analysis = analyze_hex_difference(v_data["OUT"], i_data["OUT"])
            
            differences.append({
                "cycle": cycle,
                "verilator": {
                    "IN": v_data["IN"],
                    "OUT": v_data["OUT"],
                    "IN_norm": v_in_norm,
                    "OUT_norm": v_out_norm
                },
                "icarus": {
                    "IN": i_data["IN"],
                    "OUT": i_data["OUT"],
                    "IN_norm": i_in_norm,
                    "OUT_norm": i_out_norm
                },
                "in_match": in_match,
                "out_match": out_match,
                "exact_in_match": exact_in_match,
                "exact_out_match": exact_out_match,
                "x_filtered": not exact_in_match or not exact_out_match,
                "difference_analysis": difference_analysis
            })
    
    return logs_match, differences


def analyze_top_module(top_sv_file: Path) -> Dict:
    """
    Analyze the top.sv file to extract module and connection information.
    
    Returns a dictionary with module analysis information.
    """
    analysis = {
        "modules": [],
        "wire_count": 0,
        "connections": []
    }
    
    if not top_sv_file.exists():
        return analysis
    
    try:
        with top_sv_file.open("r") as f:
            content = f.read()
        
        # Extract module instantiations
        import re
        module_pattern = r'(\w+)\s+u_(\w+)\s*\('
        matches = re.findall(module_pattern, content)
        
        for module_type, instance_name in matches:
            analysis["modules"].append({
                "module_type": module_type,
                "instance_name": f"u_{instance_name}",
                "full_name": module_type
            })
        
        # Count wire declarations
        wire_pattern = r'wire\s+(?:\[\d+:\d+\]\s+)?(\w+);'
        wire_matches = re.findall(wire_pattern, content)
        analysis["wire_count"] = len(wire_matches)
        
        # Extract some key connections for debugging
        assign_pattern = r'assign\s+(\w+)\s*=\s*([^;]+);'
        assign_matches = re.findall(assign_pattern, content)
        analysis["connections"] = assign_matches[:10]  # First 10 connections for brevity
        
    except Exception as e:
        analysis["parse_error"] = str(e)
    
    return analysis


def extract_cycle_info(cycle_dir: Path) -> Dict:
    """
    Extract cycle information from the cycle directory path.
    """
    try:
        cycle_name = cycle_dir.name
        if cycle_name.startswith("cycle_"):
            cycle_number = int(cycle_name.split("_")[1])
            return {
                "cycle_number": cycle_number,
                "cycle_name": cycle_name,
                "valid": True
            }
    except (ValueError, IndexError):
        pass
    
    return {
        "cycle_number": -1,
        "cycle_name": cycle_dir.name,
        "valid": False
    }


def copy_complete_cycle_data(cycle_dir: Path, bug_dir: Path) -> None:
    """
    Copy all files from the cycle directory to the bug directory.
    This preserves the complete test case including all build artifacts.
    """
    try:
        # Copy all files (but not subdirectories like obj_dir which can be large)
        for src_file in cycle_dir.iterdir():
            if src_file.is_file():
                shutil.copy2(src_file, bug_dir / src_file.name)
        
        # Copy important subdirectories but skip large build artifacts
        important_dirs = ["obj_dir"]  # Add other important dirs if needed
        for dir_name in important_dirs:
            src_dir = cycle_dir / dir_name
            if src_dir.exists() and src_dir.is_dir():
                dst_dir = bug_dir / dir_name
                # Only copy essential files from obj_dir, not all build artifacts
                if dir_name == "obj_dir":
                    dst_dir.mkdir(exist_ok=True)
                    # Copy the executable and key files, skip intermediate build files
                    for obj_file in src_dir.iterdir():
                        if obj_file.is_file() and (
                            obj_file.name.startswith("Vtb_") and obj_file.suffix == "" or  # Executable
                            obj_file.suffix in [".h", ".mk"] or  # Headers and makefiles
                            "main" in obj_file.name  # Main files
                        ):
                            shutil.copy2(obj_file, dst_dir / obj_file.name)
                else:
                    shutil.copytree(src_dir, dst_dir, dirs_exist_ok=True)
                    
    except Exception as e:
        print(f"[Warning] Failed to copy some cycle data: {e}")


def cleanup_old_cycles(output_dir: Path, max_cycles: int = 50, preserve_recent: int = 10) -> int:
    """
    Clean up old cycle directories to prevent disk space issues.
    
    Args:
        output_dir: Base output directory containing cycle folders
        max_cycles: Maximum number of cycle directories to keep
        preserve_recent: Always preserve this many most recent cycles
    
    Returns:
        Number of cycles deleted
    """
    try:
        # Find all cycle directories
        cycle_dirs = []
        for item in output_dir.iterdir():
            if item.is_dir() and item.name.startswith("cycle_"):
                try:
                    cycle_num = int(item.name.split("_")[1])
                    cycle_dirs.append((cycle_num, item))
                except (ValueError, IndexError):
                    continue
        
        if len(cycle_dirs) <= max_cycles:
            return 0  # No cleanup needed
        
        # Sort by cycle number
        cycle_dirs.sort(key=lambda x: x[0])
        
        # Always preserve the most recent cycles
        cycles_to_preserve = max(preserve_recent, max_cycles - len(cycle_dirs) + preserve_recent)
        cycles_to_delete = cycle_dirs[:-cycles_to_preserve] if cycles_to_preserve > 0 else cycle_dirs[:-preserve_recent]
        
        deleted_count = 0
        for cycle_num, cycle_path in cycles_to_delete:
            try:
                shutil.rmtree(cycle_path)
                deleted_count += 1
                print(f"[Cleanup] Deleted old cycle directory: {cycle_path.name}")
            except Exception as e:
                print(f"[Warning] Failed to delete {cycle_path.name}: {e}")
        
        if deleted_count > 0:
            print(f"[Cleanup] Deleted {deleted_count} old cycle directories, kept {len(cycle_dirs) - deleted_count}")
        
        return deleted_count
        
    except Exception as e:
        print(f"[Warning] Cycle cleanup failed: {e}")
        return 0


def save_bug_report(cycle_dir: Path, 
                   seed: int,
                   differences: List[Dict],
                   verilator_summary: Dict,
                   icarus_summary: Dict) -> Path:
    """
    Save a detailed bug report when simulators produce different results.
    
    Returns the path to the saved bug report.
    """
    timestamp = int(time.time())
    bug_id = f"bug_{seed}_{timestamp}"
    
    # Create bug report directory
    bug_dir = cycle_dir.parent / "bugs" / bug_id
    bug_dir.mkdir(parents=True, exist_ok=True)
    
    # Copy complete test case - all files from the cycle directory
    # This preserves the entire test case for analysis and prevents data loss
    copy_complete_cycle_data(cycle_dir, bug_dir)
    
    # Analyze the top.sv file to extract module information
    top_sv_file = cycle_dir / f"{verilator_summary.get('top_name', 'top')}.sv"
    module_analysis = analyze_top_module(top_sv_file)
    
    # Extract cycle information from the cycle directory path
    cycle_info = extract_cycle_info(cycle_dir)
    
    # Create bug report
    bug_report = {
        "bug_id": bug_id,
        "timestamp": timestamp,
        "seed": seed,
        "cycle_info": {
            "cycle_number": cycle_info["cycle_number"],
            "cycle_directory": str(cycle_dir),
            "preserved_in_bug_folder": True,
            "complete_test_case_saved": True
        },
        "test_files": {
            "top_sv": str(bug_dir / f"{verilator_summary.get('top_name', 'top')}.sv"),
            "testbench_sv": str(bug_dir / f"tb_{verilator_summary.get('top_name', 'top')}.sv"),
            "all_cycle_files": "Complete cycle directory contents preserved in bug folder"
        },
        "location_info": {
            "generated_top_module": str(top_sv_file),
            "modules_instantiated": module_analysis.get("modules", []),
            "total_modules": len(module_analysis.get("modules", [])),
            "wire_connections": module_analysis.get("wire_count", 0),
            "description": f"Bug found in cycle {cycle_info['cycle_number']} - auto-generated top.sv with {len(module_analysis.get('modules', []))} module instances"
        },
        "simulation_results": {
            "verilator": verilator_summary,
            "icarus": icarus_summary
        },
        "differences": differences,
        "total_differences": len(differences),
        "affected_cycles": [d["cycle"] for d in differences]
    }
    
    # Save bug report
    bug_report_file = bug_dir / "bug_report.json"
    with bug_report_file.open("w") as f:
        json.dump(bug_report, f, indent=2)
    
    # Create summary for main bug list
    bug_summary = {
        "bug_id": bug_id,
        "timestamp": timestamp,
        "seed": seed,
        "total_differences": len(differences),
        "bug_report_path": str(bug_report_file)
    }
    
    return bug_report_file


def run_dual_simulation(verilator_bin: str,
                       iverilog_bin: str,
                       vvp_bin: str,
                       cycle_dir: Path,
                       top_name: str,
                       tb_name: str,
                       extra_sv: list[Path],
                       verilator_flags: list[str],
                       iverilog_flags: list[str],
                       seed: int) -> Tuple[bool, Optional[Path]]:
    """
    Run both Verilator and Icarus Verilog simulations and compare results.
    
    Returns (bug_found: bool, bug_report_path: Optional[Path])
    """
    
    # Run Verilator simulation
    print(f"[DualSim] Running Verilator simulation...")
    v_build_ok, v_run_ok, v_rc, v_exe = run_verilator_binary(
        verilator_bin, cycle_dir, top_name, tb_name, extra_sv, verilator_flags
    )
    
    if not (v_build_ok and v_run_ok):
        print(f"[DualSim] Verilator simulation failed: build_ok={v_build_ok}, run_ok={v_run_ok}, rc={v_rc}")
        return None, None
    
    # Run Icarus Verilog simulation  
    print(f"[DualSim] Running Icarus Verilog simulation...")
    i_build_ok, i_run_ok, i_rc, i_vvp = run_icarus_verilog(
        iverilog_bin, vvp_bin, cycle_dir, top_name, tb_name, extra_sv, iverilog_flags
    )
    
    if not (i_build_ok and i_run_ok):
        print(f"[DualSim] Icarus Verilog simulation failed: build_ok={i_build_ok}, run_ok={i_run_ok}, rc={i_rc}")
        return None, None
    
    # Compare simulation logs
    verilator_log = cycle_dir / "sim.log"
    icarus_log = cycle_dir / "icarus_sim.log"
    
    logs_match, differences = compare_simulation_logs(verilator_log, icarus_log)
    
    if not logs_match:
        print(f"[DualSim] BUG FOUND! Simulators produced different results ({len(differences)} differences)")
        
        # Create simulation summaries
        verilator_summary = {
            "simulator": "Verilator",
            "build_ok": v_build_ok,
            "run_ok": v_run_ok,
            "return_code": v_rc,
            "executable": str(v_exe),
            "log_file": str(verilator_log),
            "top_name": top_name
        }
        
        icarus_summary = {
            "simulator": "Icarus Verilog",
            "build_ok": i_build_ok,
            "run_ok": i_run_ok,
            "return_code": i_rc,
            "vvp_file": str(i_vvp),
            "log_file": str(icarus_log),
            "top_name": top_name
        }
        
        # Save bug report
        bug_report_path = save_bug_report(
            cycle_dir, seed, differences, verilator_summary, icarus_summary
        )
        
        return True, bug_report_path
    
    else:
        print(f"[DualSim] Simulators agree - no bug found")
        return False, None


# Import the Verilator runner from the main module
def run_verilator_binary(verilator_bin: str,
                         cycle_dir: Path,
                         top_name: str,
                         tb_name: str,
                         extra_sv: list[Path],
                         verilator_flags: list[str]) -> tuple[bool, bool, int, Path]:
    """
    Build & run using Verilator's single-binary flow.
    This is imported from the main fuzzing module.
    """
    top_sv = cycle_dir / f"{top_name}.sv"
    tb_sv = cycle_dir / f"{tb_name}.sv"
    obj_dir = cycle_dir / "obj_dir"
    exe = obj_dir / f"V{tb_name}"

    cmd = [verilator_bin, "--binary", "-sv", "--top-module", tb_name]
    
    # Add cycle directory for generated files
    cmd.extend(["+incdir+" + str(cycle_dir.absolute())])
    
    # Add RTL sources first, then generated files
    cmd.extend([str(p) for p in extra_sv])
    cmd.extend([str(top_sv), str(tb_sv)])
    
    # Add user flags which should include proper include directories
    cmd.extend(verilator_flags)

    build_log = cycle_dir / "build.log"
    build_err = cycle_dir / "build.err"
    with build_log.open("w") as bout, build_err.open("w") as berr:
        try:
            proc = subprocess.run(cmd, stdout=bout, stderr=berr, cwd=cycle_dir)
            build_rc = proc.returncode
        except Exception as e:
            (cycle_dir / "build_exception.txt").write_text(str(e))
            return (False, False, 127, exe)

    if build_rc != 0:
        return (False, False, build_rc, exe)

    sim_log = cycle_dir / "sim.log"
    sim_err = cycle_dir / "sim.err"
    with sim_log.open("w") as sout, sim_err.open("w") as serr:
        try:
            # Use absolute path for the executable
            exe_abs = exe.absolute()
            proc2 = subprocess.run([str(exe_abs)], stdout=sout, stderr=serr, cwd=cycle_dir)
            sim_rc = proc2.returncode
        except Exception as e:
            (cycle_dir / "sim_exception.txt").write_text(str(e))
            return (True, False, 127, exe)

    return (True, sim_rc == 0, sim_rc, exe)


def check_seed_consistency(cycle_dir: Path, seed: int) -> Tuple[bool, Dict]:
    """
    Verify that both simulators are using the same random seed by checking
    if the input patterns in their logs match.
    
    Returns (seeds_consistent: bool, consistency_report: Dict)
    """
    verilator_log = cycle_dir / "sim.log"
    icarus_log = cycle_dir / "icarus_sim.log"
    
    verilator_cycles = parse_simulation_log(verilator_log)
    icarus_cycles = parse_simulation_log(icarus_log)
    
    consistency_report = {
        "seed": seed,
        "verilator_cycles": len(verilator_cycles),
        "icarus_cycles": len(icarus_cycles),
        "input_mismatches": [],
        "consistent": True
    }
    
    # Check first 10 cycles for input consistency (more thorough check)
    check_cycles = min(10, min(len(verilator_cycles), len(icarus_cycles)))
    
    for cycle in range(check_cycles):
        if cycle in verilator_cycles and cycle in icarus_cycles:
            v_in = normalize_hex_value(verilator_cycles[cycle]["IN"])
            i_in = normalize_hex_value(icarus_cycles[cycle]["IN"])
            
            if v_in and i_in and v_in != i_in:
                # Check if this is a real mismatch or just timing offset
                consistency_report["consistent"] = False
                consistency_report["input_mismatches"].append({
                    "cycle": cycle,
                    "verilator_input": v_in,
                    "icarus_input": i_in
                })
                print(f"[SeedCheck] Input mismatch at cycle {cycle}: Verilator={v_in}, Icarus={i_in}")
    
    if consistency_report["consistent"]:
        print(f"[SeedCheck] Seed consistency verified for {check_cycles} cycles")
    else:
        print(f"[SeedCheck] WARNING: Seed inconsistency detected! {len(consistency_report['input_mismatches'])} mismatches")
    
    return consistency_report["consistent"], consistency_report


if __name__ == "__main__":
    # Simple test of the dual simulator functionality
    print("Dual simulator module loaded successfully!")
    print(f"Icarus Verilog found at: {resolve_icarus(None)}")
