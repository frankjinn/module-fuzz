#!/usr/bin/env python3
"""
Run the Verilator-fuzzer once (simplified, fixed):
 - Instantiate Fuzz_Run
 - Use Fuzz_Run.run_random_mutations (built-in)
 - Count successes per strategy by wrapping rewire methods
 - Generate top-level Verilog and an SV testbench
 - Emit a JSON summary

Exit codes:
 0 = at least one mutation succeeded
 1 = no valid mutations available (nothing done)
 2 = error during generation / unexpected failure
"""

import argparse
import json
import random
import sys
import time
import types
from pathlib import Path

import fuzz_state


def main():
    ap = argparse.ArgumentParser(description="Run Verilator fuzzer once; perform random mutations; emit Verilog+SVTB.")
    ap.add_argument("flattened_lib", help="Path to the flattened module library (input to Fuzz_Run).")
    ap.add_argument("-n", "--max-mutations", type=int, default=50, help="Maximum successful mutations to attempt.")
    ap.add_argument("-c", "--check-every", type=int, default=10, help="Run comprehensive check after this many successes.")
    ap.add_argument("-s", "--seed", type=int, default=None, help="Random seed (optional; random if omitted).")
    ap.add_argument("-t", "--top-name", default="top", help="Top module name for generated Verilog.")
    ap.add_argument("-o", "--outdir", default="out", help="Output directory for generated files.")
    ap.add_argument("-q", "--quiet", action="store_true", help="Reduce logging.")
    ap.add_argument("--tb-cycles", type=int, default=200, help="Number of cycles for generated SV testbench.")
    args = ap.parse_args()

    verbose = not args.quiet
    outdir = Path(args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)

    # Seed handling
    if args.seed is None:
        args.seed = random.randint(0, 2**32 - 1)
    random.seed(args.seed)

    if verbose:
        print(f"[Driver] Seed={args.seed}")
        print(f"[Driver] Loading fuzzer from: {args.flattened_lib}")

    # Init Fuzz_Run
    try:
        fr = fuzz_state.Fuzz_Run(args.flattened_lib)
    except Exception as e:
        print(f"[Error] Failed to initialize Fuzz_Run: {e}", file=sys.stderr)
        return 2

    # Wrap mutation methods to count successes
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

    # Run the (now built-in) random mutation driver — use keyword args
    try:
        total_done = fr.run_random_mutations(
            max_mutations=args.max_mutations,
            check_every=args.check_every,
            seed=args.seed,
            verbose=verbose,
        )
    except Exception as e:
        print(f"[Error] Mutation run failed: {e}", file=sys.stderr)
        return 2

    # Generate top module (do NOT expect a return value)
    try:
        fr.generate_top_module(
            output_path=str(outdir) + "/",
            top_name=args.top_name
        )
        if verbose:
            print(f"[Driver] Generated top: {args.top_name}.sv")
    except Exception as e:
        print(f"[Error] Verilog generation failed: {e}", file=sys.stderr)
        return 2

    # Generate SV testbench (signature requires hold_reset_cycles in your implementation)
    try:
        if hasattr(fr, "generate_sv_testbench"):
            fr.generate_sv_testbench(
                top_name=args.top_name,
                output_path=str(outdir),
                sim_cycles=args.tb_cycles,
                clk_period=2,
                hold_reset_cycles=2,   # required by your signature (even if unused)
                trace=True,
                seed=None,
                verbose=verbose,
            )
        else:
            if verbose:
                print("[Driver] Skipping testbench generation: generate_sv_testbench not found in Fuzz_Run.")
    except Exception as e:
        print(f"[Error] Testbench generation failed: {e}", file=sys.stderr)
        return 2

    # Write and print stats
    summary = {
        "seed": args.seed,
        "total_successful_mutations": int(total_done),
        "linear_successes": int(counts["linear"]),
        "cyclical_successes": int(counts["cyclical"]),
        "top_sv": str((outdir / f"{args.top_name}.sv").as_posix()),
        "testbench_sv": str((outdir / f"tb_{args.top_name}.sv").as_posix()),
        "timestamp": int(time.time()),
    }
    summary_path = outdir / "mutation_stats.json"
    try:
        with open(summary_path, "w") as f:
            json.dump(summary, f, indent=2)
    except Exception as e:
        print(f"[Error] Failed to write stats: {e}", file=sys.stderr)

    if verbose:
        print(f"[Driver] Wrote top module: {summary['top_sv']}")
        print(f"[Driver] Wrote testbench: {summary['testbench_sv']}")
        print(f"[Driver] Mutation counts: linear={counts['linear']}, cyclical={counts['cyclical']}, total={total_done}")
        print(f"[Driver] Stats: {summary_path}")

    print(json.dumps({"linear": counts["linear"], "cyclical": counts["cyclical"], "total": total_done}, indent=2))

    # Exit code semantics:
    #  0 = at least one mutation succeeded
    #  1 = no valid mutations available (nothing done)
    #  2 = error (handled earlier)
    return 0 if total_done > 0 else 1


if __name__ == "__main__":
    try:
        code = main()
    except KeyboardInterrupt:
        code = 130
    sys.exit(code)
