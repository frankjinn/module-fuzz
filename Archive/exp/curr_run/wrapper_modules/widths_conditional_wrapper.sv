
//------------------------------------------------------------------------------
// Wrapper for widths_conditional
// Flattens 3 inputs (9 bits) into `in_flat`,
// and flattens 1 outputs (4 bits) into `out_flat`.
//------------------------------------------------------------------------------
module widths_conditional_wrapper (
    input  wire [8:0] in_flat,
    output wire [3:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire sel = in_flat[8];
  wire [3:0] x = in_flat[7:4];
  wire [3:0] y = in_flat[3:0];

  // Wires to capture original module outputs
  wire [3:0] z;

  // Instantiate the original module
  widths_conditional u_widths_conditional (
    .sel(sel),
    .x(x),
    .y(y),
    .z(z)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[3:0] = z;

endmodule  // widths_conditional_wrapper