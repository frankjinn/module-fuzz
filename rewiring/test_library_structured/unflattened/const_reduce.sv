

//------------------------------------------------------------------------------
// Module: const_reduce
// Takes a 4-bit vector and performs all reduction ops (&, |, ^, ~&, ~|, ~^).
//------------------------------------------------------------------------------
module const_reduce (
    input  wire [3:0] in_vec,
    output wire       red_and_c,
    output wire       red_or_c,
    output wire       red_xor_c,
    output wire       red_nand_c,
    output wire       red_nor_c,
    output wire       red_xnor_c
);
    assign red_and_c  = &in_vec;     // reduction AND
    assign red_or_c   = |in_vec;     // reduction OR
    assign red_xor_c  = ^in_vec;     // reduction XOR
    assign red_nand_c = ~&in_vec;    // reduction NAND
    assign red_nor_c  = ~|in_vec;    // reduction NOR
    assign red_xnor_c = ~^in_vec;    // reduction XNOR
endmodule
