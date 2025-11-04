# Understanding the Two Seeds

## The Two Seeds Explained

### Seed 1: **Fuzzer Seed** (Master Seed)
- **Command line:** `--seed 42`
- **Purpose:** Controls the **fuzzing mutations**
- **Used for:** Generating random mutation decisions
- **Scope:** Entire fuzzing campaign
- **Default:** Random if not specified

**Example:**
```bash
python tri_fuzz_and_sim_loop.py ... --seed 42
```

This initializes:
```python
rng = random.Random(args.seed)  # Master RNG for fuzzing
```

### Seed 2: **Testbench Seed** (Per-Cycle Seed)
- **Generated:** Automatically for each cycle
- **Purpose:** Controls **simulation input randomization**
- **Used for:** Generating random test inputs
- **Scope:** Single cycle (reset each cycle)
- **Generation:** Derived from fuzzer RNG

**Generated per cycle:**
```python
seed = rng.randrange(0, 2**32)  # Unique seed for this cycle
fr.reset_state(seed=seed)       # Reset fuzzer state with new seed
# This seed is passed to testbench
```

**In testbench:**
```systemverilog
int seed;
if (!$value$plusargs("seed=%d", seed)) seed = 2746317213;
rng_state = seed;  // Initialize testbench RNG
```

## How They Work Together

```
Fuzzer Seed (--seed 42)
    ↓
    Initializes Master RNG
    ↓
┌───────────────────────────────────┐
│  Cycle 0                          │
│  - Generate TB seed: 2746317213   │ ← From master RNG
│  - Use for: mutation decisions    │
│  - Pass to TB for input generation│
└───────────────────────────────────┘
    ↓
┌───────────────────────────────────┐
│  Cycle 1                          │
│  - Generate TB seed: 1181241943   │ ← From master RNG  
│  - Use for: mutation decisions    │
│  - Pass to TB for input generation│
└───────────────────────────────────┘
    ↓
    And so on...
```

## Why Two Seeds?

### 1. Reproducibility
With `--seed 42`, you get:
- **Same mutation sequence** every run
- **Same testbench seeds** for each cycle
- **Fully deterministic** test campaign

### 2. Independence
- **Fuzzer seed** → Controls which wires get rewired
- **TB seed** → Controls what input values are tested
- **Separate** → Mutation decisions don't affect input randomization

## Example

**Command:**
```bash
python tri_fuzz_and_sim_loop.py ... --seed 0
```

**Execution:**
```
Master seed: 0
  ├─ Cycle 0: TB seed = 3280387012 (from RNG(0))
  │   - Mutations: wire A→B, C→D
  │   - TB inputs: 0x5874a9, 0x56eb3a, ...
  │
  ├─ Cycle 1: TB seed = 1095513148 (from RNG(0))
  │   - Mutations: wire X→Y, Z→W  
  │   - TB inputs: 0x4ba0ad, 0xd4cc18, ...
  │
  └─ Cycle 2: TB seed = 1930549411 (from RNG(0))
      - Mutations: wire P→Q
      - TB inputs: 0x6db6d2, 0x6e6fa6, ...
```

**If you run again with --seed 0:**
- ✅ Exact same mutations
- ✅ Exact same TB seeds
- ✅ Exact same results

## Finding Seeds in Logs

**Fuzzer seed (master):**
```bash
grep "seed=" your_run.log | head -1
# Or check command line arguments
```

**Testbench seed (per-cycle):**
```bash
grep "Reloading state.*seed=" your_run.log
# Output: [Reset] Reloading state ... with seed=2746317213
```

**In bug reports:**
```json
{
  "seed": 2746317213,  ← This is the TB seed for this specific cycle
  ...
}
```

## Summary

| Seed | Type | Purpose | Scope | Reproducibility |
|------|------|---------|-------|-----------------|
| **Fuzzer Seed** | Master | Mutation decisions | Entire campaign | Full campaign |
| **TB Seed** | Derived | Input generation | Single cycle | Per-cycle |

**Both are needed for full deterministic fuzzing!**

---

**Key Insight:** The fuzzer seed controls the STRUCTURE (mutations), while TB seeds control the DATA (test inputs).
