# Quick Start: Triple Simulator with Arbitration

Get started with three-way simulator comparison in 5 minutes!

## Prerequisites

```bash
# Ensure you have all three simulators installed:
verilator --version
iverilog -v
vlog -version  # CXXRTL
```

## Installation

### If CXXRTL is Not Installed

Download Intel CXXRTL-Intel FPGA Edition (free):
https://www.intel.com/content/www/us/en/software-kit/750666/cxxrtl-intel-fpgas-standard-edition-software-version-20-1-1.html

Then set environment variable:
```bash
export MODELSIM_ROOT=/path/to/intelFPGA/20.1/cxxrtl_ase
```

## Quick Test

From the `rewiring` directory:

```bash
# Test 1: Check simulators are available
python examples/simple_tri_sim.py

# Test 2: Run 5 cycles with triple simulation
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --outdir runs_tri_test \
  --max-cycles 5 \
  --mutations-per-cycle 10
```

## Understanding the Output

### When All Simulators Agree
```
[TriSim] All three simulators agree - no bug found
[Cycle 0] ✓ Match | mu=10 (lin=5, cyc=5) | bugs_total=0
```

### When Bug is Found
```
[TriSim] BUG FOUND! Simulators produced different results
[TriSim] Agreement rate: 95.50%
[TriSim] Arbitration verdict: icarus_cxxrtl is likely correct
[TriLoop] 🐛 BUG #1 in cycle 3! Verdict: icarus_cxxrtl is likely correct
```

This means:
- Icarus and CXXRTL agree (95.5% of cycles)
- Verilator differs
- **Verdict**: Verilator likely has a bug

## Viewing Results

### Bug Report Location
```bash
cd runs_tri_test/bugs/tribug_<seed>_<timestamp>/

# View human-readable summary
cat summary.txt

# View detailed JSON report
cat bug_report.json

# View simulator logs
cat sim.log              # Verilator
cat icarus_sim.log       # Icarus
cat cxxrtl_sim.log     # CXXRTL
```

### Overall Statistics
```bash
cat runs_tri_test/bug_summary.json
```

Example output:
```json
{
  "total_cycles": 10,
  "total_bugs": 2,
  "bug_rate_percent": 20.0,
  "simulation_mode": "triple",
  "arbitration_stats": {
    "verilator_correct": 5,
    "icarus_correct": -3,
    "cxxrtl_correct": 2,
    "unclear": 0
  }
}
```

**Interpretation**: 
- Verilator is likely correct in 5 bug cases
- Icarus is likely wrong in 3 bug cases  
- CXXRTL is likely correct in 2 bug cases

## Common Use Cases

### 1. Find Bugs + Identify Culprit (Full Triple Sim)
```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/const_tests/flattened/ \
  --rtl-dir ../test_libraries/const_tests/unflattened/ \
  --outdir runs_tri \
  --max-cycles 100
```

### 2. Long-Running Fuzzing Campaign
```bash
# Run indefinitely (Ctrl+C to stop)
# Clean up old cycles to save disk space
python scripts/tri_fuzz_and_sim_loop.py \
  ../coverage_library_IO_flattened/consts_flattened/ \
  --rtl-dir ../coverage_library/consts/ \
  --outdir runs_tri_long \
  --max-cycle-dirs 50 \
  --cleanup-every 10 \
  --preserve-recent 20
```

### 3. Fallback Mode (Dual if CXXRTL Unavailable)
```bash
# Automatically use dual simulation if CXXRTL not found
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --cxxrtl-optional \
  --outdir runs_flexible
```

## Customization

### Custom Simulator Paths
```bash
python scripts/tri_fuzz_and_sim_loop.py \
  path/to/flattened/ \
  --verilator /opt/verilator/bin/verilator \
  --icarus /opt/iverilog/bin/iverilog \
  --cxxrtl /opt/intelFPGA/20.1/cxxrtl_ase/bin \
  --outdir runs_custom
```

### More Mutations Per Cycle
```bash
# More aggressive fuzzing
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --mutations-per-cycle 100 \
  --check-every 20 \
  --outdir runs_aggressive
```

### Custom Testbench Parameters
```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --tb-cycles 500 \
  --tb-clk-period 5 \
  --outdir runs_custom_tb
```

## Interpreting Arbitration

| Verdict | Meaning | Action |
|---------|---------|--------|
| `verilator_cxxrtl is likely correct` | Icarus likely has bug | Investigate Icarus behavior |
| `icarus_cxxrtl is likely correct` | Verilator likely has bug | Investigate Verilator behavior |
| `verilator_icarus is likely correct` | CXXRTL likely has bug | Investigate CXXRTL behavior |
| `Unclear - no consistent agreement` | All three differ | Manual investigation needed |

## Next Steps

1. **Read Full Documentation**: See `README_TRI_SIM.md` for detailed info
2. **Run Examples**: Try `examples/simple_tri_sim.py`
3. **Customize Flags**: Run with `--help` to see all options
4. **Compare Results**: Try both dual and triple sim to compare

## Troubleshooting

**Problem**: CXXRTL not found
```
[Error] Could not find working 'vlog' and 'vsim' binaries for CXXRTL.
```
**Solution**: 
```bash
export MODELSIM_ROOT=/path/to/cxxrtl
# Or use --cxxrtl-optional to fall back to dual sim
```

**Problem**: All cycles fail to simulate
```
[Cycle 0] ERROR | SimulationFailure: Simulation failed
```
**Solution**: Check that RTL sources are correct:
```bash
# Verify paths exist
ls ../test_libraries/basic_tests/flattened/
ls ../test_libraries/basic_tests/unflattened/
```

**Problem**: Out of disk space
```
OSError: [Errno 28] No space left on device
```
**Solution**: Enable automatic cleanup:
```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ... \
  --max-cycle-dirs 20 \
  --cleanup-every 5
```

## Performance Tips

1. **Fewer Cycles, More Mutations**: `--max-cycles 10 --mutations-per-cycle 100`
2. **Enable Cleanup**: `--max-cycle-dirs 50 --cleanup-every 10`
3. **Reduce Testbench Length**: `--tb-cycles 100` (default is 200)
4. **Use Dual Mode for Speed**: Omit CXXRTL when you don't need arbitration

## Getting Help

- Full documentation: `README_TRI_SIM.md`
- Examples: `examples/simple_tri_sim.py`
- Command help: `python scripts/tri_fuzz_and_sim_loop.py --help`
- Original dual simulator: See `dual_fuzz_and_sim_loop.py`

Happy fuzzing! 🐛

