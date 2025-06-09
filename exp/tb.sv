`timescale 1ns/1ps
`default_nettype none

module tb;
  parameter int IN_WIDTH  = 5;
  parameter int OUT_WIDTH = 477;
  parameter int CYCLES     = 20;

  // DUT interface
  logic clk = 0;
  logic rst_n;
  logic [IN_WIDTH-1:0]  in_flat;
  wire  [OUT_WIDTH-1:0] out_flat;

  // instantiate DUT
  top dut (
    .in_flat(in_flat),
    .out_flat(out_flat)
  );

  // counters
  integer i;
  integer z_count, x_count, normal_count;

  // clock
  always #5 clk = ~clk;

  initial begin
    $dumpfile("tb.vcd");
    $dumpvars(0, tb);

    rst_n = 0;
    #10;
    rst_n = 1;

    z_count      = 0;
    x_count      = 0;
    normal_count = 0;

    for (i = 0; i < CYCLES; i++) begin
      @(posedge clk);
      in_flat = $urandom;

      #1; // wait for outputs

      // count bit-states
      for (int j = 0; j < OUT_WIDTH; j++) begin
        casez (out_flat[j])
          1'bz: z_count++;
          1'bx: x_count++;
          default: normal_count++;
        endcase
      end
    end

    $display("TOTAL_Z_BITS:      %0d", z_count);
    $display("TOTAL_X_BITS:      %0d", x_count);
    $display("TOTAL_NORMAL_BITS: %0d", normal_count);
    $finish;
  end
endmodule
