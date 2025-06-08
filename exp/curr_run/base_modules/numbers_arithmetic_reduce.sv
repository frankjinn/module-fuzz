

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
