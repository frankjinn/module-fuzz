

//------------------------------------------------------------------------------
// Module: arith
// Exercises arithmetic, signed/unsigned casts, and width promotion.
//------------------------------------------------------------------------------
module arith #(
    parameter integer W_A = 8,
    parameter integer W_B = 4
) (
    input  wire signed [W_A-1:0] a,
    input  wire        [W_B-1:0] b,
    output wire signed [W_A-1:0] sum_ab,
    output wire signed [W_A-1:0] diff_ab,
    output wire signed [W_A-1:0] prod_ab,
    output wire signed [W_A-1:0] quot_ab,
    output wire        [W_A-1:0] mod_ab
);
    // Extend b to signed W_A bits:
    wire signed [W_A-1:0] b_ext = $signed({{(W_A-W_B){1'b0}}, b});

    assign sum_ab  = a + b_ext;
    assign diff_ab = a - b_ext;
    assign prod_ab = a * b_ext;
    assign quot_ab = a / b_ext;
    assign mod_ab  = a % b_ext;
endmodule
