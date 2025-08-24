// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

VL_ATTR_COLD void Vtb_top___024root___eval_initial__TOP(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__0(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__1(Vtb_top___024root* vlSelf);

void Vtb_top___024root___eval_initial(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_top___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    co_await vlSelfRef.__VtrigSched_h1586d63e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_top.clk)", 
                                                         "/opt/module-fuzz/rewiring/runs_tb/cycle_0001/tb_top.sv", 
                                                         48);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_top__DOT__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_top__DOT__i, vlSelfRef.tb_top__DOT__cycles)) {
        co_await vlSelfRef.__VtrigSched_h1586d57f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_top.clk)", 
                                                             "/opt/module-fuzz/rewiring/runs_tb/cycle_0001/tb_top.sv", 
                                                             50);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        VL_RANDOM_W(154, __Vtemp_2);
        vlSelfRef.tb_top__DOT__in_flat[0U] = __Vtemp_2[0U];
        vlSelfRef.tb_top__DOT__in_flat[1U] = __Vtemp_2[1U];
        vlSelfRef.tb_top__DOT__in_flat[2U] = __Vtemp_2[2U];
        vlSelfRef.tb_top__DOT__in_flat[3U] = __Vtemp_2[3U];
        vlSelfRef.tb_top__DOT__in_flat[4U] = (0x3ffffffU 
                                              & __Vtemp_2[4U]);
        vlSelfRef.tb_top__DOT__i = ((IData)(1U) + vlSelfRef.tb_top__DOT__i);
    }
    VL_WRITEF_NX("TB_SIM_OK cycles=%0d\n",0,32,vlSelfRef.tb_top__DOT__cycles);
    VL_FINISH_MT("/opt/module-fuzz/rewiring/runs_tb/cycle_0001/tb_top.sv", 54, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

void Vtb_top___024root___act_comb__TOP__0(Vtb_top___024root* vlSelf);

void Vtb_top___024root___eval_act(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_act\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_top___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_top___024root___act_comb__TOP__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___act_comb__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__rem_c 
        = ((0U != (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U]))
            ? (0xffU & VL_MODDIV_III(8, (0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  >> 8U)), 
                                     (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U])))
            : 0U);
    vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
        = (((QData)((IData)((0x3fffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        >> 2U)))) << 0x14U) 
           | (QData)((IData)(((0x80000U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           << 7U)) 
                              | (0x7ffffU & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                              << 0x11U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                >> 0xfU)))))));
    vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
        = ((0x7000000U & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                          << 6U)) | ((0x800000U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__rem_c) 
                                                   << 0x14U)) 
                                     | (0x7fffffU & 
                                        ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          << 5U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 0x1bU)))));
    vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c 
        = (0xffU & ((0x10000U & vlSelfRef.tb_top__DOT__in_flat[3U])
                     ? ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                         << 0x18U) | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                      >> 8U)) : (IData)(
                                                        (vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                         >> 0x12U))));
}

void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf);
void Vtb_top___024root___nba_comb__TOP__0(Vtb_top___024root* vlSelf);

void Vtb_top___024root___eval_nba(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_nba\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__tb_top__DOT__cyc;
    __Vdly__tb_top__DOT__cyc = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    __Vdly__tb_top__DOT__cyc = vlSelfRef.tb_top__DOT__cyc;
    __Vdly__tb_top__DOT__cyc = ((IData)(1U) + vlSelfRef.tb_top__DOT__cyc);
    VL_WRITEF_NX("CYCLE=%0d IN=",0,32,vlSelfRef.tb_top__DOT__cyc);
    vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i = 0x99U;
    while (VL_LTES_III(32, 0U, vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i)) {
        VL_WRITEF_NX("%0#",0,1,((0x99U >= (0xffU & vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i)) 
                                && (1U & (vlSelfRef.tb_top__DOT__in_flat[
                                          (7U & (vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i 
                                                 >> 5U))] 
                                          >> (0x1fU 
                                              & vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i)))));
        vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i 
            = (vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i 
               - (IData)(1U));
    }
    VL_WRITEF_NX(" OUT=",0);
    vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j = 0x9eU;
    while (VL_LTES_III(32, 0U, vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j)) {
        __Vtemp_1[0U] = (IData)((((QData)((IData)((
                                                   (0x3fc0000U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                       << 0xbU)) 
                                                   | ((0x3fc00U 
                                                       & ((0x3c000U 
                                                           & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                              << 3U)) 
                                                          | (0x3c00U 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                >> 1U)))) 
                                                      | ((0x3f0U 
                                                          & ((0x300U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                 << 3U)) 
                                                             | ((0xc0U 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    << 1U)) 
                                                                | (0x30U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                      >> 1U))))) 
                                                         | ((((0xfU 
                                                               == 
                                                               (0xfU 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                   >> 1U))) 
                                                              << 3U) 
                                                             | ((0U 
                                                                 != 
                                                                 (0xfU 
                                                                  & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                     >> 1U))) 
                                                                << 2U)) 
                                                            | ((2U 
                                                                & (VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                                   << 1U)) 
                                                               | (1U 
                                                                  & (~ 
                                                                     (0xfU 
                                                                      == 
                                                                      (0xfU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                          >> 1U)))))))))))) 
                                  << 0x1aU) | (QData)((IData)(
                                                              (((((0x2000000U 
                                                                   & ((~ 
                                                                       (0U 
                                                                        != 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                            >> 1U)))) 
                                                                      << 0x19U)) 
                                                                  | ((0x1000000U 
                                                                      & ((~ 
                                                                          VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))) 
                                                                         << 0x18U)) 
                                                                     | (((0xffU 
                                                                          & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              << 7U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                         == 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x11U))) 
                                                                        << 0x17U))) 
                                                                 | ((((0xffU 
                                                                       & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 7U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x19U))) 
                                                                      != 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0x11U))) 
                                                                     << 0x16U) 
                                                                    | (((0xffU 
                                                                         & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 7U) 
                                                                            | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                               >> 0x19U))) 
                                                                        < 
                                                                        (0xffU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0x11U))) 
                                                                       << 0x15U))) 
                                                                | (((((0xffU 
                                                                       & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 7U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x19U))) 
                                                                      <= 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0x11U))) 
                                                                     << 0x14U) 
                                                                    | ((((0xffU 
                                                                          & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              << 7U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                         > 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x11U))) 
                                                                        << 0x13U) 
                                                                       | (((0xffU 
                                                                            & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 7U) 
                                                                               | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                           >= 
                                                                           (0xffU 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                               >> 0x11U))) 
                                                                          << 0x12U))) 
                                                                   | ((((0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0xdU)) 
                                                                        == 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 9U))) 
                                                                       << 0x11U) 
                                                                      | (((0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0xdU)) 
                                                                          != 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 9U))) 
                                                                         << 0x10U)))) 
                                                               | ((0xf000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                      << 7U)) 
                                                                  | ((((0xcU 
                                                                        >= 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            >> 0x15U)))
                                                                        ? 
                                                                       (7U 
                                                                        & (((0U 
                                                                             == 
                                                                             (0x1fU 
                                                                              & ((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U)))))
                                                                             ? 0U
                                                                             : 
                                                                            (vlSelfRef.tb_top__DOT__in_flat[
                                                                             (((IData)(0x3bU) 
                                                                               + 
                                                                               (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))) 
                                                                              >> 5U)] 
                                                                             << 
                                                                             ((IData)(0x20U) 
                                                                              - 
                                                                              (0x1fU 
                                                                               & ((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))))))) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[
                                                                              (((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))) 
                                                                               >> 5U)] 
                                                                              >> 
                                                                              (0x1fU 
                                                                               & ((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U)))))))
                                                                        : 0U) 
                                                                      << 9U) 
                                                                     | (((0xcU 
                                                                          < 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 0x15U))) 
                                                                         << 8U) 
                                                                        | (0xffU 
                                                                           & ((((0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 0x13U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1bU))))) 
                                                                               & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)) 
                                                                                ^ 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)))) 
                                                                              | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 0x13U)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U))))))), (IData)(3U))))))))))));
        __Vtemp_1[1U] = (((IData)((((QData)((IData)(
                                                    (((0x78000U 
                                                       & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                            << 0x19U) 
                                                           | (0x1ff8000U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 7U))) 
                                                          & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x1dU) 
                                                             | (0x1fff8000U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 3U))))) 
                                                      | (0x7800U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x15U) 
                                                             | (0x1ff800U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xbU))) 
                                                            | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                << 0x19U) 
                                                               | (0x1fff800U 
                                                                  & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                     >> 7U)))))) 
                                                     | ((0x780U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x11U) 
                                                             | (0x1ff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xfU))) 
                                                            ^ 
                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x15U) 
                                                             | (0x1fff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xbU))))) 
                                                        | ((0x78U 
                                                            & ((~ 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 0xaU) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x16U))) 
                                                               << 3U)) 
                                                           | (((IData)(
                                                                       (0x30000U 
                                                                        == 
                                                                        (0x30000U 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                               << 2U) 
                                                              | (((IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0x30000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        >> 0x11U)))))))))) 
                                    << 0x18U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                  << 0x10U) 
                                                                 | ((0xff00U 
                                                                     & (((0x8000U 
                                                                          & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                          ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                          : 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 7U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             >> 0x19U))) 
                                                                        << 8U)) 
                                                                    | (0xffU 
                                                                       & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x19U))), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x11U)))
                                                                           ? 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x18U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 8U))
                                                                           : (IData)(
                                                                                (vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                                                >> 0x12U)))))))))) 
                          << 0x14U) | (IData)(((((QData)((IData)(
                                                                 ((0x3fc0000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                      << 0xbU)) 
                                                                  | ((0x3fc00U 
                                                                      & ((0x3c000U 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 3U)) 
                                                                         | (0x3c00U 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               >> 1U)))) 
                                                                     | ((0x3f0U 
                                                                         & ((0x300U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 3U)) 
                                                                            | ((0xc0U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 1U)) 
                                                                               | (0x30U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))))) 
                                                                        | ((((0xfU 
                                                                              == 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                                             << 3U) 
                                                                            | ((0U 
                                                                                != 
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                                               << 2U)) 
                                                                           | ((2U 
                                                                               & (VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                                                << 1U)) 
                                                                              | (1U 
                                                                                & (~ 
                                                                                (0xfU 
                                                                                == 
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))))))))))) 
                                                 << 0x1aU) 
                                                | (QData)((IData)(
                                                                  (((((0x2000000U 
                                                                       & ((~ 
                                                                           (0U 
                                                                            != 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))) 
                                                                          << 0x19U)) 
                                                                      | ((0x1000000U 
                                                                          & ((~ 
                                                                              VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))) 
                                                                             << 0x18U)) 
                                                                         | (((0xffU 
                                                                              & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                             == 
                                                                             (0xffU 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x11U))) 
                                                                            << 0x17U))) 
                                                                     | ((((0xffU 
                                                                           & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               << 7U) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                          != 
                                                                          (0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0x11U))) 
                                                                         << 0x16U) 
                                                                        | (((0xffU 
                                                                             & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                            < 
                                                                            (0xffU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x11U))) 
                                                                           << 0x15U))) 
                                                                    | (((((0xffU 
                                                                           & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               << 7U) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                          <= 
                                                                          (0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0x11U))) 
                                                                         << 0x14U) 
                                                                        | ((((0xffU 
                                                                              & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                             > 
                                                                             (0xffU 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x11U))) 
                                                                            << 0x13U) 
                                                                           | (((0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                               >= 
                                                                               (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x11U))) 
                                                                              << 0x12U))) 
                                                                       | ((((0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xdU)) 
                                                                            == 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 9U))) 
                                                                           << 0x11U) 
                                                                          | (((0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xdU)) 
                                                                              != 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 9U))) 
                                                                             << 0x10U)))) 
                                                                   | ((0xf000U 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          << 7U)) 
                                                                      | ((((0xcU 
                                                                            >= 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U)))
                                                                            ? 
                                                                           (7U 
                                                                            & (((0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & ((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[
                                                                                (((IData)(0x3bU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))) 
                                                                                >> 5U)] 
                                                                                << 
                                                                                ((IData)(0x20U) 
                                                                                - 
                                                                                (0x1fU 
                                                                                & ((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))))))) 
                                                                               | (vlSelfRef.tb_top__DOT__in_flat[
                                                                                (((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))) 
                                                                                >> 5U)] 
                                                                                >> 
                                                                                (0x1fU 
                                                                                & ((IData)(0x39U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U)))))))
                                                                            : 0U) 
                                                                          << 9U) 
                                                                         | (((0xcU 
                                                                              < 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x15U))) 
                                                                             << 8U) 
                                                                            | (0xffU 
                                                                               & ((((0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 0x13U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1bU))))) 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)) 
                                                                                ^ 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)))) 
                                                                                | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 0x13U)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U))))))), (IData)(3U))))))))))) 
                                               >> 0x20U)));
        __Vtemp_1[2U] = (((IData)((((QData)((IData)(
                                                    (((0x78000U 
                                                       & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                            << 0x19U) 
                                                           | (0x1ff8000U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 7U))) 
                                                          & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x1dU) 
                                                             | (0x1fff8000U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 3U))))) 
                                                      | (0x7800U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x15U) 
                                                             | (0x1ff800U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xbU))) 
                                                            | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                << 0x19U) 
                                                               | (0x1fff800U 
                                                                  & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                     >> 7U)))))) 
                                                     | ((0x780U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x11U) 
                                                             | (0x1ff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xfU))) 
                                                            ^ 
                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x15U) 
                                                             | (0x1fff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xbU))))) 
                                                        | ((0x78U 
                                                            & ((~ 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 0xaU) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x16U))) 
                                                               << 3U)) 
                                                           | (((IData)(
                                                                       (0x30000U 
                                                                        == 
                                                                        (0x30000U 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                               << 2U) 
                                                              | (((IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0x30000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        >> 0x11U)))))))))) 
                                    << 0x18U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                  << 0x10U) 
                                                                 | ((0xff00U 
                                                                     & (((0x8000U 
                                                                          & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                          ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                          : 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 7U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             >> 0x19U))) 
                                                                        << 8U)) 
                                                                    | (0xffU 
                                                                       & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x19U))), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x11U)))
                                                                           ? 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x18U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 8U))
                                                                           : (IData)(
                                                                                (vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                                                >> 0x12U)))))))))) 
                          >> 0xcU) | ((IData)(((((QData)((IData)(
                                                                 (((0x78000U 
                                                                    & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                         << 0x19U) 
                                                                        | (0x1ff8000U 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 7U))) 
                                                                       & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x1dU) 
                                                                          | (0x1fff8000U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 3U))))) 
                                                                   | (0x7800U 
                                                                      & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x15U) 
                                                                          | (0x1ff800U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xbU))) 
                                                                         | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                             << 0x19U) 
                                                                            | (0x1fff800U 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 7U)))))) 
                                                                  | ((0x780U 
                                                                      & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x11U) 
                                                                          | (0x1ff80U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xfU))) 
                                                                         ^ 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x15U) 
                                                                          | (0x1fff80U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xbU))))) 
                                                                     | ((0x78U 
                                                                         & ((~ 
                                                                             ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                               << 0xaU) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x16U))) 
                                                                            << 3U)) 
                                                                        | (((IData)(
                                                                                (0x30000U 
                                                                                == 
                                                                                (0x30000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                            << 2U) 
                                                                           | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x30000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                               << 1U) 
                                                                              | (1U 
                                                                                & (~ 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x11U)))))))))) 
                                                 << 0x18U) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                    << 0x10U) 
                                                                   | ((0xff00U 
                                                                       & (((0x8000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                            ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                            : 
                                                                           ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                             << 7U) 
                                                                            | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               >> 0x19U))) 
                                                                          << 8U)) 
                                                                      | (0xffU 
                                                                         & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x19U))), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x11U)))
                                                                             ? 
                                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              << 0x18U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 8U))
                                                                             : (IData)(
                                                                                (vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                                                >> 0x12U))))))))) 
                                               >> 0x20U)) 
                                      << 0x14U));
        __Vtemp_2[0U] = (IData)((((QData)((IData)((
                                                   (((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                        << 0xdU) 
                                                       | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                          >> 0x13U)) 
                                                      << 
                                                      (7U 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                          >> 0x10U))) 
                                                     << 0x18U) 
                                                    | (0xff0000U 
                                                       & (((0xffU 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 0x13U)) 
                                                           >> 
                                                           (7U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 0x10U))) 
                                                          << 0x10U))) 
                                                   | ((0xff00U 
                                                       & (VL_SHIFTRS_III(8,8,3, 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                             >> 0x13U)), 
                                                                         (7U 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                             >> 0x10U))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                              << 0x18U) 
                                                             | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                >> 8U)) 
                                                            + 
                                                            vlSelfRef.tb_top__DOT__in_flat[0U])))))) 
                                  << 0x20U) | (QData)((IData)(
                                                              ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                    << 0x18U) 
                                                                   | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                      >> 8U)) 
                                                                  - 
                                                                  vlSelfRef.tb_top__DOT__in_flat[0U]) 
                                                                 << 0x18U) 
                                                                | (0xff0000U 
                                                                   & (((0xffU 
                                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                           >> 8U)) 
                                                                       * 
                                                                       (0xffU 
                                                                        & vlSelfRef.tb_top__DOT__in_flat[0U])) 
                                                                      << 0x10U))) 
                                                               | ((((0U 
                                                                     != 
                                                                     (0xffU 
                                                                      & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                     ? 
                                                                    (0xffU 
                                                                     & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                     : 0U) 
                                                                   << 8U) 
                                                                  | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__rem_c)))))));
        __Vtemp_2[1U] = (IData)(((((QData)((IData)(
                                                   ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                         << 0xdU) 
                                                        | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                           >> 0x13U)) 
                                                       << 
                                                       (7U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                           >> 0x10U))) 
                                                      << 0x18U) 
                                                     | (0xff0000U 
                                                        & (((0xffU 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                >> 0x13U)) 
                                                            >> 
                                                            (7U 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                >> 0x10U))) 
                                                           << 0x10U))) 
                                                    | ((0xff00U 
                                                        & (VL_SHIFTRS_III(8,8,3, 
                                                                          (0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                              >> 0x13U)), 
                                                                          (7U 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                              >> 0x10U))) 
                                                           << 8U)) 
                                                       | (0xffU 
                                                          & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               << 0x18U) 
                                                              | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                 >> 8U)) 
                                                             + 
                                                             vlSelfRef.tb_top__DOT__in_flat[0U])))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                     << 0x18U) 
                                                                    | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                       >> 8U)) 
                                                                   - 
                                                                   vlSelfRef.tb_top__DOT__in_flat[0U]) 
                                                                  << 0x18U) 
                                                                 | (0xff0000U 
                                                                    & (((0xffU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                            >> 8U)) 
                                                                        * 
                                                                        (0xffU 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[0U])) 
                                                                       << 0x10U))) 
                                                                | ((((0U 
                                                                      != 
                                                                      (0xffU 
                                                                       & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                      ? 
                                                                     (0xffU 
                                                                      & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                      : 0U) 
                                                                    << 8U) 
                                                                   | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__rem_c)))))) 
                                 >> 0x20U));
        __Vtemp_2[2U] = __Vtemp_1[0U];
        __Vtemp_2[3U] = __Vtemp_1[1U];
        __Vtemp_2[4U] = __Vtemp_1[2U];
        VL_WRITEF_NX("%0#",0,1,((0x9eU >= (0xffU & vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j)) 
                                && (1U & (__Vtemp_2[
                                          (7U & (vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j 
                                                 >> 5U))] 
                                          >> (0x1fU 
                                              & vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j)))));
        vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j 
            = (vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\n",0);
    vlSelfRef.tb_top__DOT__cyc = __Vdly__tb_top__DOT__cyc;
}

VL_INLINE_OPT void Vtb_top___024root___nba_comb__TOP__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_comb__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
        = (((QData)((IData)((0x3fffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        >> 2U)))) << 0x14U) 
           | (QData)((IData)(((0x80000U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           << 7U)) 
                              | (0x7ffffU & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                              << 0x11U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                >> 0xfU)))))));
    vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__rem_c 
        = ((0U != (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U]))
            ? (0xffU & VL_MODDIV_III(8, (0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  >> 8U)), 
                                     (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U])))
            : 0U);
    vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c 
        = (0xffU & ((0x10000U & vlSelfRef.tb_top__DOT__in_flat[3U])
                     ? ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                         << 0x18U) | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                      >> 8U)) : (IData)(
                                                        (vlSelfRef.tb_top__DOT__dut__DOT__const_conditional_wrapper_in_flat 
                                                         >> 0x12U))));
    vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
        = ((0x7000000U & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                          << 6U)) | ((0x800000U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__rem_c) 
                                                   << 0x14U)) 
                                     | (0x7fffffU & 
                                        ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          << 5U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 0x1bU)))));
}

void Vtb_top___024root___timing_commit(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_commit\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h1586d63e__0.commit(
                                                   "@(negedge tb_top.clk)");
    }
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h1586d57f__0.commit(
                                                   "@(posedge tb_top.clk)");
    }
}

void Vtb_top___024root___timing_resume(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_resume\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h1586d63e__0.resume(
                                                   "@(negedge tb_top.clk)");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h1586d57f__0.resume(
                                                   "@(posedge tb_top.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_top___024root___eval_triggers__act(Vtb_top___024root* vlSelf);

bool Vtb_top___024root___eval_phase__act(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__act\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_top___024root___eval_triggers__act(vlSelf);
    Vtb_top___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_top___024root___timing_resume(vlSelf);
        Vtb_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_top___024root___eval_phase__nba(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__nba\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_top___024root___eval(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/opt/module-fuzz/rewiring/runs_tb/cycle_0001/tb_top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/opt/module-fuzz/rewiring/runs_tb/cycle_0001/tb_top.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_top___024root___eval_debug_assertions(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_debug_assertions\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
