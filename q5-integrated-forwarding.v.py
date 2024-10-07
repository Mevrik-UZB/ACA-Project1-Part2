// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 6 2024

module ExecuteStage (
    input [31:0] ALU_input1, ALU_input2,
    input [31:0] EX_MEM_ALU_result, MEM_WB_result,
    input [1:0] ForwardA, ForwardB,
    output [31:0] ALU_result
);

reg [31:0] ALU_operand1, ALU_operand2;

always @(*) begin
    case (ForwardA)
        2'b00: ALU_operand1 = ALU_input1;
        2'b10: ALU_operand1 = EX_MEM_ALU_result;
        2'b01: ALU_operand1 = MEM_WB_result;
        default: ALU_operand1 = ALU_input1;
    endcase

    case (ForwardB)
        2'b00: ALU_operand2 = ALU_input2;
        2'b10: ALU_operand2 = EX_MEM_ALU_result;
        2'b01: ALU_operand2 = MEM_WB_result;
        default: ALU_operand2 = ALU_input2;
    endcase
end

// ALU operation
assign ALU_result = ALU_operand1 + ALU_operand2; // Example: ADD operation

endmodule