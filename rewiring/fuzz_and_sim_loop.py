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

import fuzz_state


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
    # user-supplied RTL first (from --rtl-dir or flattened_lib dir/file)
    cmd += [str(p) for p in extra_sv]
    # generated top + tb next
    cmd += [str(top_sv), str(tb_sv)]
    # user flags last
    cmd += verilator_flags

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
    ap.add_argument("--incdir", action="append", default=[], help="Add Verilog include directory for `include (repeatable).")
    args = ap.parse_args()

    # Resolve verilator binary
    verilator_bin = resolve_verilator(args.verilator)

    base_out = Path(args.outdir)
    base_out.mkdir(parents=True, exist_ok=True)

    # Initialize fuzzer once; we will call reset_state() each cycle
    try:
        fr = fuzz_state.Fuzz_Run(args.flattened_lib)
    except Exception as e:
        print(f"[Error] Failed to initialize Fuzz_Run: {e}", file=sys.stderr)
        return 2

    # Ensure Fuzz_Run can reset using the original path
    if not hasattr(fr, "flattened_lib_path"):
        fr.flattened_lib_path = args.flattened_lib

    cycles_target = None if args.max_cycles == 0 else args.max_cycles
    cycle_idx = 0
    overall_ok = True
    rng = random.Random(args.seed)

    # Pre-collect RTL sources (user-provided)
    extra_sv: list[Path] = []
    if args.rtl_dir:
        rtl_dir = Path(args.rtl_dir)
        extra_sv = collect_rtl_sources(rtl_dir, recursive=args.rtl_recursive)
    else:
        # Fallback: if flattened_lib itself is a directory of .sv/.v, use that
        maybe_dir = Path(args.flattened_lib)
        if maybe_dir.is_dir():
            extra_sv = collect_rtl_sources(maybe_dir, recursive=args.rtl_recursive)

    if not args.quiet:
        print(f"[Loop] Verilator: {verilator_bin}")
        print(f"[Loop] Output: {base_out.resolve()}  (Ctrl+C to stop)")
        if cycles_target:
            print(f"[Loop] Will run {cycles_target} cycle(s).")
        print(f"[Loop] Mut/Cycle: {args.mutations_per_cycle} | Check every: {args.check_every} | TB cycles: {args.tb_cycles}")
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
            # NOTE: your signature is (output_path, top_name)
            fr.generate_top_module(
                output_path=str(cycle_dir) + "/",
                top_name=args.top_name
            )   

            # Your TB generator’s signature does NOT take tb_name; it derives tb_<top>.
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

            incflags = [f"+incdir+{Path(p).as_posix()}" for p in args.incdir]

            user_flags = shlex.split(args.verilator_flags) if args.verilator_flags else []
            verilator_flags = incflags + user_flags

            build_ok, run_ok, rc, exe = run_verilator_binary(
                verilator_bin, cycle_dir, args.top_name, tb_name, extra_sv, verilator_flags
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
                "verilator": verilator_bin,
                "extra_sv": [p.as_posix() for p in extra_sv],
            }
            (cycle_dir / "summary.json").write_text(json.dumps(summary, indent=2))

            # Unpatch
            unpatch()

            # Console summary
            if not args.quiet:
                status = "OK" if (build_ok and run_ok) else ("BUILD_FAIL" if not build_ok else "SIM_FAIL")
                print(f"[Cycle {cycle_idx}] {status} | mu={total_done} (lin={counts['linear']}, cyc={counts['cyclical']}) | rc={rc}")
                print("------------------------------------------------------------")
            cycle_idx += 1

    except KeyboardInterrupt:
        if not args.quiet:
            print("\n[Loop] Interrupted by user.")

    return 0 if overall_ok else 2


if __name__ == "__main__":
    sys.exit(main())
