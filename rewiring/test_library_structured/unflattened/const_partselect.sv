

//------------------------------------------------------------------------------
// Module: const_partselect
// Takes two 8-bit vectors and a 4-bit index; performs static and dynamic part-selects.
//------------------------------------------------------------------------------
module const_partselect (
    input  wire [7:0] data1,
    input  wire [7:0] data2,
    input  wire [3:0] idx,          // 0..15
    output wire [3:0] sel1_c,       // data1[7:4]
    output wire [2:0] sel2_c,       // data2[idx +: 3]
    output wire       ovf_range     // idx > 12 → overflow for width-3
);
    assign sel1_c   = data1[7:4];
    assign sel2_c   = (idx <= 4'd12) ? data2[idx +: 3] : 3'd0;
    assign ovf_range = (idx > 4'd12);
endmodule
