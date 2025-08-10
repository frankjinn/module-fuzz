#!/usr/bin/env python3
"""
Fuzz → (Top + SV Testbench) → Verilator --binary loop (TB-only, no C++ main)

Per cycle:
  1) reset fuzzer to initial state with a fresh seed
  2) run random mutations (linear/cyclical) with periodic comprehensive checks
  3) generate top module (top.sv)
  4) generate SystemVerilog testbench (tb_top.sv) using Fuzz_Run.generate_sv_testbench
  5) build & run with Verilator using --binary (no C++ main needed)
  6) write logs and summary.json

Assumptions:
 - Verilator is on PATH
 - fuzz_state.Fuzz_Run provides:
      - reset_state(seed=None, verbose=True)
      - run_random_mutations(max_mutations, check_every, seed=None, verbose=True)
      - generate_top_module(top_name, output_path)
      - generate_sv_testbench(top_name, output_path, tb_name=..., sim_cycles=..., clk_period=..., hold_reset_cycles=..., trace=..., seed=..., ...)
      - linear_rewire(), cyclical_rewire() return 0 on success, 1 on no-op
"""

import argparse
import json
import random
import shlex
import shutil
import subprocess
import sys
import time
from pathlib import Path
import types

import fuzz_state


# ------------------------- Mutation Counting Wrapper -------------------------

def wrap_mutation_counters(fr):
    """
    Monkey-patch linear_rewire and cyclical_rewire to count successes.
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


# ------------------------- Verilator Build & Run (TB-only, --binary) -------------------------

def run_verilator_binary(cycle_dir: Path,
                         top_name: str,
                         tb_name: str,
                         extra_sv: list[Path],
                         verilator_flags: list[str]):
    """
    Build & run using Verilator's single-binary flow:
      verilator --binary -sv [extra_sv...] top.sv tb_top.sv --top-module tb_top [flags...]

    Returns (build_ok: bool, run_ok: bool, rc: int, exe_path: Path)
    """
    top_sv = cycle_dir / f"{top_name}.sv"
    tb_sv = cycle_dir / f"{tb_name}.sv"
    obj_dir = cycle_dir / "obj_dir"

    cmd = [
        "verilator",
        "--binary",          # single-binary: generates+compiles+links+provides main
        "-sv",
        "--top-module", tb_name,
    ] + [str(p) for p in extra_sv] + [
        str(top_sv),
        str(tb_sv),
    ] + verilator_flags

    build_log = cycle_dir / "build.log"
    build_err = cycle_dir / "build.err"
    with build_log.open("w") as bout, build_err.open("w") as berr:
        try:
            p = subprocess.run(cmd, stdout=bout, stderr=berr, cwd=cycle_dir)
            build_rc = p.returncode
        except Exception as e:
            (cycle_dir / "build_exception.txt").write_text(str(e))
            return (False, False, 127, obj_dir / f"V{tb_name}")

    if build_rc != 0:
        return (False, False, build_rc, obj_dir / f"V{tb_name}")

    exe = obj_dir / f"V{tb_name}"
    sim_log = cycle_dir / "sim.log"
    sim_err = cycle_dir / "sim.err"
    with sim_log.open("w") as sout, sim_err.open("w") as serr:
        try:
            p2 = subprocess.run([str(exe)], stdout=sout, stderr=serr, cwd=cycle_dir)
            sim_rc = p2.returncode
        except Exception as e:
            (cycle_dir / "sim_exception.txt").write_text(str(e))
            return (True, False, 127, exe)

    return (True, sim_rc == 0, sim_rc, exe)


# ------------------------- Main Loop -------------------------

def main():
    ap = argparse.ArgumentParser(description="Fuzz → SV Testbench → Verilator --binary loop (TB-only, no C++).")
    ap.add_argument("flattened_lib", help="Path to flattened module library (input to Fuzz_Run).")
    ap.add_argument("-o", "--outdir", default="runs", help="Base output directory.")
    ap.add_argument("-t", "--top-name", default="top", help="Top module name to generate.")
    ap.add_argument("-m", "--mutations-per-cycle", type=int, default=50, help="Successful mutations per cycle before running Verilator.")
    ap.add_argument("-k", "--check-every", type=int, default=10, help="Run comprehensive check after this many successful mutations.")
    ap.add_argument("-c", "--max-cycles", type=int, default=0, help="Number of cycles to run (0 = until interrupted).")
    ap.add_argument("--seed", type=int, default=None, help="Base seed; each cycle derives a new seed if omitted.")
    ap.add_argument("--tb-cycles", type=int, default=200, help="Cycles the SV testbench should run before $finish.")
    ap.add_argument("--tb-clk-period", type=int, default=2, help="Clock period used by TB (time units).")
    ap.add_argument("--tb-hold-reset", type=int, default=2, help="Reset assertion length (cycles) inside TB.")
    ap.add_argument("--verilator-flags", default="--trace", help="Extra flags to pass to Verilator (quoted string).")
    ap.add_argument("-q", "--quiet", action="store_true", help="Reduce logging.")
    args = ap.parse_args()

    base_out = Path(args.outdir)
    base_out.mkdir(parents=True, exist_ok=True)

    # Initialize fuzzer; we'll call reset_state() each cycle
    try:
        fr = fuzz_state.Fuzz_Run(args.flattened_lib)
    except Exception as e:
        print(f"[Error] Failed to initialize Fuzz_Run: {e}", file=sys.stderr)
        return 2

    cycles_target = None if args.max_cycles == 0 else args.max_cycles
    cycle_idx = 0
    overall_ok = True
    rng = random.Random(args.seed)

    if not args.quiet:
        print(f"[Loop] Output: {base_out.resolve()}  (Ctrl+C to stop)")
        if cycles_target:
            print(f"[Loop] Will run {cycles_target} cycle(s).")
        print(f"[Loop] Mut/Cycle: {args.mutations_per_cycle} | Check every: {args.check_every} | TB cycles: {args.tb_cycles}")

    try:
        while True:
            if cycles_target is not None and cycle_idx >= cycles_target:
                break

            cycle_dir = base_out / f"cycle_{cycle_idx:04d}"
            if cycle_dir.exists():
                shutil.rmtree(cycle_dir)
            cycle_dir.mkdir(parents=True, exist_ok=True)

            # Fresh seed + reset to initial state
            seed = rng.randrange(0, 2**32)
            fr.reset_state(seed=seed, verbose=not args.quiet)

            # Wrap counters
            counts, unpatch = wrap_mutation_counters(fr)

            # Mutate
            total_done = fr.run_random_mutations(
                max_mutations=args.mutations_per_cycle,
                check_every=args.check_every,
                seed=seed,
                verbose=not args.quiet,
            )

            # Generate RTL (top) and TB
            fr.generate_top_module(top_name=args.top_name, output_path=str(cycle_dir.as_posix() + "/"))
            tb_name = f"tb_{args.top_name}"
            fr.generate_sv_testbench(
                top_name=args.top_name,
                output_path=str(cycle_dir),
                tb_name=tb_name,
                sim_cycles=args.tb_cycles,
                clk_period=args.tb_clk_period,
                hold_reset_cycles=args.tb_hold_reset,
                trace=True,
                seed=seed,
                verbose=not args.quiet,
            )

            # Build & run with Verilator (--binary, no C++)
            extra_sv = [Path(args.flattened_lib)] if Path(args.flattened_lib).exists() else []
            verilator_flags = shlex.split(args.verilator_flags) if args.verilator_flags else []
            build_ok, run_ok, rc, exe = run_verilator_binary(
                cycle_dir, args.top_name, tb_name, extra_sv, verilator_flags
            )

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
            }
            (cycle_dir / "summary.json").write_text(json.dumps(summary, indent=2))

            # Unpatch
            unpatch()

            # Console summary
            if not args.quiet:
                status = "OK" if (build_ok and run_ok) else ("BUILD_FAIL" if not build_ok else "SIM_FAIL")
                print(f"[Cycle {cycle_idx}] {status} | mu={total_done} (lin={counts['linear']}, cyc={counts['cyclical']}) | rc={rc}")

            cycle_idx += 1

    except KeyboardInterrupt:
        if not args.quiet:
            print("\n[Loop] Interrupted by user.")

    return 0 if overall_ok else 2


if __name__ == "__main__":
    sys.exit(main())
