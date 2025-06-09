#include "Vtb.h"
#include "verilated.h"
int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  Vtb* tb = new Vtb;
  while (!Verilated::gotFinish()) {
    tb->eval();
  }
  delete tb;
  return 0;
}
