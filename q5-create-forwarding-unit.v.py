// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 6 2024


module ForwardingUnit (
    input [4:0] ID_EX_Rs, ID_EX_Rt,
    input [4:0] EX_MEM_Rd, MEM_WB_Rd,
    input EX_MEM_RegWrite, MEM_WB_RegWrite,
    output reg [1:0] ForwardA, ForwardB
);

always @(*) begin
    // Forward A logic
    if (EX_MEM_RegWrite && (EX_MEM_Rd != 0) && (EX_MEM_Rd == ID_EX_Rs))
        ForwardA = 2'b10;
    else if (MEM_WB_RegWrite && (MEM_WB_Rd != 0) && (MEM_WB_Rd == ID_EX_Rs))
        ForwardA = 2'b01;
    else
        ForwardA = 2'b00;

    // Forward B logic
    if (EX_MEM_RegWrite && (EX_MEM_Rd != 0) && (EX_MEM_Rd == ID_EX_Rt))
        ForwardB = 2'b10;
    else if (MEM_WB_RegWrite && (MEM_WB_Rd != 0) && (MEM_WB_Rd == ID_EX_Rt))
        ForwardB = 2'b01;
    else
        ForwardB = 2'b00;
end

endmodule