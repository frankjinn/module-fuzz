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
        bufp->chgWData(oldp+0,(vlSelfRef.tb_top__DOT__in_flat),155);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_top__DOT__i),32);
        bufp->chgSData(oldp+6,((0xffffU & vlSelfRef.tb_top__DOT__in_flat[0U])),16);
        bufp->chgSData(oldp+7,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 5U))),10);
        bufp->chgIData(oldp+8,(((0x3fc000U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              << 7U)) 
                                | ((0x3fc0U & ((0x3c00U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 1U)) 
                                               | (0x3c0U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                     >> 5U)))) 
                                   | (0x3fU & ((0x30U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 1U)) 
                                               | ((0xcU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 3U)) 
                                                  | (3U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                        >> 5U)))))))),22);
        bufp->chgQData(oldp+9,((0x3ffffffffULL & (((QData)((IData)(
                                                                   vlSelfRef.tb_top__DOT__in_flat[4U])) 
                                                   << 0x11U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.tb_top__DOT__in_flat[3U])) 
                                                     >> 0xfU)))),34);
        bufp->chgSData(oldp+11,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           >> 0x11U))),10);
        bufp->chgIData(oldp+12,((((0x78000U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x18U) 
                                                | (0xff8000U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 8U))) 
                                               & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   << 0x1cU) 
                                                  | (0xfff8000U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                        >> 4U))))) 
                                  | (0x7800U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  << 0x14U) 
                                                 | (0xff800U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       >> 0xcU))) 
                                                | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    << 0x18U) 
                                                   | (0xfff800U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 8U)))))) 
                                 | ((0x780U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x10U) 
                                                | (0xff80U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 0x10U))) 
                                               ^ ((
                                                   vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   << 0x14U) 
                                                  | (0xfff80U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                        >> 0xcU))))) 
                                    | ((0x78U & ((~ 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    << 9U) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 0x17U))) 
                                                 << 3U)) 
                                       | (((IData)(
                                                   (0x60000U 
                                                    == 
                                                    (0x60000U 
                                                     & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                           << 2U) | 
                                          (((IData)(
                                                    (0U 
                                                     != 
                                                     (0x60000U 
                                                      & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                            << 1U) 
                                           | (1U & 
                                              (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  >> 0x12U))))))))),19);
        bufp->chgIData(oldp+13,((0x7ffffffU & ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 5U) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  >> 0x1bU)))),27);
        bufp->chgCData(oldp+14,((0xffU & ((((0xffU 
                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  << 0x12U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    >> 0xeU)) 
                                                + (
                                                   (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1aU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 6U)))) 
                                            * (0xffU 
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
                                              ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
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
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                             >> 0xeU)), 
                                                                         (0xffU 
                                                                          & ((IData)(1U) 
                                                                             + 
                                                                             ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                               << 0x1aU) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U))))))), (IData)(3U))))),8);
        bufp->chgIData(oldp+15,((0xfffffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                              << 0xaU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0x16U)))),20);
        bufp->chgCData(oldp+16,(((0xf0U & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 2U)) 
                                 | ((((0xcU >= (0xfU 
                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x16U)))
                                       ? (7U & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x3aU) 
                                                      + 
                                                      (7U 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                          >> 0x16U)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_top__DOT__in_flat[
                                                  (((IData)(0x3cU) 
                                                    + 
                                                    (7U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                        >> 0x16U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x3aU) 
                                                       + 
                                                       (7U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                           >> 0x16U))))))) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[
                                                   (((IData)(0x3aU) 
                                                     + 
                                                     (7U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                         >> 0x16U))) 
                                                    >> 5U)] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x3aU) 
                                                       + 
                                                       (7U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                           >> 0x16U)))))))
                                       : 0U) << 1U) 
                                    | (0xcU < (0xfU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 0x16U)))))),8);
        bufp->chgCData(oldp+17,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 1U))),4);
        bufp->chgCData(oldp+18,(((((0xfU == (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              >> 1U))) 
                                   << 5U) | (((0U != 
                                               (0xfU 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 1U))) 
                                              << 4U) 
                                             | (8U 
                                                & (VL_REDXOR_32(
                                                                (0xfU 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    >> 1U))) 
                                                   << 3U)))) 
                                 | ((4U & ((~ (0xfU 
                                               == (0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 1U)))) 
                                           << 2U)) 
                                    | ((2U & ((~ (0U 
                                                  != 
                                                  (0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 1U)))) 
                                              << 1U)) 
                                       | (1U & (~ VL_REDXOR_32(
                                                               (0xfU 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                   >> 1U))))))))),6);
        bufp->chgSData(oldp+19,((0x7ffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 0x10U))),11);
        bufp->chgIData(oldp+20,(((0xff0000U & ((((vlSelfRef.tb_top__DOT__in_flat[0U] 
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
        bufp->chgCData(oldp+21,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 8U))),8);
        bufp->chgCData(oldp+22,((0xffU & vlSelfRef.tb_top__DOT__in_flat[0U])),8);
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
                                         >> 0xaU))),4);
        bufp->chgBit(oldp+30,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0x11U)))));
        bufp->chgBit(oldp+31,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               != (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                            >> 0x11U)))));
        bufp->chgBit(oldp+32,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               < (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           >> 0x11U)))));
        bufp->chgBit(oldp+33,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          << 7U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 0x19U))) 
                               <= (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
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
        bufp->chgCData(oldp+36,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 0xbU))),4);
        bufp->chgCData(oldp+37,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                         >> 7U))),4);
        bufp->chgCData(oldp+38,((3U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       >> 5U))),2);
        bufp->chgCData(oldp+39,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 7U))),8);
        bufp->chgCData(oldp+40,((0xffU & ((0xf0U & 
                                           (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                            >> 7U)) 
                                          | (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              >> 0xbU))))),8);
        bufp->chgCData(oldp+41,((0x3fU & ((0x30U & 
                                           (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                            >> 1U)) 
                                          | ((0xcU 
                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 3U)) 
                                             | (3U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 5U)))))),6);
        bufp->chgCData(oldp+42,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          >> 9U))),8);
        bufp->chgCData(oldp+43,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          >> 1U))),8);
        bufp->chgCData(oldp+44,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 7U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           >> 0x19U)))),8);
        bufp->chgCData(oldp+45,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                          >> 0x11U))),8);
        bufp->chgBit(oldp+46,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                     >> 0x10U))));
        bufp->chgBit(oldp+47,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                     >> 0xfU))));
        bufp->chgCData(oldp+48,((0xffU & (VL_LTS_III(8, 
                                                     (0xffU 
                                                      & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 7U) 
                                                         | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                            >> 0x19U))), 
                                                     (0xffU 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 0x11U)))
                                           ? ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               << 0x17U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 >> 9U))
                                           : ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               << 0x1fU) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 >> 1U))))),8);
        bufp->chgCData(oldp+49,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                         >> 0x17U))),4);
        bufp->chgCData(oldp+50,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                         >> 0x13U))),4);
        bufp->chgBit(oldp+51,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0x12U))));
        bufp->chgBit(oldp+52,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0x11U))));
        bufp->chgCData(oldp+53,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 9U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           >> 0x17U)) 
                                         & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xdU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x13U))))),4);
        bufp->chgCData(oldp+54,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 9U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           >> 0x17U)) 
                                         | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xdU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x13U))))),4);
        bufp->chgCData(oldp+55,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           << 9U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                           >> 0x17U)) 
                                         ^ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 0xdU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x13U))))),4);
        bufp->chgCData(oldp+56,((0xfU & (~ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 9U) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               >> 0x17U))))),4);
        bufp->chgBit(oldp+57,((IData)((0x60000U == 
                                       (0x60000U & 
                                        vlSelfRef.tb_top__DOT__in_flat[4U])))));
        bufp->chgBit(oldp+58,((IData)((0U != (0x60000U 
                                              & vlSelfRef.tb_top__DOT__in_flat[4U])))));
        bufp->chgBit(oldp+59,((1U & (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        >> 0x12U)))));
        bufp->chgCData(oldp+60,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          >> 0xeU))),8);
        bufp->chgCData(oldp+61,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                          >> 6U))),8);
        bufp->chgCData(oldp+62,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           << 2U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 0x1eU)))),8);
        bufp->chgCData(oldp+63,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0x1bU))),3);
        bufp->chgCData(oldp+64,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x12U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 0xeU)) 
                                          + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x1aU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 6U))))),8);
        bufp->chgCData(oldp+65,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 2U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 0x1eU)) 
                                          << (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x1bU))))),8);
        bufp->chgCData(oldp+66,((0xffU & ((0xffU & 
                                           (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x12U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0xeU)) 
                                            + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                << 0x1aU) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 6U)))) 
                                          * (0xffU 
                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  << 2U) 
                                                 | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x1eU)) 
                                                << 
                                                (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x1bU))))))),8);
        bufp->chgCData(oldp+67,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x1aU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 6U)) 
                                          ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 2U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                >> 0x1eU))))),8);
        bufp->chgCData(oldp+68,((0xffU & (((0xffU & 
                                            (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 0x12U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 >> 0xeU)) 
                                             + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 << 0x1aU) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 6U)))) 
                                           * (0xffU 
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
                                             ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                 << 2U) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                   >> 0x1eU)))))),8);
        bufp->chgCData(oldp+69,((0xffU & ((IData)(1U) 
                                          + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 0x1aU) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 6U))))),8);
        bufp->chgCData(oldp+70,(((0U == (0xffU & ((IData)(1U) 
                                                  + 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1aU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 6U)))))
                                  ? 0U : (0xffU & VL_DIV_III(8, 
                                                             (0xffU 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 0xeU)), 
                                                             (0xffU 
                                                              & ((IData)(1U) 
                                                                 + 
                                                                 ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                   << 0x1aU) 
                                                                  | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                     >> 6U)))))))),8);
        bufp->chgCData(oldp+71,((0xffU & VL_MODDIV_III(8, 
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
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                          >> 0xeU)), 
                                                                      (0xffU 
                                                                       & ((IData)(1U) 
                                                                          + 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            << 0x1aU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 6U))))))), (IData)(3U)))),8);
        bufp->chgCData(oldp+72,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                          >> 2U))),8);
        bufp->chgCData(oldp+73,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           << 6U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           >> 0x1aU)))),8);
        bufp->chgCData(oldp+74,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                         >> 0x16U))),4);
        bufp->chgCData(oldp+75,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 6U))),4);
        bufp->chgCData(oldp+76,(((0xcU >= (0xfU & (
                                                   vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x16U)))
                                  ? (7U & (((0U == 
                                             (0x1fU 
                                              & ((IData)(0x3aU) 
                                                 + 
                                                 (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x16U)))))
                                             ? 0U : 
                                            (vlSelfRef.tb_top__DOT__in_flat[
                                             (((IData)(0x3cU) 
                                               + (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0x16U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(0x3aU) 
                                                     + 
                                                     (7U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                         >> 0x16U))))))) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[
                                              (((IData)(0x3aU) 
                                                + (7U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 0x16U))) 
                                               >> 5U)] 
                                              >> (0x1fU 
                                                  & ((IData)(0x3aU) 
                                                     + 
                                                     (7U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                         >> 0x16U)))))))
                                  : 0U)),3);
        bufp->chgBit(oldp+77,((0xcU < (0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               >> 0x16U)))));
        bufp->chgBit(oldp+78,((0xfU == (0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                >> 1U)))));
        bufp->chgBit(oldp+79,((0U != (0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              >> 1U)))));
        bufp->chgBit(oldp+80,((1U & VL_REDXOR_32((0xfU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                     >> 1U))))));
        bufp->chgBit(oldp+81,((1U & (~ (0xfU == (0xfU 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                    >> 1U)))))));
        bufp->chgBit(oldp+82,((1U & (~ (0U != (0xfU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 1U)))))));
        bufp->chgBit(oldp+83,((1U & (~ VL_REDXOR_32(
                                                    (0xfU 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                        >> 1U)))))));
        bufp->chgCData(oldp+84,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                          >> 0x13U))),8);
        bufp->chgCData(oldp+85,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0x10U))),3);
        bufp->chgCData(oldp+86,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            << 0xdU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                              >> 0x13U)) 
                                          << (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x10U))))),8);
        bufp->chgCData(oldp+87,((0xffU & ((0xffU & 
                                           (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                            >> 0x13U)) 
                                          >> (7U & 
                                              (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x10U))))),8);
        bufp->chgCData(oldp+88,((0xffU & VL_SHIFTRS_III(8,8,3, 
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
                                                                         & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                            >> 4U)) 
                                                                        == 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0xaU))) 
                                                                       << 0x11U) 
                                                                      | (((0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                              >> 4U)) 
                                                                          != 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0xaU))) 
                                                                         << 0x10U)))) 
                                                               | ((0xf000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                      << 6U)) 
                                                                  | ((((0xcU 
                                                                        >= 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            >> 0x16U)))
                                                                        ? 
                                                                       (7U 
                                                                        & (((0U 
                                                                             == 
                                                                             (0x1fU 
                                                                              & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))
                                                                             ? 0U
                                                                             : 
                                                                            (vlSelfRef.tb_top__DOT__in_flat[
                                                                             (((IData)(0x3cU) 
                                                                               + 
                                                                               (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                              >> 5U)] 
                                                                             << 
                                                                             ((IData)(0x20U) 
                                                                              - 
                                                                              (0x1fU 
                                                                               & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))))))) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[
                                                                              (((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                               >> 5U)] 
                                                                              >> 
                                                                              (0x1fU 
                                                                               & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))))
                                                                        : 0U) 
                                                                      << 9U) 
                                                                     | (((0xcU 
                                                                          < 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 0x16U))) 
                                                                         << 8U) 
                                                                        | (0xffU 
                                                                           & ((((0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)) 
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
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)), 
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
                                                            << 0x18U) 
                                                           | (0xff8000U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 8U))) 
                                                          & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x1cU) 
                                                             | (0xfff8000U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 4U))))) 
                                                      | (0x7800U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x14U) 
                                                             | (0xff800U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xcU))) 
                                                            | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                << 0x18U) 
                                                               | (0xfff800U 
                                                                  & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                     >> 8U)))))) 
                                                     | ((0x780U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x10U) 
                                                             | (0xff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0x10U))) 
                                                            ^ 
                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x14U) 
                                                             | (0xfff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xcU))))) 
                                                        | ((0x78U 
                                                            & ((~ 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 9U) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x17U))) 
                                                               << 3U)) 
                                                           | (((IData)(
                                                                       (0x60000U 
                                                                        == 
                                                                        (0x60000U 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                               << 2U) 
                                                              | (((IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0x60000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        >> 0x12U)))))))))) 
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
                                                                            << 0x17U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 9U))
                                                                           : 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x1fU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 1U)))))))))) 
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
                                                                             & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                                >> 4U)) 
                                                                            == 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xaU))) 
                                                                           << 0x11U) 
                                                                          | (((0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                                >> 4U)) 
                                                                              != 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0xaU))) 
                                                                             << 0x10U)))) 
                                                                   | ((0xf000U 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          << 6U)) 
                                                                      | ((((0xcU 
                                                                            >= 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))
                                                                            ? 
                                                                           (7U 
                                                                            & (((0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[
                                                                                (((IData)(0x3cU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                                >> 5U)] 
                                                                                << 
                                                                                ((IData)(0x20U) 
                                                                                - 
                                                                                (0x1fU 
                                                                                & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))))))) 
                                                                               | (vlSelfRef.tb_top__DOT__in_flat[
                                                                                (((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                                >> 5U)] 
                                                                                >> 
                                                                                (0x1fU 
                                                                                & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))))
                                                                            : 0U) 
                                                                          << 9U) 
                                                                         | (((0xcU 
                                                                              < 
                                                                              (0xfU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                             << 8U) 
                                                                            | (0xffU 
                                                                               & ((((0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)) 
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
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)), 
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
                                                            << 0x18U) 
                                                           | (0xff8000U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 8U))) 
                                                          & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x1cU) 
                                                             | (0xfff8000U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 4U))))) 
                                                      | (0x7800U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x14U) 
                                                             | (0xff800U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xcU))) 
                                                            | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                << 0x18U) 
                                                               | (0xfff800U 
                                                                  & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                     >> 8U)))))) 
                                                     | ((0x780U 
                                                         & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x10U) 
                                                             | (0xff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0x10U))) 
                                                            ^ 
                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 0x14U) 
                                                             | (0xfff80U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                   >> 0xcU))))) 
                                                        | ((0x78U 
                                                            & ((~ 
                                                                ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 9U) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x17U))) 
                                                               << 3U)) 
                                                           | (((IData)(
                                                                       (0x60000U 
                                                                        == 
                                                                        (0x60000U 
                                                                         & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                               << 2U) 
                                                              | (((IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0x60000U 
                                                                            & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        >> 0x12U)))))))))) 
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
                                                                            << 0x17U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 9U))
                                                                           : 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            << 0x1fU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 1U)))))))))) 
                          >> 0xcU) | ((IData)(((((QData)((IData)(
                                                                 (((0x78000U 
                                                                    & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                         << 0x18U) 
                                                                        | (0xff8000U 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 8U))) 
                                                                       & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x1cU) 
                                                                          | (0xfff8000U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 4U))))) 
                                                                   | (0x7800U 
                                                                      & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x14U) 
                                                                          | (0xff800U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xcU))) 
                                                                         | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                             << 0x18U) 
                                                                            | (0xfff800U 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 8U)))))) 
                                                                  | ((0x780U 
                                                                      & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x10U) 
                                                                          | (0xff80U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x10U))) 
                                                                         ^ 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 0x14U) 
                                                                          | (0xfff80U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0xcU))))) 
                                                                     | ((0x78U 
                                                                         & ((~ 
                                                                             ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                               << 9U) 
                                                                              | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x17U))) 
                                                                            << 3U)) 
                                                                        | (((IData)(
                                                                                (0x60000U 
                                                                                == 
                                                                                (0x60000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                            << 2U) 
                                                                           | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                               << 1U) 
                                                                              | (1U 
                                                                                & (~ 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x12U)))))))))) 
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
                                                                              << 0x17U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 9U))
                                                                             : 
                                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              << 0x1fU) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 1U))))))))) 
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
                                                      | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c))))) 
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
                                                       | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c))))) 
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
        bufp->chgWData(oldp+89,(__Vtemp_2),159);
        bufp->chgQData(oldp+94,((((QData)((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c)) 
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
        bufp->chgCData(oldp+96,(((((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
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
                                      << 5U) | (((0xffU 
                                                  & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      << 7U) 
                                                     | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                        >> 0x19U))) 
                                                 <= 
                                                 (0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0x11U))) 
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
                                    | ((((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                  >> 4U)) 
                                         == (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                              >> 0xaU))) 
                                        << 1U) | ((0xfU 
                                                   & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                      >> 4U)) 
                                                  != 
                                                  (0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      >> 0xaU))))))),8);
        bufp->chgIData(oldp+97,((((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                  << 0x10U) | ((0xff00U 
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
                                                       << 0x17U) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 9U))
                                                      : 
                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       << 0x1fU) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 1U))))))),24);
        bufp->chgBit(oldp+98,(((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                        >> 4U)) == 
                               (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0xaU)))));
        bufp->chgBit(oldp+99,(((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                        >> 4U)) != 
                               (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0xaU)))));
        bufp->chgCData(oldp+100,((0xffU & ((0x8000U 
                                            & vlSelfRef.tb_top__DOT__in_flat[3U])
                                            ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                            : ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                << 7U) 
                                               | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 0x19U))))),8);
    }
    bufp->chgBit(oldp+101,(vlSelfRef.tb_top__DOT__clk));
    bufp->chgIData(oldp+102,(vlSelfRef.tb_top__DOT__cyc),32);
    bufp->chgIData(oldp+103,(vlSelfRef.tb_top__DOT__cycles),32);
    bufp->chgIData(oldp+104,(vlSelfRef.tb_top__DOT__seed),32);
    bufp->chgIData(oldp+105,(vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat),24);
    bufp->chgCData(oldp+106,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c),8);
    bufp->chgCData(oldp+107,((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                      >> 4U))),4);
    bufp->chgCData(oldp+108,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c),8);
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
