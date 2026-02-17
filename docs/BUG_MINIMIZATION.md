# Bug Minimization & Isolation

Systematic wire-level delta-debugging to isolate simulator disagreements down to the minimal design that still triggers the bug.

## Overview

When the triple-simulator fuzzing loop finds a bug (a cycle where Verilator, Icarus, and/or CXXRTL disagree), the result is a full design with 25+ modules and hundreds of inter-module wires. The **minimizer** reduces this to the smallest set of wires — and ultimately a self-contained `.sv` file with just 2–3 modules — that still reproduces the disagreement.

### Pipeline

```
Bug directory (top.sv + tb_top.sv + bug_report.json)
        │
        ▼
   Bit Tracing ─── trace_bit_bundled.py identifies which
        │          output bits differ and traces their
        │          dependency chains through the design
        ▼
  Wire Cutting ─── minimize_bug.py systematically cuts
        │          inter-module wires (replacing with 1'b0),
        │          re-simulates, and checks if the bug persists
        ▼
Essential Wires ── only the wires that, when cut, eliminate
        │          the bug are marked "essential"
        ▼
  Isolated Bug ─── a single self-contained .sv file with
                   only the essential modules and wiring,
                   plus a testbench that reproduces the mismatch
```

## Prerequisites

All three simulators must be available (installed via the project Dockerfile):

| Tool | Purpose | Path in container |
|------|---------|-------------------|
| Verilator | Primary simulator | `/opt/verilator/bin/verilator` |
| Icarus Verilog | Second simulator | `/opt/iverilog/bin/iverilog`, `vvp` |
| Python 3 | Runs the scripts | System Python |

The scripts also depend on the bit tracer and dual simulator infrastructure:

- `rewiring/scripts/trace_bit_bundled.py` — dependency graph tracer
- `rewiring/scripts/dual_simulator.py` — simulator build/run/compare functions

## Quick Start

### Step 1: Run the Minimizer

```bash
cd /opt/module-fuzz/rewiring/scripts

python3 minimize_bug.py \
    --bug-dir ../../TestArchive/large_test1/bugs/tribug_1339297989_1762975525 \
    --modules ../../test_libraries/comprehensive_tests \
    --output ../../isolated_bugs/minimized/
```

**Arguments:**

| Flag | Description |
|------|-------------|
| `--bug-dir` | Path to a bug directory containing `top.sv`, `tb_top.sv`, and `bug_report.json` |
| `--modules` | Path to the module library (must contain `flattened/` and `unflattened/` subdirectories) |
| `--output` | Output directory for the minimized design and report |
| `--verilator` | (Optional) Path to Verilator binary; auto-detected if not provided |

### Step 2: Review the Results

The minimizer produces three key files:

| File | Contents |
|------|----------|
| `reduction_report.json` | Full step-by-step log: every wire tested, result, essential vs. cut |
| `top_minimal.sv` | The original `top.sv` with non-essential wires tied to `1'b0` |
| `tb_top.sv` | Unchanged copy of the original testbench |

### Step 3: Run the Isolated Bug

The self-contained `.sv` file in the output directory can be compiled and run with any simulator to demonstrate the disagreement:

**Verilator:**
```bash
verilator --binary --timing \
    -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
    -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -Wno-PINMISSING \
    -o sim bug_isolated.sv
./obj_dir/sim > verilator.log
```

**Icarus Verilog:**
```bash
iverilog -g2012 -o sim.vvp bug_isolated.sv
vvp sim.vvp > icarus.log
```

**Compare:**
```bash
diff <(grep "^CYCLE=" verilator.log) <(grep "^CYCLE=" icarus.log)
```

Any `CYCLE` lines that differ between the two logs show the simulator disagreement.

## How It Works

### Wire Categories

Every `assign` statement in `top.sv` is one of three types:

| Type | Pattern | Example | Can be cut? |
|------|---------|---------|-------------|
| **ITM** (Input-to-Module) | `in_flat[N] → module_in_flat[M]` | `assign array_wrapper_in_flat[1] = in_flat[12];` | No (stimulus) |
| **MTM** (Module-to-Module) | `module_A_out[N] → module_B_in[M]` | `assign array_wrapper_in_flat[14] = arithmetic_reduce_wrapper_out_flat[3];` | **Yes** |
| **MTO** (Module-to-Output) | `module_out[N] → out_flat[M]` | `assign out_flat[10] = array_wrapper_out_flat[0];` | No (observable) |

Only **MTM** wires are candidates for cutting. The minimizer replaces the source with `1'b0`:

```verilog
// Before (original)
assign array_wrapper_in_flat[14] = arithmetic_reduce_wrapper_out_flat[3];

// After (cut)
assign array_wrapper_in_flat[14] = 1'b0;
```

### Trace-Guided Prioritization

Rather than testing all 90 MTM wires blindly, the minimizer first runs the **bit tracer** on each differing output bit to build the dependency graph. Wires in the dependency chain are tested first, ordered by hop distance from the differing output (closest first). This typically finds essential wires early.

### Reduction Algorithm

```
1. Parse bug_report.json → find first cycle with clear ground truth
2. Parse top.sv → categorize all assign statements
3. Run bit tracer on each differing output bit → collect MTM wires in dependency chains
4. Verify baseline: original design reproduces the bug
5. For each MTM wire (trace-guided order, then remaining):
   a. Temporarily cut this wire (+ all previously cut wires)
   b. Run Verilator and Icarus on the modified design
   c. If simulators still disagree → wire is NOT essential, keep it cut
   d. If simulators now agree → wire IS essential, restore it
6. Generate minimal top.sv with all non-essential wires cut
7. Verify the minimal design still reproduces the bug
```

## Example Results

Running on `tribug_1339297989_1762975525`:

```
Total MTM wires:    90
In dependency trace: 47
Essential (kept):    1
Cut (removed):      89
Bug still present:  Yes
```

The single essential wire:

```
array_wrapper_in_flat[14] = arithmetic_reduce_wrapper_out_flat[3]
```

This maps to:

```
arithmetic_reduce.complex_expr[1]  →  array.din0[2]
```

### Root Cause

The `arithmetic_reduce` module is purely **combinational** — its output changes whenever its inputs change. The `array` module is **sequential** — it latches `din0 + 1` into `dout0` on `posedge clk`.

The bug arises because `array`'s clock is derived from `in_flat[24]` (random stimulus), and `arithmetic_reduce`'s inputs also come from `in_flat`. When the testbench updates all `in_flat` bits simultaneously on `@(negedge clk)`:

1. `in_flat[24]` (array's clock) transitions
2. `in_flat[0:11]` (arithmetic_reduce's inputs) also change
3. `arithmetic_reduce` combinationally produces a new `complex_expr[1]`
4. But `array` sees `posedge clk` at the same simulation time

Different simulators resolve step 3 vs. step 4 in different orders, producing different `dout0[2]` values. This is a classic **setup/hold race condition**.

### Verifying the Mismatch

The isolated `bug_isolated.sv` shows exactly 26 cycles of disagreement, all on `out_flat[24]` (= `array.dout0[2]`):

```
CYCLE=30   Verilator OUT=0x1aa6c59   Icarus OUT=0x0aa6c59   diff_bits=[24]
CYCLE=31   Verilator OUT=0x1aa6fff   Icarus OUT=0x0aa6fff   diff_bits=[24]
CYCLE=74   Verilator OUT=0x0c6bc75   Icarus OUT=0x1c6bc75   diff_bits=[24]
CYCLE=104  Verilator OUT=0x04c9511   Icarus OUT=0x14c9511   diff_bits=[24]
...
```

## File Organization

```
module-fuzz/
├── rewiring/scripts/
│   ├── minimize_bug.py          # Wire-cut minimizer
│   └── trace_bit_bundled.py     # Bit dependency tracer
│
├── isolated_bugs/minimized/     # Output from minimizer
│   ├── bug_isolated.sv          # Self-contained isolated bug
│   ├── top_minimal.sv           # Full design with 89 wires cut
│   ├── tb_top.sv                # Original testbench (unchanged)
│   └── reduction_report.json    # Step-by-step reduction log
│
└── TestArchive/                 # Source bug directories
    └── large_test1/bugs/
        └── tribug_.../
            ├── top.sv
            ├── tb_top.sv
            └── bug_report.json
```

## Reduction Report Format

`reduction_report.json` contains:

| Field | Description |
|-------|-------------|
| `bug_id` | Bug identifier from the fuzzing run |
| `seed` | PRNG seed used in the testbench |
| `first_diff_cycle` | First cycle with a clear ground-truth disagreement |
| `ground_truth` | Which simulator pair agrees (e.g. `verilator_cxxrtl`) |
| `differing_bits` | Output bit indices that differ between simulators |
| `total_mtm_wires` | Total module-to-module wires in the original design |
| `traced_mtm_wires` | MTM wires found in the dependency chains of differing bits |
| `essential_count` | Number of wires that, when cut, eliminate the bug |
| `cut_count` | Number of wires safely removed |
| `essential_wires` | List of essential wires with metadata |
| `cut_wires` | List of all wires that were permanently cut |
| `reduction_steps` | Detailed log of every cut attempted and its outcome |
| `minimal_design_reproduces_bug` | Final verification result |

## Tips

- **Large designs**: The minimizer runs two full simulations per wire tested. For designs with many MTM wires, this can take a few minutes. The trace-guided ordering helps find essential wires early.
- **Multiple essential wires**: Some bugs may have more than one essential wire. The report lists all of them.
- **Build failures**: If cutting a wire causes a build failure (e.g., Verilator optimization issue), the wire is conservatively treated as essential.
- **Non-reproducible bugs**: If the baseline simulation doesn't reproduce the bug, the minimizer exits early. Ensure the simulators and module library match what was used during the fuzzing run.
