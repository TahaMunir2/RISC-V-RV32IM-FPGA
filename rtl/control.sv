module control #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    input logic EQ,
    output logic RegWrite,
    output logic [2:0] ALUCtrl,
    output logic ALUSrc,
    output logic [2:0] ImmSrc,
    output logic [1:0] PCSrc,
    output logic [1:0] ResultSrc, //adding the aditional output representing the select line of the additional multiplexer in the regaludmem block
    output logic MemWrite,
    output logic ByteWrite

);

logic [6:0] op;
logic [2:0] funct3;
logic [6:0] funct7;
assign op = instr[6:0];
assign funct3 = instr[14:12];
assign funct7 = instr [31:25];

always_comb begin
    RegWrite  = 0; // 1 for writing 
    ALUCtrl   = 3'b000; // determines operation of alu
    ALUSrc    = 0; // imm (1) or rd2 (0) for alu
    ImmSrc    = 3'b000; // determines type of sign extension
    PCSrc     = 2'b00; // determines next pc
    ResultSrc = 2'b00; // alu result(0) or RD[alu_result] (1)
    MemWrite  = 0; // write enable for data mem
    ByteWrite = 0; // determines if we are doing byte or word logic
    
    // i type instructions
    if (op == 7'b0010011) begin  // ADDI
        if (funct3 == 3'b0) begin
            RegWrite = 1; // enable write to write the result into
            ALUCtrl = 3'b000; // addition
            ALUSrc = 1; // we need imm for addi
        end
    end

    else if (op == 7'b1100011) begin  // BNE
        if (funct3 == 3'b001) begin
            ALUCtrl = 3'b001; // subtraction
            ImmSrc = 3'b010; // type of signext for bne
            if (EQ == 0) begin
                PCSrc = 1; // pc + imm
            end
        end
    end

    else if (op == 7'b0110011) begin
        if (funct3 == 3'b000)  begin
            if (funct7 == 7'b0000000) begin // ADD
                RegWrite = 1; // we are writing into rd
                ALUCtrl = 3'b000; // we are adding
                ALUSrc = 0; // use ALU_op2
            end
        end
    end

    else if (op== 7'b0000011) begin
        if (funct3 == 3'b010) begin // LW
            RegWrite=1;
            ALUSrc = 1'b1; // we need the imm to write 
            ImmSrc = 3'b000; //must be 00 because it is an immediate type instruction
            ResultSrc = 1; //we are writing the output of the data mem to the regfile
        end
    else if (funct3 == 3'b100) begin // LBU
            RegWrite=1;
            ALUSrc = 1'b1; 
            ImmSrc = 3'b000; //must be 000 because it is an immediate type instruction
            ResultSrc = 1; //we are writing the output of the data mem to the regfile
            ByteWrite = 1; // bytwwise logic
        end
    end

    else if (op == 7'b1100111) begin // JALR    
        RegWrite = 1; // as we are saving the old value
        ALUCtrl = 3'b0; // we need to add r1 and imm
        ALUSrc = 1; // to add imm
        ImmSrc = 3'b000; // 000 for jalr  instruction
        PCSrc = 2'b10; // for adding an offset to PC and register
        ResultSrc = 2'b10; // for jump instruction
    end

    // S type instructions
    else if (op == 7'b0100011) begin // SB
        ALUCtrl  = 3'b000; // adding rs1 and imm
        ALUSrc   = 1; // we need imm
        ImmSrc   = 3'b001;  // for store
        MemWrite = 1; // need to write into memory
        ByteWrite = 1; // byte wise logic
    end

    // J type instructions
    else if (op == 7'b1101111) begin // JAL 
        RegWrite = 1; // as we are saving the old value
        ALUCtrl = 3'b0; // doesn't matter, ALU not used
        ALUSrc = 0; // // doesn't matter
        ImmSrc = 3'b011; // 11 for j type instruction
        PCSrc = 1; // for adding an offset to PC
        ResultSrc = 2'b10; // for jump instruction
    end

    // U type instructions
    else if (op == 7'b0110111) begin // LUI 
        RegWrite = 1; // to write into R[Rd]
        ALUCtrl = 3'b100; // just makes ALUout rd
        ALUSrc = 1; // we need to use the imm
        ImmSrc = 3'b100; // 4 for U type instructions
    end
end

endmodule
