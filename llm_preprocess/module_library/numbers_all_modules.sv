//------------------------------------------------------------------------------
// Module: constant
// Exercises numeric literal parsing: decimal, binary, octal, hex, sized, unsized.
//------------------------------------------------------------------------------
module numbers_constant (
    output wire [31:0] const_dec,
    output wire [15:0] const_bin,
    output wire [11:0] const_oct,
    output wire [15:0] const_hex,
    output wire [3:0]  const_unsized    // unsized binary constant
);
    // Decimal literal
    assign const_dec     = 123456789;
    // 16-bit binary literal (with underscores)
    assign const_bin     = 16'b1010_1011_1100_1101;
    // 12-bit octal literal
    assign const_oct     = 12'o7523;
    // 16-bit hex literal
    assign const_hex     = 16'hABCD;
    // Unsized binary literal: width = number of digits (4), value = 1010₂
    assign const_unsized = 'b1010;
endmodule


//------------------------------------------------------------------------------
// Module: arithmetic
// Exercises +, −, *, /, % with signed/unsigned operands and width promotion.
//------------------------------------------------------------------------------
module numbers_numbers_arithmetic #(
    parameter integer W_A = 8,
    parameter integer W_B = 4
) (
    input  wire signed [W_A-1:0] a,
    input  wire        [W_B-1:0] b,
    output wire signed [W_A-1:0] sum_ab,
    output wire signed [W_A-1:0] diff_ab,
    output wire signed [W_A-1:0] prod_ab,
    output wire signed [W_A-1:0] quot_ab,
    output wire        [W_A-1:0] rem_ab
);
    // Zero-extend b to W_A bits, then cast to signed for arithmetic
    wire signed [W_A-1:0] b_ext = $signed({{(W_A-W_B){1'b0}}, b});

    assign sum_ab  = a + b_ext;
    assign diff_ab = a - b_ext;
    assign prod_ab = a * b_ext;
    assign quot_ab = a / b_ext;
    assign rem_ab  = a % b_ext;
endmodule


//------------------------------------------------------------------------------
// Module: bitwise_reduce
// Exercises reduction operators: &, |, ^.
//------------------------------------------------------------------------------
module numbers_bitwise_reduce (
    input  wire [7:0] in_vec,
    output wire       red_and,
    output wire       red_or,
    output wire       red_xor
);
    assign red_and = &in_vec;
    assign red_or  = |in_vec;
    assign red_xor = ^in_vec;
endmodule


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


//------------------------------------------------------------------------------
// Module: concat_repl
// Exercises concatenation ({}) and replication ({N{…}}).
//------------------------------------------------------------------------------
module numbers_concat_repl (
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


//------------------------------------------------------------------------------
// Module: shift
// Exercises shift left (<<) and shift right (>>).
//------------------------------------------------------------------------------
module numbers_shift (
    input  wire [7:0] data_in,
    input  wire [2:0] shift_amt,
    output wire [7:0] shl_out,
    output wire [7:0] shr_out
);
    assign shl_out = data_in << shift_amt;
    assign shr_out = data_in >> shift_amt;
endmodule


//------------------------------------------------------------------------------
// Module: select
// Exercises static and dynamic part‐select, plus overflow detection.
//------------------------------------------------------------------------------
module numbers_select (
    input  wire [15:0] data_in,
    input  wire [3:0]  idx,          // allow up to 15
    output wire [3:0]  static_ps,    // bits [7:4]
    output wire [3:0]  dynamic_ps,   // bits [idx +: 4]
    output wire        ovf_range     // idx > 12 → overflow for width-4
);
    // Static part-select: bits [7:4]
    assign static_ps = data_in[7:4];
    // Dynamic part-select (requires idx ≤ 12)
    assign dynamic_ps = data_in[idx +: 4];
    // Overflow if idx > 12 (so idx+3 > 15)
    assign ovf_range  = (idx > 4'd12);
endmodule


//------------------------------------------------------------------------------
// Module: relational
// Exercises equality, inequality, relational, case-equality (===), case-inequality (!==).
//------------------------------------------------------------------------------
module numbers_relational (
    input  wire [3:0] x,
    input  wire [3:0] y,
    output wire       eq,       // x == y (logical equality)
    output wire       neq,      // x != y
    output wire       gt,       // x >  y
    output wire       lt,       // x <  y
    output wire       ge,       // x >= y
    output wire       le,       // x <= y
    output wire       case_eq,  // x === y (case-equality)
    output wire       case_neq  // x !== y (case-inequality)
);
    assign eq       = (x == y);
    assign neq      = (x != y);
    assign gt       = (x >  y);
    assign lt       = (x <  y);
    assign ge       = (x >= y);
    assign le       = (x <= y);
    assign case_eq  = (x === y);
    assign case_neq = (x !== y);
endmodule


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


//------------------------------------------------------------------------------
// Module: reduce_case
// Exercises wildcard (case) equality with X/Z bits.
//------------------------------------------------------------------------------
module numbers_reduce_case (
    input  wire [3:0] a,
    input  wire [3:0] b,
    output wire       wild_eq,  // bitwise comparison treating X/Z as wildcard
    output wire       wild_neq  // bitwise not equal with wildcard
);
    // In Verilog, '===' and '!==' compare X/Z bits exactly, not wildcard.
    // To treat X/Z in b as “don’t care” (wildcard), we can use conditional:
    //   a matches b if for all bits i: (b[i] is X/Z) OR (a[i] == b[i]).
    wire [3:0] b_is_xz = (b ^ b);  // if b bit is X or Z, then b ^ b = X/Z, else 0
    // But simpler: use case equality and then mask:
    assign wild_eq  = ( ( (a ^ b) & ~({4{1'b0}}) ) == 4'b0000 ) ||      // a==b exactly
                      (&( (b ^ 4'bzzzz) === 4'bzzzz ));                // all bits of b are X/Z
    // Actually, for a general wildcard, you'd need bitwise logic per bit; but to exercise V3Number's wildcard functions,
    // we rely on '===' and '!==' operators.
    assign wild_eq  = (a === b);
    assign wild_neq = (a !== b);
endmodule


//------------------------------------------------------------------------------
// Module: arithmetic_reduce
// A composite module numbers_to combine several arithmetic and reduction operations.
// Ensures multi-operator coverage in a single expression.
//------------------------------------------------------------------------------
module numbers_arithmetic_reduce (
    input  wire [7:0]  p,
    input  wire [7:0]  q,
    output wire [7:0]  complex_expr,
    output wire        red_and_res,
    output wire        red_or_res
);
    // Complex expression: ((p + q) & (p ^ q)) | ((p - q) % (q + 1))
    wire [7:0] add_pq     = p + q;
    wire [7:0] xor_pq     = p ^ q;
    wire [7:0] and_part   = add_pq & xor_pq;
    wire [7:0] sub_pq     = p - q;
    wire [7:0] mod_part   = sub_pq % (q + 8'd1);
    assign complex_expr   = and_part | mod_part;

    assign red_and_res    = &complex_expr;
    assign red_or_res     = |complex_expr;
endmodule
