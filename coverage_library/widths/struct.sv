

//------------------------------------------------------------------------------
// Module: struct
// Simply wires inputs directly to outputs (flattened version of SV struct).
//------------------------------------------------------------------------------
module struct (
    input  wire [7:0]  a_in,
    input  wire signed [3:0] b_in,
    output wire [7:0]  a_out,
    output wire signed [3:0] b_out
);
    // No packed struct in plain Verilog; just pass through:
    assign a_out = a_in;
    assign b_out = b_in;
endmodule
