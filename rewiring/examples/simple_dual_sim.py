#!/usr/bin/env python3
"""
Simple dual simulator example with corrected paths.

This demonstrates how to run a dual simulation correctly by ensuring
all module dependencies are properly included.
"""

import os
import sys
from pathlib import Path

# Add scripts directory to path
script_dir = Path(__file__).parent.parent / "scripts"
sys.path.insert(0, str(script_dir))

def main():
    print("🔧 Simple Dual Simulator Example")
    print("=" * 50)
    
    # Set up paths
    base_dir = Path(__file__).parent.parent
    flattened_lib = base_dir / "modules" / "test_library_structured" / "flattened"
    unflattened_lib = base_dir / "modules" / "test_library_structured" / "unflattened"
    output_dir = base_dir / "examples" / "simple_dual_sim_output"
    
    print(f"📁 Flattened modules: {flattened_lib}")
    print(f"📁 Unflattened modules: {unflattened_lib}")
    print(f"📁 Output: {output_dir}")
    print()
    
    # Change to scripts directory for execution
    os.chdir(script_dir)
    
    # Run dual simulation with corrected parameters
    import subprocess
    cmd = [
        sys.executable, "dual_fuzz_and_sim_loop.py",
        str(flattened_lib),
        "-o", str(output_dir),
        "-c", "2",                        # Just 2 cycles for demo
        "--tb-cycles", "30",              # Short simulation
        "--mutations-per-cycle", "10",    # Fewer mutations
        "--rtl-dir", str(flattened_lib),  # Wrapper modules
        "--incdir", str(unflattened_lib), # Original modules
        "--verilator", "/opt/verilator/bin/verilator",
        "--icarus", "/opt/iverilog/bin/iverilog",
        # Note: Improved Verilator flags are now included by default
        "--quiet"                         # Less verbose output
    ]
    
    print("🚀 Running dual simulation...")
    print(f"Command: {' '.join(cmd)}")
    print()
    
    result = subprocess.run(cmd, capture_output=False, text=True)
    
    if result.returncode == 0:
        print("\n✅ Dual simulation completed!")
        
        # Check results
        if output_dir.exists():
            cycles = list(output_dir.glob("cycle_*"))
            bugs_dir = output_dir / "bugs"
            
            print(f"📊 Generated {len(cycles)} test cycles")
            
            if bugs_dir.exists() and list(bugs_dir.iterdir()):
                bug_dirs = list(bugs_dir.iterdir())
                print(f"🐛 Found {len(bug_dirs)} simulator discrepancies!")
                for bug_dir in bug_dirs:
                    print(f"   - {bug_dir.name}")
            else:
                print("✅ No simulator discrepancies found (both simulators agree)")
        
        return 0
    else:
        print(f"\n❌ Dual simulation failed with return code {result.returncode}")
        return result.returncode

if __name__ == "__main__":
    sys.exit(main())
