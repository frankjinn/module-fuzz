//------------------------------------------------------------------------------
// Wrapper for select
// Flattens 2 inputs (20 bits) into `in_flat`,
// and flattens 3 outputs (9 bits) into `out_flat`.
//------------------------------------------------------------------------------
module select_wrapper (
    input  wire [19:0] in_flat,
    output wire [8:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [15:0] data_in = in_flat[19:4];
  wire [3:0] idx = in_flat[3:0];

  // Wires to capture original module outputs
  wire [3:0] static_ps;
  wire [3:0] dynamic_ps;
  wire ovf_range;

  // Instantiate the original module
  select u_select (
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

endmodule  // select_wrapper