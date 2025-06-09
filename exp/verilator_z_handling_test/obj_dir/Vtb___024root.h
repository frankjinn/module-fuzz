// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*5:0*/ tb__DOT__in_flat;
    CData/*2:0*/ tb__DOT__dut__DOT__adder_wrapper_out_flat;
    CData/*3:0*/ tb__DOT__dut__DOT__multiplier_wrapper_in_flat;
    CData/*4:0*/ tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__data_out;
    CData/*3:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__multiplier_wrapper_in_flat__0;
    CData/*0:0*/ __VstlDidInit;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*3:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__multiplier_wrapper_in_flat__1;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
