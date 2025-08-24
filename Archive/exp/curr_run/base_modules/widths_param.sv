

//------------------------------------------------------------------------------
// Module: param
// Parameterized widths and concatenation.
//------------------------------------------------------------------------------
module widths_param #(
    parameter integer WIDTH_A = 5,
    parameter integer WIDTH_B = 3
) (
    input  wire [WIDTH_A-1:0]  in_a,
    input  wire [WIDTH_B-1:0]  in_b,
    output wire [WIDTH_A+WIDTH_B-1:0] out_cat
);
    assign out_cat = { in_a, in_b };
endmodule
