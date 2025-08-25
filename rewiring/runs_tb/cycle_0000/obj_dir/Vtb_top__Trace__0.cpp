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
        bufp->chgWData(oldp+0,(vlSelfRef.tb_top__DOT__in_flat),151);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_top__DOT__i),32);
        bufp->chgIData(oldp+6,((0xffffffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                             >> 7U))),24);
        bufp->chgCData(oldp+7,(((((((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                              >> 0x17U)) 
                                    == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0xfU))) 
                                   << 7U) | (((0xffU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0x17U)) 
                                              != (0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0xfU))) 
                                             << 6U)) 
                                 | ((((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                >> 0x17U)) 
                                      < (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0xfU))) 
                                     << 5U) | (((0xffU 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0x17U)) 
                                                <= 
                                                (0xffU 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0xfU))) 
                                               << 4U))) 
                                | (((((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                >> 0x17U)) 
                                      > (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0xfU))) 
                                     << 3U) | (((0xffU 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0x17U)) 
                                                >= 
                                                (0xffU 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0xfU))) 
                                               << 2U)) 
                                   | ((((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0xbU)) 
                                        == (0xfU & 
                                            (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                             >> 7U))) 
                                       << 1U) | ((0xfU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0xbU)) 
                                                 != 
                                                 (0xfU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 7U))))))),8);
        bufp->chgSData(oldp+8,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 2U))),10);
        bufp->chgIData(oldp+9,(((0x3fc000U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              << 0xaU)) 
                                | ((0x3fc0U & ((0x3c00U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   << 2U)) 
                                               | (0x3c0U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                     >> 2U)))) 
                                   | (0x3fU & ((0x30U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   << 2U)) 
                                               | ((0xcU 
                                                   & vlSelfRef.tb_top__DOT__in_flat[3U]) 
                                                  | (3U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                        >> 2U)))))))),22);
        bufp->chgQData(oldp+10,((0x3ffffffffULL & (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.tb_top__DOT__in_flat[4U])) 
                                                    << 0x14U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.tb_top__DOT__in_flat[3U])) 
                                                      >> 0xcU)))),34);
        bufp->chgIData(oldp+12,((0x7ffffffU & ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 7U) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  >> 0x19U)))),27);
        bufp->chgCData(oldp+13,((0xffU & ((((0xffU 
                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  << 0x14U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    >> 0xcU)) 
                                                + (
                                                   (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1cU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 4U)))) 
                                            * (0xffU 
                                               & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 4U) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                      >> 0x1cU)) 
                                                  << 
                                                  (7U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                      >> 0x19U))))) 
                                           & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 0x1cU) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 4U)) 
                                              ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  << 4U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x1cU)))) 
                                          | VL_MODDIV_III(8, 
                                                          ((0U 
                                                            == 
                                                            (0xffU 
                                                             & ((IData)(1U) 
                                                                + 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                  << 0x1cU) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                    >> 4U)))))
                                                            ? 0U
                                                            : 
                                                           (0xffU 
                                                            & VL_DIV_III(8, 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                             >> 0xcU)), 
                                                                         (0xffU 
                                                                          & ((IData)(1U) 
                                                                             + 
                                                                             ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                               << 0x1cU) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U))))))), (IData)(3U))))),8);
        bufp->chgSData(oldp+14,((0x7ffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 0xeU))),11);
        bufp->chgCData(oldp+15,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 6U))),8);
        bufp->chgCData(oldp+16,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x17U))),8);
        bufp->chgCData(oldp+17,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0xfU))),8);
        bufp->chgCData(oldp+18,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0xbU))),4);
        bufp->chgCData(oldp+19,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 7U))),4);
        bufp->chgBit(oldp+20,(((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x17U)) 
                               == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0xfU)))));
        bufp->chgBit(oldp+21,(((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x17U)) 
                               != (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0xfU)))));
        bufp->chgBit(oldp+22,(((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x17U)) 
                               < (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 0xfU)))));
        bufp->chgBit(oldp+23,(((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x17U)) 
                               <= (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0xfU)))));
        bufp->chgBit(oldp+24,(((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x17U)) 
                               > (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 0xfU)))));
        bufp->chgBit(oldp+25,(((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x17U)) 
                               >= (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0xfU)))));
        bufp->chgBit(oldp+26,(((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0xbU)) == 
                               (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 7U)))));
        bufp->chgBit(oldp+27,(((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0xbU)) != 
                               (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 7U)))));
        bufp->chgCData(oldp+28,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 8U))),4);
        bufp->chgCData(oldp+29,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 4U))),4);
        bufp->chgCData(oldp+30,((3U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       >> 2U))),2);
        bufp->chgCData(oldp+31,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 4U))),8);
        bufp->chgCData(oldp+32,((0xffU & ((0xf0U & 
                                           (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                            >> 4U)) 
                                          | (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              >> 8U))))),8);
        bufp->chgCData(oldp+33,((0x3fU & ((0x30U & 
                                           (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                            << 2U)) 
                                          | ((0xcU 
                                              & vlSelfRef.tb_top__DOT__in_flat[3U]) 
                                             | (3U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 2U)))))),6);
        bufp->chgCData(oldp+34,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          >> 6U))),8);
        bufp->chgCData(oldp+35,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 2U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           >> 0x1eU)))),8);
        bufp->chgCData(oldp+36,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 0x16U))),8);
        bufp->chgCData(oldp+37,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 0xeU))),8);
        bufp->chgBit(oldp+38,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                     >> 0xdU))));
        bufp->chgBit(oldp+39,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                     >> 0xcU))));
        bufp->chgCData(oldp+40,((0xffU & (VL_LTS_III(8, 
                                                     (0xffU 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 0x16U)), 
                                                     (0xffU 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 0xeU)))
                                           ? ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               << 0x1aU) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 >> 6U))
                                           : ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               << 2U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 0x1eU))))),8);
        bufp->chgCData(oldp+41,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                         >> 0x13U))),4);
        bufp->chgBit(oldp+42,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0xfU))));
        bufp->chgBit(oldp+43,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0xeU))));
        bufp->chgCData(oldp+44,((0xfU & (~ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xdU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x13U))))),4);
        bufp->chgBit(oldp+45,((IData)((0xc000U == (0xc000U 
                                                   & vlSelfRef.tb_top__DOT__in_flat[4U])))));
        bufp->chgBit(oldp+46,((IData)((0U != (0xc000U 
                                              & vlSelfRef.tb_top__DOT__in_flat[4U])))));
        bufp->chgBit(oldp+47,((1U & (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        >> 0xfU)))));
        bufp->chgCData(oldp+48,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          >> 0xcU))),8);
        bufp->chgCData(oldp+49,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          >> 4U))),8);
        bufp->chgCData(oldp+50,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           << 4U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 0x1cU)))),8);
        bufp->chgCData(oldp+51,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0x19U))),3);
        bufp->chgCData(oldp+52,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x14U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 0xcU)) 
                                          + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x1cU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 4U))))),8);
        bufp->chgCData(oldp+53,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 4U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 0x1cU)) 
                                          << (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x19U))))),8);
        bufp->chgCData(oldp+54,((0xffU & ((0xffU & 
                                           (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x14U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0xcU)) 
                                            + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 0x1cU) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 4U)))) 
                                          * (0xffU 
                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  << 4U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x1cU)) 
                                                << 
                                                (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x19U))))))),8);
        bufp->chgCData(oldp+55,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x1cU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 4U)) 
                                          ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 4U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                >> 0x1cU))))),8);
        bufp->chgCData(oldp+56,((0xffU & (((0xffU & 
                                            (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 0x14U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 >> 0xcU)) 
                                             + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 << 0x1cU) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 4U)))) 
                                           * (0xffU 
                                              & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   << 4U) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x1cU)) 
                                                 << 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x19U))))) 
                                          & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 0x1cU) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 >> 4U)) 
                                             ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 << 4U) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                   >> 0x1cU)))))),8);
        bufp->chgCData(oldp+57,((0xffU & ((IData)(1U) 
                                          + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x1cU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 4U))))),8);
        bufp->chgCData(oldp+58,(((0U == (0xffU & ((IData)(1U) 
                                                  + 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1cU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 4U)))))
                                  ? 0U : (0xffU & VL_DIV_III(8, 
                                                             (0xffU 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 0xcU)), 
                                                             (0xffU 
                                                              & ((IData)(1U) 
                                                                 + 
                                                                 ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                   << 0x1cU) 
                                                                  | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                     >> 4U)))))))),8);
        bufp->chgCData(oldp+59,((0xffU & VL_MODDIV_III(8, 
                                                       ((0U 
                                                         == 
                                                         (0xffU 
                                                          & ((IData)(1U) 
                                                             + 
                                                             ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                               << 0x1cU) 
                                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 4U)))))
                                                         ? 0U
                                                         : 
                                                        (0xffU 
                                                         & VL_DIV_III(8, 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                          >> 0xcU)), 
                                                                      (0xffU 
                                                                       & ((IData)(1U) 
                                                                          + 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            << 0x1cU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 4U))))))), (IData)(3U)))),8);
        bufp->chgCData(oldp+60,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           << 1U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           >> 0x1fU)))),8);
        bufp->chgCData(oldp+61,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                         >> 0x14U))),4);
        bufp->chgCData(oldp+62,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 3U))),4);
        bufp->chgBit(oldp+63,((0xcU < (0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               >> 0x14U)))));
        bufp->chgCData(oldp+64,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 0x11U))),8);
        bufp->chgCData(oldp+65,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0xeU))),3);
        bufp->chgCData(oldp+66,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            << 0xfU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 0x11U)) 
                                          << (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0xeU))))),8);
        bufp->chgCData(oldp+67,((0xffU & ((0xffU & 
                                           (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            >> 0x11U)) 
                                          >> (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0xeU))))),8);
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [1U] | vlSelfRef.__Vm_traceActivity
                        [2U]) | vlSelfRef.__Vm_traceActivity
                       [3U]) | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        __Vtemp_1[0U] = (IData)((((QData)((IData)((
                                                   (0x3fc0000U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                       << 0xeU)) 
                                                   | ((0x3fc00U 
                                                       & ((0x3c000U 
                                                           & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                              << 6U)) 
                                                          | (0x3c00U 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                << 2U)))) 
                                                      | ((0x3f0U 
                                                          & ((0x300U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                 << 6U)) 
                                                             | ((0xc0U 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    << 4U)) 
                                                                | (0x30U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                      << 2U))))) 
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
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x17U)) 
                                                                         == 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0xfU))) 
                                                                        << 0x17U))) 
                                                                 | ((((0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0x17U)) 
                                                                      != 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0xfU))) 
                                                                     << 0x16U) 
                                                                    | (((0xffU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0x17U)) 
                                                                        < 
                                                                        (0xffU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0xfU))) 
                                                                       << 0x15U))) 
                                                                | (((((0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0x17U)) 
                                                                      <= 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0xfU))) 
                                                                     << 0x14U) 
                                                                    | ((((0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x17U)) 
                                                                         > 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0xfU))) 
                                                                        << 0x13U) 
                                                                       | (((0xffU 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                               >> 0x17U)) 
                                                                           >= 
                                                                           (0xffU 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                               >> 0xfU))) 
                                                                          << 0x12U))) 
                                                                   | ((((0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0xbU)) 
                                                                        == 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 7U))) 
                                                                       << 0x11U) 
                                                                      | (((0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0xbU)) 
                                                                          != 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 7U))) 
                                                                         << 0x10U)))) 
                                                               | ((0xf000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                      << 9U)) 
                                                                  | ((((0xcU 
                                                                        >= 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            >> 0x14U)))
                                                                        ? 
                                                                       (7U 
                                                                        & (((0xff800U 
                                                                             & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                << 0xdU) 
                                                                                | (0x1800U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x13U)))) 
                                                                            | ((0x400U 
                                                                                & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                                                                << 6U)) 
                                                                               | (0x3ffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x14U)))) 
                                                                           >> 
                                                                           ((IData)(4U) 
                                                                            + 
                                                                            (7U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x14U)))))
                                                                        : 0U) 
                                                                      << 9U) 
                                                                     | (((0xcU 
                                                                          < 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 0x14U))) 
                                                                         << 8U) 
                                                                        | (0xffU 
                                                                           & ((((0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x14U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xcU)) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 4U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1cU)) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x19U))))) 
                                                                               & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U)) 
                                                                                ^ 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 4U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1cU)))) 
                                                                              | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xcU)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U))))))), (IData)(3U))))))))))));
        __Vtemp_1[1U] = (((IData)((((QData)((IData)(
                                                    (((0x78000U 
                                                       & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                            << 0x1cU) 
                                                           | (0xfff8000U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 4U))) 
                                                          & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                             << 0xdU))) 
                                                      | (0x7800U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x18U) 
                                                             | (0xfff800U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 8U))) 
                                                            | (0xfffff800U 
                                                               & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                  << 9U))))) 
                                                     | ((0x780U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x14U) 
                                                             | (0xfff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xcU))) 
                                                            ^ 
                                                            (0xffffff80U 
                                                             & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                << 5U)))) 
                                                        | ((0x78U 
                                                            & ((~ 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 0xdU) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x13U))) 
                                                               << 3U)) 
                                                           | (((IData)(
                                                                       (0xc000U 
                                                                        == 
                                                                        (0xc000U 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                               << 2U) 
                                                              | (((IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0xc000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        >> 0xfU)))))))))) 
                                    << 0x18U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                  << 0x10U) 
                                                                 | ((0xff00U 
                                                                     & (((0x1000U 
                                                                          & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                          ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                          : 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 0xaU) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             >> 0x16U))) 
                                                                        << 8U)) 
                                                                    | (0xffU 
                                                                       & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x16U)), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0xeU)))
                                                                           ? 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x1aU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 6U))
                                                                           : 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 2U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              >> 0x1eU)))))))))) 
                          << 0x14U) | (IData)(((((QData)((IData)(
                                                                 ((0x3fc0000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                      << 0xeU)) 
                                                                  | ((0x3fc00U 
                                                                      & ((0x3c000U 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 6U)) 
                                                                         | (0x3c00U 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               << 2U)))) 
                                                                     | ((0x3f0U 
                                                                         & ((0x300U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 6U)) 
                                                                            | ((0xc0U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 4U)) 
                                                                               | (0x30U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 2U))))) 
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
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x17U)) 
                                                                             == 
                                                                             (0xffU 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xfU))) 
                                                                            << 0x17U))) 
                                                                     | ((((0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0x17U)) 
                                                                          != 
                                                                          (0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0xfU))) 
                                                                         << 0x16U) 
                                                                        | (((0xffU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x17U)) 
                                                                            < 
                                                                            (0xffU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xfU))) 
                                                                           << 0x15U))) 
                                                                    | (((((0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0x17U)) 
                                                                          <= 
                                                                          (0xffU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0xfU))) 
                                                                         << 0x14U) 
                                                                        | ((((0xffU 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x17U)) 
                                                                             > 
                                                                             (0xffU 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xfU))) 
                                                                            << 0x13U) 
                                                                           | (((0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x17U)) 
                                                                               >= 
                                                                               (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xfU))) 
                                                                              << 0x12U))) 
                                                                       | ((((0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xbU)) 
                                                                            == 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 7U))) 
                                                                           << 0x11U) 
                                                                          | (((0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xbU)) 
                                                                              != 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 7U))) 
                                                                             << 0x10U)))) 
                                                                   | ((0xf000U 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          << 9U)) 
                                                                      | ((((0xcU 
                                                                            >= 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x14U)))
                                                                            ? 
                                                                           (7U 
                                                                            & (((0xff800U 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                << 0xdU) 
                                                                                | (0x1800U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x13U)))) 
                                                                                | ((0x400U 
                                                                                & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                                                                << 6U)) 
                                                                                | (0x3ffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x14U)))) 
                                                                               >> 
                                                                               ((IData)(4U) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x14U)))))
                                                                            : 0U) 
                                                                          << 9U) 
                                                                         | (((0xcU 
                                                                              < 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x14U))) 
                                                                             << 8U) 
                                                                            | (0xffU 
                                                                               & ((((0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x14U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xcU)) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 4U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1cU)) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x19U))))) 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U)) 
                                                                                ^ 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 4U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1cU)))) 
                                                                                | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xcU)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1cU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 4U))))))), (IData)(3U))))))))))) 
                                               >> 0x20U)));
        __Vtemp_1[2U] = (((IData)((((QData)((IData)(
                                                    (((0x78000U 
                                                       & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                            << 0x1cU) 
                                                           | (0xfff8000U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 4U))) 
                                                          & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                             << 0xdU))) 
                                                      | (0x7800U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x18U) 
                                                             | (0xfff800U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 8U))) 
                                                            | (0xfffff800U 
                                                               & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                  << 9U))))) 
                                                     | ((0x780U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x14U) 
                                                             | (0xfff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xcU))) 
                                                            ^ 
                                                            (0xffffff80U 
                                                             & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                << 5U)))) 
                                                        | ((0x78U 
                                                            & ((~ 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 0xdU) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x13U))) 
                                                               << 3U)) 
                                                           | (((IData)(
                                                                       (0xc000U 
                                                                        == 
                                                                        (0xc000U 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                               << 2U) 
                                                              | (((IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0xc000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        >> 0xfU)))))))))) 
                                    << 0x18U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                  << 0x10U) 
                                                                 | ((0xff00U 
                                                                     & (((0x1000U 
                                                                          & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                          ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                          : 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 0xaU) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             >> 0x16U))) 
                                                                        << 8U)) 
                                                                    | (0xffU 
                                                                       & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x16U)), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0xeU)))
                                                                           ? 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x1aU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 6U))
                                                                           : 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 2U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              >> 0x1eU)))))))))) 
                          >> 0xcU) | ((IData)(((((QData)((IData)(
                                                                 (((0x78000U 
                                                                    & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                         << 0x1cU) 
                                                                        | (0xfff8000U 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 4U))) 
                                                                       & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                          << 0xdU))) 
                                                                   | (0x7800U 
                                                                      & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x18U) 
                                                                          | (0xfff800U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 8U))) 
                                                                         | (0xfffff800U 
                                                                            & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                               << 9U))))) 
                                                                  | ((0x780U 
                                                                      & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x14U) 
                                                                          | (0xfff80U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xcU))) 
                                                                         ^ 
                                                                         (0xffffff80U 
                                                                          & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                                             << 5U)))) 
                                                                     | ((0x78U 
                                                                         & ((~ 
                                                                             ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                               << 0xdU) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x13U))) 
                                                                            << 3U)) 
                                                                        | (((IData)(
                                                                                (0xc000U 
                                                                                == 
                                                                                (0xc000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                            << 2U) 
                                                                           | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                               << 1U) 
                                                                              | (1U 
                                                                                & (~ 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xfU)))))))))) 
                                                 << 0x18U) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                    << 0x10U) 
                                                                   | ((0xff00U 
                                                                       & (((0x1000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                            ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                            : 
                                                                           ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 0xaU) 
                                                                            | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               >> 0x16U))) 
                                                                          << 8U)) 
                                                                      | (0xffU 
                                                                         & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x16U)), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0xeU)))
                                                                             ? 
                                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              << 0x1aU) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 6U))
                                                                             : 
                                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              << 2U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x1eU))))))))) 
                                               >> 0x20U)) 
                                      << 0x14U));
        __Vtemp_2[0U] = (IData)((((QData)((IData)((
                                                   (((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                        << 0xfU) 
                                                       | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                          >> 0x11U)) 
                                                      << 
                                                      (7U 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                          >> 0xeU))) 
                                                     << 0x18U) 
                                                    | (0xff0000U 
                                                       & (((0xffU 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 0x11U)) 
                                                           >> 
                                                           (7U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 0xeU))) 
                                                          << 0x10U))) 
                                                   | (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                                       << 8U) 
                                                      | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c))))) 
                                  << 0x20U) | (QData)((IData)(
                                                              ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                    << 0x1aU) 
                                                                   | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                      >> 6U)) 
                                                                  - (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)) 
                                                                 << 0x18U) 
                                                                | (0xff0000U 
                                                                   & (((0xffU 
                                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                           >> 6U)) 
                                                                       * 
                                                                       (0xffU 
                                                                        & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))) 
                                                                      << 0x10U))) 
                                                               | ((((0U 
                                                                     != 
                                                                     (0xffU 
                                                                      & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                                     ? 
                                                                    (0xffU 
                                                                     & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 6U)), 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                                     : 0U) 
                                                                   << 8U) 
                                                                  | ((0U 
                                                                      != 
                                                                      (0xffU 
                                                                       & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                                      ? 
                                                                     (0xffU 
                                                                      & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 6U)), 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                                      : 0U)))))));
        __Vtemp_2[1U] = (IData)(((((QData)((IData)(
                                                   ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                         << 0xfU) 
                                                        | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                           >> 0x11U)) 
                                                       << 
                                                       (7U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                           >> 0xeU))) 
                                                      << 0x18U) 
                                                     | (0xff0000U 
                                                        & (((0xffU 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                >> 0x11U)) 
                                                            >> 
                                                            (7U 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                >> 0xeU))) 
                                                           << 0x10U))) 
                                                    | (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                                        << 8U) 
                                                       | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                     << 0x1aU) 
                                                                    | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                       >> 6U)) 
                                                                   - (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)) 
                                                                  << 0x18U) 
                                                                 | (0xff0000U 
                                                                    & (((0xffU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                            >> 6U)) 
                                                                        * 
                                                                        (0xffU 
                                                                         & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))) 
                                                                       << 0x10U))) 
                                                                | ((((0U 
                                                                      != 
                                                                      (0xffU 
                                                                       & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                                      ? 
                                                                     (0xffU 
                                                                      & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 6U)), 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                                      : 0U) 
                                                                    << 8U) 
                                                                   | ((0U 
                                                                       != 
                                                                       (0xffU 
                                                                        & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                                       ? 
                                                                      (0xffU 
                                                                       & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 6U)), 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                                       : 0U)))))) 
                                 >> 0x20U));
        __Vtemp_2[2U] = __Vtemp_1[0U];
        __Vtemp_2[3U] = __Vtemp_1[1U];
        __Vtemp_2[4U] = __Vtemp_1[2U];
        bufp->chgWData(oldp+68,(__Vtemp_2),159);
        bufp->chgQData(oldp+73,((((QData)((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c)) 
                                  << 0x20U) | (QData)((IData)(
                                                              ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                    << 0x1aU) 
                                                                   | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                      >> 6U)) 
                                                                  - (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)) 
                                                                 << 0x18U) 
                                                                | (0xff0000U 
                                                                   & (((0xffU 
                                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                           >> 6U)) 
                                                                       * 
                                                                       (0xffU 
                                                                        & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))) 
                                                                      << 0x10U))) 
                                                               | ((((0U 
                                                                     != 
                                                                     (0xffU 
                                                                      & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                                     ? 
                                                                    (0xffU 
                                                                     & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 6U)), 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                                     : 0U) 
                                                                   << 8U) 
                                                                  | ((0U 
                                                                      != 
                                                                      (0xffU 
                                                                       & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                                                      ? 
                                                                     (0xffU 
                                                                      & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 6U)), 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                                                      : 0U))))))),40);
        bufp->chgIData(oldp+75,((((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                  << 0x10U) | ((0xff00U 
                                                & (((0x1000U 
                                                     & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                     ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                     : 
                                                    ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      << 0xaU) 
                                                     | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                        >> 0x16U))) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & (VL_LTS_III(8, 
                                                                (0xffU 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    >> 0x16U)), 
                                                                (0xffU 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    >> 0xeU)))
                                                      ? 
                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       << 0x1aU) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 6U))
                                                      : 
                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       << 2U) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 0x1eU))))))),24);
        bufp->chgIData(oldp+76,((((0x78000U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x1cU) 
                                                | (0xfff8000U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 4U))) 
                                               & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                  << 0xdU))) 
                                  | (0x7800U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  << 0x18U) 
                                                 | (0xfff800U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       >> 8U))) 
                                                | (0xfffff800U 
                                                   & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                      << 9U))))) 
                                 | ((0x780U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x14U) 
                                                | (0xfff80U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 0xcU))) 
                                               ^ (0xffffff80U 
                                                  & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                                     << 5U)))) 
                                    | ((0x78U & ((~ 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    << 0xdU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 0x13U))) 
                                                 << 3U)) 
                                       | (((IData)(
                                                   (0xc000U 
                                                    == 
                                                    (0xc000U 
                                                     & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                           << 2U) | 
                                          (((IData)(
                                                    (0U 
                                                     != 
                                                     (0xc000U 
                                                      & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                            << 1U) 
                                           | (1U & 
                                              (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  >> 0xfU))))))))),19);
        bufp->chgIData(oldp+77,(((0xff800U & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                               << 0xdU) 
                                              | (0x1800U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    >> 0x13U)))) 
                                 | ((0x400U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                               << 6U)) 
                                    | (0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 >> 0x14U))))),20);
        bufp->chgCData(oldp+78,(((0xf0U & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           << 1U)) 
                                 | ((((0xcU >= (0xfU 
                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x14U)))
                                       ? (7U & (((0xff800U 
                                                  & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      << 0xdU) 
                                                     | (0x1800U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                           >> 0x13U)))) 
                                                 | ((0x400U 
                                                     & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                                        << 6U)) 
                                                    | (0x3ffU 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                          >> 0x14U)))) 
                                                >> 
                                                ((IData)(4U) 
                                                 + 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x14U)))))
                                       : 0U) << 1U) 
                                    | (0xcU < (0xfU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 0x14U)))))),8);
        bufp->chgIData(oldp+79,(((0xff0000U & ((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  << 0xfU) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x11U)) 
                                                << 
                                                (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0xeU))) 
                                               << 0x10U)) 
                                 | ((0xff00U & (((0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x11U)) 
                                                 >> 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0xeU))) 
                                                << 8U)) 
                                    | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c)))),24);
        bufp->chgCData(oldp+80,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            << 0x1aU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 6U)) 
                                          - (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))),8);
        bufp->chgCData(oldp+81,((0xffU & ((0xffU & 
                                           (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            >> 6U)) 
                                          * (0xffU 
                                             & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))),8);
        bufp->chgCData(oldp+82,(((0U != (0xffU & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                  ? (0xffU & VL_DIV_III(8, 
                                                        (0xffU 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 6U)), 
                                                        (0xffU 
                                                         & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                  : 0U)),8);
        bufp->chgCData(oldp+83,(((0U != (0xffU & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat)))
                                  ? (0xffU & VL_MODDIV_III(8, 
                                                           (0xffU 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 6U)), 
                                                           (0xffU 
                                                            & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))))
                                  : 0U)),8);
        bufp->chgCData(oldp+84,((0xffU & ((0x1000U 
                                           & vlSelfRef.tb_top__DOT__in_flat[3U])
                                           ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                           : ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                               << 0xaU) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 0x16U))))),8);
        bufp->chgCData(oldp+85,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 0xdU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             >> 0x13U)) 
                                         & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                            >> 2U)))),4);
        bufp->chgCData(oldp+86,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 0xdU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             >> 0x13U)) 
                                         | ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                            >> 2U)))),4);
        bufp->chgCData(oldp+87,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 0xdU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             >> 0x13U)) 
                                         ^ ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                            >> 2U)))),4);
        bufp->chgCData(oldp+88,(((0x80U & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           >> 0x17U)) 
                                 | ((0x40U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                              << 2U)) 
                                    | (0x3fU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0x18U))))),8);
        bufp->chgCData(oldp+89,(((0xcU >= (0xfU & (
                                                   vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x14U)))
                                  ? (7U & (((0xff800U 
                                             & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 << 0xdU) 
                                                | (0x1800U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 0x13U)))) 
                                            | ((0x400U 
                                                & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c) 
                                                   << 6U)) 
                                               | (0x3ffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x14U)))) 
                                           >> ((IData)(4U) 
                                               + (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x14U)))))
                                  : 0U)),3);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgSData(oldp+90,(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat),16);
        bufp->chgSData(oldp+91,(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat),10);
        bufp->chgCData(oldp+92,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec),4);
        bufp->chgCData(oldp+93,(((((0xfU == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)) 
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
        bufp->chgCData(oldp+94,((0xffU & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_arith_wrapper_in_flat))),8);
        bufp->chgCData(oldp+95,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c),8);
        bufp->chgCData(oldp+96,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c),8);
        bufp->chgCData(oldp+97,((0xfU & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__const_logic_wrapper_in_flat) 
                                         >> 2U))),4);
        bufp->chgBit(oldp+98,((0xfU == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))));
        bufp->chgBit(oldp+99,((0U != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))));
        bufp->chgBit(oldp+100,((1U & VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))));
        bufp->chgBit(oldp+101,((1U & (~ (0xfU == (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))));
        bufp->chgBit(oldp+102,((1U & (~ (0U != (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec))))));
        bufp->chgBit(oldp+103,((1U & (~ VL_REDXOR_4(vlSelfRef.tb_top__DOT__dut__DOT__u_const_reduce_wrapper__DOT__in_vec)))));
        bufp->chgCData(oldp+104,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_shift_wrapper__DOT__ashr_c),8);
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
