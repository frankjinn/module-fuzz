`include "const_partselect.sv"

//------------------------------------------------------------------------------
// Wrapper for const_partselect
// Flattens 3 inputs (20 bits) into `in_flat`,
// and flattens 3 outputs (8 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_partselect_wrapper (
    input  wire [19:0] in_flat,
    output wire [7:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] data1 = in_flat[19:12];
  wire [7:0] data2 = in_flat[11:4];
  wire [3:0] idx = in_flat[3:0];

  // Wires to capture original module outputs
  wire [3:0] sel1_c;
  wire [2:0] sel2_c;
  wire ovf_range;

  // Instantiate the original module
  const_partselect u_const_partselect (
    .data1(data1),
    .data2(data2),
    .idx(idx),
    .sel1_c(sel1_c),
    .sel2_c(sel2_c),
    .ovf_range(ovf_range)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[7:4] = sel1_c;
  assign out_flat[3:1] = sel2_c;
  assign out_flat[0] = ovf_range;

endmodule  // const_partselect_wrapper