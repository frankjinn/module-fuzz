

//------------------------------------------------------------------------------
// Module: const_nested
// Takes four 8-bit vectors and one 3-bit shift; computes a complex nested expression.
//------------------------------------------------------------------------------
module const_nested (
    input  wire [7:0] p,
    input  wire [7:0] q,
    input  wire [7:0] r,
    input  wire [2:0] s,
    output wire [7:0] nested_c
);
    // (( (p + q) * (r << s) ) & (q ^ r)) | ((p / (q + 8'd1)) % 8'd3)
    wire [7:0] add_pq    = p + q;
    wire [7:0] shl_rs    = r << s;
    wire [7:0] mul_part  = add_pq * shl_rs;
    wire [7:0] xor_qr    = q ^ r;
    wire [7:0] and_part  = mul_part & xor_qr;
    wire [7:0] denom     = q + 8'd1;
    wire [7:0] div_part  = (denom != 8'd0) ? (p / denom) : 8'd0;
    wire [7:0] mod_part  = div_part % 8'd3;
    assign nested_c      = and_part | mod_part;
endmodule
