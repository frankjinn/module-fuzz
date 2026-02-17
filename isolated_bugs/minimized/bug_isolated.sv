// =============================================================================
// ISOLATED BUG: tribug_1339297989_1762975525
// =============================================================================
// Race condition: combinational output of arithmetic_reduce drives a data
// input (din0[2]) of the sequential array module. Both the data and the
// array's clock (in_flat[24]) change simultaneously on @(negedge clk),
// causing simulators to disagree on whether array latches the old or new value.
//
// Essential wire:
//   arithmetic_reduce_wrapper_out_flat[3] -> array_wrapper_in_flat[14]
//   which maps to: arithmetic_reduce.complex_expr[1] -> array.din0[2]
//
// To reproduce:
//   Verilatr:  [verilator-bin] --binary --timing -Wno-TIMESCALEMOD
//              -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-UNUSEDSIGNAL
//              -Wno-UNDRIVEN -Wno-PINMISSING -o sim bug_isolated.sv
//              && ./obj_dir/sim
//   Icarus:    iverilog -g2012 -o sim.vvp bug_isolated.sv && vvp sim.vvp
//
//   Compare CYCLE lines — differences appear starting around cycle 16.
// =============================================================================

`default_nettype none
`timescale 1ns/1ps

// =============================================================================
// Module: arithmetic_reduce (purely combinational — the SOURCE of the bug wire)
// =============================================================================
module arithmetic_reduce (
    input  wire [7:0]  p,
    input  wire [7:0]  q,
    output wire [7:0]  complex_expr,
    output wire        red_and_res,
    output wire        red_or_res
);
    wire [7:0] add_pq   = p + q;
    wire [7:0] xor_pq   = p ^ q;
    wire [7:0] and_part  = add_pq & xor_pq;
    wire [7:0] sub_pq   = p - q;
    wire [7:0] mod_part  = sub_pq % (q + 8'd1);
    assign complex_expr  = and_part | mod_part;

    assign red_and_res   = &complex_expr;
    assign red_or_res    = |complex_expr;
endmodule

// =============================================================================
// Wrapper: arithmetic_reduce_wrapper (flattens 16-bit in to 10-bit out)
// =============================================================================
module arithmetic_reduce_wrapper (
    input  wire [15:0] in_flat,
    output wire [9:0]  out_flat
);
    wire [7:0] p = in_flat[15:8];
    wire [7:0] q = in_flat[7:0];

    wire [7:0] complex_expr;
    wire       red_and_res;
    wire       red_or_res;

    arithmetic_reduce u_arithmetic_reduce (
        .p(p), .q(q),
        .complex_expr(complex_expr),
        .red_and_res(red_and_res),
        .red_or_res(red_or_res)
    );

    assign out_flat[9:2] = complex_expr;
    assign out_flat[1]   = red_and_res;
    assign out_flat[0]   = red_or_res;
endmodule

// =============================================================================
// Module: array (sequential — the SINK of the bug wire; posedge clk)
// =============================================================================
module array (
    input  wire        clk,
    input  wire        rstn,
    input  wire [3:0]  din0,
    input  wire [3:0]  din1,
    input  wire [3:0]  din2,
    input  wire [3:0]  din3,
    output reg  [3:0]  dout0,
    output reg  [3:0]  dout1,
    output reg  [3:0]  dout2,
    output reg  [3:0]  dout3
);
    always @(posedge clk or negedge rstn) begin
        if (!rstn) begin
            dout0 <= 4'd0;
            dout1 <= 4'd0;
            dout2 <= 4'd0;
            dout3 <= 4'd0;
        end else begin
            dout0 <= din0 + 4'd1;
            dout1 <= din1 + 4'd1;
            dout2 <= din2 + 4'd1;
            dout3 <= din3 + 4'd1;
        end
    end
endmodule

// =============================================================================
// Wrapper: array_wrapper (flattens 18-bit in to 16-bit out)
// =============================================================================
module array_wrapper (
    input  wire [17:0] in_flat,
    output wire [15:0] out_flat
);
    wire       clk  = in_flat[17];
    wire       rstn = in_flat[16];
    wire [3:0] din0 = in_flat[15:12];
    wire [3:0] din1 = in_flat[11:8];
    wire [3:0] din2 = in_flat[7:4];
    wire [3:0] din3 = in_flat[3:0];

    wire [3:0] dout0, dout1, dout2, dout3;

    array u_array (
        .clk(clk), .rstn(rstn),
        .din0(din0), .din1(din1), .din2(din2), .din3(din3),
        .dout0(dout0), .dout1(dout1), .dout2(dout2), .dout3(dout3)
    );

    assign out_flat[15:12] = dout0;
    assign out_flat[11:8]  = dout1;
    assign out_flat[7:4]   = dout2;
    assign out_flat[3:0]   = dout3;
endmodule

// =============================================================================
// Minimal top: only arithmetic_reduce + array, one essential MTM wire
// =============================================================================
module top (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [250:0] in_flat,
    output wire [25:0]  out_flat
);

    // Per-module I/O buses
    wire [15:0] arithmetic_reduce_wrapper_in_flat;
    wire [9:0]  arithmetic_reduce_wrapper_out_flat;
    wire [17:0] array_wrapper_in_flat;
    wire [15:0] array_wrapper_out_flat;

    // ── arithmetic_reduce_wrapper inputs ──
    // ITM (from external stimulus — same bit indices as original design)
    assign arithmetic_reduce_wrapper_in_flat[0]  = in_flat[0];
    assign arithmetic_reduce_wrapper_in_flat[2]  = in_flat[1];
    assign arithmetic_reduce_wrapper_in_flat[3]  = in_flat[2];
    assign arithmetic_reduce_wrapper_in_flat[5]  = in_flat[3];
    assign arithmetic_reduce_wrapper_in_flat[6]  = in_flat[4];
    assign arithmetic_reduce_wrapper_in_flat[8]  = in_flat[5];
    assign arithmetic_reduce_wrapper_in_flat[9]  = in_flat[6];
    assign arithmetic_reduce_wrapper_in_flat[10] = in_flat[7];
    assign arithmetic_reduce_wrapper_in_flat[11] = in_flat[8];
    assign arithmetic_reduce_wrapper_in_flat[12] = in_flat[9];
    assign arithmetic_reduce_wrapper_in_flat[14] = in_flat[10];
    assign arithmetic_reduce_wrapper_in_flat[15] = in_flat[11];
    // MTM inputs — CUT (were from other modules, now tied to 0)
    assign arithmetic_reduce_wrapper_in_flat[1]  = 1'b0; // was const_conditional
    assign arithmetic_reduce_wrapper_in_flat[4]  = 1'b0; // was const_logic
    assign arithmetic_reduce_wrapper_in_flat[7]  = 1'b0; // was const_compare
    assign arithmetic_reduce_wrapper_in_flat[13] = 1'b0; // was numbers_concat_repl

    // ── array_wrapper inputs ──
    // ITM (from external stimulus)
    assign array_wrapper_in_flat[1]  = in_flat[12];
    assign array_wrapper_in_flat[2]  = in_flat[13];
    assign array_wrapper_in_flat[3]  = in_flat[14];
    assign array_wrapper_in_flat[4]  = in_flat[15];
    assign array_wrapper_in_flat[7]  = in_flat[16];
    assign array_wrapper_in_flat[8]  = in_flat[17];
    assign array_wrapper_in_flat[9]  = in_flat[18];
    assign array_wrapper_in_flat[10] = in_flat[19];
    assign array_wrapper_in_flat[11] = in_flat[20];
    assign array_wrapper_in_flat[12] = in_flat[21];
    assign array_wrapper_in_flat[13] = in_flat[22];
    assign array_wrapper_in_flat[16] = in_flat[23];  // -> rstn
    assign array_wrapper_in_flat[17] = in_flat[24];  // -> clk
    // MTM inputs — CUT (tied to 0)
    assign array_wrapper_in_flat[0]  = 1'b0; // was partselect
    assign array_wrapper_in_flat[5]  = 1'b0; // was const_conditional
    assign array_wrapper_in_flat[6]  = 1'b0; // was numbers_concat_repl
    assign array_wrapper_in_flat[15] = 1'b0; // was const_logic
    // *** ESSENTIAL WIRE — the bug ***
    assign array_wrapper_in_flat[14] = arithmetic_reduce_wrapper_out_flat[3];
    // Maps to: arithmetic_reduce.complex_expr[1] -> array.din0[2]

    // ── Outputs ──
    assign out_flat[9:0]   = arithmetic_reduce_wrapper_out_flat;
    assign out_flat[25:10] = array_wrapper_out_flat;

    // ── Instantiate ──
    arithmetic_reduce_wrapper u_arithmetic_reduce_wrapper (
        .in_flat(arithmetic_reduce_wrapper_in_flat),
        .out_flat(arithmetic_reduce_wrapper_out_flat)
    );

    array_wrapper u_array_wrapper (
        .in_flat(array_wrapper_in_flat),
        .out_flat(array_wrapper_out_flat)
    );

endmodule

// =============================================================================
// Testbench: same PRNG seed + @(negedge clk) timing as original
// =============================================================================
module tb_top;

    logic        clk;
    logic        rst_n;
    logic [250:0] in_flat;
    wire  [25:0]  out_flat;
    integer       cyc;
    reg [31:0]    rng_state;

    // Clock: 1ns period (same as original)
    initial clk = 1'b0;
    always #1 clk = ~clk;

    // Reset
    initial begin
        rst_n = 1'b0;
        #4 rst_n = 1'b1;
    end

    int cycles;
    int seed;
    initial begin
        cycles = 300; if ($value$plusargs("cycles=%d", cycles)) ;
        if (!$value$plusargs("seed=%d", seed)) seed = 1339297989;
        rng_state = seed;
        cyc = 0;
    end

    // DUT
    top dut (
        .clk(clk),
        .rst_n(rst_n),
        .in_flat(in_flat),
        .out_flat(out_flat)
    );

    // Log on posedge clk (same as original)
    always @(posedge clk) begin
        cyc <= cyc + 1;
        $write("CYCLE=%0d IN=%0h OUT=%0h\n", cyc, in_flat, out_flat);
    end

    integer i;
    initial begin
        // Initialize inputs (same PRNG sequence as original tb_top.sv)
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[31:0] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[63:32] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[95:64] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[127:96] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[159:128] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[191:160] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[223:192] = rng_state;
        rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
        in_flat[250:224] = rng_state[26:0];
        @(negedge clk);
        for (i = 0; i < cycles; i = i + 1) begin
            @(negedge clk);
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[31:0] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[63:32] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[95:64] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[127:96] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[159:128] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[191:160] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[223:192] = rng_state;
            rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
            in_flat[250:224] = rng_state[26:0];
        end
        @(posedge clk);
        $display("TB_SIM_OK cycles=%0d", cycles);
        $finish;
    end

endmodule
