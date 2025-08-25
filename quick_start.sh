#!/bin/bash
# Quick Start Script for Module Fuzzing System
# This script demonstrates the complete workflow from LLM files to fuzzing tests

set -e  # Exit on any error

echo "🚀 Module Fuzzing System - Quick Start"
echo "======================================"
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to show usage
show_usage() {
    echo "Usage: $0 [OPTION]"
    echo ""
    echo "Options:"
    echo "  --llm-workflow     Run full LLM preprocessing workflow (default)"
    echo "  --use-prebuilt     Use existing pre-built test libraries"
    echo "  --help             Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0                 # Run full LLM workflow"
    echo "  $0 --use-prebuilt  # Use pre-built test libraries"
    echo ""
}

# Parse command line arguments
USE_PREBUILT=false
while [[ $# -gt 0 ]]; do
    case $1 in
        --use-prebuilt)
            USE_PREBUILT=true
            shift
            ;;
        --help|-h)
            show_usage
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
done

# Check prerequisites
check_prerequisites() {
    print_status "Checking prerequisites..."
    
    # Check Python
    if command -v python3 &> /dev/null; then
        PYTHON_VERSION=$(python3 --version | cut -d' ' -f2)
        print_success "Python3 found: $PYTHON_VERSION"
    else
        print_error "Python3 not found. Please install Python 3.8+"
        exit 1
    fi
    
    # Check Verilator
    if command -v verilator &> /dev/null; then
        VERILATOR_VERSION=$(verilator --version | head -n1)
        print_success "Verilator found: $VERILATOR_VERSION"
    else
        print_warning "Verilator not found. Please install Verilator:"
        echo "  Ubuntu/Debian: sudo apt-get install verilator"
        echo "  macOS: brew install verilator"
        echo "  Or build from source: https://github.com/verilator/verilator"
        exit 1
    fi
    
    print_success "All prerequisites satisfied!"
    echo ""
}

# Create sample LLM file if none exists
create_sample_llm_file() {
    if [ ! -f "llm_preprocess/sample_llm_modules.sv" ]; then
        print_status "Creating sample LLM-generated modules file..."
        
        cat > "llm_preprocess/sample_llm_modules.sv" << 'EOF'
// Sample LLM-generated SystemVerilog modules
// This file demonstrates the expected format for LLM-generated test files

// Simple arithmetic module
module const_arith (
    input wire [7:0] a,
    input wire [7:0] b,
    input wire [2:0] op,
    output wire [7:0] result
);
    always_comb begin
        case (op)
            3'b000: result = a + b;
            3'b001: result = a - b;
            3'b010: result = a * b;
            3'b011: result = a / b;
            3'b100: result = a % b;
            default: result = 8'h00;
        endcase
    end
endmodule

// Logic operations module
module const_logic (
    input wire [3:0] in1,
    input wire [3:0] in2,
    input wire [1:0] op,
    output wire [3:0] out
);
    always_comb begin
        case (op)
            2'b00: out = in1 & in2;
            2'b01: out = in1 | in2;
            2'b10: out = in1 ^ in2;
            2'b11: out = ~in1;
        endcase
    end
endmodule

// Comparison module
module const_compare (
    input wire [7:0] a,
    input wire [7:0] b,
    output wire [2:0] result
);
    always_comb begin
        if (a > b)
            result = 3'b001;
        else if (a < b)
            result = 3'b010;
        else
            result = 3'b100;
    end
endmodule
EOF
        
        print_success "Sample LLM file created: llm_preprocess/sample_llm_modules.sv"
    else
        print_status "Sample LLM file already exists"
    fi
    echo ""
}

# Step 1: Process LLM files
step1_process_llm() {
    print_status "Step 1: Processing LLM-generated files..."
    
    cd llm_preprocess
    
    # Create output directory
    mkdir -p module_library
    
    # Process the sample file
    if [ -f "sample_llm_modules.sv" ]; then
        print_status "Splitting multi-module file into individual modules..."
        python3 llm_to_sv.py sample_llm_modules.sv -o module_library -t sample
        
        if [ $? -eq 0 ]; then
            print_success "Modules split successfully"
            ls -la module_library/
        else
            print_error "Failed to split modules"
            exit 1
        fi
    else
        print_warning "No sample LLM file found. Please add your LLM-generated .sv files to llm_preprocess/"
    fi
    
    cd ..
    echo ""
}

# Step 2: Generate wrapper modules
step2_generate_wrappers() {
    print_status "Step 2: Generating flattened wrapper modules..."
    print_warning "⚠️  This step is CRITICAL - the fuzzing system cannot work without wrapper modules!"
    
    cd llm_preprocess
    
    # Create output directory
    mkdir -p ../coverage_library_IO_flattened
    
    # Generate wrappers
    print_status "Running generate_wrappers.py..."
    python3 generate_wrappers.py module_library/ ../coverage_library_IO_flattened/
    
    if [ $? -eq 0 ]; then
        print_success "Wrapper modules generated successfully"
        print_success "✅ The fuzzing system can now manipulate module connections!"
        ls -la ../coverage_library_IO_flattened/
    else
        print_error "Failed to generate wrapper modules"
        print_error "❌ The fuzzing system will NOT work without wrapper modules!"
        exit 1
    fi
    
    cd ..
    echo ""
}

# Step 3: Organize test library
step3_organize_library() {
    print_status "Step 3: Organizing test library structure..."
    
    # Create test library structure
    mkdir -p test_library_structured/{flattened,unflattened}
    
    # Copy wrapper modules (for fuzzing)
    if [ -d "coverage_library_IO_flattened" ] && [ "$(ls -A coverage_library_IO_flattened)" ]; then
        cp coverage_library_IO_flattened/*.sv test_library_structured/flattened/
        print_success "Wrapper modules copied to test_library_structured/flattened/"
    fi
    
    # Copy base modules (for includes)
    if [ -d "llm_preprocess/module_library" ] && [ "$(ls -A llm_preprocess/module_library)" ]; then
        cp llm_preprocess/module_library/*.sv test_library_structured/unflattened/
        print_success "Base modules copied to test_library_structured/unflattened/"
    fi
    
    print_success "Test library structure created:"
    tree test_library_structured/ || ls -la test_library_structured/
    echo ""
}

# Alternative Step 3: Use pre-built test library
step3_use_prebuilt() {
    print_status "Step 3: Using pre-built test library..."
    
    # Check available pre-built libraries
    if [ -d "test_libraries" ]; then
        print_status "Available pre-built test libraries:"
        ls -la test_libraries/
        echo ""
        
        # Use const_tests by default (most comprehensive)
        if [ -d "test_libraries/const_tests" ]; then
            print_status "Using const_tests library (comprehensive constant operations)..."
            cp -r test_libraries/const_tests test_library_structured/
            print_success "Pre-built test library copied to test_library_structured/"
        elif [ -d "test_libraries/basic_tests" ]; then
            print_status "Using basic_tests library (simple arithmetic operations)..."
            cp -r test_libraries/basic_tests test_library_structured/
            print_success "Pre-built test library copied to test_library_structured/"
        else
            print_error "No pre-built test libraries found in test_libraries/"
            exit 1
        fi
        
        print_success "Test library structure created:"
        tree test_library_structured/ || ls -la test_library_structured/
        echo ""
    else
        print_error "test_libraries directory not found. Please ensure the project structure is correct."
        exit 1
    fi
}

# Step 4: Run fuzzing test
step4_run_fuzzing() {
    print_status "Step 4: Running fuzzing test..."
    
    cd rewiring
    
    # Check if test library exists
    if [ ! -d "../test_library_structured/flattened" ] || [ ! "$(ls -A ../test_library_structured/flattened)" ]; then
        print_error "Test library not found or empty. Please complete steps 1-3 first."
        exit 1
    fi
    
    # Run a quick test using absolute paths (working configuration)
    print_status "Running quick validation test (1 cycle, 3 mutations)..."
    python3 fuzz_and_sim_loop.py \
        /opt/module-fuzz/rewiring/test_library_structured/flattened \
        -o /opt/module-fuzz/rewiring/output/quick_test_run \
        -t top \
        -m 3 \
        -c 1 \
        --tb-cycles 5 \
        --tb-clk-period 2 \
        --tb-hold-reset 2 \
        --incdir /opt/module-fuzz/rewiring/test_library_structured/unflattened/ \
        --incdir /opt/module-fuzz/rewiring/test_library_structured/flattened/ \
        --verilator-flags="--timescale 1ns/1ps --Wno-WIDTHTRUNC --Wno-MODDUP"
    
    if [ $? -eq 0 ]; then
        print_success "Quick test completed successfully!"
        print_status "Results saved to: /opt/module-fuzz/rewiring/output/quick_test_run"
    else
        print_error "Quick test failed. Check the output above for errors."
        print_status "This is normal for the first run - the system is testing error handling."
        print_status "Check the error logs for details: /opt/module-fuzz/rewiring/output/quick_test_run/cycle_0000/error_log.json"
    fi
    
    cd ..
    echo ""
}

# Main execution
main() {
    if [ "$USE_PREBUILT" = true ]; then
        echo "This script will use pre-built test libraries for a quick start."
        echo "It will skip the LLM preprocessing steps and go directly to fuzzing."
        echo ""
        
        # Check prerequisites
        check_prerequisites
        
        # Use pre-built test library
        step3_use_prebuilt
        
        # Run fuzzing test
        step4_run_fuzzing
    else
        echo "This script will guide you through the complete Module Fuzzing System workflow."
        echo "It will create sample files and demonstrate each step."
        echo ""
        
        # Check prerequisites
        check_prerequisites
        
        # Create sample LLM file
        create_sample_llm_file
        
        # Execute workflow steps
        step1_process_llm
        step2_generate_wrappers
        step3_organize_library
        step4_run_fuzzing
    fi
    
    # Final summary
    echo "🎉 Quick Start Complete!"
    echo "========================"
    echo ""
    
    if [ "$USE_PREBUILT" = true ]; then
        echo "What was created:"
        echo "  • Pre-built test library: test_library_structured/"
        echo "  • Test results: /opt/module-fuzz/rewiring/output/quick_test_run"
        echo ""
        echo "Next steps:"
        echo "  1. Explore the generated test results"
        echo "  2. Run larger tests with more cycles and mutations"
        echo "  3. Try different test libraries: basic_tests, const_tests"
        echo "  4. Customize test parameters and Verilator flags"
    else
        echo "What was created:"
        echo "  • Sample LLM modules: llm_preprocess/sample_llm_modules.sv"
        echo "  • Individual modules: llm_preprocess/module_library/"
        echo "  • Wrapper modules: coverage_library_IO_flattened/"
        echo "  • Test library: test_library_structured/"
        echo "  • Test results: /opt/module-fuzz/rewiring/output/quick_test_run"
        echo ""
        echo "Next steps:"
        echo "  1. Replace sample_llm_modules.sv with your actual LLM-generated files"
        echo "  2. Re-run this script or execute steps manually"
        echo "  3. Run larger tests with: python3 rewiring/fuzz_and_sim_loop.py ..."
        echo "  4. Or use pre-built libraries: $0 --use-prebuilt"
        echo ""
        echo "⚠️  Remember: Wrapper generation (Step 2) is ESSENTIAL for fuzzing to work!"
    fi
    
    echo ""
    echo "For detailed usage, see README.md"
    echo ""
}

# Run main function
main "$@"
