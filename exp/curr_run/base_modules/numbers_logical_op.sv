

//------------------------------------------------------------------------------
// Module: logical_op
// Exercises logical AND (&&), logical OR (||), and logical NOT (!) on single‐bit inputs.
//------------------------------------------------------------------------------
module numbers_logical_op (
    input  wire a,
    input  wire b,
    output wire land_ab,
    output wire lor_ab,
    output wire lnot_a
);
    assign land_ab = a && b;
    assign lor_ab  = a || b;
    assign lnot_a  = !a;
endmodule
