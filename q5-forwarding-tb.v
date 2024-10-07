// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 6 2024

module forwarding_tb;
    // Declarations for inputs and outputs
    reg [4:0] EX_MEM_Rd, MEM_WB_Rd, ID_EX_Rs, ID_EX_Rt;
    reg EX_MEM_RegWrite, MEM_WB_RegWrite;
    wire [1:0] ForwardA, ForwardB;

    // Instantiate the forwarding unit
    ForwardingUnit dut (
        .ForwardA(ForwardA),
        .ForwardB(ForwardB),
        .EX_MEM_Rd(EX_MEM_Rd),
        .MEM_WB_Rd(MEM_WB_Rd),
        .ID_EX_Rs(ID_EX_Rs),
        .ID_EX_Rt(ID_EX_Rt),
        .EX_MEM_RegWrite(EX_MEM_RegWrite),
        .MEM_WB_RegWrite(MEM_WB_RegWrite)
    );

    // Test cases
    initial begin
        // Test case 1: EX-EX forwarding
        EX_MEM_Rd = 5'b00001;
        ID_EX_Rs = 5'b00001;
        EX_MEM_RegWrite = 1'b1;
        #10;
        if (ForwardA !== 2'b10) $display("Test case 1 failed");

        // Test case 2: MEM-EX forwarding
        MEM_WB_Rd = 5'b00010;
        ID_EX_Rt = 5'b00010;
        MEM_WB_RegWrite = 1'b1;
        EX_MEM_RegWrite = 1'b0;
        #10;
        if (ForwardB !== 2'b01) $display("Test case 2 failed");

        // More test cases...
    end
endmodule