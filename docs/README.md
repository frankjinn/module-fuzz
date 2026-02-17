# module-fuzz Documentation

**Welcome!** All documentation is now in this `docs/` folder.

## 🚀 Quick Start

New to module-fuzz? Start here:

1. **[TRIPLE_SIMULATOR.md](TRIPLE_SIMULATOR.md)** ⭐ - Recommended: 3-way validation (Verilator + Icarus + CXXRTL)
2. **[WORKFLOW.md](WORKFLOW.md)** - Complete development workflow
3. **[TRIPLE_SIMULATOR_TEST_REPORT.md](TRIPLE_SIMULATOR_TEST_REPORT.md)** - Proof it works

## 📚 All Documentation

### Core Guides

| Document | Description | Start Here? |
|----------|-------------|-------------|
| **[TRIPLE_SIMULATOR.md](TRIPLE_SIMULATOR.md)** | Triple simulator guide (Verilator + Icarus + CXXRTL) | ✅ **YES** |
| **[DUAL_SIMULATOR.md](DUAL_SIMULATOR.md)** | Dual simulator guide (Verilator + Icarus) | If CXXRTL unavailable |
| **[WORKFLOW.md](WORKFLOW.md)** | Complete development workflow | For developers |

### Implementation Details

| Document | Description |
|----------|-------------|
| **[YOSYS_CXXRTL_IMPLEMENTATION.md](YOSYS_CXXRTL_IMPLEMENTATION.md)** | How CXXRTL integration works |
| **[TRIPLE_SIMULATOR_TEST_REPORT.md](TRIPLE_SIMULATOR_TEST_REPORT.md)** | Test results and verification |

### Bug Analysis

| Document | Description |
|----------|-------------|
| **[BUG_MINIMIZATION.md](BUG_MINIMIZATION.md)** | Wire-level bug isolation & delta-debugging |

### Advanced Topics

| Document | Description |
|----------|-------------|
| **[coverage_example.md](coverage_example.md)** | Coverage-guided fuzzing |
| **[wire_mutation.ipynb](wire_mutation.ipynb)** | Mutation strategies notebook |

## ⚡ Quick Commands

### Run Triple Simulator (Recommended)

```bash
cd /opt/module-fuzz/rewiring

python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --incdir ../test_libraries/basic_tests/flattened/ \
  --incdir ../test_libraries/basic_tests/unflattened/ \
  --verilator-flags "--trace -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC" \
  --max-cycles 10
```

### Run Dual Simulator

```bash
cd /opt/module-fuzz/rewiring

python scripts/dual_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --max-cycles 10
```

## 🎯 Feature Comparison

| Feature | Single Sim | Dual Sim | Triple Sim |
|---------|-----------|----------|------------|
| **Simulators** | Verilator | Verilator + Icarus | Verilator + Icarus + CXXRTL |
| **Bug Detection** | ❌ No | ✅ Yes | ✅ Yes |
| **Arbitration** | ❌ No | ❌ No | ✅ Yes (2-of-3 voting) |
| **Speed** | ⚡ Fast | 🐢 2x slower | 🐌 3x slower |
| **Confidence** | Low | Medium | **High** |
| **Recommended** | No | Sometimes | ✅ **YES** |

## 📂 File Organization

```
module-fuzz/
├── README.md                              # Project overview
├── quick_start.sh                         # Automated setup
├── dockerfile                             # Container with all tools
│
├── docs/                                  # 📚 ALL DOCUMENTATION HERE
│   ├── README.md                          # This file (navigation)
│   ├── TRIPLE_SIMULATOR.md               # ⭐ Start here
│   ├── TRIPLE_SIMULATOR_TEST_REPORT.md
│   ├── DUAL_SIMULATOR.md
│   ├── WORKFLOW.md
│   ├── YOSYS_CXXRTL_IMPLEMENTATION.md
│   ├── coverage_example.md
│   └── wire_mutation.ipynb
│
├── rewiring/                              # Fuzzing infrastructure
│   ├── scripts/
│   │   ├── tri_fuzz_and_sim_loop.py     # Triple simulator
│   │   ├── dual_fuzz_and_sim_loop.py    # Dual simulator
│   │   ├── tri_simulator.py             # Comparison engine
│   │   ├── minimize_bug.py             # Wire-level bug minimizer
│   │   ├── trace_bit_bundled.py        # Bit dependency tracer
│   │   └── ...
│   └── examples/
│       ├── simple_tri_sim.py
│       └── simple_dual_sim.py
│
├── isolated_bugs/                        # Bug isolation output
│   └── minimized/
│       ├── bug_isolated.sv              # Self-contained isolated bug
│       ├── top_minimal.sv               # Minimized design
│       └── reduction_report.json        # Reduction log
│
└── test_libraries/                       # Test modules
    └── basic_tests/
        ├── flattened/                    # Wrapper modules
        └── unflattened/                  # Base modules
```

## 🔍 What Should I Read?

**I want to...**

- ✅ **Validate my Verilog with 3 simulators** → [TRIPLE_SIMULATOR.md](TRIPLE_SIMULATOR.md)
- 🐛 **Find simulator bugs** → [TRIPLE_SIMULATOR.md](TRIPLE_SIMULATOR.md)
- 🔬 **Isolate & minimize a bug** → [BUG_MINIMIZATION.md](BUG_MINIMIZATION.md)
- 🔧 **Understand the workflow** → [WORKFLOW.md](WORKFLOW.md)
- 📊 **See test results** → [TRIPLE_SIMULATOR_TEST_REPORT.md](TRIPLE_SIMULATOR_TEST_REPORT.md)
- 🛠️ **Learn how CXXRTL works** → [YOSYS_CXXRTL_IMPLEMENTATION.md](YOSYS_CXXRTL_IMPLEMENTATION.md)
- 📈 **Use coverage guidance** → [coverage_example.md](coverage_example.md)

## 🆘 Troubleshooting

Common issues and solutions in [TRIPLE_SIMULATOR.md](TRIPLE_SIMULATOR.md#troubleshooting)

## ✅ Status

**All systems tested and working** (November 2025)

- ✅ Triple simulator fully functional
- ✅ All three simulators produce identical outputs
- ✅ Arbitration logic verified
- ✅ Production ready

## 📞 Getting Help

1. Check the **Troubleshooting** section in [TRIPLE_SIMULATOR.md](TRIPLE_SIMULATOR.md)
2. Look at **examples** in `/opt/module-fuzz/rewiring/examples/`
3. Review **test reports** in [TRIPLE_SIMULATOR_TEST_REPORT.md](TRIPLE_SIMULATOR_TEST_REPORT.md)

---

**Need something else?** The main project README is at `/opt/module-fuzz/README.md`
