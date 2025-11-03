#!/usr/bin/env python3
"""
Simple example demonstrating triple simulator comparison with arbitration.

This example shows how to use the tri_simulator module to run Verilator, 
Icarus Verilog, and CXXRTL on the same testbench and use CXXRTL to 
arbitrate when the other two disagree.
"""

import sys
from pathlib import Path

# Add the scripts directory to the path
scripts_dir = Path(__file__).parent.parent / "scripts"
sys.path.insert(0, str(scripts_dir))

import tri_simulator


def run_simple_tri_sim_example():
    """
    Run a simple triple simulator comparison example.
    """
    print("=" * 70)
    print("Triple Simulator Comparison Example")
    print("=" * 70)
    
    # Check if simulators are available
    print("\n[1] Checking for available simulators...")
    
    # Check Verilator
    try:
        from dual_simulator import run_verilator_binary
        print("  ✓ Verilator found")
    except Exception as e:
        print(f"  ✗ Verilator not found: {e}")
        return 1
    
    # Check Icarus Verilog
    try:
        from dual_simulator import resolve_icarus
        iverilog_bin = resolve_icarus(None)
        print(f"  ✓ Icarus Verilog found at: {iverilog_bin}")
    except Exception as e:
        print(f"  ✗ Icarus Verilog not found: {e}")
        return 1
    
    # Check CXXRTL
    try:
        vlog_bin, vsim_bin = tri_simulator.resolve_cxxrtl(None)
        print(f"  ✓ CXXRTL found at: vlog={vlog_bin}, vsim={vsim_bin}")
        has_cxxrtl = True
    except SystemExit:
        print(f"  ✗ CXXRTL not found - will use dual comparison only")
        has_cxxrtl = False
    
    # Example usage
    print("\n[2] Example Usage:")
    print("\nTo run triple simulator fuzzing from the rewiring directory:")
    print("\n  cd /path/to/module-fuzz/rewiring")
    print("  python scripts/tri_fuzz_and_sim_loop.py \\")
    print("    ../test_libraries/basic_tests/flattened/ \\")
    print("    --rtl-dir ../test_libraries/basic_tests/unflattened/ \\")
    print("    --outdir runs_tri \\")
    print("    --max-cycles 10 \\")
    print("    --mutations-per-cycle 20")
    
    if not has_cxxrtl:
        print("\n  Note: Add --cxxrtl-optional flag to run dual simulation")
        print("        when CXXRTL is not available")
    
    print("\n[3] Key Features:")
    print("  • Three-way comparison: Verilator, Icarus, CXXRTL")
    print("  • Automatic arbitration when simulators disagree")
    print("  • Majority voting to determine likely correct result")
    print("  • Enhanced bug reports with ground truth information")
    print("  • Falls back to dual comparison if CXXRTL unavailable")
    
    print("\n[4] Arbitration Logic:")
    print("  • If 2 out of 3 simulators agree → they are likely correct")
    print("  • If all 3 disagree → marked as unclear")
    print("  • Arbitration results saved in bug reports")
    
    print("\n[5] Example Output:")
    print("  [TriSim] Running Verilator simulation...")
    print("  [TriSim] Running Icarus Verilog simulation...")
    print("  [TriSim] Running CXXRTL simulation...")
    print("  [TriSim] BUG FOUND! Simulators produced different results")
    print("  [TriSim] Agreement rate: 95.50%")
    print("  [TriSim] Arbitration verdict: icarus_cxxrtl is likely correct")
    
    print("\n" + "=" * 70)
    print("Example complete!")
    print("=" * 70)
    
    return 0


if __name__ == "__main__":
    sys.exit(run_simple_tri_sim_example())

