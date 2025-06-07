//------------------------------------------------------------------------------
// Wrapper for union
// Flattens 1 inputs (16 bits) into `in_flat`,
// and flattens 2 outputs (16 bits) into `out_flat`.
//------------------------------------------------------------------------------
module union_wrapper (
    input  wire [15:0] in_flat,
    output wire [15:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [15:0] u_in = in_flat[15:0];

  // Wires to capture original module outputs
  wire [7:0] u_low;
  wire [7:0] u_high;

  // Instantiate the original module
  union u_union (
    .u_in(u_in),
    .u_low(u_low),
    .u_high(u_high)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[15:8] = u_low;
  assign out_flat[7:0] = u_high;

endmodule  // union_wrapper