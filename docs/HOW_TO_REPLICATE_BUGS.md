# How to Replicate Bugs from Bug Reports

## 🎯 Two Methods to Replicate Bugs

### Method 1: Use Preserved Files (EASIEST)

Every bug report directory contains **complete, standalone test files**:

```bash
bugs/tribug_<seed>_<timestamp>/
├── bug_report.json       # Detailed analysis
├── summary.txt           # Human-readable summary
├── top.sv                # ✅ The exact mutated design
├── tb_top.sv             # ✅ The exact testbench
├── sim.log               # Verilator results
├── icarus_sim.log        # Icarus results
├── cxxrtl_build/
│   └── cxxrtl_sim.log    # CXXRTL results
└── *.vcd                 # Waveforms
```

**Steps:**

```bash
# 1. Navigate to bug directory
cd bugs/tribug_2746317213_1762219525/

# 2. Run Verilator directly
verilator --binary -sv --top-module tb_top \
  ../../test_libraries/comprehensive_tests/flattened/*.sv \
  ../../test_libraries/comprehensive_tests/unflattened/*.sv \
  top.sv tb_top.sv \
  --trace

# 3. Run simulation
./obj_dir/Vtb_top

# 4. Check output
cat sim.log
```

**Advantage:** No need to remember seeds - everything is preserved!

---

### Method 2: Reproduce from Seed (EXACT REPLICATION)

If you want to regenerate the bug from scratch:

**Step 1: Extract information from bug report**

```bash
# Get the seed and cycle number
cat bugs/tribug_XXXX/bug_report.json | python3 -c "
import json, sys
b = json.load(sys.stdin)
print(f'Seed: {b[\"seed\"]}')
print(f'Cycle: {b[\"cycle_info\"][\"cycle_number\"]}')
"
```

**Output example:**
```
Seed: 2746317213
Cycle: 0
```

**Step 2: Determine master seed**

You need the **original --seed** you used when running the test. This is:
- In your command history, OR
- Calculate backwards (not recommended)

**If you don't know the master seed:**
→ Use Method 1 (preserved files) instead!

**Step 3: Rerun to that cycle**

```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/comprehensive_tests/flattened/ \
  --rtl-dir ../test_libraries/comprehensive_tests/unflattened/ \
  --incdir ../test_libraries/comprehensive_tests/flattened/ \
  --incdir ../test_libraries/comprehensive_tests/unflattened/ \
  --seed 42 \                      # ← Original master seed
  --max-cycles 1 \                  # ← Stop at cycle with bug (cycle 0 = 1 cycle)
  --mutations-per-cycle 100 \
  --tb-cycles 100 \
  --outdir bug_replication
```

**The cycle number in the bug report corresponds to `--max-cycles N+1`:**
- Bug in cycle 0 → `--max-cycles 1`
- Bug in cycle 5 → `--max-cycles 6`
- Bug in cycle 23 → `--max-cycles 24`

---

## Method Comparison

| Aspect | Method 1: Preserved Files | Method 2: From Seed |
|--------|--------------------------|---------------------|
| **Difficulty** | ⭐ Easy | ⭐⭐⭐ Hard |
| **Requirements** | Bug directory | Master seed + cycle# |
| **Speed** | ⚡ Fast (direct simulation) | 🐌 Slow (regenerate) |
| **Use Case** | Debug specific bug | Reproduce campaign |

**Recommendation: Use Method 1 (preserved files) for 99% of cases!**

---

## Example Walkthrough: Method 1

### Scenario: Found Bug in Cycle 7

**Step 1: Find the bug**
```bash
cd rewiring
ls bugs/
# Output: tribug_1234567890_1762219525/
```

**Step 2: Examine bug report**
```bash
cd bugs/tribug_1234567890_1762219525/

# Read human-friendly summary
cat summary.txt

# Or JSON for programmatic access
cat bug_report.json | python3 -m json.tool | less
```

**Step 3: Check the mutated design**
```bash
# The bug is in this exact design:
head -50 top.sv

# With this exact testbench:
head -50 tb_top.sv
```

**Step 4: Compare simulator outputs**
```bash
# See what Verilator produced
head -10 sim.log

# See what Icarus produced  
head -10 icarus_sim.log

# See what CXXRTL produced
head -10 cxxrtl_build/cxxrtl_sim.log
```

**Step 5: View waveforms (if needed)**
```bash
# If you have GTKWave:
gtkwave tb_top.vcd

# Or examine VCD as text:
head -100 tb_top.vcd
```

**Step 6: Simulate again (if needed)**
```bash
# The exact testbench is preserved, just run it:
iverilog -g2012 -o test.vvp \
  ../../test_libraries/comprehensive_tests/unflattened/*.sv \
  ../../test_libraries/comprehensive_tests/flattened/*.sv \
  top.sv tb_top.sv

vvp test.vvp > my_icarus_output.log

# Compare with original
diff icarus_sim.log my_icarus_output.log
# → Should be identical!
```

---

## Example Walkthrough: Method 2

### Scenario: Reproduce Bug from Cycle 7 with Master Seed

**What you need:**
1. Original master seed (e.g., --seed 42)
2. Cycle number (e.g., 7)

**Command:**
```bash
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/comprehensive_tests/flattened/ \
  --rtl-dir ../test_libraries/comprehensive_tests/unflattened/ \
  --incdir ../test_libraries/comprehensive_tests/flattened/ \
  --incdir ../test_libraries/comprehensive_tests/unflattened/ \
  --seed 42 \
  --max-cycles 8 \        # Cycle 7 = stop after 8 cycles (0-7)
  --mutations-per-cycle 100 \
  --tb-cycles 100 \
  --outdir bug_reproduction

# Then check:
cd bug_reproduction/cycle_0007
diff top.sv ../../bugs/tribug_XXXX/top.sv
# → Should be identical!
```

---

## Quick Reference Card

```
╔═══════════════════════════════════════════════════════════╗
║  BUG REPLICATION QUICK REFERENCE                          ║
╚═══════════════════════════════════════════════════════════╝

EASY WAY (Recommended):
───────────────────────
  cd bugs/tribug_XXXX/
  cat summary.txt          # Read what happened
  head top.sv              # See the design
  iverilog ... top.sv tb_top.sv  # Re-simulate

EXACT REPRODUCTION:
───────────────────
  1. Get master seed from your original command
  2. Get cycle number from bug_report.json
  3. Rerun: --seed <master> --max-cycles <cycle+1>
  4. Compare: diff new_cycle/top.sv bugs/tribug_XX/top.sv

FILES IN BUG REPORT:
────────────────────
  ✅ top.sv        - Exact mutated design
  ✅ tb_top.sv     - Exact testbench with seed
  ✅ *.log         - All simulator outputs
  ✅ *.vcd         - Waveforms
  ✅ summary.txt   - What disagrees
  ✅ bug_report.json - Full analysis
  
EVERYTHING YOU NEED IS PRESERVED! 🎯
```

---

## Advanced: Debugging the Bug

Once you've replicated the bug:

### 1. Identify the Problematic Module

```bash
# Bug report tells you which modules are instantiated
cat bug_report.json | python3 -c "
import json, sys
b = json.load(sys.stdin)
print('Modules in this design:')
for m in b['location_info']['modules_instantiated']:
    print(f'  - {m[\"module_type\"]}')
"
```

### 2. Find Where Simulators Disagree

```bash
# Summary.txt shows visual diffs
cat summary.txt

# Or extract from JSON:
cat bug_report.json | python3 -c "
import json, sys
b = json.load(sys.stdin)
for diff in b['differences'][:3]:  # First 3 differences
    print(f\"Cycle {diff['cycle']}:\")
    if 'visual_diffs' in diff:
        vd = diff['visual_diffs']['verilator_vs_icarus']
        for line in vd['formatted_lines']:
            print(f'  {line}')
    print()
"
```

### 3. Narrow Down the Issue

```bash
# Modify top.sv to isolate modules
# Re-run simulation
# Bisect to find problematic module
```

---

## Summary

**To replicate a bug:**

✅ **EASY:** Use preserved files in `bugs/tribug_XXXX/`  
✅ **EXACT:** Rerun with same master seed to cycle N  
✅ **DEBUG:** Use preserved design + waveforms  

**Everything is saved for you - no guesswork needed!** 🎯

