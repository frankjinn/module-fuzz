//------------------------------------------------------------------------------
// Module: enum
// Replaces the SV typedef‐enum with simple localparam constants.
//------------------------------------------------------------------------------
module widths_enum_mod (
    input  wire [3:0] e_in,      // pass enum value
    output wire [3:0] e_out_eq,  // 1 if e_in == E2, else 0
    output wire       is_E2
);
    // “Enum” constants:
    localparam [3:0] E0 = 4'h0;
    localparam [3:0] E1 = 4'd5;
    localparam [3:0] E2 = 4'd6;   // (implicit)
    localparam [3:0] E3 = 4'o7;   // octal 7 → 3'b111 → 4'h7
    localparam [3:0] E4 = 4'b1010;

    assign is_E2   = (e_in == E2);
    assign e_out_eq = is_E2 ? 4'd1 : 4'd0;
endmodule


//------------------------------------------------------------------------------
// Module: struct
// Simply wires inputs directly to outputs (flattened version of SV struct).
//------------------------------------------------------------------------------
module widths_struct_mod (
    input  wire [7:0]  a_in,
    input  wire signed [3:0] b_in,
    output wire [7:0]  a_out,
    output wire signed [3:0] b_out
);
    // No packed struct in plain Verilog; just pass through:
    assign a_out = a_in;
    assign b_out = b_in;
endmodule


//------------------------------------------------------------------------------
// Module: union
// Splits a 16‐bit input into low and high bytes (flat version of SV union).
//------------------------------------------------------------------------------
module widths_union_mod (
    input  wire [15:0] u_in,
    output wire [7:0]  u_low,
    output wire [7:0]  u_high
);
    assign u_low  = u_in[7:0];
    assign u_high = u_in[15:8];
endmodule


//------------------------------------------------------------------------------
// Module: arith
// Exercises arithmetic, signed/unsigned casts, and width promotion.
//------------------------------------------------------------------------------
module widths_arith #(
    parameter integer W_A = 8,
    parameter integer W_B = 4
) (
    input  wire signed [W_A-1:0] a,
    input  wire        [W_B-1:0] b,
    output wire signed [W_A-1:0] sum_ab,
    output wire signed [W_A-1:0] diff_ab,
    output wire signed [W_A-1:0] prod_ab,
    output wire signed [W_A-1:0] quot_ab,
    output wire        [W_A-1:0] mod_ab
);
    // Extend b to signed W_A bits:
    wire signed [W_A-1:0] b_ext = $signed({{(W_A-W_B){1'b0}}, b});

    assign sum_ab  = a + b_ext;
    assign diff_ab = a - b_ext;
    assign prod_ab = a * b_ext;
    assign quot_ab = a / b_ext;
    assign mod_ab  = a % b_ext;
endmodule


//------------------------------------------------------------------------------
// Module: logic
// Logical, reduction, and comparison operations on 4‐bit vectors.
//------------------------------------------------------------------------------
module widths_logic_mod (
    input  wire [3:0]  x,
    input  wire [3:0]  y,
    output wire        eq,      // x == y
    output wire        neq,     // x != y
    output wire        gt,      // x > y
    output wire        red_and, // &x
    output wire        red_or,  // |y
    output wire        red_xor  // ^x
);
    assign eq      = (x == y);
    assign neq     = (x != y);
    assign gt      = (x > y);
    assign red_and = &x;
    assign red_or  = |y;
    assign red_xor = ^x;
endmodule


//------------------------------------------------------------------------------
// Module: concat_repl
// Concatenation and replication (Verilog‐2005 syntax).
//------------------------------------------------------------------------------
module widths_concat_repl (
    input  wire [3:0]  a,
    input  wire [1:0]  b,
    output wire [7:0]  cat_ab,
    output wire [3:0]  rep_a,
    output wire [5:0]  rep_b
);
    // Concatenate a[3:0], b[1:0], and two zeros -> 8 bits
    assign cat_ab = { a, b, 2'b00 };

    // Replicate a twice → 8 bits, then take lower 4 bits
    wire [7:0] rep_a_full = { a, a };
    assign rep_a = rep_a_full[3:0];

    // Replicate b three times → 6 bits
    assign rep_b = { b, b, b };
endmodule


//------------------------------------------------------------------------------
// Module: conditional
// Ternary operator with mixed signed/unsigned resolution.
//------------------------------------------------------------------------------
module widths_conditional (
    input  wire        sel,
    input  wire [3:0]  x,
    input  wire signed [3:0] y,
    output wire signed [3:0] z
);
    // If sel=1, zero‐extend x into 4‐bit signed; else use y
    wire signed [3:0] x_signed = $signed({1'b0, x[2:0]});
    assign z = sel ? x_signed : y;
endmodule


//------------------------------------------------------------------------------
// Module: shift
// Simple left/right shifts.
//------------------------------------------------------------------------------
module widths_shift (
    input  wire [7:0] data_in,
    input  wire [2:0] shift_amt,
    output wire [7:0] shl_out,
    output wire [7:0] shr_out
);
    assign shl_out = data_in << shift_amt;
    assign shr_out = data_in >> shift_amt;
endmodule


//------------------------------------------------------------------------------
// Module: cast
// Zero‐extension/truncation between 4 and 8 bits.
//------------------------------------------------------------------------------
module widths_cast (
    input  wire [3:0]  in4,
    input  wire [7:0]  in8,
    output wire [7:0]  cast_up,
    output wire [3:0]  cast_down
);
    // Zero‐extend 4→8
    assign cast_up   = { 4'b0000, in4 };
    // Truncate 8→4
    assign cast_down = in8[3:0];
endmodule


//------------------------------------------------------------------------------
// Module: partselect
// Uses static [7:4] and dynamic [idx +:4]; also checks overflow.
//------------------------------------------------------------------------------
module widths_partselect (
    input  wire [15:0] data_in,
    input  wire [2:0]  idx,
    output wire [3:0]  static_ps,
    output wire [3:0]  dynamic_ps,
    output wire        ovf_range
);
    // bits [7:4]
    assign static_ps = data_in[7:4];

    // dynamic [idx +: 4], idx <= 12 required
    assign dynamic_ps = data_in[idx +: 4];

    // overflow if idx > 12
    assign ovf_range = (idx > 3'd12);
endmodule


//------------------------------------------------------------------------------
// Module: array
// “Flattened” version of unpacked‐array handling. 4 separate 4‐bit inputs→4 outputs.
//------------------------------------------------------------------------------
module widths_array (
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


//------------------------------------------------------------------------------
// Module: param
// Parameterized widths and concatenation.
//------------------------------------------------------------------------------
module widths_param #(
    parameter integer WIDTH_A = 5,
    parameter integer WIDTH_B = 3
) (
    input  wire [WIDTH_A-1:0]  in_a,
    input  wire [WIDTH_B-1:0]  in_b,
    output wire [WIDTH_A+WIDTH_B-1:0] out_cat
);
    assign out_cat = { in_a, in_b };
endmodule


//------------------------------------------------------------------------------
// (removed real because plain Verilog/Yosys won’t accept “real” ports)
//------------------------------------------------------------------------------
