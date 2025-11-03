# Triple Simulator Comparison with Arbitration

This directory contains scripts for running three-way simulator comparisons using Verilator, Icarus Verilog, and CXXRTL. When Verilator and Icarus disagree on results, CXXRTL is used as an arbiter to determine which simulator is likely correct.

## Overview

The triple simulator setup extends the dual simulator infrastructure to include a third simulator (CXXRTL) for arbitration purposes. This helps identify which simulator has bugs when disagreements occur.

### Key Features

1. **Three-Way Comparison**: Runs Verilator, Icarus Verilog, and CXXRTL on the same testbench
2. **Automatic Arbitration**: Uses majority voting to determine correct results
3. **Enhanced Bug Reports**: Includes ground truth information about which simulator is likely wrong
4. **Fallback Support**: Automatically falls back to dual comparison if CXXRTL is unavailable
5. **Not Instrumented**: CXXRTL is run without coverage instrumentation (arbitration only)

## Architecture

```
┌─────────────┐
│   Fuzzer    │
│ (mutations) │
└──────┬──────┘
       │
       ├─────────────────────────────────┐
       │                                 │
       ▼                                 ▼
┌─────────────┐                  ┌──────────────┐
│  Top Module │                  │  Testbench   │
│   (top.sv)  │                  │ (tb_top.sv)  │
└──────┬──────┘                  └──────┬───────┘
       │                                 │
       └────────┬───────────────────────┘
                │
       ┌────────┴────────┬────────────────┐
       │                 │                │
       ▼                 ▼                ▼
┌──────────┐      ┌────────────┐   ┌──────────┐
│Verilator │      │   Icarus   │   │ CXXRTL │
│(instrume-│      │  Verilog   │   │ (arbiter)│
│  nted)   │      │            │   │          │
└────┬─────┘      └─────┬──────┘   └────┬─────┘
     │                  │                │
     ▼                  ▼                ▼
  sim.log         icarus_sim.log   cxxrtl_sim.log
     │                  │                │
     └──────────┬───────┴────────────────┘
                │
                ▼
        ┌───────────────┐
        │ Tri-Comparison│
        │  & Arbitration│
        └───────┬───────┘
                │
                ▼
           Bug Report
    (with arbitration verdict)
```

## Installation

### Prerequisites

1. **Verilator** (instrumented with coverage - already installed)
2. **Icarus Verilog** (already installed)
3. **CXXRTL** (new requirement)

### Installing CXXRTL

#### Option 1: Intel CXXRTL-Intel FPGA Edition (Free)

1. Download from Intel's website: https://www.intel.com/content/www/us/en/software-kit/750666/cxxrtl-intel-fpgas-standard-edition-software-version-20-1-1.html
2. Follow Intel's installation instructions
3. Set environment variables:
   ```bash
   export MODELSIM_ROOT=/path/to/intelFPGA/20.1/cxxrtl_ase
   export PATH=$MODELSIM_ROOT/bin:$PATH
   ```

#### Option 2: Docker with CXXRTL Mount

Update the Dockerfile (already done) and run with a volume mount:

```bash
docker build -t module-fuzz-tri .
docker run -v /path/to/cxxrtl:/opt/cxxrtl -it module-fuzz-tri
```

### Verification

Check that all simulators are available:

```bash
cd rewiring
python examples/simple_tri_sim.py
```

## Usage

### Basic Triple Simulation

Run from the `rewiring` directory:

```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --outdir runs_tri \
  --max-cycles 10 \
  --mutations-per-cycle 20
```

### With CXXRTL Optional (Fallback to Dual)

If CXXRTL might not always be available:

```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --outdir runs_tri \
  --cxxrtl-optional \
  --max-cycles 10
```

### Custom CXXRTL Path

If CXXRTL is installed in a non-standard location:

```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --cxxrtl /opt/intelFPGA/20.1/cxxrtl_ase/bin \
  --outdir runs_tri
```

### All Options

```bash
python scripts/tri_fuzz_and_sim_loop.py --help
```

Key options:
- `--cxxrtl PATH`: Path to CXXRTL binary directory
- `--cxxrtl-flags FLAGS`: Extra flags to pass to CXXRTL
- `--cxxrtl-optional`: Continue with dual sim if CXXRTL unavailable
- All other options same as dual_fuzz_and_sim_loop.py

## Arbitration Logic

The arbitration system uses **majority voting** to determine the correct result:

### Decision Rules

1. **All Three Agree** → No bug detected
2. **Two Agree, One Differs** → The two that agree are likely correct
   - Verilator + Icarus agree → CXXRTL likely has bug
   - Verilator + CXXRTL agree → Icarus likely has bug  
   - Icarus + CXXRTL agree → Verilator likely has bug
3. **All Three Differ** → Unclear case, requires manual investigation

### Example Arbitration Output

```
[TriSim] BUG FOUND! Simulators produced different results
[TriSim] Agreement rate: 95.50%
[TriSim] Arbitration verdict: icarus_cxxrtl is likely correct

ARBITRATION VERDICT
-------------------
icarus_cxxrtl is likely correct
Confidence: high

DISAGREEMENT BREAKDOWN
----------------------
Verilator & Icarus agree (CXXRTL differs): 0
Verilator & CXXRTL agree (Icarus differs): 0
Icarus & CXXRTL agree (Verilator differs): 9
All three differ: 0

LIKELY BUG LOCATION
-------------------
Verilator likely has bugs: True
Icarus likely has bugs: False
CXXRTL likely has bugs: False
```

## Output Structure

```
runs_tri/
├── cycle_0000/
│   ├── top.sv                    # Generated top module
│   ├── tb_top.sv                 # Generated testbench
│   ├── sim.log                   # Verilator output
│   ├── icarus_sim.log            # Icarus output
│   ├── cxxrtl_sim.log          # CXXRTL output
│   ├── summary.json              # Cycle summary with arbitration
│   └── obj_dir/                  # Build artifacts
├── cycle_0001/
│   └── ...
├── bugs/
│   └── tribug_<seed>_<timestamp>/
│       ├── bug_report.json       # Detailed bug report with arbitration
│       ├── summary.txt           # Human-readable summary
│       ├── top.sv                # Preserved test case
│       ├── tb_top.sv
│       └── *.log                 # All simulation logs
└── bug_summary.json              # Overall statistics
```

## Bug Report Format

Triple simulator bug reports include:

```json
{
  "bug_id": "tribug_12345_1234567890",
  "bug_type": "three_way_comparison",
  "agreement_status": {
    "counts": {
      "all_three": 191,
      "verilator_icarus": 0,
      "verilator_cxxrtl": 0,
      "icarus_cxxrtl": 9,
      "all_differ": 0
    },
    "total_cycles": 200,
    "disagreement_cycles": 9,
    "agreement_rate": 95.5
  },
  "arbitration": {
    "verdict": "icarus_cxxrtl is likely correct",
    "confidence": "high",
    "verilator_likely_correct": -9,
    "icarus_likely_correct": 9,
    "cxxrtl_likely_correct": 9,
    "unclear_cases": 0
  },
  "differences": [
    {
      "cycle": 10,
      "verilator": {"IN": "A5", "OUT": "1A"},
      "icarus": {"IN": "A5", "OUT": "2B"},
      "cxxrtl": {"IN": "A5", "OUT": "2B"},
      "ground_truth": "icarus_cxxrtl",
      "likely_bug_in": "verilator"
    }
  ]
}
```

## Performance Considerations

- **Runtime**: ~3x longer than dual simulation (three simulators instead of two)
- **Disk Space**: More log files (cxxrtl_sim.log, cxxrtl_work/, etc.)
- **CXXRTL**: Not instrumented, so no coverage overhead for CXXRTL itself
- **Cleanup**: Use `--max-cycle-dirs` and `--cleanup-every` to manage disk usage

## Comparison: Dual vs Triple Simulation

| Feature | Dual Sim | Triple Sim |
|---------|----------|------------|
| Simulators | 2 (Verilator, Icarus) | 3 (Verilator, Icarus, CXXRTL) |
| Bug Detection | Yes | Yes |
| Arbitration | No | Yes (majority voting) |
| Ground Truth | No | Yes (2 out of 3) |
| Runtime | Baseline | ~1.5x slower |
| Disk Usage | Baseline | ~1.3x more |
| Use Case | Find disagreements | Find bugs + identify culprit |

## When to Use Triple Simulation

**Use Triple Simulation When:**
- You need to know which simulator is likely wrong
- You're debugging simulator bugs (not just finding them)
- You have CXXRTL available
- You can afford the extra runtime

**Use Dual Simulation When:**
- You just need to find disagreements
- CXXRTL is not available
- You need maximum throughput
- Disk space is limited

## Troubleshooting

### CXXRTL Not Found

```
[Error] Could not find working 'vlog' and 'vsim' binaries for CXXRTL.
```

**Solution**: Set `MODELSIM_ROOT` environment variable or use `--cxxrtl` flag

### CXXRTL License Issues

```
[CXXRTL] Failed to create work library: License error
```

**Solution**: Use Intel CXXRTL-Intel FPGA Edition (free, no license required)

### CXXRTL 32-bit Library Issues (Linux)

```
error while loading shared libraries: libXft.so.2
```

**Solution**: Install 32-bit libraries (already in updated Dockerfile):
```bash
sudo dpkg --add-architecture i386
sudo apt-get update
sudo apt-get install libxft2:i386 libxext6:i386 libncurses5:i386
```

## Examples

See `examples/simple_tri_sim.py` for a complete working example.

## Contributing

When adding new features to the triple simulator:
1. Update `tri_simulator.py` for core simulation logic
2. Update `tri_fuzz_and_sim_loop.py` for fuzzing integration
3. Update this README with new features
4. Add examples if introducing new workflows

## References

- Original dual simulator: `dual_simulator.py`, `dual_fuzz_and_sim_loop.py`
- Fuzzing state management: `fuzz_state.py`
- Coverage analysis: `verilator_coverage.py`
- Documentation: `docs/coverage_example.md`

