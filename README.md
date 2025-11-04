# module-fuzz

Differential fuzzing framework for SystemVerilog modules with multi-simulator validation.

## 📚 Documentation

**All documentation is now in the [`docs/`](docs/) directory.**

**Start here:** [docs/TRIPLE_SIMULATOR.md](docs/TRIPLE_SIMULATOR.md) ⭐

### Quick Links

- [Triple Simulator Guide](docs/TRIPLE_SIMULATOR.md) - **Recommended:** Verilator + Icarus + CXXRTL with arbitration
- [Documentation Index](docs/README.md) - Navigate all docs
- [Workflow Guide](docs/WORKFLOW.md) - Development process
- [Test Report](docs/TRIPLE_SIMULATOR_TEST_REPORT.md) - Verification results

## 🚀 Quick Start (5 minutes)

### Option 1: Docker (Recommended)

```bash
# Build image with all simulators
docker build -t modulefuzz:latest .

# Run container
docker run -it modulefuzz:latest

# Inside container - run triple simulator
cd /opt/module-fuzz/rewiring
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --incdir ../test_libraries/basic_tests/flattened/ \
  --incdir ../test_libraries/basic_tests/unflattened/ \
  --max-cycles 10
```

### Option 2: Quick Start Script

```bash
./quick_start.sh
```

## 🎯 What Does This Do?

**module-fuzz** validates hardware designs by:

1. **Mutating** Verilog designs (rewiring module connections)
2. **Simulating** with multiple independent simulators
3. **Comparing** outputs to find disagreements
4. **Arbitrating** using 2-of-3 voting to identify bugs

### Triple Simulator (NEW! ✨)

Run your design through **three independent simulators**:

- **Verilator** - Fast C++ compiler-based simulator
- **Icarus Verilog** - Traditional event-driven simulator  
- **Yosys CXXRTL** - Cycle-based C++ simulator

When simulators disagree, automatic **majority voting** determines which is likely correct.

## 📊 Features

| Feature | Triple Sim | Dual Sim | Single Sim |
|---------|-----------|----------|------------|
| Simulators | 3 | 2 | 1 |
| Bug Detection | ✅ High confidence | ✅ Medium | ❌ None |
| Arbitration | ✅ 2-of-3 voting | ❌ | ❌ |
| Speed | Slower | Medium | Fast |

## 🏗️ Project Structure

```
module-fuzz/
├── docs/                      # 📚 All documentation here
│   ├── README.md             # Documentation index
│   ├── TRIPLE_SIMULATOR.md   # ⭐ Start here
│   └── ...
│
├── rewiring/                  # Fuzzing engine
│   ├── scripts/
│   │   ├── tri_fuzz_and_sim_loop.py    # Triple simulator
│   │   ├── dual_fuzz_and_sim_loop.py   # Dual simulator
│   │   ├── tri_simulator.py            # Comparison engine
│   │   └── fuzz_state.py               # Mutation engine
│   └── examples/
│       └── simple_tri_sim.py
│
├── test_libraries/           # Test modules
│   └── basic_tests/
│       ├── flattened/        # Wrapper modules
│       └── unflattened/      # Base modules
│
├── dockerfile                # Container with all tools
└── quick_start.sh           # Automated setup
```

## 🔧 Requirements

### Docker (Easiest)
- Docker 20.10+
- 4GB RAM
- 10GB disk space

### Manual Installation
- Python 3.8+
- Verilator 5.0+
- Icarus Verilog 11.0+
- Yosys 0.30+ (for CXXRTL)
- C++ compiler (clang++ or g++)

## 📖 Usage Examples

### Basic Triple Simulation

```bash
cd rewiring
python scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --incdir ../test_libraries/basic_tests/flattened/ \
  --incdir ../test_libraries/basic_tests/unflattened/ \
  --max-cycles 100
```

### With Custom Options

```bash
python scripts/tri_fuzz_and_sim_loop.py \
  path/to/modules/ \
  --rtl-dir path/to/base_modules/ \
  --incdir path/to/modules/ \
  --incdir path/to/base_modules/ \
  --max-cycles 500 \
  --mutations-per-cycle 50 \
  --tb-cycles 1000 \
  --outdir my_results
```

### Fallback to Dual Sim

```bash
# Run with --yosys-optional to fall back if CXXRTL unavailable
python scripts/tri_fuzz_and_sim_loop.py \
  modules/ \
  --yosys-optional \
  --max-cycles 100
```

## 📈 Results

When complete, check:

```bash
# View bug summary
cat runs_triple/bug_summary.json

# Check arbitration results
grep -r "verdict" runs_triple/bugs/

# View cycle summaries
cat runs_triple/cycle_*/summary.json
```

## ✅ Status

**Production Ready** (November 2025)

- ✅ Triple simulator fully functional
- ✅ All three simulators produce identical outputs on test suite
- ✅ Arbitration logic verified
- ✅ Comprehensive documentation

See [docs/TRIPLE_SIMULATOR_TEST_REPORT.md](docs/TRIPLE_SIMULATOR_TEST_REPORT.md) for test results.

## 🤝 Contributing

See [docs/WORKFLOW.md](docs/WORKFLOW.md) for development workflow.

## 📝 License

See LICENSE file for details.

## 🙏 Credits

- **Yosys CXXRTL** - https://github.com/YosysHQ/yosys
- **Verilator** - https://www.veripool.org/verilator/
- **Icarus Verilog** - http://iverilog.icarus.com/

---

**For detailed documentation, visit [`docs/`](docs/) directory** 📚
