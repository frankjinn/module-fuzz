

//------------------------------------------------------------------------------
// Module: const_compare
// Takes two 8-bit vectors and two 4-bit vectors; performs various comparisons.
//------------------------------------------------------------------------------
module const_compare (
    input  wire [7:0] a,
    input  wire [7:0] b,
    input  wire [3:0] c,
    input  wire [3:0] d,
    output wire       eq_c,       // a == b
    output wire       neq_c,      // a != b
    output wire       lt_c,       // a <  b
    output wire       le_c,       // a <= b
    output wire       gt_c,       // a >  b
    output wire       ge_c,       // a >= b
    output wire       case_eq_c,  // c === d
    output wire       case_neq_c  // c !== d
);
    assign eq_c       = (a ==  b);
    assign neq_c      = (a !=  b);
    assign lt_c       = (a <   b);
    assign le_c       = (a <=  b);
    assign gt_c       = (a >   b);
    assign ge_c       = (a >=  b);
    assign case_eq_c  = (c === d);
    assign case_neq_c = (c !== d);
endmodule
