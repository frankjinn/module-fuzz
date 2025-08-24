module adder (
    input  wire [1:0] a,
    input wire [1:0] b,
    output wire [2:0] data_out
);
    assign data_out  = a + b;
endmodule