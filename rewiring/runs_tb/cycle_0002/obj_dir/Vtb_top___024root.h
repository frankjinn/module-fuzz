// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_top.h for the primary calling header

#ifndef VERILATED_VTB_TOP___024ROOT_H_
#define VERILATED_VTB_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_top__DOT__clk;
    CData/*7:0*/ tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c;
    CData/*7:0*/ tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c;
    CData/*3:0*/ tb_top__DOT__dut__DOT__u_const_logic_wrapper__DOT__and_c;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_top__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat;
    VlWide<5>/*153:0*/ tb_top__DOT__in_flat;
    IData/*31:0*/ tb_top__DOT__cyc;
    IData/*31:0*/ tb_top__DOT__cycles;
    IData/*31:0*/ tb_top__DOT__seed;
    IData/*31:0*/ tb_top__DOT__i;
    IData/*31:0*/ tb_top__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_top__DOT__unnamedblk2__DOT__j;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h1586d63e__0;
    VlTriggerScheduler __VtrigSched_h1586d57f__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_top___024root(Vtb_top__Syms* symsp, const char* v__name);
    ~Vtb_top___024root();
    VL_UNCOPYABLE(Vtb_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
