

//------------------------------------------------------------------------------
// Module: concat_repl
// Exercises concatenation ({}) and replication ({N{…}}).
//------------------------------------------------------------------------------
module concat_repl (
    input  wire [3:0] a,
    input  wire [1:0] b,
    output wire [7:0] cat_ab,
    output wire [7:0] rep_a,
    output wire [5:0] rep_b
);
    // Concatenate 4-bit a, 2-bit b, and two zeros → 8 bits
    assign cat_ab = { a, b, 2'b00 };
    // Replicate a twice → 8 bits
    assign rep_a  = { {a}, {a} };
    // Replicate b three times → 6 bits
    assign rep_b  = { {b}, {b}, {b} };
endmodule
