

//------------------------------------------------------------------------------
// Module: logic
// Logical, reduction, and comparison operations on 4‐bit vectors.
//------------------------------------------------------------------------------
module widths_logic_mod (
    input  wire [3:0]  x,
    input  wire [3:0]  y,
    output wire        eq,      // x == y
    output wire        neq,     // x != y
    output wire        gt,      // x > y
    output wire        red_and, // &x
    output wire        red_or,  // |y
    output wire        red_xor  // ^x
);
    assign eq      = (x == y);
    assign neq     = (x != y);
    assign gt      = (x > y);
    assign red_and = &x;
    assign red_or  = |y;
    assign red_xor = ^x;
endmodule
