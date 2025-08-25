//------------------------------------------------------------------------------
// Module: const_arith
// Takes two 8-bit inputs and computes sum, difference, product, quotient, and remainder.
//------------------------------------------------------------------------------
module const_arith (
    input  wire [7:0] a,
    input  wire [7:0] b,
    output wire [7:0] sum_c,
    output wire [7:0] diff_c,
    output wire [7:0] prod_c,
    output wire [7:0] quot_c,
    output wire [7:0] rem_c
);
    // Zero‐extend or sign‐extend as needed (here treat both as unsigned)
    assign sum_c  = a + b;
    assign diff_c = a - b;
    assign prod_c = a * b;
    assign quot_c = b != 0 ? (a / b) : 8'd0;
    assign rem_c  = b != 0 ? (a % b) : 8'd0;
endmodule
