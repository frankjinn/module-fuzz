#!/bin/bash
# Quick Start for module-fuzz Triple Simulator
# Runs a quick 5-cycle test to verify everything works

set -e

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "🚀 module-fuzz Triple Simulator Quick Start"
echo "============================================"
echo ""

# Check if we're in the right directory
if [ ! -d "rewiring" ] || [ ! -d "test_libraries" ]; then
    echo -e "${YELLOW}Error: Please run this from /opt/module-fuzz directory${NC}"
    exit 1
fi

# Check if simulators are available
echo -e "${BLUE}Checking simulators...${NC}"
command -v verilator >/dev/null 2>&1 || { echo "❌ Verilator not found"; exit 1; }
command -v iverilog >/dev/null 2>&1 || { echo "❌ Icarus Verilog not found"; exit 1; }
command -v yosys >/dev/null 2>&1 || { echo "❌ Yosys not found"; exit 1; }

echo "✅ Verilator found"
echo "✅ Icarus Verilog found"
echo "✅ Yosys/CXXRTL found"
echo ""

# Run quick test
echo -e "${BLUE}Running 5-cycle triple simulator test...${NC}"
echo ""

cd rewiring
python3 scripts/tri_fuzz_and_sim_loop.py \
  ../test_libraries/basic_tests/flattened/ \
  --rtl-dir ../test_libraries/basic_tests/unflattened/ \
  --incdir ../test_libraries/basic_tests/flattened/ \
  --incdir ../test_libraries/basic_tests/unflattened/ \
  --verilator-flags "--trace -Wno-TIMESCALEMOD -Wno-WIDTHTRUNC" \
  --outdir quickstart_results \
  --max-cycles 5 \
  --mutations-per-cycle 10

echo ""
echo -e "${GREEN}✅ Quick start complete!${NC}"
echo ""
echo "Results saved to: rewiring/quickstart_results/"
echo ""
echo "Next steps:"
echo "  • Check results: cat rewiring/quickstart_results/bug_summary.json"
echo "  • Run more cycles: Add --max-cycles 100"
echo "  • Read docs: cat docs/README.md"
echo "  • Full guide: docs/TRIPLE_SIMULATOR.md"
echo ""
