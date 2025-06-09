// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__clk;
        CData/*0:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn;
        CData/*5:0*/ tb__DOT__in_flat;
        CData/*7:0*/ tb__DOT__dut__DOT__const_compare_wrapper_out_flat;
        CData/*5:0*/ tb__DOT__dut__DOT__const_reduce_wrapper_out_flat;
        CData/*2:0*/ tb__DOT__dut__DOT__numbers_bitwise_reduce_wrapper_out_flat;
        CData/*2:0*/ tb__DOT__dut__DOT__numbers_logical_op_wrapper_out_flat;
        CData/*7:0*/ tb__DOT__dut__DOT__numbers_relational_wrapper_out_flat;
        CData/*5:0*/ tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat;
        CData/*4:0*/ tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat;
        CData/*5:0*/ tb__DOT__dut__DOT__widths_logic_mod_wrapper_out_flat;
        CData/*1:0*/ tb__DOT__dut__DOT____Vcellout__u_widths_param_wrapper__out_flat;
        CData/*7:0*/ tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c;
        CData/*3:0*/ tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__a;
        CData/*3:0*/ tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b;
        CData/*3:0*/ tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__u_numbers_reduce_case__DOT__match_bits;
        CData/*3:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__din3;
        CData/*3:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout0;
        CData/*3:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout1;
        CData/*3:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout2;
        CData/*3:0*/ tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__dout3;
        CData/*3:0*/ tb__DOT__dut__DOT__u_widths_conditional_wrapper__DOT__z;
        CData/*3:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b__0;
        CData/*4:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat__0;
        CData/*7:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_compare_wrapper_out_flat__0;
        CData/*7:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c__0;
        CData/*5:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*3:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_numbers_reduce_case_wrapper__DOT__b__1;
        CData/*4:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_enum_mod_wrapper_out_flat__1;
        CData/*7:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_compare_wrapper_out_flat__1;
        CData/*7:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_const_nested_wrapper__DOT__nested_c__1;
        CData/*5:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_concat_repl_wrapper_in_flat__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__u_widths_array_wrapper__DOT__rstn__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb__DOT__dut__DOT__const_arith_wrapper_in_flat;
        SData/*9:0*/ tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat;
        SData/*9:0*/ tb__DOT__dut__DOT__const_logic_wrapper_in_flat;
        SData/*9:0*/ tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat;
        SData/*12:0*/ tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat;
        SData/*8:0*/ tb__DOT__dut__DOT__numbers_select_wrapper_out_flat;
        SData/*10:0*/ tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat;
        SData/*15:0*/ tb__DOT__dut__DOT__numbers_shift_wrapper_out_flat;
        SData/*15:0*/ tb__DOT__dut__DOT__widths_array_wrapper_out_flat;
        SData/*11:0*/ tb__DOT__dut__DOT__widths_cast_wrapper_out_flat;
        SData/*8:0*/ tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat;
        SData/*15:0*/ tb__DOT__dut__DOT__widths_shift_wrapper_out_flat;
        SData/*11:0*/ tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat;
        SData/*15:0*/ tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat;
        SData/*9:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat__0;
        SData/*11:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_cast_wrapper_out_flat__0;
        SData/*11:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat__0;
        SData/*8:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat__0;
        SData/*15:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_arith_wrapper_in_flat__0;
        SData/*9:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat__0;
        SData/*9:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_logic_wrapper_in_flat__0;
        SData/*10:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat__0;
        SData/*12:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat__0;
        SData/*9:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_arithmetic_reduce_wrapper_out_flat__1;
        SData/*15:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_union_mod_wrapper_out_flat__1;
    };
    struct {
        SData/*11:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_cast_wrapper_out_flat__1;
        SData/*11:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_struct_mod_wrapper_in_flat__1;
        SData/*8:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__widths_partselect_wrapper_out_flat__1;
        SData/*15:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_arith_wrapper_in_flat__1;
        SData/*9:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_concat_repl_wrapper_in_flat__1;
        SData/*9:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_logic_wrapper_in_flat__1;
        SData/*10:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_shift_wrapper_in_flat__1;
        SData/*12:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_in_flat__1;
        IData/*21:0*/ tb__DOT__dut__DOT__const_concat_repl_wrapper_out_flat;
        IData/*23:0*/ tb__DOT__dut__DOT__const_conditional_wrapper_out_flat;
        IData/*18:0*/ tb__DOT__dut__DOT__const_logic_wrapper_out_flat;
        IData/*23:0*/ tb__DOT__dut__DOT__const_shift_wrapper_out_flat;
        IData/*23:0*/ tb__DOT__dut__DOT__numbers_bitwise_logic_wrapper_out_flat;
        IData/*21:0*/ tb__DOT__dut__DOT__numbers_concat_repl_wrapper_out_flat;
        IData/*24:0*/ tb__DOT__dut__DOT__numbers_numbers_arithmetic_wrapper_out_flat;
        IData/*17:0*/ tb__DOT__dut__DOT__widths_concat_repl_wrapper_out_flat;
        IData/*23:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_conditional_wrapper_out_flat__0;
        IData/*23:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__const_conditional_wrapper_out_flat__1;
        IData/*31:0*/ __VactIterCount;
        QData/*39:0*/ tb__DOT__dut__DOT__const_arith_wrapper_out_flat;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerVec<17> __VstlTriggered;
    VlTriggerVec<19> __VactTriggered;
    VlTriggerVec<19> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
