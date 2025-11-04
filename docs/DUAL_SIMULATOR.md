# Module Fuzzing and Dual Simulator Framework

This directory contains tools for fuzzing SystemVerilog modules and running dual simulator comparisons between Verilator and Icarus Verilog.

## Directory Structure

```
rewiring/
├── scripts/           # Main scripts and utilities
│   ├── dual_fuzz_and_sim_loop.py  # Dual simulator fuzzing loop
│   ├── dual_simulator.py          # Dual simulator core functionality
│   ├── fuzz_and_sim_loop.py      # Single simulator fuzzing loop
│   ├── fuzz_state.py             # Fuzzing state management
│   ├── run_fuzzer_once.py        # Single fuzzing run
│   ├── count_IO.py               # I/O counting utilities
│   ├── IO_map.py                 # I/O mapping utilities
│   └── verilator_coverage.py     # Coverage analysis tools
├── modules/           # SystemVerilog module libraries
│   └── test_library_structured/
│       ├── flattened/    # Wrapper modules with flattened I/O
│       └── unflattened/  # Original modules
├── docs/             # Documentation and examples
│   ├── coverage_example.md
│   └── wire_mutation.ipynb
└── examples/         # Example scripts and configurations
```

## Quick Start

### Running a Dual Simulator Example

Dual simulation compares the behavior of **Verilator** and **Icarus Verilog** on the same test cases to find simulator bugs or discrepancies:

```bash
cd scripts
python3 dual_fuzz_and_sim_loop.py ../modules/test_library_structured/flattened/ \
    -o dual_sim_results \
    -c 5 \
    --tb-cycles 100 \
    --mutations-per-cycle 30 \
    --rtl-dir ../modules/test_library_structured/flattened/ \
    --incdir ../modules/test_library_structured/unflattened/
```

**Note**: The `--rtl-dir` and `--incdir` flags are **required** for proper module resolution:
- `--rtl-dir`: Points to wrapper modules (flattened)
- `--incdir`: Points to original modules (unflattened)

**Important**: Dual simulation requires both Verilator and Icarus Verilog to be installed:
- Verilator: `/opt/verilator/bin/verilator`
- Icarus Verilog: `/opt/iverilog/bin/iverilog` and `/opt/iverilog/bin/vvp`

### Running a Single Simulator Fuzz

To run fuzzing with just Verilator (faster, but no cross-validation):

```bash
cd scripts
python3 fuzz_and_sim_loop.py ../modules/test_library_structured/flattened/ \
    -o single_sim_results \
    -c 10 \
    --rtl-dir ../modules/test_library_structured/flattened/ \
    --incdir ../modules/test_library_structured/unflattened/
```

## Dual vs Single Simulation

### Single Simulation (fuzz_and_sim_loop.py)
- **Purpose**: Test random module connections with Verilator only
- **Speed**: Fast (only one simulator)
- **Output**: Validates that generated RTL compiles and runs
- **Use case**: General fuzzing to find synthesis/compilation issues

### Dual Simulation (dual_fuzz_and_sim_loop.py)
- **Purpose**: Compare Verilator vs Icarus Verilog results to find simulator bugs
- **Speed**: Slower (runs both simulators)
- **Output**: Detects when simulators produce different results
- **Use case**: Find discrepancies between different simulator implementations

### What Dual Simulation Detects

When the same testbench produces different outputs between simulators:
- **Simulator bugs**: One simulator has incorrect behavior
- **Standard interpretation differences**: IEEE standard ambiguities
- **Timing differences**: Race conditions or initialization issues
- **Feature support gaps**: One simulator doesn't support certain constructs

Bug reports are automatically saved with:
- Complete test cases (RTL + testbench)
- Detailed comparison of simulator outputs
- Cycle-by-cycle difference analysis

## Key Features

- **Dual Simulator Comparison**: Compare Verilator and Icarus Verilog results to find simulator bugs
- **Systematic Fuzzing**: Random mutation of module connections with consistency checking
- **Bug Detection**: Automatic detection and reporting of simulator discrepancies
- **Coverage Analysis**: Track which modules and connections are being tested
- **Clean Architecture**: Organized codebase with clear separation of concerns
- **Optimized Performance**: Improved file discovery, regex compilation, and data caching
- **Robust Error Handling**: Better validation and graceful failure recovery

## Requirements

- Python 3.8+
- Verilator (for all simulations)
- Icarus Verilog (for dual simulations only)
- SystemVerilog modules in the test library

## Troubleshooting

### Common Dual Simulation Issues

**"Cannot find file containing module"**
- Make sure both `--rtl-dir` and `--incdir` are specified
- `--rtl-dir` should point to flattened wrapper modules
- `--incdir` should point to unflattened original modules

**"Verilator simulation failed"**
- Check `build.err` for compilation errors
- Ensure all module dependencies are included
- Verify SystemVerilog syntax is correct

**"No simulator discrepancies found"**
- This is normal - it means both simulators agree
- Try running more cycles or different mutations
- Some bugs only appear with specific input patterns

**Performance Tips**
- Use fewer cycles (`-c`) for quick tests
- Reduce mutations per cycle (`--mutations-per-cycle`) for faster execution
- Enable cleanup (`--cleanup-every`) to manage disk space

## Recent Optimizations

### Improved Default Settings
- **Verilator flags**: Now includes `-Wno-TIMESCALEMOD -Wno-WIDTHTRUNC` by default
- **Better error handling**: More robust path validation and directory creation
- **Performance improvements**: Optimized file discovery and regex compilation

### Required Arguments
Both simulators now require these arguments for proper operation:
- `--rtl-dir <path>`: Directory containing wrapper modules (usually flattened/)
- `--incdir <path>`: Directory containing original modules (usually unflattened/)

### Example with All Required Flags
```bash
cd scripts
python3 dual_fuzz_and_sim_loop.py ../modules/test_library_structured/flattened/ \
    -o my_dual_test \
    -c 3 \
    --rtl-dir ../modules/test_library_structured/flattened/ \
    --incdir ../modules/test_library_structured/unflattened/
```

## Output Structure

### Single Simulation Output
```
single_sim_results/
├── cycle_0000/
│   ├── top.sv              # Generated top module
│   ├── tb_top.sv           # SystemVerilog testbench
│   ├── build.log           # Verilator build log
│   ├── sim.log             # Simulation output
│   └── summary.json        # Cycle statistics
├── cycle_0001/
│   └── ...
└── error_summary.json      # Overall error statistics
```

### Dual Simulation Output
```
dual_sim_results/
├── cycle_0000/
│   ├── top.sv              # Generated top module
│   ├── tb_top.sv           # SystemVerilog testbench
│   ├── build.log           # Verilator build log
│   ├── sim.log             # Verilator simulation output
│   ├── icarus_build.log    # Icarus build log
│   ├── icarus_sim.log      # Icarus simulation output
│   └── summary.json        # Cycle statistics
├── bugs/                   # Bug reports (if any found)
│   └── bug_<seed>_<time>/
│       ├── bug_report.json # Detailed bug analysis
│       ├── top.sv          # Test case that triggered bug
│       └── tb_top.sv       # Testbench that triggered bug
└── bug_summary.json        # Overall bug statistics
```

### Key Files to Check

- **summary.json**: Per-cycle statistics and success/failure status
- **bug_summary.json**: List of all bugs found with metadata
- **bug_report.json**: Detailed analysis of each simulator discrepancy
- **sim.log vs icarus_sim.log**: Compare simulator outputs manually

## Usage Best Practices

### Quick Start Commands

**For dual simulation testing:**
```bash
cd scripts
python3 dual_fuzz_and_sim_loop.py ../modules/test_library_structured/flattened/ \
    -o my_dual_test -c 5 \
    --rtl-dir ../modules/test_library_structured/flattened/ \
    --incdir ../modules/test_library_structured/unflattened/
```

**For single simulation testing:**
```bash
cd scripts  
python3 fuzz_and_sim_loop.py ../modules/test_library_structured/flattened/ \
    -o my_single_test -c 10 \
    --rtl-dir ../modules/test_library_structured/flattened/ \
    --incdir ../modules/test_library_structured/unflattened/
```

**For quick one-shot testing:**
```bash
cd scripts
python3 run_fuzzer_once.py ../modules/test_library_structured/flattened/ \
    -n 20 -o quick_test
```

### Important Notes

- **Always specify both `--rtl-dir` and `--incdir`** for proper module resolution
- **Default Verilator flags** now include warning suppression for common issues
- **Dual simulation is slower** but provides valuable cross-validation
- **Start with small cycle counts** (`-c 1-5`) for initial testing
