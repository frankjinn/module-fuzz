

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
