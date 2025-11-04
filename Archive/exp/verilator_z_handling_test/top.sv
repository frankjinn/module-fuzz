
// Automatically generated top module
module top (
    input  wire [7:0] in_flat,
    output wire [7:0] out_flat
);

  // Per-module flattened I/O buses
  wire [3:0] adder_wrapper_in_flat;
  wire [2:0] adder_wrapper_out_flat;
  wire [3:0] multiplier_wrapper_in_flat;
  wire [4:0] multiplier_wrapper_out_flat;

  // Drive module inputs from top-level in_flat
  assign adder_wrapper_in_flat[0] = in_flat[4];
  assign adder_wrapper_in_flat[1] = in_flat[0];
  assign adder_wrapper_in_flat[2] = in_flat[3];
  assign adder_wrapper_in_flat[3] = in_flat[7];
  assign multiplier_wrapper_in_flat[0] = in_flat[5];
  assign multiplier_wrapper_in_flat[1] = in_flat[2];
  assign multiplier_wrapper_in_flat[2] = in_flat[6];
  assign multiplier_wrapper_in_flat[3] = in_flat[1];

  // Drive top-level out_flat from module outputs
  assign out_flat[0] = adder_wrapper_out_flat[0];
  assign out_flat[1] = adder_wrapper_out_flat[1];
  assign out_flat[6] = adder_wrapper_out_flat[2];
  assign out_flat[7] = multiplier_wrapper_out_flat[0];
  assign out_flat[4] = multiplier_wrapper_out_flat[1];
  assign out_flat[2] = multiplier_wrapper_out_flat[2];
  assign out_flat[5] = multiplier_wrapper_out_flat[3];
  assign out_flat[3] = multiplier_wrapper_out_flat[4];

  // Instantiate each module's wrapper
  adder_wrapper u_adder_wrapper (
    .in_flat  (adder_wrapper_in_flat),
    .out_flat (adder_wrapper_out_flat)
  );
  multiplier_wrapper u_multiplier_wrapper (
    .in_flat  (multiplier_wrapper_in_flat),
    .out_flat (multiplier_wrapper_out_flat)
  );

endmodule