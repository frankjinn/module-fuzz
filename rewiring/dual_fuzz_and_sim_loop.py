#!/usr/bin/env python3
"""
Dual Simulator Fuzz → (Top + SV Testbench) → Verilator + Icarus Verilog loop

This extends the original fuzzing loop to run both Verilator and Icarus Verilog
simultaneously and compare their results to find bugs in either simulator.

Per cycle:
  1) reset fuzzer to initial state with a fresh seed
  2) run random mutations (linear/cyclical) with periodic comprehensive checks
  3) generate top module (<top>.sv)    [kept with TB in the cycle dir]
  4) generate SystemVerilog testbench (tb_<top>.sv) with hex logging
  5) build & run with both Verilator and Icarus Verilog
  6) compare simulation logs and detect differences
  7) save bug reports when differences are found
  8) write logs and summary.json
"""

import argparse
import json
import os
import random
import shlex
import shutil
import subprocess
import sys
import time
from pathlib import Path
import types
import traceback
from datetime import datetime

import fuzz_state
import dual_simulator


# ------------------------- Output folder management -------------------------

def ensure_clean_output_folder(output_path: Path) -> Path:
    """
    Ensure the output folder is clean for a new run.
    If the folder exists and contains data, archive it with timestamp.
    
    Returns the clean output path (may be different from input if archived).
    """
    if not output_path.exists():
        output_path.mkdir(parents=True, exist_ok=True)
        return output_path
    
    has_content = False
    try:
        for item in output_path.iterdir():
            if item.is_file() or item.is_dir():
                has_content = True
                break
    except (PermissionError, OSError):
        has_content = True
    
    if not has_content:
        return output_path
    
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    archive_name = f"{output_path.name}_archive_{timestamp}"
    archive_path = output_path.parent / archive_name
    
    try:
        output_path.rename(archive_path)
        print(f"[Archive] Existing output folder archived to: {archive_path}")
    except (PermissionError, OSError) as e:
        try:
            shutil.copytree(output_path, archive_path)
            shutil.rmtree(output_path)
            print(f"[Archive] Existing output folder copied to: {archive_path} and removed")
        except Exception as copy_error:
            new_output_path = output_path.parent / f"{output_path.name}_new_{timestamp}"
            new_output_path.mkdir(parents=True, exist_ok=True)
            print(f"[Archive] Could not archive existing folder. Created new folder: {new_output_path}")
            print(f"[Archive] Original folder remains at: {output_path}")
            print(f"[Archive] Archive error: {e}, Copy error: {copy_error}")
            return new_output_path
    
    output_path.mkdir(parents=True, exist_ok=True)
    return output_path


# ------------------------- Simulator path resolution -------------------------

def resolve_simulators(verilator_path: str | None, icarus_path: str | None) -> tuple[str, str, str]:
    """
    Resolve simulator binary paths.
    Returns (verilator_bin, iverilog_bin, vvp_bin)
    """
    # Resolve Verilator
    verilator_candidates = []
    if verilator_path:
        verilator_candidates.append(verilator_path)
    
    env_verilator = os.environ.get("VERILATOR")
    if env_verilator:
        verilator_candidates.append(env_verilator)
    
    vroot = os.environ.get("VERILATOR_ROOT")
    if vroot:
        verilator_candidates.append(str(Path(vroot) / "bin" / "verilator"))
    
    which_verilator = shutil.which("verilator")
    if which_verilator:
        verilator_candidates.append(which_verilator)
    
    verilator_bin = None
    for c in verilator_candidates:
        if c and Path(c).exists() and os.access(c, os.X_OK):
            verilator_bin = c
            break
    
    if not verilator_bin:
        print("[Error] Could not find a working 'verilator' binary.", file=sys.stderr)
        sys.exit(2)
    
    # Resolve Icarus Verilog
    icarus_candidates = []
    if icarus_path:
        icarus_candidates.append(icarus_path)
    
    env_icarus = os.environ.get("IVERILOG")
    if env_icarus:
        icarus_candidates.append(env_icarus)
    
    which_icarus = shutil.which("iverilog")
    if which_icarus:
        icarus_candidates.append(which_icarus)
    
    iverilog_bin = None
    for c in icarus_candidates:
        if c and Path(c).exists() and os.access(c, os.X_OK):
            iverilog_bin = c
            break
    
    if not iverilog_bin:
        print("[Error] Could not find a working 'iverilog' binary.", file=sys.stderr)
        sys.exit(2)
    
    # Find vvp
    vvp_bin = shutil.which("vvp")
    if not vvp_bin:
        # Try same directory as iverilog
        vvp_candidate = Path(iverilog_bin).parent / "vvp"
        if vvp_candidate.exists() and os.access(vvp_candidate, os.X_OK):
            vvp_bin = str(vvp_candidate)
    
    if not vvp_bin:
        print("[Error] Could not find a working 'vvp' binary.", file=sys.stderr)
        sys.exit(2)
    
    return verilator_bin, iverilog_bin, vvp_bin


# ------------------------- Collect RTL from file/dir -------------------------

def collect_rtl_sources(src: Path, recursive: bool = False) -> list[Path]:
    """
    Return a list of .sv/.v files from 'src'.
    If 'src' is a directory, collect files (non-recursive by default).
    """
    if src.is_file():
        return [src] if src.suffix.lower() in (".sv", ".v") else []

    if not src.is_dir():
        return []

    if recursive:
        files = [p for p in src.rglob("*") if p.is_file() and p.suffix.lower() in (".sv", ".v")]
    else:
        files = [p for p in src.iterdir() if p.is_file() and p.suffix.lower() in (".sv", ".v")]

    return sorted(files)


# ------------------------- Mutation Counting Wrapper -------------------------

def wrap_mutation_counters(fr):
    """
    Monkey-patch linear_rewire and cyclical_rewire to count successes.
    Returns (counts_dict, unpatch_function).
    """
    counts = {"linear": 0, "cyclical": 0}
    orig_linear = fr.linear_rewire
    orig_cyc = fr.cyclical_rewire

    def wrapped_linear():
        rc = orig_linear()
        if rc == 0:
            counts["linear"] += 1
        return rc

    def wrapped_cyc():
        rc = orig_cyc()
        if rc == 0:
            counts["cyclical"] += 1
        return rc

    fr.linear_rewire = types.MethodType(lambda self=fr: wrapped_linear(), fr)
    fr.cyclical_rewire = types.MethodType(lambda self=fr: wrapped_cyc(), fr)

    def unpatch():
        fr.linear_rewire = orig_linear
        fr.cyclical_rewire = orig_cyc

    return counts, unpatch


# ------------------------- Main Loop -------------------------

def main():
    ap = argparse.ArgumentParser(description="Dual simulator fuzzing: Verilator + Icarus Verilog comparison.")
    ap.add_argument("flattened_lib", help="Path to flattened module library (JSON or directory).")
    ap.add_argument("-o", "--outdir", default="runs_dual", help="Base output directory for generated top/tb & logs.")
    ap.add_argument("-t", "--top-name", default="top", help="Top module name to generate.")
    ap.add_argument("-m", "--mutations-per-cycle", type=int, default=40, help="Successful mutations per cycle before running simulators.")
    ap.add_argument("-k", "--check-every", type=int, default=10, help="Run comprehensive check after this many successful mutations.")
    ap.add_argument("-c", "--max-cycles", type=int, default=0, help="Number of cycles to run (0 = until interrupted).")
    ap.add_argument("--seed", type=int, default=None, help="Base seed; each cycle derives a new seed if omitted.")
    ap.add_argument("--tb-cycles", type=int, default=200, help="Cycles the SV testbench should run before $finish.")
    ap.add_argument("--tb-clk-period", type=int, default=2, help="Clock period used by TB (time units).")
    ap.add_argument("--tb-hold-reset", type=int, default=2, help="Reset assertion length (cycles) inside TB (kept for API compat).")
    ap.add_argument("--verilator-flags", default="--trace", help="Extra flags to pass to Verilator (single string).")
    ap.add_argument("--icarus-flags", default="", help="Extra flags to pass to Icarus Verilog (single string).")
    ap.add_argument("--verilator", default=None, help="Path to verilator binary (defaults to env/which resolution).")
    ap.add_argument("--icarus", default=None, help="Path to iverilog binary (defaults to env/which resolution).")
    ap.add_argument("--rtl-dir", default=None, help="Directory containing your flattened + unflattened RTL (.sv/.v).")
    ap.add_argument("--rtl-recursive", action="store_true", help="When collecting from --rtl-dir, include files recursively.")
    ap.add_argument("-q", "--quiet", action="store_true", help="Reduce logging.")
    ap.add_argument("--incdir", action="append", default=[], help="Include directories for simulators")
    ap.add_argument("--skip-seed-check", action="store_true", help="Skip seed consistency verification")
    ap.add_argument("--max-cycle-dirs", type=int, default=50, help="Maximum number of cycle directories to keep (older ones will be deleted)")
    ap.add_argument("--cleanup-every", type=int, default=20, help="Run cycle cleanup every N cycles")
    ap.add_argument("--preserve-recent", type=int, default=10, help="Always preserve this many most recent cycle directories")
    
    args = ap.parse_args()
    
    # Resolve simulator binary paths
    verilator_bin, iverilog_bin, vvp_bin = resolve_simulators(args.verilator, args.icarus)
    
    print(f"[DualLoop] Verilator: {verilator_bin}")
    print(f"[DualLoop] Icarus Verilog: {iverilog_bin}")
    print(f"[DualLoop] VVP: {vvp_bin}")
    
    # Setup output directory
    base_out = Path(args.outdir)
    base_out = ensure_clean_output_folder(base_out)
    print(f"[DualLoop] Output: {base_out}  (Ctrl+C to stop)")
    
    # Create bugs directory
    bugs_dir = base_out / "bugs"
    bugs_dir.mkdir(exist_ok=True)
    
    # Initialize fuzzer
    try:
        fr = fuzz_state.Fuzz_Run(args.flattened_lib)
    except Exception as e:
        print(f"[Error] Failed to initialize Fuzz_Run: {e}", file=sys.stderr)
        return 2
    
    # Collect RTL sources
    extra_sv = []
    if args.rtl_dir:
        rtl_dir = Path(args.rtl_dir)
        if args.rtl_recursive:
            extra_sv = list(rtl_dir.rglob("*.sv")) + list(rtl_dir.rglob("*.v"))
        else:
            extra_sv = list(rtl_dir.glob("*.sv")) + list(rtl_dir.glob("*.v"))
    
    # Add include directories
    if args.incdir:
        for incdir in args.incdir:
            incdir_path = Path(incdir)
            if incdir_path.exists():
                extra_sv.extend(incdir_path.glob("*.sv"))
                extra_sv.extend(incdir_path.glob("*.v"))
    
    # Remove duplicates and sort
    extra_sv = sorted(set(extra_sv))
    
    # Setup cycle loop
    cycle_idx = 0
    cycles_target = args.max_cycles if args.max_cycles > 0 else None
    overall_ok = True
    consecutive_failures = 0
    max_consecutive_failures = 10
    bugs_found = 0
    
    # Initialize random number generator
    rng = random.Random(args.seed)
    
    # Bug tracking
    bug_summary = []
    
    if not args.quiet:
        if cycles_target:
            print(f"[DualLoop] Will run {cycles_target} cycle(s).")
        print(f"[DualLoop] Mut/Cycle: {args.mutations_per_cycle} | Check every: {args.check_every} | TB cycles: {args.tb_cycles}")
        print(f"[DualLoop] Resilience: Will continue running even with up to {max_consecutive_failures} consecutive failures")
        if extra_sv:
            print(f"[DualLoop] RTL sources: {len(extra_sv)} file(s)")

    try:
        while True:
            if cycles_target is not None and cycle_idx >= cycles_target:
                break

            cycle_dir = base_out / f"cycle_{cycle_idx:04d}"
            if cycle_dir.exists():
                shutil.rmtree(cycle_dir)
            cycle_dir.mkdir(parents=True, exist_ok=True)

            cycle_start_time = time.time()
            cycle_success = False
            cycle_error = None
            cycle_error_type = None
            bug_found = False
            bug_report_path = None

            try:
                # Fresh seed + reset to initial state
                seed = rng.randrange(0, 2**32)
                fr.reset_state(seed=seed, verbose=not args.quiet)

                # Wrap counters
                counts, unpatch = wrap_mutation_counters(fr)

                # Mutate
                try:
                    total_done = fr.run_random_mutations(
                        max_mutations=args.mutations_per_cycle,
                        check_every=args.check_every,
                        seed=seed,
                        verbose=not args.quiet,
                    )
                except Exception as e:
                    cycle_success = False
                    cycle_error = f"Mutation process failed: {str(e)}"
                    cycle_error_type = "MutationError"
                    consecutive_failures += 1
                    continue

                # Generate RTL (top) and TB
                try:
                    fr.generate_top_module(
                        output_path=str(cycle_dir) + "/",
                        top_name=args.top_name
                    )   

                    # Generate testbench with hex logging
                    fr.generate_sv_testbench(
                        top_name=args.top_name,
                        output_path=str(cycle_dir) + "/",
                        sim_cycles=args.tb_cycles,
                        clk_period=args.tb_clk_period,
                        hold_reset_cycles=args.tb_hold_reset,
                        trace=True,
                        seed=seed,
                        verbose=not args.quiet,
                    )
                    tb_name = f"tb_{args.top_name}"
                except Exception as e:
                    cycle_success = False
                    cycle_error = f"RTL generation failed: {str(e)}"
                    cycle_error_type = "RTLGenerationError"
                    consecutive_failures += 1
                    continue

                # Build include flags - need to point to the base directory so relative paths work
                # The generated top.sv references modules like "test_library_structured/flattened/const_arith_wrapper.sv"
                # So we need the include directory to be the parent of "test_library_structured"
                base_incdir = str(Path.cwd().absolute())  # /opt/module-fuzz/rewiring
                incflags = [f"+incdir+{base_incdir}"]
                
                # Also add user-specified include directories
                for incdir in args.incdir:
                    incflags.append(f"+incdir+{Path(incdir).absolute().as_posix()}")

                # Parse user flags and combine with include flags
                verilator_user_flags = shlex.split(args.verilator_flags) if args.verilator_flags else []
                verilator_flags = incflags + verilator_user_flags
                
                # For Icarus, convert +incdir to -I format and add SystemVerilog support
                icarus_incflags = ["-g2012", f"-I{base_incdir}"]  # -g2012 enables SystemVerilog
                for incdir in args.incdir:
                    icarus_incflags.append(f"-I{Path(incdir).absolute().as_posix()}")
                
                icarus_user_flags = shlex.split(args.icarus_flags) if args.icarus_flags else []
                icarus_flags = icarus_incflags + icarus_user_flags

                # Run dual simulation
                try:
                    bug_found, bug_report_path = dual_simulator.run_dual_simulation(
                        verilator_bin, iverilog_bin, vvp_bin,
                        cycle_dir, args.top_name, tb_name, extra_sv,
                        verilator_flags, icarus_flags, seed
                    )
                    
                    # Check if dual simulation actually succeeded
                    if bug_found is None:  # This indicates simulation failure
                        cycle_success = False
                        cycle_error = "Dual simulation failed - one or both simulators failed"
                        cycle_error_type = "DualSimulationFailure"
                        consecutive_failures += 1
                        continue
                    
                    if bug_found:
                        bugs_found += 1
                        bug_summary.append({
                            "cycle": cycle_idx,
                            "seed": seed,
                            "bug_report": str(bug_report_path),
                            "timestamp": int(time.time())
                        })
                        print(f"[DualLoop] 🐛 BUG #{bugs_found} FOUND in cycle {cycle_idx}! Report: {bug_report_path}")
                    
                    # Check seed consistency if not skipped
                    if not args.skip_seed_check:
                        seeds_consistent, consistency_report = dual_simulator.check_seed_consistency(cycle_dir, seed)
                        if not seeds_consistent:
                            print(f"[DualLoop] ⚠️  Seed consistency warning in cycle {cycle_idx}")
                    
                    cycle_success = True
                    consecutive_failures = 0
                    
                except Exception as e:
                    cycle_success = False
                    cycle_error = f"Dual simulation failed: {str(e)}"
                    cycle_error_type = "DualSimulationError"
                    consecutive_failures += 1
                    continue

                # Persist stats
                summary = {
                    "cycle": cycle_idx,
                    "seed": seed,
                    "mutations_requested": args.mutations_per_cycle,
                    "mutations_done": int(total_done),
                    "linear_successes": int(counts["linear"]),
                    "cyclical_successes": int(counts["cyclical"]),
                    "dual_simulation_ok": True,
                    "bug_found": bug_found,
                    "bug_report_path": str(bug_report_path) if bug_report_path else None,
                    "top_sv": str((cycle_dir / f"{args.top_name}.sv").as_posix()),
                    "testbench_sv": str((cycle_dir / f"{tb_name}.sv").as_posix()),
                    "time": int(time.time()),
                    "verilator": verilator_bin,
                    "icarus": iverilog_bin,
                    "extra_sv": [p.as_posix() for p in extra_sv],
                    "cycle_success": True,
                    "error": None,
                    "error_type": None,
                    "cycle_duration": round(time.time() - cycle_start_time, 2),
                    "total_bugs_found": bugs_found
                }
                (cycle_dir / "summary.json").write_text(json.dumps(summary, indent=2))

                # Console summary
                if not args.quiet:
                    bug_status = f"🐛 BUG!" if bug_found else "✓ Match"
                    print(f"[Cycle {cycle_idx}] {bug_status} | mu={total_done} (lin={counts['linear']}, cyc={counts['cyclical']}) | bugs_total={bugs_found}")
                    print("------------------------------------------------------------")

            except Exception as e:
                # Cycle failed - log error and continue
                cycle_success = False
                cycle_error = str(e)
                cycle_error_type = type(e).__name__
                consecutive_failures += 1
                
                # Log error details
                error_log = {
                    "cycle": cycle_idx,
                    "seed": seed if 'seed' in locals() else None,
                    "error": cycle_error,
                    "error_type": cycle_error_type,
                    "traceback": traceback.format_exc(),
                    "consecutive_failures": consecutive_failures,
                    "time": int(time.time()),
                    "cycle_duration": round(time.time() - cycle_start_time, 2)
                }
                
                (cycle_dir / "error_log.json").write_text(json.dumps(error_log, indent=2))
                
                if not args.quiet:
                    print(f"[Cycle {cycle_idx}] ERROR | {cycle_error_type}: {cycle_error}")
                    print(f"[Cycle {cycle_idx}] Consecutive failures: {consecutive_failures}")
                    print("------------------------------------------------------------")
                
                overall_ok = False
                
            finally:
                # Always cleanup and unpatch if counters were wrapped
                if 'unpatch' in locals():
                    unpatch()
                
                cycle_idx += 1
                
                # Periodic cleanup of old cycle directories
                if args.cleanup_every > 0 and cycle_idx % args.cleanup_every == 0:
                    deleted_count = dual_simulator.cleanup_old_cycles(
                        base_out, 
                        max_cycles=args.max_cycle_dirs,
                        preserve_recent=args.preserve_recent
                    )
                    if not args.quiet and deleted_count > 0:
                        print(f"[Cleanup] Removed {deleted_count} old cycle directories to save disk space")

    except KeyboardInterrupt:
        if not args.quiet:
            print("\n[DualLoop] Interrupted by user.")
    
    # Final summary
    if not args.quiet:
        print(f"\n[Summary] Total cycles: {cycle_idx}")
        print(f"[Summary] Bugs found: {bugs_found}")
        if bugs_found > 0:
            print(f"[Summary] Bug rate: {bugs_found/cycle_idx*100:.2f}%")
            print(f"[Summary] Bug reports saved in: {bugs_dir}")
    
    # Save bug summary
    if bug_summary:
        bug_summary_file = base_out / "bug_summary.json"
        with bug_summary_file.open("w") as f:
            json.dump({
                "total_cycles": cycle_idx,
                "total_bugs": bugs_found,
                "bug_rate_percent": bugs_found/cycle_idx*100 if cycle_idx > 0 else 0,
                "bugs": bug_summary,
                "timestamp": int(time.time())
            }, f, indent=2)
        print(f"[Summary] Bug summary saved to: {bug_summary_file}")
    
    return 0 if overall_ok else 2


if __name__ == "__main__":
    sys.exit(main())
