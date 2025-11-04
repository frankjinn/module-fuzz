//------------------------------------------------------------------------------
// Wrapper for width_struct
// Flattens 2 inputs (12 bits) into `in_flat`,
// and flattens 2 outputs (12 bits) into `out_flat`.
//------------------------------------------------------------------------------
module width_struct_wrapper (
    input  wire [11:0] in_flat,
    output wire [11:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] a_in = in_flat[11:4];
  wire [3:0] b_in = in_flat[3:0];

  // Wires to capture original module outputs
  wire [7:0] a_out;
  wire [3:0] b_out;

  // Instantiate the original module
  width_struct u_width_struct (
    .a_in(a_in),
    .b_in(b_in),
    .a_out(a_out),
    .b_out(b_out)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[11:4] = a_out;
  assign out_flat[3:0] = b_out;

endmodule  // width_struct_wrapper