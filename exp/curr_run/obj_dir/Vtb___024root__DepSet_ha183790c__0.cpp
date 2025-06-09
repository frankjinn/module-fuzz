// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___act_sequent__TOP__1(Vtb___024root* vlSelf);
void Vtb___024root___act_sequent__TOP__2(Vtb___024root* vlSelf);
void Vtb___024root___act_sequent__TOP__3(Vtb___024root* vlSelf);
void Vtb___024root___act_sequent__TOP__4(Vtb___024root* vlSelf);
void Vtb___024root___act_sequent__TOP__5(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__1(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__2(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__3(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__4(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__5(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__6(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__7(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__8(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__9(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__10(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__11(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__12(Vtb___024root* vlSelf);
void Vtb___024root___act_comb__TOP__13(Vtb___024root* vlSelf);

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x8000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__4(vlSelf);
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__5(vlSelf);
    }
    if ((0x2008ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0x4cc18ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0x4cc38ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__2(vlSelf);
    }
    if ((0x4ee38ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__3(vlSelf);
    }
    if ((0x4fef8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__4(vlSelf);
    }
    if ((0x4ff38ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__5(vlSelf);
    }
    if ((0x4ee78ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__6(vlSelf);
    }
    if ((0x4ff78ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__7(vlSelf);
    }
    if ((0x4ff7cULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__8(vlSelf);
    }
    if ((0x4ff7aULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__9(vlSelf);
    }
    if ((0x4ff7eULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__10(vlSelf);
    }
    if ((0x4ff7bULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__11(vlSelf);
    }
    if ((0x4fffbULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__12(vlSelf);
    }
    if ((0x4ffffULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__13(vlSelf);
    }
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
        = ((0x3fc000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat) 
                         << 0xcU)) | ((0x3fc0U & ((0x3c00U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat) 
                                                      << 4U)) 
                                                  | (0x3c0U 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat)))) 
                                      | (0x3fU & ((0x30U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat) 
                                                      << 4U)) 
                                                  | ((0xcU 
                                                      & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat) 
                                                         << 2U)) 
                                                     | (3U 
                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat)))))));
    vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn 
        = (1U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                 >> 3U));
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
        = (((0x3c000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                         << 0xcU)) | (0x3000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                                                 << 0xcU))) 
           | ((0x3c0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                         << 4U)) | (0x3fU & ((0x30U 
                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                                                 << 4U)) 
                                             | ((0xcU 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat) 
                                                    << 2U)) 
                                                | (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat)))))));
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat 
        = ((0xff00U & ((((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat) 
                         >> 3U) << (7U & (IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat))) 
                       << 8U)) | (0xffU & ((0xffU & 
                                            ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat) 
                                             >> 3U)) 
                                           >> (7U & (IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat)))));
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__3(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__3\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
        = (((0x78000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                          << 9U) & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                    << 0xdU))) | (0x7800U 
                                                  & (((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                      << 5U) 
                                                     | ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                        << 9U)))) 
           | ((0x780U & ((0xffffff80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                         << 1U)) ^ 
                         (0xffffff80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                         << 5U)))) 
              | ((0x78U & ((~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                               >> 6U)) << 3U)) | (((IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat)))) 
                                                   << 2U) 
                                                  | (((IData)(
                                                              (0U 
                                                               != 
                                                               (3U 
                                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat)))) 
                                                      << 1U) 
                                                     | (1U 
                                                        & (~ 
                                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                            >> 1U))))))));
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__4(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__4\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
        = (((0x1f00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                            + ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                               >> 8U)) << 0x14U)) | 
            (0xf8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                          - ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                             >> 8U)) << 0xfU))) | (
                                                   (0x7c00U 
                                                    & (VL_MULS_III(8, 
                                                                   (0xffU 
                                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat)), 
                                                                   (0x1fU 
                                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                                                       >> 8U))) 
                                                       << 0xaU)) 
                                                   | ((((0U 
                                                         != 
                                                         VL_EXTENDS_II(32,8, 
                                                                       (0x1fU 
                                                                        & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                                                           >> 8U))))
                                                         ? 
                                                        (0x1fU 
                                                         & VL_DIVS_III(8, 
                                                                       (0xffU 
                                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat)), 
                                                                       (0x1fU 
                                                                        & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                                                           >> 8U))))
                                                         : 0U) 
                                                       << 5U) 
                                                      | ((0U 
                                                          != 
                                                          VL_EXTENDS_II(32,8, 
                                                                        (0x1fU 
                                                                         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                                                            >> 8U))))
                                                          ? 
                                                         (0x1fU 
                                                          & VL_MODDIV_III(8, 
                                                                          (0xffU 
                                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat)), 
                                                                          (0x1fU 
                                                                           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat) 
                                                                              >> 8U))))
                                                          : 0U))));
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__5(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__5\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
        = (((QData)((IData)((0xffU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                       >> 8U) + (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat))))) 
            << 0x20U) | (QData)((IData)(((((((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                             >> 8U) 
                                            - (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat)) 
                                           << 0x18U) 
                                          | (0xff0000U 
                                             & (((0xffU 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                                     >> 8U)) 
                                                 * 
                                                 (0xffU 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat))) 
                                                << 0x10U))) 
                                         | ((((0U != 
                                               (0xffU 
                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                               ? (0xffU 
                                                  & VL_DIV_III(8, 
                                                               (0xffU 
                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                                                   >> 8U)), 
                                                               (0xffU 
                                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                               : 0U) 
                                             << 8U) 
                                            | ((0U 
                                                != 
                                                (0xffU 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                ? (0xffU 
                                                   & VL_MODDIV_III(8, 
                                                                   (0xffU 
                                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat) 
                                                                       >> 8U)), 
                                                                   (0xffU 
                                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                : 0U))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ tb__DOT__dut__DOT__numbers_logical_op_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_logical_op_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__numbers_logical_op_wrapper_in_flat 
        = ((2U & vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat) 
           | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                    >> 9U)));
    vlSelfRef.tb__DOT__dut__DOT__numbers_logical_op_wrapper_out_flat 
        = (((IData)((3U == (IData)(tb__DOT__dut__DOT__numbers_logical_op_wrapper_in_flat))) 
            << 2U) | (((IData)((0U != (IData)(tb__DOT__dut__DOT__numbers_logical_op_wrapper_in_flat))) 
                       << 1U) | (1U & (~ ((IData)(tb__DOT__dut__DOT__numbers_logical_op_wrapper_in_flat) 
                                          >> 1U)))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*10:0*/ tb__DOT__dut__DOT__const_shift_wrapper_in_flat;
    tb__DOT__dut__DOT__const_shift_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__const_shift_wrapper_in_flat 
        = (0x80U | ((((0x400U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                 << 0xaU)) | ((0x200U 
                                               & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                  << 5U)) 
                                              | (0x100U 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                    >> 6U)))) 
                     | ((0x40U & ((IData)(vlSelfRef.tb__DOT__in_flat) 
                                  << 3U)) | (0x20U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((0x10U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                  >> 0xdU)) | ((8U 
                                                & ((IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                            >> 0x1aU)) 
                                                   << 3U)) 
                                               | (4U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                     << 2U)))) 
                       | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                 >> 6U)) | (1U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                  >> 7U))))));
    vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
        = ((0xff0000U & ((((IData)(tb__DOT__dut__DOT__const_shift_wrapper_in_flat) 
                           >> 3U) << (7U & (IData)(tb__DOT__dut__DOT__const_shift_wrapper_in_flat))) 
                         << 0x10U)) | ((0xff00U & (
                                                   ((0xffU 
                                                     & ((IData)(tb__DOT__dut__DOT__const_shift_wrapper_in_flat) 
                                                        >> 3U)) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(tb__DOT__dut__DOT__const_shift_wrapper_in_flat))) 
                                                   << 8U)) 
                                       | (0xffU & VL_SHIFTRS_III(8,8,3, 
                                                                 (0xffU 
                                                                  & ((IData)(tb__DOT__dut__DOT__const_shift_wrapper_in_flat) 
                                                                     >> 3U)), 
                                                                 (7U 
                                                                  & (IData)(tb__DOT__dut__DOT__const_shift_wrapper_in_flat))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*5:0*/ tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat 
        = (2U | (((0x20U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                            << 2U)) | ((0x10U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                 >> 0xbU)) 
                                       | (8U & ((IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                         >> 0x1cU)) 
                                                << 3U)))) 
                 | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                           >> 6U)) | (1U & (IData)(
                                                   (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                    >> 0x27U))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
        = (((0x3c0000U & ((IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat) 
                          << 0x10U)) | (0x30000U & 
                                        ((IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat) 
                                         << 0x10U))) 
           | ((0x3fc0U & ((0x3c00U & ((IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat) 
                                      << 8U)) | (0x3c0U 
                                                 & ((IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat) 
                                                    << 4U)))) 
              | (0x3fU & ((0x30U & ((IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat) 
                                    << 4U)) | ((0xcU 
                                                & ((IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat) 
                                                   << 2U)) 
                                               | (3U 
                                                  & (IData)(tb__DOT__dut__DOT__numbers_concat_repl_wrapper_in_flat)))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__3(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__3\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ tb__DOT__dut__DOT__const_reduce_wrapper_in_flat;
    tb__DOT__dut__DOT__const_reduce_wrapper_in_flat = 0;
    CData/*7:0*/ tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat = 0;
    SData/*10:0*/ tb__DOT__dut__DOT__widths_shift_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_shift_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__widths_shift_wrapper_in_flat 
        = ((0x400U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2) 
                      << 0xaU)) | ((0x200U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                              << 8U)) 
                                   | ((0x100U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                 << 8U)) 
                                      | (((0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0) 
                                            << 5U)) 
                                          | (0x20U 
                                             & ((IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                         >> 4U)) 
                                                << 5U))) 
                                         | ((0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_logical_op_wrapper_out_flat) 
                                                << 3U)) 
                                            | ((8U 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                   << 3U)) 
                                               | ((2U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                        >> 9U)))))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat 
        = ((0xff00U & ((((IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat) 
                         >> 3U) << (7U & (IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat))) 
                       << 8U)) | (0xffU & ((0xffU & 
                                            ((IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat) 
                                             >> 3U)) 
                                           >> (7U & (IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat)))));
    tb__DOT__dut__DOT__const_reduce_wrapper_in_flat 
        = (4U | ((8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                        >> 1U)) | ((2U & (IData)(vlSelfRef.tb__DOT__in_flat)) 
                                   | (1U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                            >> 4U)))));
    tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat 
        = (4U | ((((0x80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                             << 5U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                 << 5U))) 
                  | ((0x20U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                               >> 5U)) | (0x10U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                   >> 3U)))) 
                 | ((8U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                           << 1U)) | (1U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                            >> 0x13U)))));
    vlSelfRef.tb__DOT__dut__DOT__const_reduce_wrapper_out_flat 
        = ((((0xfU == (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat)) 
             << 5U) | (((0U != (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat)) 
                        << 4U) | (8U & (VL_REDXOR_4(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat) 
                                        << 3U)))) | 
           ((4U & ((~ (0xfU == (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat))) 
                   << 2U)) | ((2U & ((~ (0U != (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat))) 
                                     << 1U)) | (1U 
                                                & (~ 
                                                   VL_REDXOR_4(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat 
        = (((((0xfU & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                       >> 4U)) == (0xfU & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
             << 5U) | ((((0xfU & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                  >> 4U)) != (0xfU 
                                              & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
                        << 4U) | (((0xfU & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                            >> 4U)) 
                                   > (0xfU & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
                                  << 3U))) | (((0xfU 
                                                == 
                                                (0xfU 
                                                 & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                                    >> 4U))) 
                                               << 2U) 
                                              | (((0U 
                                                   != 
                                                   (0xfU 
                                                    & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
                                                  << 1U) 
                                                 | (1U 
                                                    & VL_REDXOR_32(
                                                                   (0xfU 
                                                                    & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                                                       >> 4U)))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__4(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__4\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_in_flat 
        = ((((0x200U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                        >> 0xbU)) | ((0x100U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                << 1U)) 
                                     | (0x80U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                                 >> 7U)))) 
            | ((0x40U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                         >> 3U)) | (0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                             >> 9U)))) 
           | ((0x10U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat) 
                        << 1U)) | ((8U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                   >> 0x1fU)) 
                                          << 3U)) | 
                                   ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                           << 2U)) 
                                    | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                             >> 0xbU))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__5(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__5\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat = 0;
    CData/*0:0*/ tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__eq;
    tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__eq = 0;
    CData/*0:0*/ tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__neq;
    tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__neq = 0;
    // Body
    tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat 
        = ((((0x80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                       >> 5U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                           >> 5U))) 
            | ((0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                         << 4U)) | (0x10U & ((IData)(
                                                     (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                      >> 0x25U)) 
                                             << 4U)))) 
           | (((8U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                      >> 7U)) | (4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                       >> 0xaU))) | 
              ((2U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                               >> 0x17U)) << 1U)) | 
               (1U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                      >> 0x15U)))));
    tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__eq 
        = ((0xfU & ((IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat) 
                    >> 4U)) == (0xfU & (IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat)));
    tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__neq 
        = ((0xfU & ((IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat) 
                    >> 4U)) != (0xfU & (IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat)));
    vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat 
        = (((((IData)(tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__eq) 
              << 7U) | ((IData)(tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__neq) 
                        << 6U)) | ((((0xfU & ((IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat) 
                                              >> 4U)) 
                                     > (0xfU & (IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat))) 
                                    << 5U) | (((0xfU 
                                                & ((IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat) 
                                                   >> 4U)) 
                                               < (0xfU 
                                                  & (IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat))) 
                                              << 4U))) 
           | (((((0xfU & ((IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat) 
                          >> 4U)) >= (0xfU & (IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat))) 
                << 3U) | (((0xfU & ((IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat) 
                                    >> 4U)) <= (0xfU 
                                                & (IData)(tb__DOT__dut__DOT__numbers_relational_wrapper_in_flat))) 
                          << 2U)) | (((IData)(tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__eq) 
                                      << 1U) | (IData)(tb__DOT__dut__DOT__u_numbers_relational_wrapper__DOT__neq))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__6(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__6\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat 
        = (((0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                      << 5U)) | ((0x10U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                           >> 0xdU)) 
                                 | (8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat) 
                                          << 2U)))) 
           | ((4U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                     >> 7U)) | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0) 
                                       << 1U)) | (1U 
                                                  & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                     >> 0xcU)))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__7(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__7\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat = 0;
    SData/*8:0*/ tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat = 0;
    SData/*15:0*/ tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat = 0;
    // Body
    vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat 
        = (0x82U | ((0x400U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                               << 2U)) | ((0x200U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_array_wrapper_out_flat) 
                                            >> 1U)) 
                                          | ((0x40U 
                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                                 << 3U)) 
                                             | (((0x10U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                     << 1U)) 
                                                 | ((8U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                                        << 2U)) 
                                                    | (4U 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2)))) 
                                                | (1U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                      >> 1U)))))));
    tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat 
        = (0x1600U | ((0x4000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                  << 0xcU)) | ((0x100U 
                                                & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                   << 8U)) 
                                               | ((0x80U 
                                                   & ((IData)(
                                                              (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                               >> 0xaU)) 
                                                      << 7U)) 
                                                  | (((0x20U 
                                                       & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                          << 3U)) 
                                                      | ((0x10U 
                                                          & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                             >> 3U)) 
                                                         | (8U 
                                                            & ((IData)(
                                                                       (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                                        >> 0x21U)) 
                                                               << 3U)))) 
                                                     | ((4U 
                                                         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1) 
                                                            >> 1U)) 
                                                        | ((2U 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                               >> 0x15U)) 
                                                           | (1U 
                                                              & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                                 >> 0xcU)))))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
        = ((0xff0000U & (((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                          << 8U) & ((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                                    << 0x10U))) | (
                                                   (0xff00U 
                                                    & ((0xffffff00U 
                                                        & (IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat)) 
                                                       | ((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                                                          << 8U))) 
                                                   | (0xffU 
                                                      & (((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                                                          >> 8U) 
                                                         ^ (IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat)))));
    tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat 
        = (0x6400U | (((0x8000U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                   << 0xaU)) | (0x1000U 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                   << 2U))) 
                      | ((0x800U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                    >> 9U)) | ((0x200U 
                                                & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                   >> 8U)) 
                                               | ((0x100U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                      << 5U)) 
                                                  | ((((0x40U 
                                                        & ((IData)(
                                                                   (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                                    >> 0xdU)) 
                                                           << 6U)) 
                                                       | (0x20U 
                                                          & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                             << 3U))) 
                                                      | ((0x10U 
                                                          & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                             >> 0xfU)) 
                                                         | (8U 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                               >> 1U)))) 
                                                     | ((4U 
                                                         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                            >> 2U)) 
                                                        | ((2U 
                                                            & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                               >> 7U)) 
                                                           | (1U 
                                                              & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                                 >> 0xcU))))))))));
    tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat 
        = (0x140U | (((0x80U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                >> 6U)) | ((0x20U & 
                                            (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                             >> 0xdU)) 
                                           | (0x10U 
                                              & vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat))) 
                     | (((8U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                >> 5U)) | (4U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                 >> 0xbU))) 
                        | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                  >> 4U)) | (1U & (IData)(
                                                          (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                           >> 0x13U)))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat 
        = ((0xff00U & ((IData)(tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat) 
                       << 8U)) | (0xffU & ((IData)(tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat) 
                                           >> 8U)));
    vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z 
        = (0xfU & ((0x100U & (IData)(tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat))
                    ? (7U & ((IData)(tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat) 
                             >> 4U)) : (IData)(tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat)));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__8(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__8\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat 
        = ((((0x800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                        << 0xbU)) | ((0x400U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                >> 7U)) 
                                     | (0x200U & ((IData)(
                                                          (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                           >> 0xbU)) 
                                                  << 9U)))) 
            | ((0x100U & (IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat)) 
               | ((0x80U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                            << 6U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                >> 0x11U))))) 
           | (((0x20U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                         >> 6U)) | ((0x10U & ((IData)(vlSelfRef.tb__DOT__in_flat) 
                                              << 2U)) 
                                    | (8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                             >> 2U)))) 
              | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                        >> 5U)) | ((2U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                          >> 0xeU)) 
                                   | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_array_wrapper_out_flat) 
                                            >> 9U))))));
    vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat 
        = (((((0x8000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z) 
                          << 0xdU)) | (0x4000U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                  << 1U))) 
             | ((0x2000U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                            << 8U)) | (0x1000U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                  >> 8U)))) 
            | (((0x800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                           << 7U)) | (0x400U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                >> 5U))) 
               | ((0x200U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                             << 3U)) | (0x100U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                  >> 6U))))) 
           | ((0x80U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                        >> 9U)) | ((0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                             >> 0xdU)) 
                                   | ((0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0) 
                                                << 3U)) 
                                      | (((8U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                 >> 7U)) 
                                          | (4U & ((IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                            >> 3U)) 
                                                   << 2U))) 
                                         | ((2U & ((IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                            >> 7U)) 
                                                   << 1U)) 
                                            | (1U & 
                                               (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                                >> 0x10U))))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__9(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__9\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a 
        = (((8U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                   >> 0xbU)) | (4U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                      >> 3U))) | ((2U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                                      >> 2U)) 
                                                  | (1U 
                                                     & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                        >> 0x14U))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__10(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__10\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat 
        = (0x221U | ((0x1000U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                          >> 0x26U)) 
                                 << 0xcU)) | ((((0x400U 
                                                 & ((IData)(
                                                            (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                             >> 0x19U)) 
                                                    << 0xaU)) 
                                                | (0x100U 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                      >> 0xaU))) 
                                               | ((0x80U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                                      << 6U)) 
                                                  | (0x40U 
                                                     & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                        << 3U)))) 
                                              | (((0x10U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                                      << 4U)) 
                                                  | ((8U 
                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0)) 
                                                     | (4U 
                                                        & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z) 
                                                           << 1U)))) 
                                                 | (2U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                                       >> 1U))))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__11(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__11\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat = 0;
    // Body
    vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits 
        = ((0xcU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits)) 
           | ((((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a) 
                       >> 1U)) == (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                         >> 1U))) << 1U) 
              | ((1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a)) 
                 == (1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b)))));
    vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits 
        = ((3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits)) 
           | ((((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a) 
                       >> 3U)) == (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                         >> 3U))) << 3U) 
              | (((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a) 
                         >> 2U)) == (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                           >> 2U))) 
                 << 2U)));
    tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat 
        = (4U | ((((0x80U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                             << 1U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                 >> 8U))) 
                  | ((0x20U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                               >> 7U)) | (0x10U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                   >> 7U)))) 
                 | ((8U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                           >> 6U)) | ((2U & ((IData)(vlSelfRef.tb__DOT__in_flat) 
                                             >> 3U)) 
                                      | (0xfU == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_out_flat 
        = (((0xffU == (IData)(tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat)) 
            << 2U) | (((0U != (IData)(tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat)) 
                       << 1U) | (1U & VL_REDXOR_8(tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat))));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__12(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__12\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*19:0*/ tb__DOT__dut__DOT__numbers_select_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_select_wrapper_in_flat = 0;
    CData/*3:0*/ tb__DOT__dut__DOT__widths_enum_mod_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_enum_mod_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__numbers_select_wrapper_in_flat 
        = (0x24U | (((((0x80000U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                    << 4U)) | ((0x40000U 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat) 
                                                   << 0xeU)) 
                                               | (0x20000U 
                                                  & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                     >> 6U)))) 
                      | ((0x10000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_out_flat) 
                                      << 0x10U)) | 
                         (0x8000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                     << 8U)))) | ((
                                                   (0x4000U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat) 
                                                       << 7U)) 
                                                   | ((0x2000U 
                                                       & ((~ 
                                                           (0xfU 
                                                            == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits))) 
                                                          << 0xdU)) 
                                                      | (0x1000U 
                                                         & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                            >> 4U)))) 
                                                  | ((0x800U 
                                                      & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                                         << 0xbU)) 
                                                     | (0x400U 
                                                        & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                           << 7U))))) 
                    | ((0x200U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                  >> 1U)) | ((0x100U 
                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                 << 4U)) 
                                             | ((0x40U 
                                                 & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                    >> 0xbU)) 
                                                | ((8U 
                                                    & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                       >> 5U)) 
                                                   | (1U 
                                                      & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                         >> 9U))))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat 
        = ((0x1e0U & (tb__DOT__dut__DOT__numbers_select_wrapper_in_flat 
                      >> 3U)) | ((0x1eU & ((tb__DOT__dut__DOT__numbers_select_wrapper_in_flat 
                                            >> ((IData)(4U) 
                                                + (0xfU 
                                                   & tb__DOT__dut__DOT__numbers_select_wrapper_in_flat))) 
                                           << 1U)) 
                                 | (0xcU < (0xfU & tb__DOT__dut__DOT__numbers_select_wrapper_in_flat))));
    tb__DOT__dut__DOT__widths_enum_mod_wrapper_in_flat 
        = (1U | (((8U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                         >> 0xcU)) | (4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat) 
                                            << 2U))) 
                 | (2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                          >> 3U))));
    vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat 
        = ((((6U == (IData)(tb__DOT__dut__DOT__widths_enum_mod_wrapper_in_flat))
              ? 1U : 0U) << 1U) | (6U == (IData)(tb__DOT__dut__DOT__widths_enum_mod_wrapper_in_flat)));
}

VL_INLINE_OPT void Vtb___024root___act_comb__TOP__13(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__13\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ tb__DOT__dut__DOT__const_compare_wrapper_in_flat;
    tb__DOT__dut__DOT__const_compare_wrapper_in_flat = 0;
    QData/*33:0*/ tb__DOT__dut__DOT__const_conditional_wrapper_in_flat;
    tb__DOT__dut__DOT__const_conditional_wrapper_in_flat = 0;
    IData/*26:0*/ tb__DOT__dut__DOT__const_nested_wrapper_in_flat;
    tb__DOT__dut__DOT__const_nested_wrapper_in_flat = 0;
    IData/*19:0*/ tb__DOT__dut__DOT__const_partselect_wrapper_in_flat;
    tb__DOT__dut__DOT__const_partselect_wrapper_in_flat = 0;
    CData/*7:0*/ tb__DOT__dut__DOT__const_partselect_wrapper_out_flat;
    tb__DOT__dut__DOT__const_partselect_wrapper_out_flat = 0;
    SData/*15:0*/ tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat = 0;
    SData/*11:0*/ tb__DOT__dut__DOT__widths_cast_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_cast_wrapper_in_flat = 0;
    IData/*18:0*/ tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat = 0;
    CData/*7:0*/ tb__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c;
    tb__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c = 0;
    CData/*7:0*/ tb__DOT__dut__DOT__u_numbers_arithmetic_reduce_wrapper__DOT__complex_expr;
    tb__DOT__dut__DOT__u_numbers_arithmetic_reduce_wrapper__DOT__complex_expr = 0;
    // Body
    vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b 
        = (((8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_out_flat) 
                   << 1U)) | (4U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                    >> 3U))) | ((2U 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                                                    << 1U)) 
                                                | (1U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                                      >> 8U))));
    tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat 
        = (((((0x40000U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                           << 0xbU)) | ((0x20000U & 
                                         ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                          << 6U)) | 
                                        (0x10000U & 
                                         ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                                          << 0xbU)))) 
             | ((0x8000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                            << 0xcU)) | (0x4000U & 
                                         (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                          << 5U)))) 
            | (((0x2000U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                            << 0xdU)) | ((0x1000U & 
                                          ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                           << 7U)) 
                                         | (0x800U 
                                            & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                               >> 1U)))) 
               | ((0x400U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                             << 5U)) | (0x200U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                  << 4U))))) 
           | ((((0x100U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                    >> 8U)) << 8U)) 
                | ((0x80U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                             << 6U)) | (0x40U & vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat))) 
               | ((0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_reduce_wrapper_out_flat) 
                            << 5U)) | (0x10U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                                << 2U)))) 
              | (((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z)) 
                  | (4U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                           >> 2U))) | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                              >> 1U)) 
                                       | (1U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                >> 7U))))));
    tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
        = (((QData)((IData)((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3) 
                                   >> 3U)))) << 0x20U) 
           | (QData)((IData)((0x10000U | ((((((0x80000000U 
                                               & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                                  << 0x1bU)) 
                                              | (0x40000000U 
                                                 & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                                    << 0x10U))) 
                                             | ((0x20000000U 
                                                 & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                    << 0x1bU)) 
                                                | (0x10000000U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3) 
                                                      << 0x1aU)))) 
                                            | (((0x8000000U 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1) 
                                                    << 0x1bU)) 
                                                | (0x4000000U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                      << 0xfU))) 
                                               | ((0x2000000U 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                      << 0xeU)) 
                                                  | (0x1000000U 
                                                     & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                        << 8U))))) 
                                           | ((((0x800000U 
                                                 & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                    << 0x11U)) 
                                                | (0x400000U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z) 
                                                      << 0x16U))) 
                                               | ((0x200000U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                                      << 0x12U)) 
                                                  | (0x100000U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                        << 0x11U)))) 
                                              | (((0x80000U 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                      >> 1U)) 
                                                  | (0x40000U 
                                                     & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                        << 7U))) 
                                                 | (0x20000U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                       << 9U))))) 
                                          | ((((0x8000U 
                                                & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                   >> 1U)) 
                                               | (0x4000U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                                     << 8U))) 
                                              | ((0x2000U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                     << 0xbU)) 
                                                 | (0x1000U 
                                                    & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                       >> 5U)))) 
                                             | ((0x800U 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_reduce_wrapper_out_flat) 
                                                    << 6U)) 
                                                | ((0x400U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                       << 1U)) 
                                                   | ((0x200U 
                                                       & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                          << 8U)) 
                                                      | ((((0x80U 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                               >> 0xdU)) 
                                                           | (0x40U 
                                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                                                                 >> 2U))) 
                                                          | ((0x20U 
                                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat)) 
                                                             | (0x10U 
                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                                                   >> 5U)))) 
                                                         | (((8U 
                                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat)) 
                                                             | (4U 
                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3) 
                                                                   << 2U))) 
                                                            | ((2U 
                                                                & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                                   >> 0x11U)) 
                                                               | (1U 
                                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                                     >> 1U))))))))))))));
    tb__DOT__dut__DOT__const_partselect_wrapper_in_flat 
        = (0x4041aU | (((((0x80000U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                       >> 5U)) | (0x20000U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                                     << 0xcU))) 
                         | ((0x10000U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                  >> 9U)) 
                                         << 0x10U)) 
                            | (0x8000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                                          << 8U)))) 
                        | (((0x4000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT____Vcellout__u_widths_param_wrapper__out_flat) 
                                        << 0xeU)) | 
                            ((0x2000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                         << 7U)) | 
                             (0x1000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                                         << 5U)))) 
                           | (0x800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                        << 8U)))) | 
                       ((0x200U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                            >> 0xfU)) 
                                   << 9U)) | ((0x100U 
                                               & ((IData)(
                                                          (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                           >> 0x16U)) 
                                                  << 8U)) 
                                              | (((0x40U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                                                      << 6U)) 
                                                  | (0x20U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_logical_op_wrapper_out_flat) 
                                                        << 5U))) 
                                                 | ((4U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat) 
                                                        >> 2U)) 
                                                    | (1U 
                                                       & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat) 
                                                          >> 2U))))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat 
        = ((0x1e0U & (tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat 
                      >> 2U)) | ((0x1eU & ((tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat 
                                            >> ((IData)(3U) 
                                                + (7U 
                                                   & tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat))) 
                                           << 1U)) 
                                 | (4U < (7U & tb__DOT__dut__DOT__widths_partselect_wrapper_in_flat))));
    tb__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c 
        = (0xffU & ((1U & (IData)((tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                   >> 1U))) ? (IData)(
                                                      (tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                       >> 0x1aU))
                     : (IData)((tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                >> 0x12U))));
    tb__DOT__dut__DOT__const_partselect_wrapper_out_flat 
        = ((0xf0U & (tb__DOT__dut__DOT__const_partselect_wrapper_in_flat 
                     >> 0xcU)) | ((((0xcU >= (0xfU 
                                              & tb__DOT__dut__DOT__const_partselect_wrapper_in_flat))
                                     ? (7U & (tb__DOT__dut__DOT__const_partselect_wrapper_in_flat 
                                              >> ((IData)(4U) 
                                                  + 
                                                  (7U 
                                                   & tb__DOT__dut__DOT__const_partselect_wrapper_in_flat))))
                                     : 0U) << 1U) | 
                                  (0xcU < (0xfU & tb__DOT__dut__DOT__const_partselect_wrapper_in_flat))));
    vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__din3 
        = (((8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                   >> 5U)) | (4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                    << 2U))) | ((2U 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                    >> 3U)) 
                                                | (1U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                      >> 6U))));
    vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
        = (((IData)(tb__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
            << 0x10U) | ((0xff00U & (((1U & (IData)(tb__DOT__dut__DOT__const_conditional_wrapper_in_flat))
                                       ? (IData)(tb__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                       : (IData)((tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                  >> 0xaU))) 
                                     << 8U)) | (0xffU 
                                                & (VL_LTS_III(8, 
                                                              (0xffU 
                                                               & (IData)(
                                                                         (tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                                          >> 0xaU))), 
                                                              (0xffU 
                                                               & (IData)(
                                                                         (tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                                          >> 2U))))
                                                    ? (IData)(
                                                              (tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                               >> 0x1aU))
                                                    : (IData)(
                                                              (tb__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                               >> 0x12U))))));
    vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat 
        = (0x20U | (((0x200U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                << 7U)) | ((0x100U 
                                            & ((IData)(tb__DOT__dut__DOT__const_partselect_wrapper_out_flat) 
                                               << 4U)) 
                                           | (0x80U 
                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                                 << 5U)))) 
                    | ((0x40U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                          >> 2U)) << 6U)) 
                       | (((8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                                  << 2U)) | (4U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                                   >> 0xaU))) 
                          | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat) 
                                    >> 4U)) | (1U & 
                                               ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2) 
                                                >> 1U)))))));
    tb__DOT__dut__DOT__widths_cast_wrapper_in_flat 
        = ((((0x800U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                 >> 1U)) << 0xbU)) 
             | ((0x400U & ((IData)(tb__DOT__dut__DOT__const_partselect_wrapper_out_flat) 
                           << 4U)) | (0x200U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                >> 4U)))) 
            | ((0x100U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                   >> 0x11U)) << 8U)) 
               | ((0x80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                            >> 4U)) | (0x40U & ((IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                         >> 0x20U)) 
                                                << 6U))))) 
           | (((0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                         << 1U)) | ((0x10U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                              >> 0xbU)) 
                                    | (8U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                             >> 5U)))) 
              | ((4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat)) 
                 | ((2U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                           >> 0x16U)) | (1U & ((IData)(tb__DOT__dut__DOT__const_partselect_wrapper_out_flat) 
                                               >> 1U))))));
    tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
        = (0x830200U | (((((0x400000U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                         << 0x14U)) 
                           | (0x200000U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                           << 0x15U))) 
                          | ((0x100000U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                           >> 2U)) 
                             | ((0x80000U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                             << 5U)) 
                                | (0x40000U & vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat)))) 
                         | ((0x8000U & ((IData)(tb__DOT__dut__DOT__const_partselect_wrapper_out_flat) 
                                        << 0xdU)) | 
                            ((0x4000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                         << 8U)) | 
                             ((0x2000U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                   >> 0x14U)) 
                                          << 0xdU)) 
                              | (0x1000U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                            >> 0xaU)))))) 
                        | ((((0x800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                        >> 1U)) | (0x400U 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                      >> 5U))) 
                            | ((0x100U & vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat) 
                               | ((0x80U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                            >> 4U)) 
                                  | (0x40U & ((IData)(
                                                      (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                       >> 6U)) 
                                              << 6U))))) 
                           | ((0x20U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                        >> 0xdU)) | 
                              ((0x10U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                         >> 0x11U)) 
                               | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat) 
                                         << 1U)) | 
                                  ((2U & ((IData)((vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                   >> 0x12U)) 
                                          << 1U)) | 
                                   (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                          >> 0xfU)))))))));
    tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
        = (0x100002U | (((0x4000000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                                        << 0x17U)) 
                         | ((0x2000000U & ((IData)(tb__DOT__dut__DOT__const_partselect_wrapper_out_flat) 
                                           << 0x14U)) 
                            | (0x1000000U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                             << 0xeU)))) 
                        | ((0x800000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                         << 0x11U)) 
                           | ((0x400000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat) 
                                            << 0x13U)) 
                              | (((((0x80000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                 << 0xdU)) 
                                    | (0x40000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                                   << 0xaU))) 
                                   | ((0x20000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                                   << 4U)) 
                                      | ((0x10000U 
                                          & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                             << 6U)) 
                                         | (0x8000U 
                                            & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                               << 0xbU))))) 
                                  | (((0x4000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_out_flat) 
                                                  << 0xdU)) 
                                      | ((0x2000U & 
                                          ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_select_wrapper_out_flat) 
                                           << 8U)) 
                                         | (0x1000U 
                                            & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                               << 1U)))) 
                                     | ((0x800U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                   >> 8U)) 
                                        | (0x400U & 
                                           (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                            >> 0xbU))))) 
                                 | ((((0x200U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                 >> 7U)) 
                                      | ((0x100U & 
                                          ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                           << 1U)) 
                                         | (0x80U & 
                                            (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                             >> 6U)))) 
                                     | ((0x40U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                  << 4U)) 
                                        | (0x20U & 
                                           (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                            >> 1U)))) 
                                    | ((0x10U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                 >> 6U)) 
                                       | ((4U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                 >> 7U)) 
                                          | (1U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                                   >> 9U))))))))));
    tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat 
        = (0x20U | (((0x8000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c) 
                                 << 0xdU)) | ((0x4000U 
                                               & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                  << 1U)) 
                                              | (0x2000U 
                                                 & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                    << 2U)))) 
                    | ((0x1000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_reduce_wrapper_out_flat) 
                                   << 0xbU)) | ((0x800U 
                                                 & vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat) 
                                                | ((0x400U 
                                                    & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                       >> 0xbU)) 
                                                   | ((((0x100U 
                                                         & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                            >> 6U)) 
                                                        | ((0x80U 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                               >> 7U)) 
                                                           | (0x40U 
                                                              & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                                 >> 2U)))) 
                                                       | (0x10U 
                                                          & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                                             << 3U))) 
                                                      | (((8U 
                                                           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                              >> 2U)) 
                                                          | (4U 
                                                             & ((IData)(tb__DOT__dut__DOT__const_partselect_wrapper_out_flat) 
                                                                >> 1U))) 
                                                         | ((2U 
                                                             & ((IData)(vlSelfRef.tb__DOT__in_flat) 
                                                                << 1U)) 
                                                            | (1U 
                                                               & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                                  >> 0xfU))))))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat 
        = ((0xf0U & ((IData)(tb__DOT__dut__DOT__widths_cast_wrapper_in_flat) 
                     >> 4U)) | (0xfU & (IData)(tb__DOT__dut__DOT__widths_cast_wrapper_in_flat)));
    vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat 
        = ((((((0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                         >> 0x10U)) == (0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                 >> 8U))) 
              << 7U) | (((0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                   >> 0x10U)) != (0xffU 
                                                  & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                     >> 8U))) 
                        << 6U)) | ((((0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                               >> 0x10U)) 
                                     < (0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                 >> 8U))) 
                                    << 5U) | (((0xffU 
                                                & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                   >> 0x10U)) 
                                               <= (0xffU 
                                                   & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                      >> 8U))) 
                                              << 4U))) 
           | (((((0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                           >> 0x10U)) > (0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                  >> 8U))) 
                << 3U) | (((0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                     >> 0x10U)) >= 
                           (0xffU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                     >> 8U))) << 2U)) 
              | ((((0xfU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                            >> 4U)) == (0xfU & tb__DOT__dut__DOT__const_compare_wrapper_in_flat)) 
                  << 1U) | ((0xfU & (tb__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                     >> 4U)) != (0xfU 
                                                 & tb__DOT__dut__DOT__const_compare_wrapper_in_flat)))));
    vlSelfRef.tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c 
        = (0xffU & ((((0xffU & ((tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                 >> 0x13U) + (tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                              >> 0xbU))) 
                      * (0xffU & ((tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                   >> 3U) << (7U & tb__DOT__dut__DOT__const_nested_wrapper_in_flat)))) 
                     & ((tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                         >> 0xbU) ^ (tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                     >> 3U))) | VL_MODDIV_III(8, 
                                                              ((0U 
                                                                == 
                                                                (0xffU 
                                                                 & ((IData)(1U) 
                                                                    + 
                                                                    (tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                     >> 0xbU))))
                                                                ? 0U
                                                                : 
                                                               (0xffU 
                                                                & VL_DIV_III(8, 
                                                                             (0xffU 
                                                                              & (tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 0x13U)), 
                                                                             (0xffU 
                                                                              & ((IData)(1U) 
                                                                                + 
                                                                                (tb__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 0xbU)))))), (IData)(3U))));
    tb__DOT__dut__DOT__u_numbers_arithmetic_reduce_wrapper__DOT__complex_expr 
        = (0xffU & (((((IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat) 
                       >> 8U) + (IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat)) 
                     & (((IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat) 
                         >> 8U) ^ (IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat))) 
                    | VL_MODDIV_III(8, (0xffU & (((IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat) 
                                                  >> 8U) 
                                                 - (IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat))), 
                                    (0xffU & ((IData)(1U) 
                                              + (IData)(tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_in_flat))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat 
        = (((IData)(tb__DOT__dut__DOT__u_numbers_arithmetic_reduce_wrapper__DOT__complex_expr) 
            << 2U) | (((0xffU == (IData)(tb__DOT__dut__DOT__u_numbers_arithmetic_reduce_wrapper__DOT__complex_expr)) 
                       << 1U) | (0U != (IData)(tb__DOT__dut__DOT__u_numbers_arithmetic_reduce_wrapper__DOT__complex_expr))));
}

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__2(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__3(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__6(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__7(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__8(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__11(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__12(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__13(Vtb___024root* vlSelf);

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x30000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x30228ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x302e8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__4(vlSelf);
    }
    if ((0x70228ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x30238ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x30328ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__5(vlSelf);
    }
    if ((0x30278ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__6(vlSelf);
    }
    if ((0x30368ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x7037cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x30378ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x3036aULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__9(vlSelf);
    }
    if ((0x3036eULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__10(vlSelf);
    }
    if ((0x3037cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__11(vlSelf);
    }
    if ((0x3036bULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__12(vlSelf);
    }
    if ((0x7037bULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__13(vlSelf);
    }
    if ((0x703fbULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__12(vlSelf);
    }
    if ((0x703ffULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___act_comb__TOP__13(vlSelf);
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn) {
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3 
            = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__din3)));
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1 
            = (0xfU & ((IData)(1U) + (1U | (((8U & 
                                              (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                               >> 0x13U)) 
                                             | (4U 
                                                & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                   >> 0x11U))) 
                                            | (2U & 
                                               (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                >> 2U))))));
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2 
            = (0xfU & ((IData)(1U) + (4U | ((8U & ((IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                            >> 0x10U)) 
                                                   << 3U)) 
                                            | ((2U 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__const_compare_wrapper_out_flat) 
                                                   << 1U)) 
                                               | (1U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                     >> 0xaU)))))));
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0 
            = (0xfU & ((IData)(1U) + (((8U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                              >> 3U)) 
                                       | (4U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                                >> 3U))) 
                                      | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                >> 9U)) 
                                         | (1U & (IData)(
                                                         (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                          >> 0x15U)))))));
    } else {
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3 = 0U;
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1 = 0U;
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2 = 0U;
        vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0 = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__widths_array_wrapper_out_flat 
        = ((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0) 
             << 0xcU) | ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1) 
                         << 8U)) | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2) 
                                     << 4U) | (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3)));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*10:0*/ tb__DOT__dut__DOT__widths_shift_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_shift_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__widths_shift_wrapper_in_flat 
        = ((0x400U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2) 
                      << 0xaU)) | ((0x200U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                              << 8U)) 
                                   | ((0x100U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                 << 8U)) 
                                      | (((0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0) 
                                            << 5U)) 
                                          | (0x20U 
                                             & ((IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                         >> 4U)) 
                                                << 5U))) 
                                         | ((0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_logical_op_wrapper_out_flat) 
                                                << 3U)) 
                                            | ((8U 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                   << 3U)) 
                                               | ((2U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                        >> 9U)))))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat 
        = ((0xff00U & ((((IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat) 
                         >> 3U) << (7U & (IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat))) 
                       << 8U)) | (0xffU & ((0xffU & 
                                            ((IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat) 
                                             >> 3U)) 
                                           >> (7U & (IData)(tb__DOT__dut__DOT__widths_shift_wrapper_in_flat)))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ tb__DOT__dut__DOT__const_reduce_wrapper_in_flat;
    tb__DOT__dut__DOT__const_reduce_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__const_reduce_wrapper_in_flat 
        = (4U | ((8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                        >> 1U)) | ((2U & (IData)(vlSelfRef.tb__DOT__in_flat)) 
                                   | (1U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                            >> 4U)))));
    vlSelfRef.tb__DOT__dut__DOT__const_reduce_wrapper_out_flat 
        = ((((0xfU == (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat)) 
             << 5U) | (((0U != (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat)) 
                        << 4U) | (8U & (VL_REDXOR_4(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat) 
                                        << 3U)))) | 
           ((4U & ((~ (0xfU == (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat))) 
                   << 2U)) | ((2U & ((~ (0U != (IData)(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat))) 
                                     << 1U)) | (1U 
                                                & (~ 
                                                   VL_REDXOR_4(tb__DOT__dut__DOT__const_reduce_wrapper_in_flat))))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__3(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__3\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat 
        = (4U | ((((0x80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                             << 5U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                 << 5U))) 
                  | ((0x20U & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                               >> 5U)) | (0x10U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                   >> 3U)))) 
                 | ((8U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                           << 1U)) | (1U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                            >> 0x13U)))));
    vlSelfRef.tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat 
        = (((((0xfU & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                       >> 4U)) == (0xfU & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
             << 5U) | ((((0xfU & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                  >> 4U)) != (0xfU 
                                              & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
                        << 4U) | (((0xfU & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                            >> 4U)) 
                                   > (0xfU & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
                                  << 3U))) | (((0xfU 
                                                == 
                                                (0xfU 
                                                 & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                                    >> 4U))) 
                                               << 2U) 
                                              | (((0U 
                                                   != 
                                                   (0xfU 
                                                    & (IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat))) 
                                                  << 1U) 
                                                 | (1U 
                                                    & VL_REDXOR_32(
                                                                   (0xfU 
                                                                    & ((IData)(tb__DOT__dut__DOT__widths_logic_mod_wrapper_in_flat) 
                                                                       >> 4U)))))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__6(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__6\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat = 0;
    SData/*8:0*/ tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat = 0;
    // Body
    vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat 
        = (0x82U | ((0x400U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                               << 2U)) | ((0x200U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_array_wrapper_out_flat) 
                                            >> 1U)) 
                                          | ((0x40U 
                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                                 << 3U)) 
                                             | (((0x10U 
                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                                     << 1U)) 
                                                 | ((8U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_shift_wrapper_out_flat) 
                                                        << 2U)) 
                                                    | (4U 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2)))) 
                                                | (1U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                      >> 1U)))))));
    tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat 
        = (0x1600U | ((0x4000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat) 
                                  << 0xcU)) | ((0x100U 
                                                & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                   << 8U)) 
                                               | ((0x80U 
                                                   & ((IData)(
                                                              (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                               >> 0xaU)) 
                                                      << 7U)) 
                                                  | (((0x20U 
                                                       & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                          << 3U)) 
                                                      | ((0x10U 
                                                          & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                             >> 3U)) 
                                                         | (8U 
                                                            & ((IData)(
                                                                       (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                                        >> 0x21U)) 
                                                               << 3U)))) 
                                                     | ((4U 
                                                         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1) 
                                                            >> 1U)) 
                                                        | ((2U 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                               >> 0x15U)) 
                                                           | (1U 
                                                              & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                                 >> 0xcU)))))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
        = ((0xff0000U & (((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                          << 8U) & ((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                                    << 0x10U))) | (
                                                   (0xff00U 
                                                    & ((0xffffff00U 
                                                        & (IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat)) 
                                                       | ((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                                                          << 8U))) 
                                                   | (0xffU 
                                                      & (((IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat) 
                                                          >> 8U) 
                                                         ^ (IData)(tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_in_flat)))));
    tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat 
        = (0x140U | (((0x80U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                >> 6U)) | ((0x20U & 
                                            (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                             >> 0xdU)) 
                                           | (0x10U 
                                              & vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat))) 
                     | (((8U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                >> 5U)) | (4U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                 >> 0xbU))) 
                        | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                  >> 4U)) | (1U & (IData)(
                                                          (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                           >> 0x13U)))))));
    vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z 
        = (0xfU & ((0x100U & (IData)(tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat))
                    ? (7U & ((IData)(tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat) 
                             >> 4U)) : (IData)(tb__DOT__dut__DOT__widths_conditional_wrapper_in_flat)));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__7(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__7\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat 
        = ((((0x800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                        << 0xbU)) | ((0x400U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                                >> 7U)) 
                                     | (0x200U & ((IData)(
                                                          (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                           >> 0xbU)) 
                                                  << 9U)))) 
            | ((0x100U & (IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat)) 
               | ((0x80U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                            << 6U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                >> 0x11U))))) 
           | (((0x20U & (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                         >> 6U)) | ((0x10U & ((IData)(vlSelfRef.tb__DOT__in_flat) 
                                              << 2U)) 
                                    | (8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat) 
                                             >> 2U)))) 
              | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                        >> 5U)) | ((2U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                                          >> 0xeU)) 
                                   | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_array_wrapper_out_flat) 
                                            >> 9U))))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__8(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__8\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat;
    tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat 
        = (0x6400U | (((0x8000U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                   << 0xaU)) | (0x1000U 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat) 
                                                   << 2U))) 
                      | ((0x800U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                                    >> 9U)) | ((0x200U 
                                                & (vlSelfRef.tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat 
                                                   >> 8U)) 
                                               | ((0x100U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat) 
                                                      << 5U)) 
                                                  | ((((0x40U 
                                                        & ((IData)(
                                                                   (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                                    >> 0xdU)) 
                                                           << 6U)) 
                                                       | (0x20U 
                                                          & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                             << 3U))) 
                                                      | ((0x10U 
                                                          & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                             >> 0xfU)) 
                                                         | (8U 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                                                               >> 1U)))) 
                                                     | ((4U 
                                                         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                            >> 2U)) 
                                                        | ((2U 
                                                            & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat) 
                                                               >> 7U)) 
                                                           | (1U 
                                                              & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                                 >> 0xcU))))))))));
    vlSelfRef.tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat 
        = ((0xff00U & ((IData)(tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat) 
                       << 8U)) | (0xffU & ((IData)(tb__DOT__dut__DOT__widths_union_mod_wrapper_in_flat) 
                                           >> 8U)));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__11(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__11\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_in_flat 
        = (((((0x8000U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z) 
                          << 0xdU)) | (0x4000U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                  << 1U))) 
             | ((0x2000U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                            << 8U)) | (0x1000U & (vlSelfRef.tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat 
                                                  >> 8U)))) 
            | (((0x800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                           << 7U)) | (0x400U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                >> 5U))) 
               | ((0x200U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat) 
                             << 3U)) | (0x100U & (vlSelfRef.tb__DOT__dut__DOT__const_shift_wrapper_out_flat 
                                                  >> 6U))))) 
           | ((0x80U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                        >> 9U)) | ((0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                             >> 0xdU)) 
                                   | ((0x20U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0) 
                                                << 3U)) 
                                      | (((8U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                 >> 7U)) 
                                          | (4U & ((IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                            >> 3U)) 
                                                   << 2U))) 
                                         | ((2U & ((IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__const_arith_wrapper_out_flat 
                                                            >> 7U)) 
                                                   << 1U)) 
                                            | (1U & 
                                               (vlSelfRef.tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat 
                                                >> 0x10U))))))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__12(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__12\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits 
        = ((0xcU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits)) 
           | ((((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a) 
                       >> 1U)) == (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                         >> 1U))) << 1U) 
              | ((1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a)) 
                 == (1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b)))));
    vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits 
        = ((3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits)) 
           | ((((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a) 
                       >> 3U)) == (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                         >> 3U))) << 3U) 
              | (((1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a) 
                         >> 2U)) == (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b) 
                                           >> 2U))) 
                 << 2U)));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__13(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__13\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat;
    tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat = 0;
    // Body
    tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat 
        = (4U | ((((0x80U & (vlSelfRef.tb__DOT__dut__DOT__const_logic_wrapper_out_flat 
                             << 1U)) | (0x40U & (vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat 
                                                 >> 8U))) 
                  | ((0x20U & (vlSelfRef.tb__DOT__dut__DOT__const_conditional_wrapper_out_flat 
                               >> 7U)) | (0x10U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__widths_cast_wrapper_out_flat) 
                                                   >> 7U)))) 
                 | ((8U & (vlSelfRef.tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat 
                           >> 6U)) | ((2U & ((IData)(vlSelfRef.tb__DOT__in_flat) 
                                             >> 3U)) 
                                      | (0xfU == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits))))));
    vlSelfRef.tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_out_flat 
        = (((0xffU == (IData)(tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat)) 
            << 2U) | (((0U != (IData)(tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat)) 
                       << 1U) | (1U & VL_REDXOR_8(tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_in_flat))));
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x40000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<19> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb.sv", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
