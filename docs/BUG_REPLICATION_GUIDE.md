# Bug Replication Guide

## ✅ Every Bug Report Now Includes the Original Command!

As of the latest update, all bug reports contain the exact command used to generate them.

## Finding the Command

### In JSON Bug Report

```bash
cat bugs/tribug_XXXX/bug_report.json | python3 -c "
import json, sys
b = json.load(sys.stdin)
print(b['original_command'])
"
```

**Output example:**
```
python scripts/tri_fuzz_and_sim_loop.py ../test_libraries/comprehensive_tests/flattened/ --rtl-dir ../test_libraries/comprehensive_tests/unflattened/ --incdir ../test_libraries/comprehensive_tests/flattened/ --incdir ../test_libraries/comprehensive_tests/unflattened/ --verilator-flags --trace -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-PINMISSING --seed 42 --max-cycles 300 --mutations-per-cycle 100 --tb-cycles 100 --outdir comprehensive_300cycles_100mut
```

## How to Replicate a Bug

### Step 1: Extract Bug Information

```bash
cd bugs/tribug_XXXX/

# Get cycle number and command
python3 << 'EOF'
import json
b = json.load(open('bug_report.json'))
cycle = b['cycle_info']['cycle_number']
cmd = b['original_command']

print(f"Bug found in: Cycle {cycle}")
print(f"\nOriginal command:\n{cmd}")
print(f"\nTo replicate, modify command:")
print(f"  1. Change --max-cycles to {cycle + 1}")
print(f"  2. Keep all other flags the same")
print(f"  3. Output will be in cycle_{cycle:04d}/")
EOF
```

### Step 2: Run Modified Command

```bash
# Copy the original command from bug report
# Modify --max-cycles to stop at the bug cycle

python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/comprehensive_tests/flattened/ \
  --rtl-dir ../test_libraries/comprehensive_tests/unflattened/ \
  --incdir ../test_libraries/comprehensive_tests/flattened/ \
  --incdir ../test_libraries/comprehensive_tests/unflattened/ \
  --verilator-flags "--trace -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-PINMISSING" \
  --seed 42 \                    # ← Same seed
  --max-cycles 53 \              # ← Cycle 52 = max-cycles 53
  --mutations-per-cycle 100 \
  --tb-cycles 100 \
  --outdir bug_replication
```

### Step 3: Verify Replication

```bash
cd bug_replication/cycle_0052  # The cycle with the bug

# Compare generated design
diff top.sv ../../bugs/tribug_XXXX/top.sv
# → Should be IDENTICAL ✅

# Compare simulation outputs  
diff sim.log ../../bugs/tribug_XXXX/sim.log | grep "^[<>]" | grep "CYCLE="
# → Should be IDENTICAL (except timing metadata) ✅
```

---

## Quick Replication Template

Save this as `replicate_bug.sh`:

```bash
#!/bin/bash
# Replicate a specific bug

if [ $# -ne 1 ]; then
    echo "Usage: $0 bugs/tribug_XXXX"
    exit 1
fi

BUG_DIR=$1

# Extract info from bug report
python3 << PYEOF
import json
b = json.load(open('${BUG_DIR}/bug_report.json'))
cycle = b['cycle_info']['cycle_number']
cmd = b['original_command']

print(f"Replicating bug from cycle {cycle}")
print(f"\nRun this command:")
print(f"{cmd}".replace(f"--max-cycles 300", f"--max-cycles {cycle + 1}"))
print(f"\nThen check: <outdir>/cycle_{cycle:04d}/")
PYEOF
```

**Usage:**
```bash
chmod +x replicate_bug.sh
./replicate_bug.sh bugs/tribug_2746317213_1762293187
```

---

## Alternative: Use Preserved Files (Easier!)

You don't even need to replicate - everything is already saved:

```bash
cd bugs/tribug_XXXX/

# All files preserved:
ls -la
# → top.sv, tb_top.sv, sim.log, icarus_sim.log, cxxrtl_sim.log, *.vcd

# Read the summary
cat summary.txt

# Re-simulate if needed
verilator --binary -sv --top-module tb_top \
  +incdir+../../test_libraries/.../flattened \
  +incdir+../../test_libraries/.../unflattened \
  ../../test_libraries/.../flattened/*.sv \
  ../../test_libraries/.../unflattened/*.sv \
  top.sv tb_top.sv

./obj_dir/Vtb_top > my_sim.log
diff my_sim.log sim.log  # Should match!
```

---

## What the Bug Report Contains

```json
{
  "bug_id": "tribug_2746317213_1762293187",
  "original_command": "python scripts/tri_fuzz_and_sim_loop.py ... --seed 42 ...",
  "seed": 2746317213,          // TB seed for this cycle
  "cycle_info": {
    "cycle_number": 0           // This is cycle 0
  },
  "arbitration": {
    "verdict": "verilator_icarus likely correct",
    "likely_bug_in": "cxxrtl"
  },
  "differences": [...]          // Exact disagreements
}
```

**Key fields:**
- `original_command` - Full command to run ✅
- `seed` - Testbench seed (for this specific cycle)
- `cycle_number` - Which cycle had the bug
- Master seed is in `original_command` (--seed flag)

---

## Summary

✅ **Bug reports include original command** (with python prefix)  
✅ **Includes --seed flag** (master seed for full reproducibility)  
✅ **Includes cycle number** (know which cycle to stop at)  
✅ **Includes all files** (top.sv, tb.sv, logs, waveforms)  

**To replicate:** Just modify `--max-cycles` in the saved command! 🎯

