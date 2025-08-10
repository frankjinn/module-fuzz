#!/usr/bin/env python3
"""
Run the Verilator-fuzzer once:
 - Instantiate Fuzz_Run
 - Perform random rewiring mutations (linear/cyclical)
 - Count how many of each type succeeded
 - Generate a final top-level Verilog
 - Generate a SystemVerilog testbench for the top
 - Emit a JSON summary with the counts

Exit codes:
 0 = at least one mutation succeeded and Verilog/testbench were generated
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


def _run_random_mutations_fallback(fr, max_mutations, check_every=10, seed=None, verbose=True):
    if seed is not None:
        random.seed(seed)

    done = 0
    linear_exhausted = False
    cyclical_exhausted = False

    while done < max_mutations:
        choices = []
        if not linear_exhausted:
            choices.append("linear")
        if not cyclical_exhausted:
            choices.append("cyclical")

        if not choices:
            if verbose:
                print(f"[Run/Fallback] Both strategies exhausted after {done} mutation(s).")
            break

        choice = random.choice(choices)

        if choice == "linear":
            rc = fr.linear_rewire()
            if rc == 0:
                done += 1
            else:
                linear_exhausted = True
        else:
            rc = fr.cyclical_rewire()
            if rc == 0:
                done += 1
            else:
                cyclical_exhausted = True

        if done > 0 and (done % max(1, check_every) == 0):
            ok = False
            if hasattr(fr, "comprehensive_consistency_check"):
                ok = fr.comprehensive_consistency_check(verbose=verbose)
            else:
                ok = fr.verify_consistency(verbose=verbose)
            if not ok:
                raise RuntimeError(f"[Run/Fallback] Consistency check failed at mutation {done}.")

    if verbose:
        print(f"[Run/Fallback] Completed {done}/{max_mutations} mutation(s).")
    return done


def main():
    ap = argparse.ArgumentParser(description="Run Verilator fuzzer once and generate top-level Verilog + testbench.")
    ap.add_argument("flattened_lib", help="Path to the flattened library (input to Fuzz_Run).")
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

    if args.seed is None:
        args.seed = random.randint(0, 2**32 - 1)
    random.seed(args.seed)

    if verbose:
        print(f"[Driver] Seed={args.seed}")
        print(f"[Driver] Loading fuzzer from: {args.flattened_lib}")

    try:
        fr = fuzz_state.Fuzz_Run(args.flattened_lib)
    except Exception as e:
        print(f"[Error] Failed to initialize Fuzz_Run: {e}", file=sys.stderr)
        return 2

    # Wrap mutation counters
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

    # Run mutations
    try:
        if hasattr(fr, "run_random_mutations"):
            total_done = fr.run_random_mutations(
                max_mutations=args.max_mutations,
                check_every=args.check_every,
                seed=args.seed,
                verbose=verbose,
            )
        else:
            total_done = _run_random_mutations_fallback(
                fr,
                max_mutations=args.max_mutations,
                check_every=args.check_every,
                seed=args.seed,
                verbose=verbose,
            )
    except Exception as e:
        print(f"[Error] Mutation run failed: {e}", file=sys.stderr)
        return 2

    # Generate top module
    try:
        fr.generate_top_module(top_name=args.top_name, output_path=str(outdir.as_posix() + "/"))
    except Exception as e:
        print(f"[Error] Verilog generation failed: {e}", file=sys.stderr)
        return 2

    # Generate SV testbench
    try:
        if hasattr(fr, "generate_sv_testbench"):
            fr.generate_sv_testbench(
                top_name=args.top_name,
                output_path=str(outdir),
                sim_cycles=args.tb_cycles,
                trace=True,
                verbose=verbose
            )
        else:
            if verbose:
                print("[Driver] Skipping testbench generation: generate_sv_testbench not found in Fuzz_Run.")
    except Exception as e:
        print(f"[Error] Testbench generation failed: {e}", file=sys.stderr)
        return 2

    # Write stats
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
    with open(summary_path, "w") as f:
        json.dump(summary, f, indent=2)

    if verbose:
        print(f"[Driver] Wrote top module: {summary['top_sv']}")
        print(f"[Driver] Wrote testbench: {summary['testbench_sv']}")
        print(f"[Driver] Mutation counts: linear={counts['linear']}, cyclical={counts['cyclical']}, total={total_done}")
        print(f"[Driver] Stats: {summary_path}")

    print(json.dumps({"linear": counts["linear"], "cyclical": counts["cyclical"], "total": total_done}, indent=2))
    return 0


if __name__ == "__main__":
    try:
        code = main()
    except KeyboardInterrupt:
        code = 130
    sys.exit(code)
