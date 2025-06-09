// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb__Syms.h"
#include "Vtb___024root.h"

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb__DOT__z_count;
    tb__DOT__z_count = 0;
    IData/*31:0*/ tb__DOT__x_count;
    tb__DOT__x_count = 0;
    IData/*31:0*/ tb__DOT__normal_count;
    tb__DOT__normal_count = 0;
    IData/*31:0*/ tb__DOT__unnamedblk1__DOT__j;
    tb__DOT__unnamedblk1__DOT__j = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"tb.vcd"});
    VL_PRINTF_MT("-Info: tb.sv:30: $dumpvar ignored, as Verilated without --trace\n");
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb.sv", 
                                         33);
    tb__DOT__z_count = 0U;
    tb__DOT__x_count = 0U;
    tb__DOT__normal_count = 0U;
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    co_await vlSelfRef.__VtrigSched_h3f6eaf1d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "tb.sv", 
                                                         41);
    vlSelfRef.tb__DOT__in_flat = (0x1fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         44);
    tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(32, 0x1ddU, tb__DOT__unnamedblk1__DOT__j)) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
        tb__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                        + tb__DOT__unnamedblk1__DOT__j);
    }
    VL_WRITEF_NX("TOTAL_Z_BITS:      %0d\nTOTAL_X_BITS:      %0d\nTOTAL_NORMAL_BITS: %0d\n",0,
                 32,tb__DOT__z_count,32,tb__DOT__x_count,
                 32,tb__DOT__normal_count);
    VL_FINISH_MT("tb.sv", 59, "");
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb.sv", 
                                             26);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b__1)));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat__1)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat__1)));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat__1)));
    vlSelfRef.__VactTriggered.setBit(4U, (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_conditional_wrapper_out_flat__1));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_cast_wrapper_out_flat__1)));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_compare_wrapper_out_flat__1)));
    vlSelfRef.__VactTriggered.setBit(8U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c__1)));
    vlSelfRef.__VactTriggered.setBit(9U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0xaU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_arith_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0xbU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0xcU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0xdU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_logic_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0xeU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0xfU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(0x10U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(0x11U, ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn__0)));
    vlSelfRef.__VactTriggered.setBit(0x12U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(0x13U, ((IData)(vlSelfRef.tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b__1 
        = vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_conditional_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_cast_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_compare_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c__1 
        = vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_arith_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_logic_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__clk__0 
        = vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn__0 
        = vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(0U, 1U);
        vlSelfRef.__VactTriggered.setBit(1U, 1U);
        vlSelfRef.__VactTriggered.setBit(2U, 1U);
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
        vlSelfRef.__VactTriggered.setBit(5U, 1U);
        vlSelfRef.__VactTriggered.setBit(6U, 1U);
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
        vlSelfRef.__VactTriggered.setBit(8U, 1U);
        vlSelfRef.__VactTriggered.setBit(9U, 1U);
        vlSelfRef.__VactTriggered.setBit(0xaU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xbU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xcU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xdU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xeU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xfU, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
