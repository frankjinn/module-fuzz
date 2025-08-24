

//------------------------------------------------------------------------------
// Module: bitwise_logic
// Exercises bitwise &, |, ^ between two vectors.
//------------------------------------------------------------------------------
module numbers_bitwise_logic (
    input  wire [7:0] x,
    input  wire [7:0] y,
    output wire [7:0] and_xy,
    output wire [7:0] or_xy,
    output wire [7:0] xor_xy
);
    assign and_xy = x & y;
    assign or_xy  = x | y;
    assign xor_xy = x ^ y;
endmodule
