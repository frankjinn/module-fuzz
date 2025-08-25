# Module Fuzzing System

A comprehensive hardware verification system that automatically generates, mutates, and tests SystemVerilog modules using advanced fuzzing techniques and Verilator simulation.

## 🚀 Overview

This system takes LLM-generated SystemVerilog test files and transforms them into a structured test library for automated fuzzing. It generates wrapper modules, creates comprehensive testbenches, and runs extensive mutation-based testing to verify hardware designs.

## 📁 Project Structure

```
module-fuzz/
├── llm_preprocess/           # LLM file processing and wrapper generation
│   ├── llm_to_sv.py         # Split multi-module files into individual files
│   ├── generate_wrappers.py  # Generate flattened wrapper modules
│   └── module_library/       # Processed LLM-generated modules
├── test_libraries/           # Pre-built test libraries for quick start
│   ├── basic_tests/          # Basic arithmetic operations (adder, multiplier, subtractor)
│   │   ├── flattened/        # Wrapper modules
│   │   └── unflattened/      # Base modules
│   └── const_tests/          # Constant operations (logic, arithmetic, comparison)
│       ├── flattened/        # Wrapper modules
│       └── unflattened/      # Base modules
├── coverage_library/          # Generated coverage library modules
├── coverage_library_IO_flattened/  # Flattened wrapper modules
├── test_library_structured/   # Final structured test library
│   ├── flattened/            # Wrapper modules for fuzzing
│   └── unflattened/          # Base modules for includes
├── rewiring/                 # Core fuzzing engine
│   ├── fuzz_state.py         # Core fuzzing logic and state management
│   ├── fuzz_and_sim_loop.py  # Main fuzzing and simulation loop
│   ├── IO_map.py             # I/O port mapping utilities
│   ├── output/               # Dedicated test results folder (gitignored)
│   └── test_library_structured/  # Test library for fuzzing
└── Archive/                  # Archived test results
```

## 🔄 Complete Workflow

### **Option 1: Full LLM Processing Workflow**
**Step 1: Upload LLM-Generated Test Files**

Place your LLM-generated SystemVerilog files in the `llm_preprocess/` directory. These files should contain one or more module definitions.

**Example LLM-generated file:**
```systemverilog
// Arithmetic operations module
module const_arith (
    input wire [7:0] a,
    input wire [7:0] b,
    input wire [2:0] op,
    output wire [7:0] result
);
    // ... module implementation
endmodule

// Logic operations module  
module const_logic (
    input wire [3:0] in1,
    input wire [3:0] in2,
    output wire [3:0] out
);
    // ... module implementation
endmodule
```

**Step 2: Generate Individual Module Files**

Use `llm_to_sv.py` to split multi-module files into individual files:

```bash
cd llm_preprocess
python3 llm_to_sv.py your_llm_file.sv -o module_library -t llm
```

**Options:**
- `-o, --output-dir`: Output directory (default: `modules_out`)
- `-t, --tag`: Optional filename prefix to avoid conflicts

**Result:** Each module gets its own `.sv` file in the `module_library/` directory.

**Step 3: Generate Flattened Wrapper Modules**

Use `generate_wrappers.py` to create flattened wrapper modules:

```bash
python3 generate_wrappers.py module_library/ coverage_library_IO_flattened/
```

**What this does:**
- Scans all `.sv` files in the input directory
- Parses port declarations (inputs/outputs)
- Generates wrapper modules that:
  - Concatenate all inputs into a single `in_flat` bus
  - Concatenate all outputs into a single `out_flat` bus
  - Automatically include the original module file
  - Wire the flattened buses to individual ports

**Example generated wrapper:**
```systemverilog
`include "const_arith.sv"

module const_arith_wrapper (
    input wire [18:0] in_flat,    // All inputs concatenated
    output wire [7:0] out_flat    // All outputs concatenated
);
    // Extract individual inputs
    wire [7:0] a = in_flat[17:10];
    wire [7:0] b = in_flat[9:2];
    wire [2:0] op = in_flat[1:0];
    
    // Instantiate original module
    const_arith inst (
        .a(a), .b(b), .op(op), .result(result)
    );
    
    // Concatenate outputs
    assign out_flat = result;
endmodule
```

**⚠️ CRITICAL: Wrapper generation is ESSENTIAL for the fuzzing system to work!**
The `generate_wrappers.py` script creates the standardized I/O interfaces that enable the fuzzer to manipulate module connections. **Never skip this step.**

**Step 4: Organize Test Library Structure**

Create the final test library structure:

```bash
mkdir -p test_library_structured/{flattened,unflattened}

# Copy wrapper modules (for fuzzing)
cp coverage_library_IO_flattened/*.sv test_library_structured/flattened/

# Copy base modules (for includes)
cp module_library/*.sv test_library_structured/unflattened/
```

**Final structure:**
```
test_library_structured/
├── flattened/           # Wrapper modules used by fuzzer
│   ├── const_arith_wrapper.sv
│   ├── const_logic_wrapper.sv
│   └── ...
└── unflattened/        # Base modules for include directives
    ├── const_arith.sv
    ├── const_logic.sv
    └── ...
```

### **Option 2: Quick Start with Pre-built Test Libraries**

**Skip the LLM processing steps and use existing test libraries:**

```bash
# Copy a pre-built test library
cp -r test_libraries/const_tests test_library_structured/

# Or copy basic tests
cp -r test_libraries/basic_tests test_library_structured/
```

**Available pre-built libraries:**
- **`basic_tests/`**: Simple arithmetic operations (adder, multiplier, subtractor)
- **`const_tests/`**: Comprehensive constant operations (logic, arithmetic, comparison, etc.)

### **Step 5: Run Fuzzing Tests**

**⚠️ IMPORTANT: Use absolute paths when running from the rewiring folder**

```bash
cd rewiring

# Working configuration (use absolute paths)
python3 fuzz_and_sim_loop.py \
    /opt/module-fuzz/rewiring/test_library_structured/flattened \
    -o /opt/module-fuzz/rewiring/output/runs_tb \
    -t top \
    -m 10 \
    -k 5 \
    -c 5 \
    --tb-cycles 20 \
    --tb-clk-period 2 \
    --tb-hold-reset 2 \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/ \
    --verilator-flags="--timescale 1ns/1ps --Wno-WIDTHTRUNC --Wno-MODDUP"
```

**❌ Common Mistake (Relative Paths):**
```bash
# This will NOT work from rewiring folder
python3 fuzz_and_sim_loop.py test_library_structured/flattened -o output/runs_tb ...
```

**✅ Correct Approach (Absolute Paths):**
```bash
# This WILL work from rewiring folder
python3 fuzz_and_sim_loop.py /opt/module-fuzz/rewiring/test_library_structured/flattened -o /opt/module-fuzz/rewiring/output/runs_tb ...
```

## 🎯 Fuzzing Engine Features

### **Core Capabilities**
- **Linear Rewiring**: Sequential module connections and mutations
- **Cyclical Rewiring**: Creates and resolves combinational loops
- **Automatic Register Insertion**: Breaks combinational loops with registers
- **Consistency Checking**: Validates internal data structures after mutations
- **Error Tolerance**: Continues running despite individual cycle failures

### **Mutation Strategies**
- **Linear Rewiring**: Sequential module connections and mutations
- **Cyclical Rewiring**: Creates and resolves combinational loops
- **Tree Merging**: Combines module trees for complex topologies
- **Depth Changes**: **Result from mutations**, not a separate strategy - occurs when mutations alter module hierarchy relationships

### **Simulation & Verification**
- **Verilator Integration**: Automatic SystemVerilog compilation and simulation
- **Testbench Generation**: Creates comprehensive testbenches with randomized inputs
- **Coverage Tracking**: Monitors mutation success rates and consistency
- **Detailed Logging**: Per-cycle logs, error summaries, and performance metrics

## 📊 Command Line Options

### **Basic Parameters**
- `flattened_lib`: Path to flattened wrapper modules (use absolute paths)
- `-o, --outdir`: Output directory for test results (use absolute paths)
- `-t, --top-name`: Name of the generated top module
- `-m, --mutations-per-cycle`: Maximum mutations per fuzzing cycle
- `-k, --check-every`: Run consistency checks every N mutations
- `-c, --max-cycles`: Number of fuzzing cycles to run

### **Testbench Configuration**
- `--tb-cycles`: Number of simulation cycles per testbench
- `--tb-clk-period`: Clock period for simulation
- `--tb-hold-reset`: Reset assertion length in cycles

### **Verilator Options**
- `--verilator`: Custom path to Verilator binary
- `--verilator-flags`: Additional Verilator compilation flags
- `--incdir`: Include directories for module resolution (use absolute paths)
- `--rtl-dir`: Additional RTL source directories

### **Advanced Options**
- `--seed`: Base seed for reproducible results
- `--quiet`: Reduce console output
- `--rtl-recursive`: Recursively search RTL directories

## 🔧 Prerequisites

### **Required Software**
- **Python 3.8+**: Core scripting and automation
- **Verilator**: SystemVerilog compilation and simulation
- **Git**: Version control (optional but recommended)

### **System Requirements**
- **Memory**: 4GB+ RAM for large test runs
- **Storage**: 10GB+ free space for test results
- **OS**: Linux, macOS, or Windows with WSL

### **Installation**
```bash
# Install Verilator
# Ubuntu/Debian
sudo apt-get install verilator

# macOS
brew install verilator

# Or build from source
git clone https://github.com/verilator/verilator
cd verilator
autoconf
./configure
make
sudo make install
```

## 📈 Example Test Runs

### **Quick Start with Pre-built Library**
```bash
# Copy existing test library
cp -r test_libraries/const_tests test_library_structured/

# Run fuzzing test
cd rewiring
python3 fuzz_and_sim_loop.py \
    /opt/module-fuzz/rewiring/test_library_structured/flattened \
    -o /opt/module-fuzz/rewiring/output/quick_test \
    -t top \
    -m 5 \
    -c 2 \
    --tb-cycles 10 \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/ \
    --verilator-flags="--timescale 1ns/1ps --Wno-WIDTHTRUNC --Wno-MODDUP"
```

### **Quick Validation Test**
```bash
# Test with 5 cycles, 10 mutations each
python3 fuzz_and_sim_loop.py \
    /opt/module-fuzz/rewiring/test_library_structured/flattened \
    -o /opt/module-fuzz/rewiring/output/test_run \
    -t top \
    -m 10 \
    -c 5 \
    --tb-cycles 10 \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/
```

### **Comprehensive Test Run**
```bash
# Large-scale test: 50 cycles, 100 mutations each
python3 fuzz_and_sim_loop.py \
    /opt/module-fuzz/rewiring/test_library_structured/flattened \
    -o /opt/module-fuzz/rewiring/output/comprehensive_test \
    -t top \
    -m 100 \
    -c 50 \
    --tb-cycles 20 \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/ \
    --verilator-flags="--trace --timescale 1ns/1ps --Wno-WIDTHTRUNC --Wno-MODDUP"
```

### **Debug/Development Mode**
```bash
# Single cycle with detailed output
python3 fuzz_and_sim_loop.py \
    /opt/module-fuzz/rewiring/test_library_structured/flattened \
    -o /opt/module-fuzz/rewiring/output/debug_run \
    -t top \
    -m 5 \
    -c 1 \
    --tb-cycles 5 \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/
```

## 📋 Output Structure

### **Dedicated Output Folder**
All test results are automatically saved to the dedicated `rewiring/output/` folder, which is gitignored to prevent accidental commits of test data.

### **Per-Cycle Results**
```
rewiring/output/
├── quick_test/              # Quick validation test results
│   └── cycle_0000/
│       ├── top.sv              # Generated top module
│       ├── tb_top.sv           # Generated testbench
│       ├── summary.json        # Cycle results summary
│       └── error_log.json      # Error details (if any)
├── comprehensive_test/       # Large-scale test results
│   ├── cycle_0000/
│   ├── cycle_0001/
│   └── ...
├── debug_run/               # Debug/development test results
│   └── cycle_0000/
└── error_summary.json       # Overall run summary (if errors occur)
```

### **Summary Files**
- **`summary.json`**: Per-cycle mutation counts, build status, simulation results
- **`error_log.json`**: Detailed error information for failed cycles
- **`error_summary.json`**: Overall success/failure statistics

### **Output Folder Management**
- **Automatic Archiving**: Existing output folders are automatically archived with timestamps before new tests
- **Clean Organization**: All test results are organized in the dedicated `rewiring/output/` folder
- **Git Safety**: The output folder is gitignored to prevent accidental commits of test data
- **Easy Cleanup**: Remove all test results with: `rm -rf rewiring/output/*`

## 🚨 Troubleshooting

### **Common Issues**

**Verilator Not Found**
```bash
# Set environment variable
export VERILATOR_ROOT=/path/to/verilator
export PATH=$VERILATOR_ROOT/bin:$PATH

# Or specify path explicitly
--verilator /path/to/verilator
```

**Module Resolution Errors**
```bash
# Ensure include directories are specified with absolute paths
--incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/
--incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/

# Add Verilator flags to suppress warnings
--verilator-flags="--Wno-MODDUP --Wno-WIDTHTRUNC"
```

**Path Resolution Issues**
```bash
# ❌ DON'T use relative paths from rewiring folder
python3 fuzz_and_sim_loop.py test_library_structured/flattened ...

# ✅ DO use absolute paths from rewiring folder
python3 fuzz_and_sim_loop.py /opt/module-fuzz/rewiring/test_library_structured/flattened ...
```

**Permission Errors**
```bash
# Check file permissions
chmod -R 755 test_library_structured/
chmod -R 755 output/
```

### **Debug Mode**
```bash
# Enable verbose output
python3 fuzz_and_sim_loop.py ... --quiet=false

# Check individual components
python3 -c "import fuzz_state; print('Fuzz state OK')"
verilator --version
```

## 🔄 Automation & CI/CD

### **Batch Processing**
```bash
#!/bin/bash
# Process multiple LLM files
for file in llm_preprocess/*.sv; do
    echo "Processing $file..."
    python3 llm_preprocess/llm_to_sv.py "$file" -o modules_out -t $(basename "$file" .sv)
done

# Generate wrappers
python3 llm_preprocess/generate_wrappers.py modules_out/ coverage_library_IO_flattened/

# Run fuzzing tests
cd rewiring
python3 fuzz_and_sim_loop.py \
    /opt/module-fuzz/rewiring/test_library_structured/flattened \
    -o /opt/module-fuzz/rewiring/output/automated_test_run \
    -t top \
    -m 50 \
    -c 10 \
    --tb-cycles 15 \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
    --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/
```

### **Scheduled Testing**
```bash
# Add to crontab for daily testing
0 2 * * * cd /opt/module-fuzz/rewiring && python3 fuzz_and_sim_loop.py /opt/module-fuzz/rewiring/test_library_structured/flattened -o /opt/module-fuzz/rewiring/output/daily_test -t top -m 20 -c 5 --tb-cycles 10 --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/ --verilator-flags="--timescale 1ns/1ps --Wno-WIDTHTRUNC --Wno-MODDUP"
```

## 📚 Advanced Usage

### **Custom Mutation Strategies**
Extend `fuzz_state.py` to add new mutation types:
```python
def custom_mutation_strategy(self):
    # Implement custom mutation logic
    pass
```

### **Custom Testbench Generation**
Modify testbench generation in `fuzz_state.py`:
```python
def generate_custom_testbench(self, **kwargs):
    # Custom testbench logic
    pass
```

### **Integration with Other Tools**
- **Coverage Tools**: Integrate with coverage analysis tools
- **Formal Verification**: Add formal property checking
- **Performance Analysis**: Measure mutation effectiveness

## 🤝 Contributing

1. **Fork** the repository
2. **Create** a feature branch
3. **Implement** your changes
4. **Test** thoroughly with various module types
5. **Submit** a pull request with detailed description

## 🆘 Support

For issues and questions:
1. Check the troubleshooting section above
2. Review existing GitHub issues
3. Create a new issue with detailed error information
4. Include system details, error logs, and reproduction steps

---

**Happy Fuzzing! 🎯✨**
