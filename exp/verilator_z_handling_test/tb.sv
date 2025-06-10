`timescale 1ns/1ps
`default_nettype none

module tb;
  parameter int IN_WIDTH  = 8;
  parameter int OUT_WIDTH = 8;
  parameter int CYCLES     = 20;

  // DUT interface
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
  integer z_count, normal_count;


  initial begin
    $dumpfile("tb.vcd");
    $dumpvars(0, tb);

    z_count      = 0;
    normal_count = 0;

    $display("Starting randomized testbench for top");
    $display("--------------------------------------------------");
    $display("| Iter |   in_flat   |      out_flat          |");
    $display("--------------------------------------------------");

    for (i = 0; i < CYCLES; i++) begin
      in_flat = $random;

      #1; // wait for outputs
      $display("| %4d | %b | %b |", i, in_flat, out_flat);

      // count bit-states
      for (int j = 0; j < OUT_WIDTH; j++) begin
        if (out_flat[j] === 1'bz)      z_count++;
        else                           normal_count++;
      end
    end

    $display("TOTAL_Z_BITS:      %0d", z_count);
    $display("TOTAL_NORMAL_BITS: %0d", normal_count);
    $finish;
  end
endmodule
