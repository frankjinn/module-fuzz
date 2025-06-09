// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb__Syms.h"
#include "Vtb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root___eval_triggers__stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b__0)));
    vlSelfRef.__VstlTriggered.setBit(2U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(3U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(4U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(5U, (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_conditional_wrapper_out_flat__0));
    vlSelfRef.__VstlTriggered.setBit(6U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_cast_wrapper_out_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(7U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(8U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_compare_wrapper_out_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(9U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c__0)));
    vlSelfRef.__VstlTriggered.setBit(0xaU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(0xbU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_arith_wrapper_in_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(0xcU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(0xdU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(0xeU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_logic_wrapper_in_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(0xfU, ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat) 
                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat__0)));
    vlSelfRef.__VstlTriggered.setBit(0x10U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b__0 
        = vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_conditional_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_cast_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_compare_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c__0 
        = vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_arith_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_logic_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat__0 
        = vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
        vlSelfRef.__VstlTriggered.setBit(2U, 1U);
        vlSelfRef.__VstlTriggered.setBit(3U, 1U);
        vlSelfRef.__VstlTriggered.setBit(4U, 1U);
        vlSelfRef.__VstlTriggered.setBit(5U, 1U);
        vlSelfRef.__VstlTriggered.setBit(6U, 1U);
        vlSelfRef.__VstlTriggered.setBit(7U, 1U);
        vlSelfRef.__VstlTriggered.setBit(8U, 1U);
        vlSelfRef.__VstlTriggered.setBit(9U, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xaU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xbU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xcU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xdU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xeU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xfU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0x10U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
