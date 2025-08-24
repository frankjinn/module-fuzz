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


//------------------------------------------------------------------------------
// Module: const_compare
// Takes two 8-bit vectors and two 4-bit vectors; performs various comparisons.
//------------------------------------------------------------------------------
module const_compare (
    input  wire [7:0] a,
    input  wire [7:0] b,
    input  wire [3:0] c,
    input  wire [3:0] d,
    output wire       eq_c,       // a == b
    output wire       neq_c,      // a != b
    output wire       lt_c,       // a <  b
    output wire       le_c,       // a <= b
    output wire       gt_c,       // a >  b
    output wire       ge_c,       // a >= b
    output wire       case_eq_c,  // c === d
    output wire       case_neq_c  // c !== d
);
    assign eq_c       = (a ==  b);
    assign neq_c      = (a !=  b);
    assign lt_c       = (a <   b);
    assign le_c       = (a <=  b);
    assign gt_c       = (a >   b);
    assign ge_c       = (a >=  b);
    assign case_eq_c  = (c === d);
    assign case_neq_c = (c !== d);
endmodule


//------------------------------------------------------------------------------
// Module: const_shift
// Takes one 8-bit vector and a 3-bit shift amount; performs logical and arithmetic shifts.
//------------------------------------------------------------------------------
module const_shift (
    input  wire [7:0] data_in,
    input  wire [2:0] shift_amt,
    output wire [7:0] shl_c,
    output wire [7:0] shr_c,
    output wire [7:0] ashr_c
);
    assign shl_c  = data_in << shift_amt;            // logical left shift
    assign shr_c  = data_in >> shift_amt;            // logical right shift
    assign ashr_c = $signed(data_in) >>> shift_amt;  // arithmetic right shift
endmodule


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


//------------------------------------------------------------------------------
// Module: const_conditional
// Takes four 8-bit vectors and two select bits; applies nested ternary logic.
//------------------------------------------------------------------------------
module const_conditional (
    input  wire [7:0] a,
    input  wire [7:0] b,
    input  wire [7:0] c,
    input  wire [7:0] d,
    input  wire       sel1,
    input  wire       sel2,
    output wire [7:0] cond1_c,  // sel1 ? a : b
    output wire [7:0] cond2_c,  // sel2 ? (sel1 ? a : b) : c
    output wire [7:0] cond3_c   // (signed c < signed d) ? a : b
);
    assign cond1_c = sel1 ? a : b;
    assign cond2_c = sel2 ? cond1_c : c;
    assign cond3_c = ($signed(c) < $signed(d)) ? a : b;
endmodule


//------------------------------------------------------------------------------
// Module: const_nested
// Takes four 8-bit vectors and one 3-bit shift; computes a complex nested expression.
//------------------------------------------------------------------------------
module const_nested (
    input  wire [7:0] p,
    input  wire [7:0] q,
    input  wire [7:0] r,
    input  wire [2:0] s,
    output wire [7:0] nested_c
);
    // (( (p + q) * (r << s) ) & (q ^ r)) | ((p / (q + 8'd1)) % 8'd3)
    wire [7:0] add_pq    = p + q;
    wire [7:0] shl_rs    = r << s;
    wire [7:0] mul_part  = add_pq * shl_rs;
    wire [7:0] xor_qr    = q ^ r;
    wire [7:0] and_part  = mul_part & xor_qr;
    wire [7:0] denom     = q + 8'd1;
    wire [7:0] div_part  = (denom != 8'd0) ? (p / denom) : 8'd0;
    wire [7:0] mod_part  = div_part % 8'd3;
    assign nested_c      = and_part | mod_part;
endmodule


//------------------------------------------------------------------------------
// Module: const_partselect
// Takes two 8-bit vectors and a 4-bit index; performs static and dynamic part-selects.
//------------------------------------------------------------------------------
module const_partselect (
    input  wire [7:0] data1,
    input  wire [7:0] data2,
    input  wire [3:0] idx,          // 0..15
    output wire [3:0] sel1_c,       // data1[7:4]
    output wire [2:0] sel2_c,       // data2[idx +: 3]
    output wire       ovf_range     // idx > 12 → overflow for width-3
);
    assign sel1_c   = data1[7:4];
    assign sel2_c   = (idx <= 4'd12) ? data2[idx +: 3] : 3'd0;
    assign ovf_range = (idx > 4'd12);
endmodule
