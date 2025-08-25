
// Logic operations module
module const_logic (
    input wire [3:0] in1,
    input wire [3:0] in2,
    input wire [1:0] op,
    output wire [3:0] out
);
    always_comb begin
        case (op)
            2'b00: out = in1 & in2;
            2'b01: out = in1 | in2;
            2'b10: out = in1 ^ in2;
            2'b11: out = ~in1;
        endcase
    end
endmodule
