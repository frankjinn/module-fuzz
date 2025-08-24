module multiplier (
    input  wire [1:0] a,
    input wire [1:0] b,
    output wire [4:0] data_out
);
    assign data_out  = a * b;
endmodule