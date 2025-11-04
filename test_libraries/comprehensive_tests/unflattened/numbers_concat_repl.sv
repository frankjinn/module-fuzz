

//------------------------------------------------------------------------------
// Module: concat_repl
// Concatenation and replication (Verilog‐2005 syntax).
//------------------------------------------------------------------------------
module numbers_concat_repl (
    input  wire [3:0]  a,
    input  wire [1:0]  b,
    output wire [7:0]  cat_ab,
    output wire [3:0]  rep_a,
    output wire [5:0]  rep_b
);
    // Concatenate a[3:0], b[1:0], and two zeros -> 8 bits
    assign cat_ab = { a, b, 2'b00 };

    // Replicate a twice → 8 bits, then take lower 4 bits
    wire [7:0] rep_a_full = { a, a };
    assign rep_a = rep_a_full[3:0];

    // Replicate b three times → 6 bits
    assign rep_b = { b, b, b };
endmodule
