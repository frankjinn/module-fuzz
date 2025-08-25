`include "const_nested.sv"

//------------------------------------------------------------------------------
// Wrapper for const_nested
// Flattens 4 inputs (27 bits) into `in_flat`,
// and flattens 1 outputs (8 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_nested_wrapper (
    input  wire [26:0] in_flat,
    output wire [7:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] p = in_flat[26:19];
  wire [7:0] q = in_flat[18:11];
  wire [7:0] r = in_flat[10:3];
  wire [2:0] s = in_flat[2:0];

  // Wires to capture original module outputs
  wire [7:0] nested_c;

  // Instantiate the original module
  const_nested u_const_nested (
    .p(p),
    .q(q),
    .r(r),
    .s(s),
    .nested_c(nested_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[7:0] = nested_c;

endmodule  // const_nested_wrapper