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
    // Body
    co_await vlSelfRef.__VtrigSched_h159771e3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_top.clk)", 
                                                         "/module-fuzz/rewiring/runs_tb/cycle_0002/tb_top.sv", 
                                                         48);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_top__DOT__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_top__DOT__i, vlSelfRef.tb_top__DOT__cycles)) {
        co_await vlSelfRef.__VtrigSched_h15977b22__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_top.clk)", 
                                                             "/module-fuzz/rewiring/runs_tb/cycle_0002/tb_top.sv", 
                                                             50);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.tb_top__DOT__in_flat = (0x3ffU & 
                                          VL_RANDOM_I());
        vlSelfRef.tb_top__DOT__i = ((IData)(1U) + vlSelfRef.tb_top__DOT__i);
    }
    VL_WRITEF_NX("TB_SIM_OK cycles=%0d\n",0,32,vlSelfRef.tb_top__DOT__cycles);
    VL_FINISH_MT("/module-fuzz/rewiring/runs_tb/cycle_0002/tb_top.sv", 54, "");
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
    }
}

VL_INLINE_OPT void Vtb_top___024root___act_comb__TOP__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___act_comb__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out 
        = (7U & ((3U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                        >> 5U)) + (3U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                         >> 3U))));
    vlSelfRef.tb_top__DOT__dut__DOT__u_multiplier_wrapper__DOT__data_out 
        = (0x1fU & (((2U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                            >> 8U)) | (1U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out) 
                                             >> 1U))) 
                    * (3U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                             >> 7U))));
    vlSelfRef.tb_top__DOT__out_flat = (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_multiplier_wrapper__DOT__data_out) 
                                        << 6U) | (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out) 
                                                   << 3U) 
                                                  | (7U 
                                                     & (((2U 
                                                          & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                                             >> 1U)) 
                                                         | (1U 
                                                            & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_multiplier_wrapper__DOT__data_out) 
                                                               >> 2U))) 
                                                        + 
                                                        (3U 
                                                         & (IData)(vlSelfRef.tb_top__DOT__in_flat))))));
}

void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf);

void Vtb_top___024root___eval_nba(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_nba\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_top___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__tb_top__DOT__cyc;
    __Vdly__tb_top__DOT__cyc = 0;
    // Body
    __Vdly__tb_top__DOT__cyc = vlSelfRef.tb_top__DOT__cyc;
    vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j = 0xffffffffU;
    __Vdly__tb_top__DOT__cyc = ((IData)(1U) + vlSelfRef.tb_top__DOT__cyc);
    VL_WRITEF_NX("CYCLE=%0d IN=%0#%0#%0#%0#%0#%0#%0#%0#%0#%0# OUT=%0#%0#%0#%0#%0#%0#%0#%0#%0#%0#%0#\n",0,
                 32,vlSelfRef.tb_top__DOT__cyc,1,(1U 
                                                  & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                                     >> 9U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                          >> 8U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                           >> 7U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                          >> 6U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                           >> 5U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                          >> 4U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                           >> 3U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                          >> 2U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                           >> 1U)),
                 1,(1U & (IData)(vlSelfRef.tb_top__DOT__in_flat)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                          >> 0xaU)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                                             >> 9U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                          >> 8U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                                           >> 7U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                          >> 6U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                                           >> 5U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                          >> 4U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                                           >> 3U)),
                 1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                          >> 2U)),1,(1U & ((IData)(vlSelfRef.tb_top__DOT__out_flat) 
                                           >> 1U)),
                 1,(1U & (IData)(vlSelfRef.tb_top__DOT__out_flat)));
    vlSelfRef.tb_top__DOT__cyc = __Vdly__tb_top__DOT__cyc;
}

void Vtb_top___024root___timing_commit(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_commit\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h159771e3__0.commit(
                                                   "@(negedge tb_top.clk)");
    }
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h15977b22__0.commit(
                                                   "@(posedge tb_top.clk)");
    }
}

void Vtb_top___024root___timing_resume(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_resume\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h159771e3__0.resume(
                                                   "@(negedge tb_top.clk)");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h15977b22__0.resume(
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
            VL_FATAL_MT("/module-fuzz/rewiring/runs_tb/cycle_0002/tb_top.sv", 3, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/module-fuzz/rewiring/runs_tb/cycle_0002/tb_top.sv", 3, "", "Active region did not converge.");
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
