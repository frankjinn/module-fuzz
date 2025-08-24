`default_nettype none
`timescale 1ns/1ps
module tb_top;

  // Declarations
  logic clk;
  logic [153:0] in_flat;
  wire  [158:0] out_flat;
  integer cyc;

  // Clock generator
  initial clk = 1'b0;
  always #1 clk = ~clk;

  int cycles;
  int seed;
  initial begin
    cycles = 200; if ($value$plusargs("cycles=%d", cycles)) ;
    if (!$value$plusargs("seed=%d", seed)) seed = 0;
    void'($urandom(seed));
    cyc = 0;
  end

  // Waveform dump (enable with Verilator --trace)
  initial begin
    $dumpfile("tb_top.vcd");
    $dumpvars(0, tb_top);
  end

  // DUT instance
  top dut (
    .clk(clk),
    .in_flat(in_flat),
    .out_flat(out_flat)
  );

  always @(posedge clk) begin
    cyc <= cyc + 1;
    $write("CYCLE=%0d IN=", cyc);
    for (int i = 154-1; i >= 0; i--) $write("%0d", in_flat[i]);
    $write(" OUT=");
    for (int j = 159-1; j >= 0; j--) $write("%0d", out_flat[j]);
    $write("\n");
  end

  integer i;
  initial begin
    @(negedge clk); // small settle before starting
    for (i = 0; i < cycles; i = i + 1) begin
      @(posedge clk);
in_flat = {32'($urandom()), 32'($urandom()), 32'($urandom()), 32'($urandom()), 26'($urandom())};
    end
    $display("TB_SIM_OK cycles=%0d", cycles);
    $finish;
  end

endmodule
