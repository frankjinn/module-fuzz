# Comprehensive Test Library

Automatically generated from coverage_library (consts, numbers, widths).

## Contents

**25 working modules** covering:
- **Const operations:** 9 modules
- **Number operations:** 7 modules  
- **Width operations:** 9 modules

## Module List

### Const Operations (9)
- const_arith
- const_compare
- const_concat_repl
- const_conditional
- const_logic
- const_nested
- const_partselect
- const_reduce
- const_shift

### Number Operations (7)
- arithmetic_reduce
- bitwise_logic
- bitwise_reduce
- logical_op
- relational
- select
- shift
- numbers_concat_repl (renamed to avoid conflict)

### Width Operations (9)
- array
- cast
- conditional
- partselect
- width_enum (renamed from enum)
- width_logic (renamed from logic)
- width_struct (renamed from struct)
- width_union (renamed from union)
- concat_repl (from widths/)

## Excluded Modules (5)

**Parametrized (not supported by wrapper generator):**
- arith (has #(parameter W_A, W_B))
- arithmetic (has parameters)
- param (has parameters)

**Synthesis Issues:**
- constant (no inputs - generates invalid [-1:0] bus)
- reduce_case (uses tristate 'zzzz' not supported by Verilator)

## Usage

```bash
cd /opt/module-fuzz/rewiring

python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/comprehensive_tests/flattened/ \
  --rtl-dir ../test_libraries/comprehensive_tests/unflattened/ \
  --incdir ../test_libraries/comprehensive_tests/flattened/ \
  --incdir ../test_libraries/comprehensive_tests/unflattened/ \
  --verilator-flags "--trace -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-PINMISSING" \
  --max-cycles 50
```

## Test Results

Initial 5-cycle test:
- ✅ All 3 simulators ran successfully
- ✅ Wide bus support working (up to 412 bits)
- Bugs found: 4/5 cycles had X-value related differences (expected)

Generated: November 4, 2025
