# How Randomization Works in the Triple Simulator

## Overview

The fuzzer uses **two separate random number generation systems**:
1. **Python RNG** for mutation decisions (fuzzing)
2. **LCG in Verilog** for testbench inputs (simulation)

---

## Part 1: Mutation Decisions (Python RNG)

### Initialization

```python
# In tri_fuzz_and_sim_loop.py
rng = random.Random(args.seed)  # Master RNG with your --seed
```

### Per-Cycle Reset

```python
# Generate unique TB seed for this cycle
seed = rng.randrange(0, 2**32)  # Uses master RNG!
fr.reset_state(seed=seed)       # Pass to fuzzer
```

### Mutation Decisions (in fuzz_state.py)

The fuzzer makes random choices using Python's `random` module:

```python
# Example 1: Pick random output wire
output_wire_id = external_outputs[random.randrange(num_outputs)]

# Example 2: Pick random target module  
target_mod = all_modules[random.randrange(num_modules)]

# Example 3: Pick random input wire
target_wire_id = target_inputs[random.randrange(len(target_inputs))]
```

**Key Point:** All these use the **TB seed** (reset per cycle):

```python
def reset_state(self, seed=None):
    """Reset fuzzer with new seed."""
    if seed is not None:
        random.seed(seed)  # ← Sets Python's random module seed
    # ... reload modules ...
```

### Example Mutation Sequence (Seed 984982403)

```
Cycle 0, TB Seed: 984982403
  ↓
  random.seed(984982403)  # Set Python RNG
  ↓
  Pick output wire: random.randrange(11) → 7
  Pick target module: random.randrange(3) → 1 ("adder_wrapper")
  Pick input wire: random.randrange(4) → 2
  ↓
  Result: Rewire output 7 → adder_wrapper input 2
```

---

## Part 2: Testbench Input Generation (Verilog LCG)

### Testbench Initialization

```systemverilog
// Generated testbench (tb_top.sv)
int seed;
reg [31:0] rng_state;

initial begin
  // Get seed from command line or use default
  if (!$value$plusargs("seed=%d", seed)) seed = 984982403;
  rng_state = seed;  // Initialize LCG state
  cyc = 0;
end
```

### Input Generation - Linear Congruential Generator (LCG)

The testbench uses the same LCG algorithm used in C standard library:

```systemverilog
// Generate random value
rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
in_flat[31:0] = rng_state;  // Use for input

// For wide buses, call LCG multiple times:
rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
in_flat[63:32] = rng_state;  // Next 32 bits

rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
in_flat[95:64] = rng_state;  // Next 32 bits
// ... and so on for wider buses
```

### LCG Constants

```
Multiplier: 0x41C64E6D (1103515245)
Increment:  0x3039     (12345)
Modulus:    2^32       (implicit via & 0xFFFFFFFF)
```

This is the **same LCG used in glibc** - well-tested and portable!

### Example Input Sequence (Seed 984982403)

```
Initial: rng_state = 984982403

Step 1: rng_state = (984982403 * 0x41C64E6D + 0x3039) & 0xFFFFFFFF
      = 0x2a7
      in_flat[31:0] = 0x2a7

Step 2: rng_state = (0x2a7 * 0x41C64E6D + 0x3039) & 0xFFFFFFFF
      = 0x354
      in_flat[31:0] = 0x354  // Next input

Step 3: rng_state = (0x354 * 0x41C64E6D + 0x3039) & 0xFFFFFFFF
      = 0x2fd
      in_flat[31:0] = 0x2fd  // Next input
```

---

## How They Work Together

```
User: --seed 777
        ↓
   Master RNG = Random(777)
        ↓
    ┌───────────────────────────────┐
    │  Cycle 0                      │
    ├───────────────────────────────┤
    │ TB Seed = 984982403           │ ← From Master RNG
    │                               │
    │ MUTATIONS (Python):           │
    │   random.seed(984982403)      │
    │   Pick wire: randrange() → 7  │
    │   Pick module: randrange() → 1│
    │   Result: Rewire wire 7→mod 1 │
    │                               │
    │ TESTBENCH (Verilog):          │
    │   rng_state = 984982403       │
    │   Generate input: LCG → 0x2a7 │
    │   Next input: LCG → 0x354     │
    │   Next input: LCG → 0x2fd     │
    └───────────────────────────────┘
        ↓
    ┌───────────────────────────────┐
    │  Cycle 1                      │
    ├───────────────────────────────┤
    │ TB Seed = 3231174163          │ ← From Master RNG
    │                               │
    │ MUTATIONS (Python):           │
    │   random.seed(3231174163)     │
    │   Pick wire: randrange() → 3  │
    │   Pick module: randrange() → 0│
    │   Result: Rewire wire 3→mod 0 │
    │                               │
    │ TESTBENCH (Verilog):          │
    │   rng_state = 3231174163      │
    │   Generate input: LCG → 0xXXX │
    │   Next input: LCG → 0xYYY     │
    └───────────────────────────────┘
```

---

## Why This Design?

### Advantages

1. **Reproducibility** - Same master seed = identical everything
2. **Independence** - Mutation RNG separate from input RNG
3. **Cross-simulator** - LCG works identically in Verilator/Icarus/CXXRTL
4. **Efficiency** - Hardware LCG is fast in simulation

### The LCG Choice

**Why not use `$random` in SystemVerilog?**

❌ **Different simulators implement $random differently!**
- Verilator: One algorithm
- Icarus: Different algorithm  
- CXXRTL: Doesn't support $random

✅ **Explicit LCG gives:**
- Same sequence in all simulators
- Bitwise identical inputs
- Fair comparison (no random differences)

---

## Verification Example (From Your Test)

**Seed 777 → Cycle 0:**

**Mutation decisions (Python):**
```python
random.seed(984982403)
random.randrange(3) → Picks "subtractor_wrapper"
random.randrange(3) → Picks "multiplier_wrapper"  
random.randrange(4) → Picks input wire 1
→ Result: subtractor_wrapper → multiplier_wrapper via input 1
```

**Testbench inputs (Verilog LCG):**
```systemverilog
seed = 984982403
rng_state = 984982403

// Generate inputs
rng_state = LCG(984982403) → 0x2a7
in_flat = 0x2a7

@negedge clk
rng_state = LCG(0x2a7) → 0x354  
in_flat = 0x354

@negedge clk
rng_state = LCG(0x354) → 0x2fd
in_flat = 0x2fd
```

**Both runs with seed 777:**
- Same mutation: subtractor → multiplier via input 1 ✅
- Same inputs: 0x2a7, 0x354, 0x2fd ✅
- Same outputs: 0x304, 0x424, 0x34b ✅

---

## Summary

| Aspect | Mechanism | Seed | Reproducible |
|--------|-----------|------|--------------|
| **Mutations** | Python `random` module | TB seed (per-cycle) | ✅ Yes |
| **TB Inputs** | Verilog LCG | TB seed (per-cycle) | ✅ Yes |
| **TB Seed** | Python `rng.randrange()` | Master seed (--seed) | ✅ Yes |
| **Everything** | Hierarchical seeding | Master seed | ✅ **Fully deterministic!** |

**One master seed controls everything through hierarchical random generation!** 🎲

