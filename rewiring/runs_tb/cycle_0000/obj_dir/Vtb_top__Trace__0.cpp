// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0_sub_0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgWData(oldp+0,(vlSelfRef.tb_top__DOT__in_flat),154);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_top__DOT__i),32);
        bufp->chgSData(oldp+6,((0xffffU & vlSelfRef.tb_top__DOT__in_flat[0U])),16);
        bufp->chgQData(oldp+7,((((QData)((IData)((0xffU 
                                                  & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                       << 0x18U) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                         >> 8U)) 
                                                     + 
                                                     vlSelfRef.tb_top__DOT__in_flat[0U])))) 
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
                                                                 | ((0U 
                                                                     != 
                                                                     (0xffU 
                                                                      & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                     ? 
                                                                    (0xffU 
                                                                     & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                     : 0U))))))),40);
        bufp->chgIData(oldp+9,((0xffffffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              << 0x17U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                >> 9U)))),24);
        bufp->chgSData(oldp+10,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           >> 4U))),10);
        bufp->chgIData(oldp+11,(((0x3fc000U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                               << 8U)) 
                                 | ((0x3fc0U & ((0x3c00U 
                                                 & vlSelfRef.tb_top__DOT__in_flat[3U]) 
                                                | (0x3c0U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 4U)))) 
                                    | (0x3fU & ((0x30U 
                                                 & vlSelfRef.tb_top__DOT__in_flat[3U]) 
                                                | ((0xcU 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                       >> 2U)) 
                                                   | (3U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 4U)))))))),22);
        bufp->chgQData(oldp+12,((0x3ffffffffULL & (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.tb_top__DOT__in_flat[4U])) 
                                                    << 0x12U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.tb_top__DOT__in_flat[3U])) 
                                                      >> 0xeU)))),34);
        bufp->chgSData(oldp+14,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           >> 0x10U))),10);
        bufp->chgIData(oldp+15,((((0x78000U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x19U) 
                                                | (0x1ff8000U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 7U))) 
                                               & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   << 0x1dU) 
                                                  | (0x1fff8000U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                        >> 3U))))) 
                                  | (0x7800U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  << 0x15U) 
                                                 | (0x1ff800U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       >> 0xbU))) 
                                                | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    << 0x19U) 
                                                   | (0x1fff800U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 7U)))))) 
                                 | ((0x780U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x11U) 
                                                | (0x1ff80U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 0xfU))) 
                                               ^ ((
                                                   vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   << 0x15U) 
                                                  | (0x1fff80U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                        >> 0xbU))))) 
                                    | ((0x78U & ((~ 
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
                                           << 2U) | 
                                          (((IData)(
                                                    (0U 
                                                     != 
                                                     (0x30000U 
                                                      & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                            << 1U) 
                                           | (1U & 
                                              (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  >> 0x11U))))))))),19);
        bufp->chgIData(oldp+16,((0xfffffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                              << 0xbU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0x15U)))),20);
        bufp->chgCData(oldp+17,(((0xf0U & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 1U)) 
                                 | ((((0xcU >= (0xfU 
                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x15U)))
                                       ? (7U & (((0U 
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
                                       : 0U) << 1U) 
                                    | (0xcU < (0xfU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 0x15U)))))),8);
        bufp->chgSData(oldp+18,((0x7ffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 0x10U))),11);
        bufp->chgIData(oldp+19,(((0xff0000U & ((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  << 0xdU) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x13U)) 
                                                << 
                                                (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x10U))) 
                                               << 0x10U)) 
                                 | ((0xff00U & (((0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x13U)) 
                                                 >> 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x10U))) 
                                                << 8U)) 
                                    | (0xffU & VL_SHIFTRS_III(8,8,3, 
                                                              (0xffU 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                  >> 0x13U)), 
                                                              (7U 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                  >> 0x10U))))))),24);
        bufp->chgCData(oldp+20,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 8U))),8);
        bufp->chgCData(oldp+21,((0xffU & vlSelfRef.tb_top__DOT__in_flat[0U])),8);
        bufp->chgCData(oldp+22,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            << 0x18U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 8U)) 
                                          + vlSelfRef.tb_top__DOT__in_flat[0U]))),8);
        bufp->chgCData(oldp+23,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            << 0x18U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 8U)) 
                                          - vlSelfRef.tb_top__DOT__in_flat[0U]))),8);
        bufp->chgCData(oldp+24,((0xffU & ((0xffU & 
                                           (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            >> 8U)) 
                                          * (0xffU 
                                             & vlSelfRef.tb_top__DOT__in_flat[0U])))),8);
        bufp->chgCData(oldp+25,(((0U != (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                  ? (0xffU & VL_DIV_III(8, 
                                                        (0xffU 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 8U)), 
                                                        (0xffU 
                                                         & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                  : 0U)),8);
        bufp->chgCData(oldp+26,(((0U != (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                  ? (0xffU & VL_MODDIV_III(8, 
                                                           (0xffU 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 8U)), 
                                                           (0xffU 
                                                            & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                  : 0U)),8);
        bufp->chgCData(oldp+27,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           << 7U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 0x19U)))),8);
        bufp->chgCData(oldp+28,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x11U))),8);
        bufp->chgCData(oldp+29,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0xdU))),4);
        bufp->chgCData(oldp+30,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 9U))),4);
        bufp->chgBit(oldp+31,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0x11U)))));
        bufp->chgBit(oldp+32,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               != (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0x11U)))));
        bufp->chgBit(oldp+33,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               < (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 0x11U)))));
        bufp->chgBit(oldp+34,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               > (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 0x11U)))));
        bufp->chgBit(oldp+35,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               >= (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0x11U)))));
        bufp->chgBit(oldp+36,(((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0xdU)) == 
                               (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 9U)))));
        bufp->chgBit(oldp+37,(((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0xdU)) != 
                               (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 9U)))));
        bufp->chgCData(oldp+38,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 0xaU))),4);
        bufp->chgCData(oldp+39,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 6U))),4);
        bufp->chgCData(oldp+40,((3U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       >> 4U))),2);
        bufp->chgCData(oldp+41,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 6U))),8);
        bufp->chgCData(oldp+42,((0xffU & ((0xf0U & 
                                           (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                            >> 6U)) 
                                          | (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              >> 0xaU))))),8);
        bufp->chgCData(oldp+43,((0x3fU & ((0x30U & 
                                           vlSelfRef.tb_top__DOT__in_flat[3U]) 
                                          | ((0xcU 
                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 2U)) 
                                             | (3U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 4U)))))),6);
        bufp->chgCData(oldp+44,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          >> 8U))),8);
        bufp->chgCData(oldp+45,((0xffU & vlSelfRef.tb_top__DOT__in_flat[4U])),8);
        bufp->chgCData(oldp+46,((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                 >> 0x18U)),8);
        bufp->chgCData(oldp+47,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 0x10U))),8);
        bufp->chgBit(oldp+48,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                     >> 0xfU))));
        bufp->chgBit(oldp+49,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                     >> 0xeU))));
        bufp->chgCData(oldp+50,((0xffU & (VL_LTS_III(8, 
                                                     (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 0x18U), 
                                                     (0xffU 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 0x10U)))
                                           ? ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               << 0x18U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 >> 8U))
                                           : vlSelfRef.tb_top__DOT__in_flat[4U]))),8);
        bufp->chgCData(oldp+51,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                         >> 0x16U))),4);
        bufp->chgCData(oldp+52,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                         >> 0x12U))),4);
        bufp->chgBit(oldp+53,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0x11U))));
        bufp->chgBit(oldp+54,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0x10U))));
        bufp->chgCData(oldp+55,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 0xaU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             >> 0x16U)) 
                                         & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xeU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x12U))))),4);
        bufp->chgCData(oldp+56,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 0xaU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             >> 0x16U)) 
                                         | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xeU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x12U))))),4);
        bufp->chgCData(oldp+57,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 0xaU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             >> 0x16U)) 
                                         ^ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xeU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x12U))))),4);
        bufp->chgCData(oldp+58,((0xfU & (~ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xaU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x16U))))),4);
        bufp->chgBit(oldp+59,((IData)((0x30000U == 
                                       (0x30000U & 
                                        vlSelfRef.tb_top__DOT__in_flat[4U])))));
        bufp->chgBit(oldp+60,((IData)((0U != (0x30000U 
                                              & vlSelfRef.tb_top__DOT__in_flat[4U])))));
        bufp->chgBit(oldp+61,((1U & (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        >> 0x11U)))));
        bufp->chgCData(oldp+62,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          >> 0xdU))),8);
        bufp->chgCData(oldp+63,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          >> 5U))),8);
        bufp->chgCData(oldp+64,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0x1bU))),3);
        bufp->chgCData(oldp+65,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x13U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 0xdU)) 
                                          + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x1bU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 5U))))),8);
        bufp->chgCData(oldp+66,((0xffU & ((IData)(1U) 
                                          + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x1bU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 5U))))),8);
        bufp->chgCData(oldp+67,(((0U == (0xffU & ((IData)(1U) 
                                                  + 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1bU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 5U)))))
                                  ? 0U : (0xffU & VL_DIV_III(8, 
                                                             (0xffU 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 0xdU)), 
                                                             (0xffU 
                                                              & ((IData)(1U) 
                                                                 + 
                                                                 ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                   << 0x1bU) 
                                                                  | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                     >> 5U)))))))),8);
        bufp->chgCData(oldp+68,((0xffU & VL_MODDIV_III(8, 
                                                       ((0U 
                                                         == 
                                                         (0xffU 
                                                          & ((IData)(1U) 
                                                             + 
                                                             ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                               << 0x1bU) 
                                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 5U)))))
                                                         ? 0U
                                                         : 
                                                        (0xffU 
                                                         & VL_DIV_III(8, 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                          >> 0xdU)), 
                                                                      (0xffU 
                                                                       & ((IData)(1U) 
                                                                          + 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            << 0x1bU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 5U))))))), (IData)(3U)))),8);
        bufp->chgCData(oldp+69,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 1U))),8);
        bufp->chgCData(oldp+70,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           << 7U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           >> 0x19U)))),8);
        bufp->chgCData(oldp+71,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                         >> 0x15U))),4);
        bufp->chgCData(oldp+72,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 5U))),4);
        bufp->chgCData(oldp+73,(((0xcU >= (0xfU & (
                                                   vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x15U)))
                                  ? (7U & (((0U == 
                                             (0x1fU 
                                              & ((IData)(0x39U) 
                                                 + 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x15U)))))
                                             ? 0U : 
                                            (vlSelfRef.tb_top__DOT__in_flat[
                                             (((IData)(0x3bU) 
                                               + (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x15U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(0x39U) 
                                                     + 
                                                     (7U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                         >> 0x15U))))))) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[
                                              (((IData)(0x39U) 
                                                + (7U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 0x15U))) 
                                               >> 5U)] 
                                              >> (0x1fU 
                                                  & ((IData)(0x39U) 
                                                     + 
                                                     (7U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                         >> 0x15U)))))))
                                  : 0U)),3);
        bufp->chgBit(oldp+74,((0xcU < (0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               >> 0x15U)))));
        bufp->chgCData(oldp+75,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 0x13U))),8);
        bufp->chgCData(oldp+76,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0x10U))),3);
        bufp->chgCData(oldp+77,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            << 0xdU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 0x13U)) 
                                          << (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x10U))))),8);
        bufp->chgCData(oldp+78,((0xffU & ((0xffU & 
                                           (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            >> 0x13U)) 
                                          >> (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x10U))))),8);
        bufp->chgCData(oldp+79,((0xffU & VL_SHIFTRS_III(8,8,3, 
                                                        (0xffU 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 0x13U)), 
                                                        (7U 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 0x10U))))),8);
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [1U] | vlSelfRef.__Vm_traceActivity
                        [2U]) | vlSelfRef.__Vm_traceActivity
                       [3U]) | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        __Vtemp_1[0U] = (IData)((((QData)((IData)((
                                                   (0x3fc0000U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                       << 0xcU)) 
                                                   | ((0x3fc00U 
                                                       & ((0x3c000U 
                                                           & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                              << 4U)) 
                                                          | (0x3c00U 
                                                             & vlSelfRef.tb_top__DOT__in_flat[3U]))) 
                                                      | ((0x3f0U 
                                                          & ((0x300U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                 << 4U)) 
                                                             | ((0xc0U 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    << 2U)) 
                                                                | (0x30U 
                                                                   & vlSelfRef.tb_top__DOT__in_flat[3U])))) 
                                                         | ((((0xfU 
                                                               == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
                                                              << 3U) 
                                                             | ((0U 
                                                                 != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
                                                                << 2U)) 
                                                            | ((2U 
                                                                & (VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec) 
                                                                   << 1U)) 
                                                               | (1U 
                                                                  & (~ 
                                                                     (0xfU 
                                                                      == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))))))))) 
                                  << 0x1aU) | (QData)((IData)(
                                                              (((((0x2000000U 
                                                                   & ((~ 
                                                                       (0U 
                                                                        != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))) 
                                                                      << 0x19U)) 
                                                                  | ((0x1000000U 
                                                                      & ((~ 
                                                                          VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
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
                                                                | ((((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_compare_wrapper__DOT__le_c) 
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
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x13U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xdU)) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 3U) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1bU))))) 
                                                                               & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U)) 
                                                                                ^ 
                                                                                (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 3U))) 
                                                                              | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xdU)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U))))))), (IData)(3U))))))))))));
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
                                                                     & (((0x4000U 
                                                                          & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                          ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                          : 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 8U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             >> 0x18U))) 
                                                                        << 8U)) 
                                                                    | (0xffU 
                                                                       & (VL_LTS_III(8, 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x18U), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x10U)))
                                                                           ? 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x18U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 8U))
                                                                           : 
                                                                          vlSelfRef.tb_top__DOT__in_flat[4U])))))))) 
                          << 0x14U) | (IData)(((((QData)((IData)(
                                                                 ((0x3fc0000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                      << 0xcU)) 
                                                                  | ((0x3fc00U 
                                                                      & ((0x3c000U 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 4U)) 
                                                                         | (0x3c00U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[3U]))) 
                                                                     | ((0x3f0U 
                                                                         & ((0x300U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 4U)) 
                                                                            | ((0xc0U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 2U)) 
                                                                               | (0x30U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[3U])))) 
                                                                        | ((((0xfU 
                                                                              == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
                                                                             << 3U) 
                                                                            | ((0U 
                                                                                != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
                                                                               << 2U)) 
                                                                           | ((2U 
                                                                               & (VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec) 
                                                                                << 1U)) 
                                                                              | (1U 
                                                                                & (~ 
                                                                                (0xfU 
                                                                                == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))))))))) 
                                                 << 0x1aU) 
                                                | (QData)((IData)(
                                                                  (((((0x2000000U 
                                                                       & ((~ 
                                                                           (0U 
                                                                            != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))) 
                                                                          << 0x19U)) 
                                                                      | ((0x1000000U 
                                                                          & ((~ 
                                                                              VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
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
                                                                    | ((((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_compare_wrapper__DOT__le_c) 
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
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x13U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xdU)) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 3U) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1bU))))) 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U)) 
                                                                                ^ 
                                                                                (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                                                >> 3U))) 
                                                                                | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xdU)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1bU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U))))))), (IData)(3U))))))))))) 
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
                                                                     & (((0x4000U 
                                                                          & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                          ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                          : 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 8U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             >> 0x18U))) 
                                                                        << 8U)) 
                                                                    | (0xffU 
                                                                       & (VL_LTS_III(8, 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x18U), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x10U)))
                                                                           ? 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x18U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 8U))
                                                                           : 
                                                                          vlSelfRef.tb_top__DOT__in_flat[4U])))))))) 
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
                                                                       & (((0x4000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                            ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                            : 
                                                                           ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 8U) 
                                                                            | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               >> 0x18U))) 
                                                                          << 8U)) 
                                                                      | (0xffU 
                                                                         & (VL_LTS_III(8, 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x18U), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x10U)))
                                                                             ? 
                                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              << 0x18U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 8U))
                                                                             : 
                                                                            vlSelfRef.tb_top__DOT__in_flat[4U]))))))) 
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
                                                                  | ((0U 
                                                                      != 
                                                                      (0xffU 
                                                                       & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                      ? 
                                                                     (0xffU 
                                                                      & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                      : 0U)))))));
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
                                                                   | ((0U 
                                                                       != 
                                                                       (0xffU 
                                                                        & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                       ? 
                                                                      (0xffU 
                                                                       & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                       : 0U)))))) 
                                 >> 0x20U));
        __Vtemp_2[2U] = __Vtemp_1[0U];
        __Vtemp_2[3U] = __Vtemp_1[1U];
        __Vtemp_2[4U] = __Vtemp_1[2U];
        bufp->chgWData(oldp+80,(__Vtemp_2),159);
        bufp->chgCData(oldp+85,(((((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                << 7U) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0x19U))) 
                                     == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0x11U))) 
                                    << 7U) | (((0xffU 
                                                & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                    << 7U) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      >> 0x19U))) 
                                               != (0xffU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      >> 0x11U))) 
                                              << 6U)) 
                                  | ((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  << 7U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0x19U))) 
                                       < (0xffU & (
                                                   vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                   >> 0x11U))) 
                                      << 5U) | ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_compare_wrapper__DOT__le_c) 
                                                << 4U))) 
                                 | (((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  << 7U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0x19U))) 
                                       > (0xffU & (
                                                   vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                   >> 0x11U))) 
                                      << 3U) | (((0xffU 
                                                  & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      << 7U) 
                                                     | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                        >> 0x19U))) 
                                                 >= 
                                                 (0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0x11U))) 
                                                << 2U)) 
                                    | ((((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0xdU)) 
                                         == (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                              >> 9U))) 
                                        << 1U) | ((0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      >> 0xdU)) 
                                                  != 
                                                  (0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      >> 9U))))))),8);
        bufp->chgIData(oldp+86,((((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                  << 0x10U) | ((0xff00U 
                                                & (((0x4000U 
                                                     & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                     ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                     : 
                                                    ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      << 8U) 
                                                     | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                        >> 0x18U))) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & (VL_LTS_III(8, 
                                                                (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                 >> 0x18U), 
                                                                (0xffU 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    >> 0x10U)))
                                                      ? 
                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       << 0x18U) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 8U))
                                                      : 
                                                     vlSelfRef.tb_top__DOT__in_flat[4U]))))),24);
        bufp->chgCData(oldp+87,((0xffU & ((((0xffU 
                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  << 0x13U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    >> 0xdU)) 
                                                + (
                                                   (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1bU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 5U)))) 
                                            * (0xffU 
                                               & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                   >> 3U) 
                                                  << 
                                                  (7U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                      >> 0x1bU))))) 
                                           & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 0x1bU) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 5U)) 
                                              ^ (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                 >> 3U))) 
                                          | VL_MODDIV_III(8, 
                                                          ((0U 
                                                            == 
                                                            (0xffU 
                                                             & ((IData)(1U) 
                                                                + 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                  << 0x1bU) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                    >> 5U)))))
                                                            ? 0U
                                                            : 
                                                           (0xffU 
                                                            & VL_DIV_III(8, 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                             >> 0xdU)), 
                                                                         (0xffU 
                                                                          & ((IData)(1U) 
                                                                             + 
                                                                             ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                               << 0x1bU) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 5U))))))), (IData)(3U))))),8);
        bufp->chgCData(oldp+88,((0xffU & ((0x4000U 
                                           & vlSelfRef.tb_top__DOT__in_flat[3U])
                                           ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                           : ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                               << 8U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 0x18U))))),8);
        bufp->chgCData(oldp+89,((0xffU & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                           >> 3U) << 
                                          (7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x1bU))))),8);
        bufp->chgCData(oldp+90,((0xffU & ((0xffU & 
                                           (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x13U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0xdU)) 
                                            + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 0x1bU) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 5U)))) 
                                          * (0xffU 
                                             & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                 >> 3U) 
                                                << 
                                                (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x1bU))))))),8);
        bufp->chgCData(oldp+91,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x1bU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 5U)) 
                                          ^ (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                             >> 3U)))),8);
        bufp->chgCData(oldp+92,((0xffU & (((0xffU & 
                                            (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 0x13U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 >> 0xdU)) 
                                             + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 << 0x1bU) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 5U)))) 
                                           * (0xffU 
                                              & ((vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                  >> 3U) 
                                                 << 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x1bU))))) 
                                          & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 0x1bU) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 >> 5U)) 
                                             ^ (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                                >> 3U))))),8);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgIData(oldp+93,(vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat),27);
        bufp->chgCData(oldp+94,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec),4);
        bufp->chgCData(oldp+95,(((((0xfU == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
                                   << 5U) | (((0U != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
                                              << 4U) 
                                             | (8U 
                                                & (VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec) 
                                                   << 3U)))) 
                                 | ((4U & ((~ (0xfU 
                                               == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))) 
                                           << 2U)) 
                                    | ((2U & ((~ (0U 
                                                  != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))) 
                                              << 1U)) 
                                       | (1U & (~ VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))))),6);
        bufp->chgBit(oldp+96,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_compare_wrapper__DOT__le_c));
        bufp->chgCData(oldp+97,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c),8);
        bufp->chgCData(oldp+98,((0xffU & (vlSelfRef.tb_top__DOT__dut__DOT__const_nested_wrapper_in_flat 
                                          >> 3U))),8);
        bufp->chgBit(oldp+99,((0xfU == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))));
        bufp->chgBit(oldp+100,((0U != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))));
        bufp->chgBit(oldp+101,((1U & VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))));
        bufp->chgBit(oldp+102,((1U & (~ (0xfU == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))));
        bufp->chgBit(oldp+103,((1U & (~ (0U != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))));
        bufp->chgBit(oldp+104,((1U & (~ VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)))));
    }
    bufp->chgBit(oldp+105,(vlSelfRef.tb_top__DOT__clk));
    bufp->chgIData(oldp+106,(vlSelfRef.tb_top__DOT__cyc),32);
    bufp->chgIData(oldp+107,(vlSelfRef.tb_top__DOT__cycles),32);
    bufp->chgIData(oldp+108,(vlSelfRef.tb_top__DOT__seed),32);
    bufp->chgIData(oldp+109,(vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i),32);
    bufp->chgIData(oldp+110,(vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j),32);
}

void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
