//------------------------------------------------------------------------------
// Module: arithmetic
// Exercises +, −, *, /, % with signed/unsigned operands and width promotion.
//------------------------------------------------------------------------------
module numbers_numbers_arithmetic (
    input  wire signed [4:0] b,
    input  wire        [7:0] a,
    output wire signed [4:0] sum_ab,
    output wire signed [4:0] diff_ab,
    output wire signed [4:0] prod_ab,
    output wire signed [4:0] quot_ab,
    output wire        [4:0] rem_ab
);

    // Promote both operands to signed 8-bit for operations
    wire signed [7:0] a_ext = $signed({1'b0, a});         // zero-extend a to signed
    wire signed [7:0] b_ext = $signed({3'b000, b});       // sign-extend b to 8 bits

    // Do math in 8-bit signed space, then truncate back to 5 bits
    assign sum_ab  = a_ext + b_ext;
    assign diff_ab = a_ext - b_ext;
    assign prod_ab = a_ext * b_ext;
    assign quot_ab = b_ext != 0 ? a_ext / b_ext : 5'sb0;
    assign rem_ab  = b_ext != 0 ? a_ext % b_ext : 5'b0;

endmodule

