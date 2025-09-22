`default_nettype none
`timescale 1ns/1ps
module tb_top;

  // Declarations
  logic clk;
  logic rst_n;
  logic [139:0] in_flat;
  wire  [158:0] out_flat;
  integer cyc;
  reg [31:0] rng_state;

  // Clock generator
  initial clk = 1'b0;
  always #1 clk = ~clk;

  // Reset generator
  initial begin
    rst_n = 1'b0;
    #4 rst_n = 1'b1; // Release reset after 2 clock cycles
  end

  int cycles;
  int seed;
  initial begin
    cycles = 200; if ($value$plusargs("cycles=%d", cycles)) ;
    if (!$value$plusargs("seed=%d", seed)) seed = 3760660250;
    rng_state = seed;
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
    .rst_n(rst_n),
    .in_flat(in_flat),
    .out_flat(out_flat)
  );

  always @(posedge clk) begin
    cyc <= cyc + 1;
    $write("CYCLE=%0d IN=%0h OUT=%0h\n", cyc, in_flat, out_flat);
  end

  integer i;
  initial begin
    // Initialize inputs before starting
    // Linear congruential generator for deterministic cross-simulator randomization
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[31:0] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[63:32] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[95:64] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[127:96] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[139:128] = rng_state[11:0];
    @(negedge clk); // small settle before starting
    for (i = 0; i < cycles; i = i + 1) begin
      @(negedge clk); // update inputs on negative edge
    // Linear congruential generator for deterministic cross-simulator randomization
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[31:0] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[63:32] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[95:64] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[127:96] = rng_state;
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat[139:128] = rng_state[11:0];
    end
    @(posedge clk); // final clock edge
    $display("TB_SIM_OK cycles=%0d", cycles);
    $finish;
  end

endmodule
