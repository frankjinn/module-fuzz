
// Comparison module
module const_compare (
    input wire [7:0] a,
    input wire [7:0] b,
    output wire [2:0] result
);
    always_comb begin
        if (a > b)
            result = 3'b001;
        else if (a < b)
            result = 3'b010;
        else
            result = 3'b100;
    end
endmodule
