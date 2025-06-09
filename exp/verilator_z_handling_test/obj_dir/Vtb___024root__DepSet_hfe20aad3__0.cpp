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
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"tb.vcd"});
    VL_PRINTF_MT("-Info: tb.sv:27: $dumpvar ignored, as Verilated without --trace\n");
    tb__DOT__z_count = 0U;
    tb__DOT__x_count = 0U;
    tb__DOT__normal_count = 0U;
    VL_WRITEF_NX("Starting randomized testbench for top\n--------------------------------------------------\n| Iter |   in_flat   |      out_flat          |\n--------------------------------------------------\n",0);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    0 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    1 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    2 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    3 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    4 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    5 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    6 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    7 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    8 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|    9 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   10 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   11 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   12 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   13 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   14 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   15 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   16 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   17 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   18 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    vlSelfRef.tb__DOT__in_flat = (0x3fU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         41);
    VL_WRITEF_NX("|   19 | %b | %b |\n",0,6,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                        >> 2U)) * (3U 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                << 4U)) | (0x40U & 
                                           ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                            << 6U))) 
                     | ((0x20U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          >> 2U)) * 
                                   (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                  << 3U)) | (0x10U 
                                             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat) 
                                                << 3U)))) 
                    | (((8U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                       >> 2U)) * (3U 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                               << 3U)) | (4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__adder_wrapper_out_flat))) 
                       | ((2U & (((3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                         >> 2U)) * 
                                  (3U & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                 >> 3U)) | (1U & ((
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                                       >> 2U)) 
                                                   * 
                                                   (3U 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat))) 
                                                  >> 1U))))));
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    VL_WRITEF_NX("TOTAL_Z_BITS:      %0d\nTOTAL_X_BITS:      %0d\nTOTAL_NORMAL_BITS: %0d\n",0,
                 32,tb__DOT__z_count,32,tb__DOT__x_count,
                 32,tb__DOT__normal_count);
    VL_FINISH_MT("tb.sv", 57, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__multiplier_wrapper_in_flat__1)));
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__multiplier_wrapper_in_flat__1 
        = vlSelfRef.tb__DOT__dut__DOT__multiplier_wrapper_in_flat;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(0U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
