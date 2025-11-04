//------------------------------------------------------------------------------
// Wrapper for width_enum
// Flattens 1 inputs (4 bits) into `in_flat`,
// and flattens 2 outputs (5 bits) into `out_flat`.
//------------------------------------------------------------------------------
module width_enum_wrapper (
    input  wire [3:0] in_flat,
    output wire [4:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] e_in = in_flat[3:0];

  // Wires to capture original module outputs
  wire [3:0] e_out_eq;
  wire is_E2;

  // Instantiate the original module
  width_enum u_width_enum (
    .e_in(e_in),
    .e_out_eq(e_out_eq),
    .is_E2(is_E2)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[4:1] = e_out_eq;
  assign out_flat[0] = is_E2;

endmodule  // width_enum_wrapper