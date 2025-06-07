

//------------------------------------------------------------------------------
// Module: bitwise_reduce
// Exercises reduction operators: &, |, ^.
//------------------------------------------------------------------------------
module bitwise_reduce (
    input  wire [7:0] in_vec,
    output wire       red_and,
    output wire       red_or,
    output wire       red_xor
);
    assign red_and = &in_vec;
    assign red_or  = |in_vec;
    assign red_xor = ^in_vec;
endmodule
