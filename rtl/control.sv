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
    RegWrite  = 0;
    ALUCtrl   = 3'b000;
    ALUSrc    = 0;
    ImmSrc    = 3'b000;
    PCSrc     = 2'b00;
    ResultSrc = 0;
    MemWrite  = 0;
    ByteWrite = 0;
    
    if (op == 7'b0010011) begin
        ///logic for addi instruction
        if (funct3 == 3'b0) begin
            RegWrite = 1;
            ALUCtrl = 3'b000;
            ALUSrc = 1;
            ImmSrc = 3'b00;
            PCSrc = 0;
            ResultSrc = 1'b0; //we want to write the output of the ALU to the regfile
            MemWrite = 0; // don't care
            ByteWrite = 0; // don't care
         
        end
    end

    else if (op == 7'b1100011) begin
        ///logic for bne instruction
        if (funct3 == 3'b001) begin
            RegWrite = 0;
            ALUCtrl = 3'b001;
            ALUSrc = 0;
            ImmSrc = 3'b010;
            MemWrite = 0; // don't care
            ByteWrite = 0;
           
            if (EQ) begin
                PCSrc = 0;
            end
            else begin
                PCSrc = 1;
            end
            ResultSrc = 0; //Don't care can take any value (because we are not writing to the regfile)
        end
    end

    else if (op == 7'b0110011) begin
        if (funct3 == 3'b000)  begin
            if (funct7 == 7'b0000000) begin // add instruction
                RegWrite = 1; // we are writing into rd
                ALUCtrl = 3'b000; // we are adding
                ALUSrc = 0; // use ALU_op2
                ImmSrc = 3'b00; // not used
                PCSrc = 0; // normal PC
                ResultSrc = 0; // write to register
                MemWrite = 0; // don't care
                ByteWrite = 0; // don't care
           
            end
        end
    end

    else if (op== 7'b0000011) begin
        //logic for the load word instruction
        if (funct3 == 3'b010) begin
            RegWrite=1;
            ALUCtrl =3'b0; 
            ALUSrc = 1'b1; 
            ImmSrc = 3'b0; //must be 00 because it is an immediate type instruction
            PCSrc = 0; //normal PC incrementation
            MemWrite = 0;
            ResultSrc = 1; //we are writing the output of the data mem to the regfile
            ByteWrite = 0; // don't care
           
        end
        else if (funct3 == 3'b100) begin // lbu
            RegWrite=1;
            ALUCtrl =3'b0; 
            ALUSrc = 1'b1; 
            ImmSrc = 3'b0; //must be 00 because it is an immediate type instruction
            PCSrc = 0; //normal PC incrementation
            ResultSrc = 1; //we are writing the output of the data mem to the regfile
            MemWrite = 0;
            ByteWrite = 1;
         
        end
    end

    else if (op == 7'b0100011) begin // SB
        RegWrite = 0;
        ALUCtrl  = 3'b000; 
        ALUSrc   = 1;
        ImmSrc   = 3'b01;  
        PCSrc    = 0;
        ResultSrc = 0;     
        MemWrite = 1;     
        ByteWrite = 1;     
    end
    

    else if (op == 7'b1101111) begin // JAL / J
        RegWrite = 1; // as we are saving the old value
        ALUCtrl = 3'b0; // doesn't matter, ALU not used
        ALUSrc = 0; // // doesn't matter
        ImmSrc = 3'b11; // 11 for j type instruction
        PCSrc = 1; // for adding an offset to PC
        ResultSrc = 2'b10; // don't care
        MemWrite = 0; // don't care
        ByteWrite = 0; // don't care
      
    end

    else if (op == 7'b1100111) begin // JALR    
        RegWrite = 1; // as we are saving the old value
        ALUCtrl = 3'b0; // we need to add r1 and imm
        ALUSrc = 1; // to add imm
        ImmSrc = 3'b000; // 11 for j type instruction
        PCSrc = 2'b10; // for adding an offset to PC and register
        ResultSrc = 2'b10; // don't care
        MemWrite = 0; // don't care
        ByteWrite = 0; // don't care
      
    end

    else if (op == 7'b0110111) begin // LUI / LI
        RegWrite = 1; // to write into R[Rd]
        ALUCtrl = 3'b100; // just makes ALUout rd
        ALUSrc = 1; // we need to use the imm
        ImmSrc = 3'b100; // 4 for U type instructions
        PCSrc = 0; // normal PC
        ResultSrc = 0; // don't care
        MemWrite = 0; // don't care
        ByteWrite = 0; // don't care
    
    end

end

endmodule
