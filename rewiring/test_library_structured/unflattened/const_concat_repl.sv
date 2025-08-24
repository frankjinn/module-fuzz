

//------------------------------------------------------------------------------
// Module: const_concat_repl
// Takes a 4-bit and a 4-bit vector plus a 2-bit vector; concatenates and replicates.
//------------------------------------------------------------------------------
module const_concat_repl (
    input  wire [3:0] a,
    input  wire [3:0] b,
    input  wire [1:0] c,
    output wire [7:0] cat_c,   // {a, b}
    output wire [7:0] rep_c,   // replicate a twice
    output wire [5:0] rep2_c   // replicate c three times
);
    assign cat_c   = { a, b };            // 8 bits
    assign rep_c   = { a, a };            // 8 bits (two copies of 4-bit a)
    assign rep2_c  = { c, c, c };         // 6 bits (three copies of 2-bit c)
endmodule
