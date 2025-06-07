//------------------------------------------------------------------------------
// Wrapper for const_reduce
// Flattens 1 inputs (4 bits) into `in_flat`,
// and flattens 6 outputs (6 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_reduce_wrapper (
    input  wire [3:0] in_flat,
    output wire [5:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] in_vec = in_flat[3:0];

  // Wires to capture original module outputs
  wire red_and_c;
  wire red_or_c;
  wire red_xor_c;
  wire red_nand_c;
  wire red_nor_c;
  wire red_xnor_c;

  // Instantiate the original module
  const_reduce u_const_reduce (
    .in_vec(in_vec),
    .red_and_c(red_and_c),
    .red_or_c(red_or_c),
    .red_xor_c(red_xor_c),
    .red_nand_c(red_nand_c),
    .red_nor_c(red_nor_c),
    .red_xnor_c(red_xnor_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[5] = red_and_c;
  assign out_flat[4] = red_or_c;
  assign out_flat[3] = red_xor_c;
  assign out_flat[2] = red_nand_c;
  assign out_flat[1] = red_nor_c;
  assign out_flat[0] = red_xnor_c;

endmodule  // const_reduce_wrapper