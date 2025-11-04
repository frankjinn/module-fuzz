# Triple Simulator for module-fuzz

Cross-validation fuzzing with **Verilator**, **Icarus Verilog**, and **Yosys CXXRTL** with automatic arbitration.

## Quick Start

### 1. Prerequisites

All three simulators are pre-installed in the Docker image:
- ✅ Verilator: `/opt/verilator/bin/verilator`
- ✅ Icarus Verilog: `/opt/iverilog/bin/iverilog`
- ✅ Yosys CXXRTL: `/opt/yosys/yosys`

### 2. Run Triple Simulator (5-minute test)

```bash
cd /opt/module-fuzz/rewiring

python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --incdir ../test_libraries/basic_tests/flattened/ \
  --incdir ../test_libraries/basic_tests/unflattened/ \
  --verilator-flags "--trace -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC" \
  --outdir runs_triple \
  --max-cycles 10 \
  --mutations-per-cycle 20
```

### 3. Check Results

```bash
# View summary
cat runs_triple/bug_summary.json

# Check if all simulators agreed
grep "All three simulators agree" runs_triple/cycle_*/summary.json
```

## How It Works

### Architecture

```
┌─────────────┐  ┌──────────────┐  ┌─────────────┐
│  Verilator  │  │Icarus Verilog│  │Yosys CXXRTL │
└──────┬──────┘  └──────┬───────┘  └──────┬──────┘
       │                │                  │
       │    Fuzzer generates mutated      │
       │    design with random inputs     │
       │                │                  │
       ▼                ▼                  ▼
  ┌────────────────────────────────────────────┐
  │        3-Way Log Comparison Engine         │
  │  • Parse all three simulation logs         │
  │  • Compare cycle-by-cycle outputs          │
  │  • Detect any disagreements                │
  └────────────┬───────────────────────────────┘
               │
               ▼
       ┌───────────────┐
       │  Arbitration  │
       │  (2 out of 3) │
       └───────┬───────┘
               │
        ┌──────┴──────┐
        │ If Disagree  │
        ▼              ▼
   ┌────────┐    ┌──────────┐
   │2 Agree │    │3 Differ  │
   │= Truth │    │= Unclear │
   └────────┘    └──────────┘
```

### Arbitration Logic

When simulators disagree:

| Verilator | Icarus | CXXRTL | Verdict                        |
|-----------|--------|--------|--------------------------------|
| ✓         | ✓      | ✗      | Verilator+Icarus likely correct|
| ✓         | ✗      | ✓      | Verilator+CXXRTL likely correct|
| ✗         | ✓      | ✓      | Icarus+CXXRTL likely correct   |
| ✗         | ✗      | ✗      | Unclear - manual investigation |

## Command-Line Options

### Required Arguments

```bash
flattened_lib          # Path to flattened wrapper modules
--rtl-dir DIR          # Path to base (unflattened) modules
--incdir DIR           # Include directories (use twice: flattened + unflattened)
```

### Triple Simulator Options

```bash
--yosys PATH           # Custom Yosys binary path
--yosys-optional       # Fall back to dual sim if CXXRTL unavailable
--cxxrtl-flags FLAGS   # Custom flags for CXXRTL
```

### Fuzzing Options

```bash
--max-cycles N         # Number of fuzzing cycles (0 = infinite)
--mutations-per-cycle N # Mutations per cycle before simulating
--outdir DIR           # Output directory
--tb-cycles N          # Simulation cycles per testbench
```

### Simulator Flags

```bash
--verilator-flags FLAGS  # E.g., "--trace -Wno-TIMESCALEMOD"
--icarus-flags FLAGS     # E.g., "-g2012"
```

## Output Structure

```
runs_triple/
├── cycle_0000/
│   ├── top.sv              # Generated DUT
│   ├── tb_top.sv           # Testbench
│   ├── sim.log             # Verilator output
│   ├── icarus_sim.log      # Icarus output
│   ├── cxxrtl_build/
│   │   ├── design.cpp      # CXXRTL generated C++
│   │   ├── wrapper.cpp     # Testbench in C++
│   │   ├── cxxrtl_sim      # Compiled binary
│   │   └── cxxrtl_sim.log  # CXXRTL output
│   └── summary.json        # Cycle results + arbitration
├── cycle_0001/
│   └── ...
├── bugs/
│   └── tribug_<seed>_<timestamp>/
│       ├── bug_report.json  # Detailed disagreement analysis
│       ├── top.sv
│       ├── tb_top.sv
│       └── all simulator logs
└── bug_summary.json        # Overall statistics
```

## Example: Finding Simulator Bugs

When simulators disagree, the system generates detailed bug reports:

```json
{
  "arbitration": {
    "verdict": "verilator_icarus likely correct",
    "verilator_icarus_agreement": "98.5%",
    "cxxrtl_differs_at_cycles": [5, 12, 89],
    "likely_bug_in": "cxxrtl",
    "confidence": "high"
  }
}
```

## Important Notes

### Wrapper File Requirements

Wrapper files **must not** contain `include` statements. All modules are passed explicitly:

**❌ Bad (will cause duplicate declarations):**
```systemverilog
`include "adder.sv"
module adder_wrapper (...);
```

**✅ Good:**
```systemverilog
module adder_wrapper (...);
  // No include statement
  adder u_adder(...);  // Module passed via --incdir
endmodule
```

### Include Directories

Always specify **both** directories:
```bash
--incdir path/to/flattened/ --incdir path/to/unflattened/
```

The system needs:
- Flattened directory: For wrapper modules
- Unflattened directory: For base modules

## Performance

| Simulator     | Synthesis | Compile | Run      | Total    |
|---------------|-----------|---------|----------|----------|
| Verilator     | -         | ~1s     | ~1ms     | ~1s      |
| Icarus        | -         | ~1s     | ~1ms     | ~1s      |
| CXXRTL        | ~2-3s     | ~0.1s   | ~1ms     | ~2-3s    |

**Note:** CXXRTL is slower but provides independent validation.

## Troubleshooting

### "Cannot find module"

**Problem:** Verilator reports missing modules  
**Solution:** Add both directories to `--incdir`:
```bash
--incdir flattened/ --incdir unflattened/
```

### "Duplicate module declaration"

**Problem:** Modules defined twice  
**Solution:** Remove `include` statements from wrapper files

### "CXXRTL simulation failed"

**Problem:** CXXRTL build/run error  
**Solution:** Check `cxxrtl_yosys.err` and `cxxrtl_compile.err` in cycle directory

### "Agreement rate: 0%"

**Problem:** Timing mismatch  
**Solution:** This should be fixed now. If you see this, report it as a bug.

## Files Modified

### Core Implementation
- `rewiring/scripts/tri_simulator.py` - Triple comparison & CXXRTL runner
- `rewiring/scripts/tri_fuzz_and_sim_loop.py` - Fuzzing loop with arbitration
- `rewiring/scripts/dual_simulator.py` - Updated log parser for CXXRTL format

### Test Infrastructure
- `test_libraries/basic_tests/flattened/*.sv` - Removed `include` statements
- `rewiring/examples/simple_tri_sim.py` - Fixed function names

## Test Status

✅ **TESTED AND WORKING** (November 2025)

All three simulators produce **identical outputs** across all test cycles.

See `TRIPLE_SIMULATOR_TEST_REPORT.md` for detailed test results.

## References

- **Yosys CXXRTL Documentation**: https://yosyshq.readthedocs.io/projects/yosys/en/latest/cmd/write_cxxrtl.html
- **Tom Verbeure's Tutorial**: https://tomverbeure.github.io/2020/08/08/CXXRTL-the-New-Yosys-Simulation-Backend.html
- **Original Dual Simulator**: `rewiring/README.md`

---

**For detailed implementation notes, see `YOSYS_CXXRTL_IMPLEMENTATION.md`**

