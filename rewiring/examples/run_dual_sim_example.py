#!/usr/bin/env python3
"""
Simple example script demonstrating dual simulator functionality.

This script runs a basic dual simulator comparison between Verilator and Icarus Verilog
using the test module library. It compares the outputs of both simulators to detect
discrepancies that could indicate bugs in either simulator.

What this does:
1. Generates random module interconnections (fuzzing)
2. Creates SystemVerilog testbenches with deterministic random inputs
3. Runs the same testbench on both Verilator and Icarus Verilog
4. Compares outputs cycle-by-cycle to find differences
5. Reports any simulator discrepancies as potential bugs
"""

import sys
import os
from pathlib import Path

# Add scripts directory to path
script_dir = Path(__file__).parent.parent / "scripts"
sys.path.insert(0, str(script_dir))

def run_dual_sim_example():
    """Run a simple dual simulator example with predefined settings."""
    
    print("🔧 Dual Simulator Example")
    print("=" * 50)
    
    # Set up paths
    base_dir = Path(__file__).parent.parent
    flattened_lib = base_dir / "modules" / "test_library_structured" / "flattened"
    unflattened_lib = base_dir / "modules" / "test_library_structured" / "unflattened"
    output_dir = base_dir / "examples" / "dual_sim_example_output"
    
    # Check if required directories exist
    if not flattened_lib.exists():
        print(f"❌ Error: Module library not found at {flattened_lib}")
        return 1
    
    print(f"📁 Module library: {flattened_lib}")
    print(f"📁 Output directory: {output_dir}")
    print(f"🎯 Running 3 cycles with 20 mutations each")
    print()
    
    # Import and run the dual simulator
    try:
        os.chdir(script_dir)
        
        # Run the dual simulator with safe parameters
        cmd = [
            sys.executable, "dual_fuzz_and_sim_loop.py",
            str(flattened_lib),
            "-o", str(output_dir),
            "-c", "3",                    # 3 cycles
            "--tb-cycles", "50",          # 50 testbench cycles
            "--mutations-per-cycle", "20", # 20 mutations per cycle
            "--rtl-dir", str(flattened_lib),    # Required: wrapper modules
            "--incdir", str(unflattened_lib),   # Required: original modules
            "--verilator", "/opt/verilator/bin/verilator",
            "--icarus", "/opt/iverilog/bin/iverilog"
            # Note: Verilator flags now include proper warning suppression by default
        ]
        
        import subprocess
        result = subprocess.run(cmd, capture_output=False, text=True)
        
        if result.returncode == 0:
            print("\n✅ Dual simulator example completed successfully!")
            if output_dir.exists():
                print(f"📊 Results saved to: {output_dir}")
                
                # Check for bug reports
                bugs_dir = output_dir / "bugs"
                if bugs_dir.exists() and list(bugs_dir.iterdir()):
                    print("🐛 Bug reports found! Check the bugs directory.")
                else:
                    print("✅ No simulator discrepancies found.")
        else:
            print(f"\n❌ Dual simulator example failed with return code {result.returncode}")
            return result.returncode
            
    except Exception as e:
        print(f"❌ Error running dual simulator: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit_code = run_dual_sim_example()
    sys.exit(exit_code)
