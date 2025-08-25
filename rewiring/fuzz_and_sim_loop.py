#!/usr/bin/env python3
"""
Fuzz → (Top + SV Testbench) → Verilator --binary loop (TB-only, no C++ main)

Per cycle:
  1) reset fuzzer to initial state with a fresh seed
  2) run random mutations (linear/cyclical) with periodic comprehensive checks
  3) generate top module (<top>.sv)    [kept with TB in the cycle dir]
  4) generate SystemVerilog testbench (tb_<top>.sv) via Fuzz_Run.generate_sv_testbench
  5) build & run with Verilator using --binary (no C++ main needed)
  6) write logs and summary.json

You can point --rtl-dir at a folder containing both your flattened and unflattened modules.
Generated <top>.sv and tb_<top>.sv are written into the per-cycle output folder.
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


# ------------------------- Output folder management -------------------------

def ensure_clean_output_folder(output_path: Path) -> Path:
    """
    Ensure the output folder is clean for a new run.
    If the folder exists and contains data, archive it with timestamp.
    
    Returns the clean output path (may be different from input if archived).
    """
    if not output_path.exists():
        # Folder doesn't exist, create it
        output_path.mkdir(parents=True, exist_ok=True)
        return output_path
    
    # Check if folder has content (not just empty)
    has_content = False
    try:
        # Look for any files or subdirectories
        for item in output_path.iterdir():
            if item.is_file() or item.is_dir():
                has_content = True
                break
    except (PermissionError, OSError):
        # If we can't read the directory, assume it has content
        has_content = True
    
    if not has_content:
        # Empty folder, safe to use
        return output_path
    
    # Folder has content - archive it
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    archive_name = f"{output_path.name}_archive_{timestamp}"
    archive_path = output_path.parent / archive_name
    
    try:
        # Try to rename the existing folder
        output_path.rename(archive_path)
        print(f"[Archive] Existing output folder archived to: {archive_path}")
    except (PermissionError, OSError) as e:
        # If rename fails, try to copy and then remove
        try:
            shutil.copytree(output_path, archive_path)
            shutil.rmtree(output_path)
            print(f"[Archive] Existing output folder copied to: {archive_path} and removed")
        except Exception as copy_error:
            # If all else fails, create a new folder with different name
            new_output_path = output_path.parent / f"{output_path.name}_new_{timestamp}"
            new_output_path.mkdir(parents=True, exist_ok=True)
            print(f"[Archive] Could not archive existing folder. Created new folder: {new_output_path}")
            print(f"[Archive] Original folder remains at: {output_path}")
            print(f"[Archive] Archive error: {e}, Copy error: {copy_error}")
            return new_output_path
    
    # Create fresh output folder
    output_path.mkdir(parents=True, exist_ok=True)
    return output_path


# ------------------------- Verilator path resolution -------------------------

def resolve_verilator(custom_path: str | None) -> str:
    """
    Resolve the verilator binary path according to the user's environment.
    Priority: --verilator > $VERILATOR > $VERILATOR_ROOT/bin/verilator > which verilator
    """
    candidates = []
    if custom_path:
        candidates.append(custom_path)

    env_verilator = os.environ.get("VERILATOR")
    if env_verilator:
        candidates.append(env_verilator)

    vroot = os.environ.get("VERILATOR_ROOT")
    if vroot:
        candidates.append(str(Path(vroot) / "bin" / "verilator"))

    which_path = shutil.which("verilator")
    if which_path:
        candidates.append(which_path)

    for c in candidates:
        if c and Path(c).exists() and os.access(c, os.X_OK):
            return c

    print("[Error] Could not find a working 'verilator' binary.\n"
          "Tried: --verilator, $VERILATOR, $VERILATOR_ROOT/bin/verilator, and PATH.",
          file=sys.stderr)
    sys.exit(2)


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


# ------------------------- Verilator Build & Run (TB-only, --binary) -------------------------

def run_verilator_binary(verilator_bin: str,
                         cycle_dir: Path,
                         top_name: str,
                         tb_name: str,
                         extra_sv: list[Path],
                         verilator_flags: list[str]) -> tuple[bool, bool, int, Path]:
    """
    Build & run using Verilator's single-binary flow:
      verilator --binary -sv [extra_sv...] <top>.sv tb_<top>.sv --top-module tb_<top> [flags...]

    Returns (build_ok: bool, run_ok: bool, rc: int, exe_path: Path)
    """
    top_sv = cycle_dir / f"{top_name}.sv"
    tb_sv = cycle_dir / f"{tb_name}.sv"
    obj_dir = cycle_dir / "obj_dir"
    exe = obj_dir / f"V{tb_name}"

    cmd = [verilator_bin, "--binary", "-sv", "--top-module", tb_name]
    
    # Add include directories for the RTL sources
    rtl_dirs = set()
    for sv_file in extra_sv:
        rtl_dirs.add(str(sv_file.parent))
    
    # Add include directories first
    for rtl_dir in sorted(rtl_dirs):
        cmd.extend(["+incdir+" + rtl_dir])
    
    # Add RTL sources and generated files
    cmd.extend([str(p) for p in extra_sv])
    cmd.extend([str(top_sv), str(tb_sv)])
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
            proc2 = subprocess.run([str(exe)], stdout=sout, stderr=serr, cwd=cycle_dir)
            sim_rc = proc2.returncode
        except Exception as e:
            (cycle_dir / "sim_exception.txt").write_text(str(e))
            return (True, False, 127, exe)

    return (True, sim_rc == 0, sim_rc, exe)


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
    ap = argparse.ArgumentParser(description="Fuzz → SV Testbench → Verilator --binary loop (TB-only, no C++).")
    ap.add_argument("flattened_lib", help="Path to flattened module library (JSON or other input expected by Fuzz_Run).")
    ap.add_argument("-o", "--outdir", default="runs_tb", help="Base output directory for generated top/tb & logs.")
    ap.add_argument("-t", "--top-name", default="top", help="Top module name to generate.")
    ap.add_argument("-m", "--mutations-per-cycle", type=int, default=40, help="Successful mutations per cycle before running Verilator.")
    ap.add_argument("-k", "--check-every", type=int, default=10, help="Run comprehensive check after this many successful mutations.")
    ap.add_argument("-c", "--max-cycles", type=int, default=0, help="Number of cycles to run (0 = until interrupted).")
    ap.add_argument("--seed", type=int, default=None, help="Base seed; each cycle derives a new seed if omitted.")
    ap.add_argument("--tb-cycles", type=int, default=200, help="Cycles the SV testbench should run before $finish.")
    ap.add_argument("--tb-clk-period", type=int, default=2, help="Clock period used by TB (time units).")
    ap.add_argument("--tb-hold-reset", type=int, default=2, help="Reset assertion length (cycles) inside TB (kept for API compat).")
    ap.add_argument("--verilator-flags", default="--trace", help="Extra flags to pass to Verilator (single string).")
    ap.add_argument("--verilator", default=None, help="Path to verilator binary (defaults to env/which resolution).")
    ap.add_argument("--rtl-dir", default=None, help="Directory containing your flattened + unflattened RTL (.sv/.v).")
    ap.add_argument("--rtl-recursive", action="store_true", help="When collecting from --rtl-dir, include files recursively.")
    ap.add_argument("-q", "--quiet", action="store_true", help="Reduce logging.")
    ap.add_argument("--incdir", action="append", default=[], help="Include directories for Verilator")
    
    args = ap.parse_args()
    
    # Resolve verilator binary path
    verilator_bin = args.verilator or shutil.which("verilator")
    if not verilator_bin:
        print("[Error] Verilator not found. Please install or specify --verilator path.")
        return 1
    
    print(f"[Loop] Verilator: {verilator_bin}")
    
    # Setup output directory
    base_out = Path(args.outdir)
    base_out = ensure_clean_output_folder(base_out)
    print(f"[Loop] Output: {base_out}  (Ctrl+C to stop)")
    
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
    max_consecutive_failures = 10  # Continue running even with many consecutive failures
    
    # Initialize random number generator
    rng = random.Random(args.seed)
    
    if not args.quiet:
        if cycles_target:
            print(f"[Loop] Will run {cycles_target} cycle(s).")
        print(f"[Loop] Mut/Cycle: {args.mutations_per_cycle} | Check every: {args.check_every} | TB cycles: {args.tb_cycles}")
        print(f"[Loop] Resilience: Will continue running even with up to {max_consecutive_failures} consecutive failures")
        if extra_sv:
            print(f"[Loop] RTL sources: {len(extra_sv)} file(s) from "
                  f"{args.rtl_dir if args.rtl_dir else args.flattened_lib}")

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
                    # Mutation process failed
                    cycle_success = False
                    cycle_error = f"Mutation process failed: {str(e)}"
                    cycle_error_type = "MutationError"
                    consecutive_failures += 1
                    
                    # Log error details
                    error_log = {
                        "cycle": cycle_idx,
                        "seed": seed,
                        "error": cycle_error,
                        "error_type": cycle_error_type,
                        "traceback": traceback.format_exc(),
                        "consecutive_failures": consecutive_failures,
                        "time": int(time.time()),
                        "cycle_duration": round(time.time() - cycle_start_time, 2)
                    }
                    
                    # Save error log
                    (cycle_dir / "error_log.json").write_text(json.dumps(error_log, indent=2))
                    
                    # Console error summary
                    if not args.quiet:
                        print(f"[Cycle {cycle_idx}] ERROR | {cycle_error_type}: {cycle_error}")
                        print(f"[Cycle {cycle_idx}] Consecutive failures: {consecutive_failures}")
                        print(f"[Cycle {cycle_idx}] Error logged to: {cycle_dir}/error_log.json")
                        
                        # Warn if too many consecutive failures
                        if consecutive_failures >= max_consecutive_failures:
                            print(f"[Cycle {cycle_idx}] WARNING: {consecutive_failures} consecutive failures - consider investigating")
                        
                        print("------------------------------------------------------------")
                    
                    # Update overall status
                    overall_ok = False
                    
                    # Log to main error summary
                    if not hasattr(main, 'error_summary'):
                        main.error_summary = []
                    
                    main.error_summary.append({
                        "cycle": cycle_idx,
                        "error_type": cycle_error_type,
                        "error": cycle_error,
                        "consecutive_failures": consecutive_failures,
                        "time": int(time.time())
                    })
                    
                    # Continue to next cycle
                    continue

                # Generate RTL (top) and TB
                try:
                    fr.generate_top_module(
                        output_path=str(cycle_dir) + "/",
                        top_name=args.top_name
                    )   

                    # Generate testbench
                    fr.generate_sv_testbench(
                        top_name=args.top_name,
                        output_path=str(cycle_dir) + "/",
                        sim_cycles=args.tb_cycles,
                        clk_period=args.tb_clk_period,
                        hold_reset_cycles=args.tb_hold_reset,
                        trace=True,
                        seed=seed if args.seed is not None else 0,
                        verbose=not args.quiet,
                    )
                    tb_name = f"tb_{args.top_name}"
                except Exception as e:
                    # RTL generation failed
                    cycle_success = False
                    cycle_error = f"RTL generation failed: {str(e)}"
                    cycle_error_type = "RTLGenerationError"
                    consecutive_failures += 1
                    
                    # Log error details
                    error_log = {
                        "cycle": cycle_idx,
                        "seed": seed,
                        "error": cycle_error,
                        "error_type": cycle_error_type,
                        "traceback": traceback.format_exc(),
                        "consecutive_failures": consecutive_failures,
                        "time": int(time.time()),
                        "cycle_duration": round(time.time() - cycle_start_time, 2)
                    }
                    
                    # Save error log
                    (cycle_dir / "error_log.json").write_text(json.dumps(error_log, indent=2))
                    
                    # Console error summary
                    if not args.quiet:
                        print(f"[Cycle {cycle_idx}] ERROR | {cycle_error_type}: {cycle_error}")
                        print(f"[Cycle {cycle_idx}] Consecutive failures: {consecutive_failures}")
                        print(f"[Cycle {cycle_idx}] Error logged to: {cycle_dir}/error_log.json")
                        
                        # Warn if too many consecutive failures
                        if consecutive_failures >= max_consecutive_failures:
                            print(f"[Cycle {cycle_idx}] WARNING: {consecutive_failures} consecutive failures - consider investigating")
                        
                        print("------------------------------------------------------------")
                    
                    # Update overall status
                    overall_ok = False
                    
                    # Log to main error summary
                    if not hasattr(main, 'error_summary'):
                        main.error_summary = []
                    
                    main.error_summary.append({
                        "cycle": cycle_idx,
                        "error_type": cycle_error_type,
                        "error": cycle_error,
                        "consecutive_failures": consecutive_failures,
                        "time": int(time.time())
                    })
                    
                    # Continue to next cycle
                    continue

                # Build include flags
                incflags = [f"+incdir+{Path(p).as_posix()}" for p in args.incdir]

                # Parse user flags and combine with include flags
                user_flags = shlex.split(args.verilator_flags) if args.verilator_flags else []
                verilator_flags = incflags + user_flags

                # Run Verilator build and simulation
                build_ok, run_ok, rc, exe = run_verilator_binary(
                    verilator_bin, cycle_dir, args.top_name, tb_name, extra_sv, verilator_flags
                )

                # Check if Verilator build/simulation failed
                if not build_ok or not run_ok:
                    # Verilator failure - treat as error but don't crash
                    cycle_success = False
                    cycle_error = f"Verilator {'build' if not build_ok else 'simulation'} failed with return code {rc}"
                    cycle_error_type = "VerilatorError"
                    consecutive_failures += 1
                    
                    # Log error details
                    error_log = {
                        "cycle": cycle_idx,
                        "seed": seed,
                        "error": cycle_error,
                        "error_type": cycle_error_type,
                        "build_ok": build_ok,
                        "run_ok": run_ok,
                        "verilator_rc": rc,
                        "consecutive_failures": consecutive_failures,
                        "time": int(time.time()),
                        "cycle_duration": round(time.time() - cycle_start_time, 2)
                    }
                    
                    # Save error log
                    (cycle_dir / "error_log.json").write_text(json.dumps(error_log, indent=2))
                    
                    # Console error summary
                    if not args.quiet:
                        print(f"[Cycle {cycle_idx}] ERROR | {cycle_error_type}: {cycle_error}")
                        print(f"[Cycle {cycle_idx}] Consecutive failures: {consecutive_failures}")
                        print(f"[Cycle {cycle_idx}] Error logged to: {cycle_dir}/error_log.json")
                        
                        # Warn if too many consecutive failures
                        if consecutive_failures >= max_consecutive_failures:
                            print(f"[Cycle {cycle_idx}] WARNING: {consecutive_failures} consecutive failures - consider investigating")
                        
                        print("------------------------------------------------------------")
                    
                    # Update overall status
                    overall_ok = False
                    
                    # Log to main error summary
                    if not hasattr(main, 'error_summary'):
                        main.error_summary = []
                    
                    main.error_summary.append({
                        "cycle": cycle_idx,
                        "error_type": cycle_error_type,
                        "error": cycle_error,
                        "consecutive_failures": consecutive_failures,
                        "time": int(time.time())
                    })
                    
                    # Continue to next cycle
                    continue

                # Cycle completed successfully
                cycle_success = True
                overall_ok = overall_ok and (build_ok and run_ok)
                consecutive_failures = 0  # Reset consecutive failure counter
                
                # Persist stats
                summary = {
                    "cycle": cycle_idx,
                    "seed": seed,
                    "mutations_requested": args.mutations_per_cycle,
                    "mutations_done": int(total_done),
                    "linear_successes": int(counts["linear"]),
                    "cyclical_successes": int(counts["cyclical"]),
                    "build_ok": bool(build_ok),
                    "run_ok": bool(run_ok),
                    "verilator_rc": int(rc),
                    "binary": str(exe.as_posix()),
                    "top_sv": str((cycle_dir / f"{args.top_name}.sv").as_posix()),
                    "testbench_sv": str((cycle_dir / f"{tb_name}.sv").as_posix()),
                    "time": int(time.time()),
                    "verilator": verilator_bin,
                    "extra_sv": [p.as_posix() for p in extra_sv],
                    "cycle_success": True,
                    "error": None,
                    "error_type": None,
                    "cycle_duration": round(time.time() - cycle_start_time, 2)
                }
                (cycle_dir / "summary.json").write_text(json.dumps(summary, indent=2))

                # Console summary
                if not args.quiet:
                    status = "OK" if (build_ok and run_ok) else ("BUILD_FAIL" if not build_ok else "SIM_FAIL")
                    print(f"[Cycle {cycle_idx}] {status} | mu={total_done} (lin={counts['linear']}, cyc={counts['cyclical']}) | rc={rc}")
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
                
                # Save error log
                (cycle_dir / "error_log.json").write_text(json.dumps(error_log, indent=2))
                
                # Console error summary
                if not args.quiet:
                    print(f"[Cycle {cycle_idx}] ERROR | {cycle_error_type}: {cycle_error}")
                    print(f"[Cycle {cycle_idx}] Consecutive failures: {consecutive_failures}")
                    print(f"[Cycle {cycle_idx}] Error logged to: {cycle_dir}/error_log.json")
                    
                    # Warn if too many consecutive failures
                    if consecutive_failures >= max_consecutive_failures:
                        print(f"[Cycle {cycle_idx}] WARNING: {consecutive_failures} consecutive failures - consider investigating")
                    
                    print("------------------------------------------------------------")
                
                # Update overall status
                overall_ok = False
                
                # Log to main error summary
                if not hasattr(main, 'error_summary'):
                    main.error_summary = []
                
                main.error_summary.append({
                    "cycle": cycle_idx,
                    "error_type": cycle_error_type,
                    "error": cycle_error,
                    "consecutive_failures": consecutive_failures,
                    "time": int(time.time())
                })
                
            finally:
                # Always cleanup and unpatch if counters were wrapped
                if 'unpatch' in locals():
                    unpatch()
                
                # Save cycle summary regardless of success/failure
                if not cycle_success:
                    summary = {
                        "cycle": cycle_idx,
                        "seed": seed if 'seed' in locals() else None,
                        "mutations_requested": args.mutations_per_cycle,
                        "mutations_done": 0,
                        "linear_successes": 0,
                        "cyclical_successes": 0,
                        "build_ok": False,
                        "run_ok": False,
                        "verilator_rc": -1,
                        "binary": None,
                        "top_sv": None,
                        "testbench_sv": None,
                        "time": int(time.time()),
                        "verilator": verilator_bin,
                        "extra_sv": [p.as_posix() for p in extra_sv],
                        "cycle_success": False,
                        "error": cycle_error,
                        "error_type": cycle_error_type,
                        "cycle_duration": round(time.time() - cycle_start_time, 2)
                    }
                    (cycle_dir / "summary.json").write_text(json.dumps(summary, indent=2))
                
                cycle_idx += 1

    except KeyboardInterrupt:
        if not args.quiet:
            print("\n[Loop] Interrupted by user.")
    
    # Final error summary
    if hasattr(main, 'error_summary') and main.error_summary:
        error_summary_path = base_out / "error_summary.json"
        error_summary = {
            "total_cycles": cycle_idx,
            "successful_cycles": cycle_idx - len(main.error_summary),
            "failed_cycles": len(main.error_summary),
            "success_rate": round((cycle_idx - len(main.error_summary) / cycle_idx) * 100, 2) if cycle_idx > 0 else 0,
            "errors": main.error_summary,
            "final_time": int(time.time())
        }
        error_summary_path.write_text(json.dumps(error_summary, indent=2))
        
        if not args.quiet:
            print(f"\n[Summary] Total cycles: {cycle_idx}")
            print(f"[Summary] Successful: {error_summary['successful_cycles']}")
            print(f"[Summary] Failed: {error_summary['failed_cycles']}")
            print(f"[Summary] Success rate: {error_summary['success_rate']}%")
            print(f"[Summary] Error details saved to: {error_summary_path}")
    
    return 0 if overall_ok else 2


if __name__ == "__main__":
    sys.exit(main())
