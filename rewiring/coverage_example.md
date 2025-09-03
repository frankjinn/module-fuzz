# Verilator Coverage Instrumentation Example

This document shows how to use the new coverage instrumentation feature in `fuzz_and_sim_loop.py`.

## What This Measures

The coverage instrumentation captures **Verilator's internal code coverage** (not the Verilog files being processed). This helps you understand:

- Which parts of Verilator's compiler are being exercised by your fuzzing
- How comprehensive your test cases are at exploring Verilator's code paths
- Areas of Verilator that might need more focused testing

## Prerequisites

1. **VERILATOR_ROOT environment variable** must be set
2. **gcovr** must be installed: `pip install gcovr`  
3. **Verilator compiled with gcc** (the dockerfile already handles this)

## Basic Usage

### Enable Coverage (Default Settings)
```bash
python fuzz_and_sim_loop.py --enable-coverage flattened_lib.json
```

This will:
- Collect coverage data after each successful cycle
- Generate HTML reports every 10 cycles (default)
- Store data in `<outdir>/coverage/`

### Custom Coverage Settings
```bash
python fuzz_and_sim_loop.py \
    --enable-coverage \
    --coverage-report-every 5 \
    --coverage-dir /path/to/custom/coverage \
    --max-cycles 20 \
    flattened_lib.json
```

This will:
- Generate HTML reports every 5 cycles
- Store coverage data in a custom directory
- Run for exactly 20 cycles

## Output Structure

When coverage is enabled, you'll get:

```
runs_tb/                          # Main output directory
├── cycle_0000/                   # Per-cycle data
│   ├── summary.json             # Includes coverage info
│   ├── top.sv
│   └── tb_top.sv
├── cycle_0001/
│   └── ...
└── coverage/                    # Coverage data
    ├── json/                    # JSON data per cycle
    │   ├── cycle_0000.json
    │   ├── cycle_0001.json
    │   └── ...
    └── html/                    # HTML reports
        ├── report_cycle_0004/   # Every N cycles
        │   └── coverage_report.html
        ├── report_cycle_0009/
        │   └── coverage_report.html
        └── ...
```

## Understanding the Reports

### JSON Files
Each `cycle_XXXX.json` contains detailed coverage data for that specific cycle, including:
- Line coverage percentages
- Function coverage
- Branch coverage
- File-by-file breakdowns

### HTML Reports
The HTML reports provide:
- **Aggregated coverage** from all cycles up to that point
- **Interactive browsing** of source files with coverage highlighting
- **Summary statistics** showing overall coverage percentages
- **Detailed views** of uncovered lines and branches

## Example Output

When running with coverage enabled, you'll see:

```bash
[Loop] Coverage enabled: Reports every 10 cycles
[Loop] Coverage data: /path/to/runs_tb/coverage

[Cycle 0] OK | mu=40 (lin=25, cyc=15) | rc=0
[Cycle 0] Coverage collected
------------------------------------------------------------
[Cycle 1] OK | mu=40 (lin=28, cyc=12) | rc=0
[Cycle 1] Coverage collected
------------------------------------------------------------
...
[Cycle 9] OK | mu=40 (lin=22, cyc=18) | rc=0
[Cycle 9] Coverage collected | HTML report: /path/to/coverage/html/report_cycle_0009/coverage_report.html
------------------------------------------------------------

[Coverage Summary] Total cycles with coverage: 10
[Coverage Summary] Latest HTML report: /path/to/coverage/html/report_cycle_0009/coverage_report.html
[Coverage Summary] Final aggregated report: /path/to/coverage/html/report_cycle_0009/coverage_report.html
```

## Performance Considerations

- Coverage collection adds ~1-2 seconds per cycle
- JSON files are small (~10-50KB each)
- HTML reports can be larger (~1-5MB with details)
- Old data is automatically cleaned up to prevent disk space issues

## Troubleshooting

### "VERILATOR_ROOT not set"
```bash
export VERILATOR_ROOT=/opt/verilator
```

### "gcovr not found"
```bash
pip install gcovr
```

### "No coverage data generated"
This usually means:
1. Verilator wasn't compiled with gcc instrumentation, or
2. The gcov data files aren't being generated properly

Check that your Verilator build includes gcc instrumentation support.
