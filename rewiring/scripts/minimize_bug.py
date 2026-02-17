#!/usr/bin/env python3
"""
Wire-Level Delta-Debugging Bug Minimizer

Uses the bit trace dependency graph to systematically cut individual
inter-module (MTM) wires in top.sv, re-simulating after each cut to
converge on the minimal wiring that still reproduces the simulator
disagreement.

Usage:
    python3 minimize_bug.py \
        --bug-dir TestArchive/large_test1/bugs/tribug_1339297989_1762975525 \
        --modules test_libraries/comprehensive_tests \
        --output isolated_bugs/minimized/
"""

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time
from collections import defaultdict, deque
from pathlib import Path
from typing import Optional

# Allow importing from the same directory
SCRIPT_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(SCRIPT_DIR))

from trace_bit_bundled import BundledBitTracer
from dual_simulator import (
    run_verilator_binary,
    run_icarus_verilog,
    compare_simulation_logs,
)


# ─────────────────────────────────────────────────────────────────────────────
# Step 1: Parse top.sv into structured wire/assign data
# ─────────────────────────────────────────────────────────────────────────────

class TopDesign:
    """Structured representation of a top.sv design for surgical editing."""

    def __init__(self, top_sv_path: Path):
        self.path = top_sv_path
        self.raw_text = top_sv_path.read_text()

        # Module port declarations: module_name -> {in_width, out_width}
        self.modules: dict[str, dict] = {}
        # Wire declarations as raw lines
        self.wire_decl_lines: list[str] = []
        # All assign statements, categorized
        self.assigns: list[dict] = []  # each: {type, target, target_bit, source, source_bit, line}
        # Module instantiation lines
        self.inst_lines: list[str] = []
        # Registered output blocks
        self.reg_blocks: list[str] = []
        # Top-level port widths
        self.in_flat_width = 0
        self.out_flat_width = 0
        # Other header/footer lines
        self.header_lines: list[str] = []

        self._parse()

    def _parse(self):
        """Parse top.sv into structured components."""
        content = self.raw_text

        # Extract top-level port widths
        m = re.search(r'input\s+wire\s+\[(\d+):0\]\s+in_flat', content)
        if m:
            self.in_flat_width = int(m.group(1)) + 1
        m = re.search(r'output\s+wire\s+\[(\d+):0\]\s+out_flat', content)
        if m:
            self.out_flat_width = int(m.group(1)) + 1

        # Parse module wire declarations
        for match in re.finditer(r'wire\s+\[(\d+):(\d+)\]\s+(\w+)_(in|out)_flat;', content):
            high, low, mod_name, port_type = match.groups()
            if mod_name not in self.modules:
                self.modules[mod_name] = {'in_width': 0, 'out_width': 0}
            width = int(high) - int(low) + 1
            if port_type == 'in':
                self.modules[mod_name]['in_width'] = width
            else:
                self.modules[mod_name]['out_width'] = width

        # Parse all assign statements and categorize
        assign_pat = re.compile(
            r'assign\s+(\w+)\[(\d+)\]\s*=\s*(\w+)\[(\d+)\]\s*;'
        )
        for match in assign_pat.finditer(content):
            target, target_bit, source, source_bit = match.groups()
            target_bit = int(target_bit)
            source_bit = int(source_bit)

            # Categorize
            if source == 'in_flat' and target.endswith('_in_flat'):
                atype = 'ITM'  # input-to-module
            elif source.endswith('_out_flat') and target == 'out_flat':
                atype = 'MTO'  # module-to-output
            elif source.endswith(('_out_flat', '_out_reg')) and target.endswith('_in_flat'):
                atype = 'MTM'  # module-to-module
            else:
                atype = 'OTHER'

            self.assigns.append({
                'type': atype,
                'target': target,
                'target_bit': target_bit,
                'source': source,
                'source_bit': source_bit,
                'line': match.group(0),
            })

    def get_mtm_assigns(self) -> list[dict]:
        """Return only MTM (module-to-module) assigns."""
        return [a for a in self.assigns if a['type'] == 'MTM']

    def get_mtm_key(self, assign: dict) -> str:
        """Unique key for an MTM assign."""
        return f"{assign['target']}[{assign['target_bit']}]={assign['source']}[{assign['source_bit']}]"

    def generate_top_sv(self, cut_wires: set[str]) -> str:
        """
        Regenerate top.sv text, replacing cut MTM wires with 1'b0.

        cut_wires: set of MTM keys (from get_mtm_key) to cut
        """
        lines = []
        for line in self.raw_text.splitlines():
            stripped = line.strip()

            # Check if this line is an MTM assign that should be cut
            m = re.match(
                r'assign\s+(\w+)\[(\d+)\]\s*=\s*(\w+)\[(\d+)\]\s*;',
                stripped,
            )
            if m:
                target, target_bit, source, source_bit = m.groups()
                key = f"{target}[{target_bit}]={source}[{source_bit}]"
                if key in cut_wires:
                    # Replace with constant 0
                    lines.append(f"assign {target}[{target_bit}] = 1'b0; // CUT: was {source}[{source_bit}]")
                    continue

            lines.append(line)

        return "\n".join(lines)


# ─────────────────────────────────────────────────────────────────────────────
# Step 2: Use BundledBitTracer to get dependency chains; extract MTM wires
# ─────────────────────────────────────────────────────────────────────────────

def find_differing_bits(hex_a: str, hex_b: str) -> list[int]:
    """XOR two hex strings and return sorted list of differing bit indices (LSB=0)."""
    val_a = int(hex_a.strip(), 16) if hex_a.strip() else 0
    val_b = int(hex_b.strip(), 16) if hex_b.strip() else 0
    xor_val = val_a ^ val_b
    bits = []
    idx = 0
    v = xor_val
    while v:
        if v & 1:
            bits.append(idx)
        v >>= 1
        idx += 1
    return sorted(bits)


def parse_bug_report(bug_dir: Path) -> dict:
    """
    Parse bug_report.json and find the first cycle with a clear ground truth.

    Returns dict with cycle, verilator_out, icarus_out, differing_bits, etc.
    """
    report_path = bug_dir / "bug_report.json"
    with open(report_path) as f:
        report = json.load(f)

    for diff in report.get('differences', []):
        gt = diff.get('ground_truth', 'unknown')
        if gt == 'unknown':
            continue

        v_out = diff['verilator']['OUT']
        i_out = diff['icarus']['OUT']
        diff_bits = find_differing_bits(v_out, i_out)
        if not diff_bits:
            continue

        return {
            'bug_id': report.get('bug_id', 'unknown'),
            'seed': report.get('seed', 0),
            'cycle': diff['cycle'],
            'verilator_out': v_out,
            'icarus_out': i_out,
            'differing_bits': diff_bits,
            'ground_truth': gt,
        }

    raise ValueError("No differences with clear ground truth found in bug report")


def collect_mtm_wires_in_trace(
    tracer: BundledBitTracer,
    top_design: TopDesign,
    diff_bits: list[int],
) -> dict[str, int]:
    """
    Run the bit tracer for each differing output bit.
    Collect all MTM wire connections that appear in the dependency chains.

    Returns dict: mtm_key -> hop_distance (min distance from any differing output bit).
    """
    all_mtm_keys: dict[str, int] = {}
    mtm_assigns_by_key = {
        top_design.get_mtm_key(a): a for a in top_design.get_mtm_assigns()
    }

    for bit in diff_bits:
        print(f"  Tracing out_flat[{bit}]...")
        try:
            # trace_and_bundle returns (graph, visited)
            # visited is a set of (signal_name, bit_index) tuples
            _graph, visited = tracer.trace_and_bundle('out_flat', bit)
        except Exception as e:
            print(f"    [Warning] Trace failed for bit {bit}: {e}")
            continue

        # visited contains all (signal, bit) pairs in the dependency chain.
        # We need to find which MTM assigns connect signals in this chain.
        # An MTM assign: target_in_flat[N] = source_out_flat[M]
        # It's in the chain if (target_in_flat, N) is visited AND (source_out_flat, M) is visited.
        for key, assign in mtm_assigns_by_key.items():
            target_pair = (assign['target'], assign['target_bit'])
            source_pair = (assign['source'], assign['source_bit'])
            if target_pair in visited and source_pair in visited:
                # Estimate hop distance: count how many _out_flat signals
                # are between this wire and out_flat[bit]
                # Simple heuristic: closer to out_flat = lower hop count
                # For now, just mark as present; we'll sort by distance later
                if key not in all_mtm_keys:
                    all_mtm_keys[key] = 999
                # Use 0 as a placeholder; we'll compute proper distances next

    # Compute approximate hop distances via BFS from out_flat bits
    # through the bit_connections graph
    for bit in diff_bits:
        distances: dict[tuple, int] = {}
        queue = deque([( ('out_flat', bit), 0 )])
        seen = set()
        while queue:
            (sig, idx), dist = queue.popleft()
            if (sig, idx) in seen:
                continue
            seen.add((sig, idx))
            distances[(sig, idx)] = dist

            # Follow bit_connections backwards (target -> source)
            if (sig, idx) in tracer.bit_connections:
                src_sig, src_bit = tracer.bit_connections[(sig, idx)]
                queue.append(((src_sig, src_bit), dist + 1))

            # Follow module internals: out_flat -> in_flat
            if sig.endswith('_out_flat'):
                mod_name = sig[:-9]
                result = tracer.get_bit_dependencies(mod_name, idx)
                if result and result['input_bits']:
                    mod_in_sig = f"{mod_name}_in_flat"
                    for in_bit in result['input_bits']:
                        queue.append(((mod_in_sig, in_bit), dist + 1))

        # Update MTM wire distances
        for key, assign in mtm_assigns_by_key.items():
            target_pair = (assign['target'], assign['target_bit'])
            if target_pair in distances:
                d = distances[target_pair]
                if key in all_mtm_keys:
                    all_mtm_keys[key] = min(all_mtm_keys[key], d)

    return all_mtm_keys


# ─────────────────────────────────────────────────────────────────────────────
# Step 3: Simulator runner for modified designs
# ─────────────────────────────────────────────────────────────────────────────

def collect_rtl_sources(module_dir: Path) -> list[Path]:
    """Collect all .sv source files from the module library."""
    files = []
    for subdir in ['flattened', 'unflattened']:
        d = module_dir / subdir
        if d.exists():
            files.extend(sorted(d.glob('*.sv')))
    return files


def resolve_verilator() -> str:
    """Find the Verilator binary."""
    for candidate in ['/opt/verilator/bin/verilator', shutil.which('verilator') or '']:
        if candidate and Path(candidate).exists():
            return candidate
    raise FileNotFoundError("Verilator binary not found")


def resolve_icarus() -> tuple[str, str]:
    """Find iverilog and vvp binaries."""
    iverilog = shutil.which('iverilog') or '/usr/bin/iverilog'
    vvp = shutil.which('vvp') or '/usr/bin/vvp'
    if not Path(iverilog).exists():
        raise FileNotFoundError("iverilog not found")
    if not Path(vvp).exists():
        raise FileNotFoundError("vvp not found")
    return iverilog, vvp


def run_both_simulators(
    work_dir: Path,
    extra_sv: list[Path],
    verilator_bin: str,
    iverilog_bin: str,
    vvp_bin: str,
    top_name: str = 'top',
    tb_name: str = 'tb_top',
) -> tuple[bool, list]:
    """
    Run Verilator and Icarus on the design in work_dir.

    Returns (has_differences: bool, differences: list).
    """
    # Build verilator flags
    verilator_flags = [
        '-Wno-TIMESCALEMOD', '-Wno-WIDTHTRUNC', '-Wno-WIDTHEXPAND',
        '-Wno-UNUSEDSIGNAL', '-Wno-UNDRIVEN', '-Wno-PINMISSING',
        '--timing',
        f'+incdir+{work_dir.absolute()}',
    ]

    # Build icarus flags
    icarus_flags = [
        '-g2012',
        f'-I{work_dir.absolute()}',
    ]

    # Clean any previous build artifacts
    obj_dir = work_dir / 'obj_dir'
    if obj_dir.exists():
        shutil.rmtree(obj_dir)
    for f in work_dir.glob('*.vvp'):
        f.unlink()

    # Run Verilator
    v_build_ok, v_run_ok, v_rc, v_exe = run_verilator_binary(
        verilator_bin, work_dir, top_name, tb_name, extra_sv, verilator_flags
    )
    if not v_build_ok:
        return None, []  # Build failure
    if not v_run_ok:
        return None, []

    # Run Icarus
    i_build_ok, i_run_ok, i_rc, i_vvp = run_icarus_verilog(
        iverilog_bin, vvp_bin, work_dir, top_name, tb_name, extra_sv, icarus_flags
    )
    if not i_build_ok:
        return None, []
    if not i_run_ok:
        return None, []

    # Compare logs
    verilator_log = work_dir / 'sim.log'
    icarus_log = work_dir / 'icarus_sim.log'

    if not verilator_log.exists() or not icarus_log.exists():
        return None, []

    logs_match, differences = compare_simulation_logs(verilator_log, icarus_log)
    return (not logs_match), differences


# ─────────────────────────────────────────────────────────────────────────────
# Step 4: Greedy reduction loop
# ─────────────────────────────────────────────────────────────────────────────

def run_reduction(
    bug_dir: Path,
    module_dir: Path,
    output_dir: Path,
    verilator_bin: str,
    iverilog_bin: str,
    vvp_bin: str,
) -> dict:
    """
    Main reduction loop.

    1. Parse bug report and trace differing bits
    2. Collect MTM wires in dependency chains
    3. Iteratively cut wires and re-simulate
    4. Output minimal design and report
    """
    output_dir.mkdir(parents=True, exist_ok=True)

    # ── Parse bug ──
    print("\n[Step 1] Parsing bug report...")
    bug_data = parse_bug_report(bug_dir)
    print(f"  Bug ID: {bug_data['bug_id']}")
    print(f"  Seed:   {bug_data['seed']}")
    print(f"  First clear diff at cycle {bug_data['cycle']}")
    print(f"  Ground truth: {bug_data['ground_truth']}")
    print(f"  Differing output bits: {bug_data['differing_bits']}")

    # ── Parse top.sv ──
    print("\n[Step 2] Parsing top.sv structure...")
    top_sv_path = bug_dir / 'top.sv'
    top_design = TopDesign(top_sv_path)
    all_mtm = top_design.get_mtm_assigns()
    print(f"  Modules: {len(top_design.modules)}")
    print(f"  Total assigns: {len(top_design.assigns)}")
    print(f"  MTM (module-to-module) wires: {len(all_mtm)}")

    # ── Trace differing bits ──
    print("\n[Step 3] Tracing differing bits to find relevant MTM wires...")
    tracer = BundledBitTracer(str(top_sv_path), str(module_dir))
    traced_mtm = collect_mtm_wires_in_trace(
        tracer, top_design, bug_data['differing_bits']
    )
    print(f"  MTM wires in dependency chains: {len(traced_mtm)} / {len(all_mtm)}")

    # Sort by hop distance (closest to output first)
    sorted_mtm = sorted(traced_mtm.items(), key=lambda x: x[1])
    for key, dist in sorted_mtm[:10]:
        print(f"    {key}  (hop distance: {dist})")
    if len(sorted_mtm) > 10:
        print(f"    ... and {len(sorted_mtm) - 10} more")

    # ── Set up working directory ──
    work_dir = output_dir / 'work'
    work_dir.mkdir(parents=True, exist_ok=True)

    # Copy testbench (never changes)
    tb_src = bug_dir / 'tb_top.sv'
    tb_dst = work_dir / 'tb_top.sv'
    shutil.copy2(tb_src, tb_dst)

    # Collect RTL sources
    extra_sv = collect_rtl_sources(module_dir)
    print(f"\n  RTL source files: {len(extra_sv)}")

    # ── Baseline: verify bug reproduces ──
    print("\n[Step 4] Verifying baseline (bug reproduces with original design)...")
    shutil.copy2(top_sv_path, work_dir / 'top.sv')
    has_diff, baseline_diffs = run_both_simulators(
        work_dir, extra_sv, verilator_bin, iverilog_bin, vvp_bin
    )

    if has_diff is None:
        print("  [ERROR] Baseline simulation failed to build/run!")
        return {'error': 'baseline_failed'}

    if not has_diff:
        print("  [ERROR] Bug does NOT reproduce on baseline! Cannot minimize.")
        return {'error': 'bug_not_reproduced'}

    print(f"  Baseline confirmed: {len(baseline_diffs)} cycles with differences")

    # ── Reduction loop ──
    print(f"\n[Step 5] Starting wire-cut reduction ({len(sorted_mtm)} MTM wires to test)...")

    # Track state
    permanently_cut: set[str] = set()   # wires that were cut without losing the bug
    essential_wires: list[dict] = []     # wires that, when cut, eliminate the bug
    reduction_steps: list[dict] = []     # log of every step

    # Also try non-traced MTM wires after the traced ones
    traced_keys = {k for k, _ in sorted_mtm}
    non_traced_mtm = [
        (top_design.get_mtm_key(a), 1000)
        for a in all_mtm
        if top_design.get_mtm_key(a) not in traced_keys
    ]
    all_wires_to_try = sorted_mtm + non_traced_mtm

    step_num = 0
    for mtm_key, hop_dist in all_wires_to_try:
        step_num += 1

        # Skip if already permanently cut
        if mtm_key in permanently_cut:
            continue

        in_trace = mtm_key in traced_keys
        print(f"\n  [{step_num}/{len(all_wires_to_try)}] Trying to cut: {mtm_key}"
              f"  {'(in trace, hop=' + str(hop_dist) + ')' if in_trace else '(not in trace)'}")

        # Generate modified top.sv with this wire cut + all permanently cut wires
        trial_cuts = permanently_cut | {mtm_key}
        modified_top = top_design.generate_top_sv(trial_cuts)
        (work_dir / 'top.sv').write_text(modified_top)

        # Run simulators
        has_diff, diffs = run_both_simulators(
            work_dir, extra_sv, verilator_bin, iverilog_bin, vvp_bin
        )

        step_entry = {
            'step': step_num,
            'wire': mtm_key,
            'in_trace': in_trace,
            'hop_distance': hop_dist,
        }

        if has_diff is None:
            # Build/sim failure — treat as essential (can't cut it)
            print(f"    -> BUILD/SIM FAILURE: keeping wire (essential)")
            step_entry['result'] = 'build_failure'
            step_entry['action'] = 'restore'
            essential_wires.append({
                'wire': mtm_key,
                'reason': 'build_failure',
                'in_trace': in_trace,
                'hop_distance': hop_dist,
            })
        elif has_diff:
            # Bug still present — wire is NOT essential, keep it cut
            print(f"    -> Bug persists ({len(diffs)} diff cycles): CUT permanently")
            permanently_cut.add(mtm_key)
            step_entry['result'] = 'bug_persists'
            step_entry['action'] = 'cut'
            step_entry['diff_cycles'] = len(diffs)
        else:
            # Bug gone — wire IS essential, restore it
            print(f"    -> Bug GONE: wire is ESSENTIAL, restoring")
            step_entry['result'] = 'bug_eliminated'
            step_entry['action'] = 'restore'
            essential_wires.append({
                'wire': mtm_key,
                'reason': 'bug_eliminated_when_cut',
                'in_trace': in_trace,
                'hop_distance': hop_dist,
            })

        reduction_steps.append(step_entry)

    # ── Generate final minimal design ──
    print(f"\n[Step 6] Generating minimal design...")
    minimal_top = top_design.generate_top_sv(permanently_cut)
    minimal_top_path = output_dir / 'top_minimal.sv'
    minimal_top_path.write_text(minimal_top)
    print(f"  Wrote: {minimal_top_path}")

    # Copy testbench
    final_tb = output_dir / 'tb_top.sv'
    shutil.copy2(tb_src, final_tb)
    print(f"  Wrote: {final_tb}")

    # ── Verify minimal design still triggers bug ──
    print("\n[Step 7] Verifying minimal design still triggers bug...")
    shutil.copy2(minimal_top_path, work_dir / 'top.sv')
    has_diff, final_diffs = run_both_simulators(
        work_dir, extra_sv, verilator_bin, iverilog_bin, vvp_bin
    )
    if has_diff:
        print(f"  Minimal design confirmed: {len(final_diffs)} diff cycles")
    else:
        print(f"  [WARNING] Minimal design does NOT reproduce bug!")

    # ── Write report ──
    report = {
        'bug_id': bug_data['bug_id'],
        'seed': bug_data['seed'],
        'first_diff_cycle': bug_data['cycle'],
        'ground_truth': bug_data['ground_truth'],
        'differing_bits': bug_data['differing_bits'],
        'total_mtm_wires': len(all_mtm),
        'traced_mtm_wires': len(traced_mtm),
        'essential_count': len(essential_wires),
        'cut_count': len(permanently_cut),
        'essential_wires': essential_wires,
        'cut_wires': sorted(permanently_cut),
        'reduction_steps': reduction_steps,
        'minimal_design_reproduces_bug': bool(has_diff),
        'baseline_diff_cycles': len(baseline_diffs),
        'minimal_diff_cycles': len(final_diffs) if has_diff else 0,
        'files': {
            'top_minimal': str(minimal_top_path),
            'tb_top': str(final_tb),
        },
    }

    report_path = output_dir / 'reduction_report.json'
    with open(report_path, 'w') as f:
        json.dump(report, f, indent=2)
    print(f"  Wrote: {report_path}")

    # Clean up work directory
    if work_dir.exists():
        shutil.rmtree(work_dir, ignore_errors=True)

    return report


# ─────────────────────────────────────────────────────────────────────────────
# CLI
# ─────────────────────────────────────────────────────────────────────────────

def main():
    ap = argparse.ArgumentParser(
        description="Wire-level delta-debugging bug minimizer"
    )
    ap.add_argument(
        '--bug-dir', required=True,
        help='Path to bug directory (e.g. TestArchive/large_test1/bugs/tribug_...)',
    )
    ap.add_argument(
        '--modules', required=True,
        help='Path to module library (e.g. test_libraries/comprehensive_tests)',
    )
    ap.add_argument(
        '--output', default='isolated_bugs/minimized',
        help='Output directory for minimal design and report',
    )
    ap.add_argument(
        '--verilator', default='',
        help='Path to Verilator binary (auto-detected if not given)',
    )
    args = ap.parse_args()

    bug_dir = Path(args.bug_dir).resolve()
    module_dir = Path(args.modules).resolve()
    output_dir = Path(args.output).resolve()

    if not bug_dir.exists():
        print(f"[Error] Bug directory not found: {bug_dir}", file=sys.stderr)
        return 1
    if not module_dir.exists():
        print(f"[Error] Module directory not found: {module_dir}", file=sys.stderr)
        return 1

    # Resolve simulators
    try:
        verilator_bin = args.verilator if args.verilator else resolve_verilator()
        iverilog_bin, vvp_bin = resolve_icarus()
    except FileNotFoundError as e:
        print(f"[Error] {e}", file=sys.stderr)
        return 1

    print(f"Verilator: {verilator_bin}")
    print(f"Icarus:    {iverilog_bin}")
    print(f"VVP:       {vvp_bin}")

    report = run_reduction(
        bug_dir, module_dir, output_dir,
        verilator_bin, iverilog_bin, vvp_bin,
    )

    if 'error' in report:
        print(f"\n[Error] Reduction failed: {report['error']}")
        return 1

    print(f"\n{'='*70}")
    print(f"REDUCTION COMPLETE")
    print(f"{'='*70}")
    print(f"  Total MTM wires:    {report['total_mtm_wires']}")
    print(f"  In trace:           {report['traced_mtm_wires']}")
    print(f"  Essential (kept):   {report['essential_count']}")
    print(f"  Cut (removed):      {report['cut_count']}")
    print(f"  Bug still present:  {report['minimal_design_reproduces_bug']}")
    print(f"\n  Essential wires:")
    for w in report['essential_wires']:
        print(f"    {w['wire']}  (reason: {w['reason']}, in_trace: {w['in_trace']})")
    print(f"\n  Output: {output_dir}")
    return 0


if __name__ == '__main__':
    sys.exit(main())
