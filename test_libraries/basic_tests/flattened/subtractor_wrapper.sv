//------------------------------------------------------------------------------
// Wrapper for adder
// Flattens 2 inputs (4 bits) into `in_flat`,
// and flattens 1 outputs (3 bits) into `out_flat`.
//------------------------------------------------------------------------------
module subtractor_wrapper (
    input  wire [3:0] in_flat,
    output wire [2:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [1:0] a = in_flat[3:2];
  wire [1:0] b = in_flat[1:0];

  // Wires to capture original module outputs
  wire [2:0] data_out;

  // Instantiate the original module
  adder u_subtractor (
    .a(a),
    .b(b),
    .data_out(data_out)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[2:0] = data_out;

endmodule  // adder_wrapper