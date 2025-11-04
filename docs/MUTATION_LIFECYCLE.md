# Mutation Lifecycle - Does Each Cycle Start Fresh?

## ✅ YES - Each Cycle Starts from Scratch

## The Reset Process

### Code Evidence (fuzz_state.py, line 1184)

```python
def reset_state(self, seed=None, verbose=True):
    """Reset the fuzzer to its initial, unmutated state."""
    
    # Re-initialize all state from the original file
    self.__init__(self.flattened_lib_path)  # ← Starts from ZERO!
    
    # Set new random seed
    random.seed(seed)
    
    return seed
```

**Key insight:** `__init__()` is called again, completely **reloading from original files**!

---

## Lifecycle of a Fuzzing Campaign

### Structure

```
Master Seed: --seed 777
    ↓
┌──────────────────────────────────────────┐
│  CYCLE 0                                 │
├──────────────────────────────────────────┤
│ 1. reset_state(TB_seed_0)                │
│    └─ Reload from flattened/ ← FRESH!    │
│                                          │
│ 2. Apply mutations (×10)                 │
│    ├─ Mutation 1: A→B                    │
│    ├─ Mutation 2: C→D                    │
│    └─ ...                                │
│                                          │
│ 3. Simulate mutated design               │
│    └─ Result: 0 bugs                     │
└──────────────────────────────────────────┘
    ↓ DISCARD ALL MUTATIONS
┌──────────────────────────────────────────┐
│  CYCLE 1                                 │
├──────────────────────────────────────────┤
│ 1. reset_state(TB_seed_1)                │
│    └─ Reload from flattened/ ← FRESH!    │
│                                          │
│ 2. Apply NEW mutations (×10)             │
│    ├─ Mutation 1: X→Y                    │
│    ├─ Mutation 2: Z→W                    │
│    └─ ...                                │
│                                          │
│ 3. Simulate NEW mutated design           │
│    └─ Result: 0 bugs                     │
└──────────────────────────────────────────┘
    ↓ DISCARD ALL MUTATIONS
┌──────────────────────────────────────────┐
│  CYCLE 2                                 │
├──────────────────────────────────────────┤
│ 1. reset_state(TB_seed_2)                │
│    └─ Reload from flattened/ ← FRESH!    │
│                                          │
│ 2. Apply NEW mutations (×10)             │
│    └─ ...                                │
└──────────────────────────────────────────┘
```

---

## Evidence from Your Test (Seed 777)

### Mutation Counts

```
Cycle 0: mu=2 (2 mutations applied)
Cycle 1: mu=3 (3 mutations applied)  
Cycle 2: mu=2 (2 mutations applied)
Cycle 3: mu=3 (3 mutations applied)
Cycle 4: mu=2 (2 mutations applied)
```

**If mutations accumulated:**
- Cycle 0: 2 mutations
- Cycle 1: 5 mutations (2+3) ← Would keep growing
- Cycle 2: 7 mutations (5+2)

**But they DON'T accumulate - each cycle is independent!**

---

## Why Start Fresh Each Cycle?

### Benefits

1. **Independence** - Each cycle tests a different mutation pattern
2. **Coverage** - Explore diverse design space
3. **Debugging** - Each bug report is self-contained
4. **Reproducibility** - Can reproduce any single cycle

### Drawbacks (and why they don't matter)

❌ "Can't explore compounded mutations"
✅ But: You test 100s of cycles, so you explore many combinations anyway

❌ "Mutations don't build on each other"
✅ But: The goal is to find simulator bugs, not evolve designs

---

## The Full Picture

```
User Command:
  python tri_fuzz_and_sim_loop.py ... --seed 777 --max-cycles 5

Execution:
  Master RNG: Random(777)
  
  Cycle 0:
    TB seed: 984982403 (from master RNG)
    Load: adder_wrapper, multiplier_wrapper, subtractor_wrapper (clean)
    Mutate: 2 rewirings
    Simulate: Test mutations
    Discard: Mutations discarded
  
  Cycle 1:
    TB seed: 3231174163 (from master RNG)
    Load: adder_wrapper, multiplier_wrapper, subtractor_wrapper (clean)
    Mutate: 3 NEW rewirings
    Simulate: Test NEW mutations
    Discard: Mutations discarded
  
  ... and so on
```

---

## Analogy

Think of it like:

**NOT like this (accumulating):**
```
Cycle 0: Clean design → Add mutation A
Cycle 1: Design with A → Add mutation B
Cycle 2: Design with A+B → Add mutation C
```

**ACTUALLY like this (independent):**
```
Cycle 0: Clean design → Add mutations {A, B} → Test → Discard
Cycle 1: Clean design → Add mutations {X, Y, Z} → Test → Discard  
Cycle 2: Clean design → Add mutations {P, Q} → Test → Discard
```

Each cycle is a **fresh experiment**!

---

## Verification

**From your reproducibility test:**

Both runs with seed 777:
- Cycle 0: Started fresh, applied 2 mutations ✅
- Cycle 1: Started fresh, applied 3 mutations ✅
- Cycle 2: Started fresh, applied 2 mutations ✅

**Same seed = Same mutations = Same everything** ✅

---

## Summary

**YES - Each cycle/mutation run starts from NOTHING:**

✅ Reloads original modules from `flattened/`  
✅ Resets all wire connections  
✅ Resets module tree  
✅ Applies fresh mutations  
✅ Tests, then discards everything  

**This is BY DESIGN for maximum exploration and reproducibility!** 🎯

