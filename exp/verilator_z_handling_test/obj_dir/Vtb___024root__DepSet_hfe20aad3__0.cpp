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
    IData/*31:0*/ tb__DOT__normal_count;
    tb__DOT__normal_count = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"tb.vcd"});
    VL_PRINTF_MT("-Info: tb.sv:27: $dumpvar ignored, as Verilated without --trace\n");
    tb__DOT__z_count = 0U;
    tb__DOT__normal_count = 0U;
    VL_WRITEF_NX("Starting randomized testbench for top\n--------------------------------------------------\n| Iter |   in_flat   |      out_flat          |\n--------------------------------------------------\n",0);
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    0 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    1 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    2 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    3 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    4 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    5 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    6 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    7 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    8 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|    9 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   10 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   11 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   12 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   13 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   14 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   15 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   16 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   17 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   18 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    vlSelfRef.tb__DOT__in_flat = (0xffU & VL_RANDOM_I());
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb.sv", 
                                         40);
    VL_WRITEF_NX("|   19 | %b | %b |\n",0,8,vlSelfRef.tb__DOT__in_flat,
                 8,((((0x80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                << 7U)) | (0x40U & 
                                           (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                             + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                            << 4U))) 
                     | ((0x20U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                   * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                  << 2U)) | (0x10U 
                                             & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                 * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                                << 3U)))) 
                    | ((8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                               * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                              >> 1U)) | ((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))) 
                                         | (3U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))));
    if (((1U & (~ (IData)(vlSelfRef.tb__DOT__out_flat__en))) 
         && (1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 1U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 2U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 3U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 4U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 4U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 1U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 5U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b)) 
                                               >> 3U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 6U))) && (1U & (~ (1U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__a) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_adder_wrapper__DOT__b)) 
                                               >> 2U)))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    if (((1U & (~ ((IData)(vlSelfRef.tb__DOT__out_flat__en) 
                   >> 7U))) && (1U & (~ (0x1fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__a) 
                                                  * (IData)(vlSelfRef.tb__DOT__dut__DOT__u_multiplier_wrapper__DOT__b))))))) {
        tb__DOT__z_count = ((IData)(1U) + tb__DOT__z_count);
    } else {
        tb__DOT__normal_count = ((IData)(1U) + tb__DOT__normal_count);
    }
    VL_WRITEF_NX("TOTAL_Z_BITS:      %0d\nTOTAL_NORMAL_BITS: %0d\n",0,
                 32,tb__DOT__z_count,32,tb__DOT__normal_count);
    VL_FINISH_MT("tb.sv", 52, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, vlSelfRef.__VdlySched.awaitingCurrentTime());
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
