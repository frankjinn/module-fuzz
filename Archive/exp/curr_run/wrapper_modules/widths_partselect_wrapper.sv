
//------------------------------------------------------------------------------
// Wrapper for widths_partselect
// Flattens 2 inputs (19 bits) into `in_flat`,
// and flattens 3 outputs (9 bits) into `out_flat`.
//------------------------------------------------------------------------------
module widths_partselect_wrapper (
    input  wire [18:0] in_flat,
    output wire [8:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [15:0] data_in = in_flat[18:3];
  wire [2:0] idx = in_flat[2:0];

  // Wires to capture original module outputs
  wire [3:0] static_ps;
  wire [3:0] dynamic_ps;
  wire ovf_range;

  // Instantiate the original module
  widths_partselect u_widths_partselect (
    .data_in(data_in),
    .idx(idx),
    .static_ps(static_ps),
    .dynamic_ps(dynamic_ps),
    .ovf_range(ovf_range)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[8:5] = static_ps;
  assign out_flat[4:1] = dynamic_ps;
  assign out_flat[0] = ovf_range;

endmodule  // widths_partselect_wrapper