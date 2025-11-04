//------------------------------------------------------------------------------
// Wrapper for array
// Flattens 6 inputs (18 bits) into `in_flat`,
// and flattens 4 outputs (16 bits) into `out_flat`.
//------------------------------------------------------------------------------
module array_wrapper (
    input  wire [17:0] in_flat,
    output wire [15:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire clk = in_flat[17];
  wire rstn = in_flat[16];
  wire [3:0] din0 = in_flat[15:12];
  wire [3:0] din1 = in_flat[11:8];
  wire [3:0] din2 = in_flat[7:4];
  wire [3:0] din3 = in_flat[3:0];

  // Wires to capture original module outputs
  wire [3:0] dout0;
  wire [3:0] dout1;
  wire [3:0] dout2;
  wire [3:0] dout3;

  // Instantiate the original module
  array u_array (
    .clk(clk),
    .rstn(rstn),
    .din0(din0),
    .din1(din1),
    .din2(din2),
    .din3(din3),
    .dout0(dout0),
    .dout1(dout1),
    .dout2(dout2),
    .dout3(dout3)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[15:12] = dout0;
  assign out_flat[11:8] = dout1;
  assign out_flat[7:4] = dout2;
  assign out_flat[3:0] = dout3;

endmodule  // array_wrapper