`include "sample_const_logic.sv"

//------------------------------------------------------------------------------
// Wrapper for const_logic
// Flattens 3 inputs (10 bits) into `in_flat`,
// and flattens 1 outputs (4 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_logic_wrapper (
    input  wire [9:0] in_flat,
    output wire [3:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] in1 = in_flat[9:6];
  wire [3:0] in2 = in_flat[5:2];
  wire [1:0] op = in_flat[1:0];

  // Wires to capture original module outputs
  wire [3:0] out;

  // Instantiate the original module
  const_logic u_const_logic (
    .in1(in1),
    .in2(in2),
    .op(op),
    .out(out)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[3:0] = out;

endmodule  // const_logic_wrapper