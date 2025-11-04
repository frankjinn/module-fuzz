# Module Fuzzing - Rewiring Scripts

**📚 All documentation has been moved to `/opt/module-fuzz/docs/`**

## Quick Links

- **[Triple Simulator Guide](../docs/TRIPLE_SIMULATOR.md)** ⭐ Recommended
- **[Dual Simulator Guide](../docs/DUAL_SIMULATOR.md)**
- **[All Documentation](../docs/README.md)**

## Quick Start

```bash
# Triple simulator (Verilator + Icarus + CXXRTL)
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --incdir ../test_libraries/basic_tests/flattened/ \
  --incdir ../test_libraries/basic_tests/unflattened/ \
  --max-cycles 10
```

See full documentation at **[docs/TRIPLE_SIMULATOR.md](../docs/TRIPLE_SIMULATOR.md)**
