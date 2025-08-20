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
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.tb_top__DOT__clk));
    bufp->chgCData(oldp+1,(vlSelfRef.tb_top__DOT__in_flat),8);
    bufp->chgSData(oldp+2,(vlSelfRef.tb_top__DOT__out_flat),11);
    bufp->chgIData(oldp+3,(vlSelfRef.tb_top__DOT__cyc),32);
    bufp->chgIData(oldp+4,(vlSelfRef.tb_top__DOT__cycles),32);
    bufp->chgIData(oldp+5,(vlSelfRef.tb_top__DOT__seed),32);
    bufp->chgIData(oldp+6,(vlSelfRef.tb_top__DOT__i),32);
    bufp->chgCData(oldp+7,(((0xeU & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                     << 1U)) | (1U 
                                                & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__multiplier_wrapper_out_reg)))),4);
    bufp->chgCData(oldp+8,(vlSelfRef.tb_top__DOT__dut__DOT__u_adder_wrapper__DOT__data_out),3);
    bufp->chgCData(oldp+9,(((8U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                   >> 4U)) | ((4U & 
                                               ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out) 
                                                << 1U)) 
                                              | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)))),4);
    bufp->chgCData(oldp+10,((0x1fU & (((2U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                              >> 6U)) 
                                       | (1U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out) 
                                                >> 1U))) 
                                      * (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)))),5);
    bufp->chgCData(oldp+11,(((8U & ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_adder_wrapper__DOT__data_out) 
                                    << 2U)) | (7U & 
                                               ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                                >> 3U)))),4);
    bufp->chgCData(oldp+12,(vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out),3);
    bufp->chgCData(oldp+13,(vlSelfRef.tb_top__DOT__dut__DOT__multiplier_wrapper_out_reg),5);
    bufp->chgCData(oldp+14,((3U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                   >> 1U))),2);
    bufp->chgCData(oldp+15,(((2U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                    << 1U)) | (1U & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__multiplier_wrapper_out_reg)))),2);
    bufp->chgCData(oldp+16,(((2U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                    >> 6U)) | (1U & 
                                               ((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_subtractor_wrapper__DOT__data_out) 
                                                >> 1U)))),2);
    bufp->chgCData(oldp+17,(vlSelfRef.tb_top__DOT__dut__DOT__u_multiplier_wrapper__DOT__b),2);
    bufp->chgCData(oldp+18,(((2U & (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_adder_wrapper__DOT__data_out)) 
                             | (1U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                      >> 5U)))),2);
    bufp->chgCData(oldp+19,((3U & ((IData)(vlSelfRef.tb_top__DOT__in_flat) 
                                   >> 3U))),2);
    bufp->chgIData(oldp+20,(vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i),32);
    bufp->chgIData(oldp+21,(vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j),32);
}

void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
