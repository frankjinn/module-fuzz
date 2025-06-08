

//------------------------------------------------------------------------------
// Module: const_logic
// Takes two 4-bit vectors and two 1-bit signals for bitwise and logical ops.
//------------------------------------------------------------------------------
module const_logic (
    input  wire [3:0] x,
    input  wire [3:0] y,
    input  wire       a,
    input  wire       b,
    output wire [3:0] and_c,
    output wire [3:0] or_c,
    output wire [3:0] xor_c,
    output wire [3:0] not_c,   // NOT of x
    output wire       land_c,  // a && b
    output wire       lor_c,   // a || b
    output wire       lnot_c   // !a
);
    assign and_c  = x & y;
    assign or_c   = x | y;
    assign xor_c  = x ^ y;
    assign not_c  = ~x;
    assign land_c = a && b;
    assign lor_c  = a || b;
    assign lnot_c = !a;
endmodule
