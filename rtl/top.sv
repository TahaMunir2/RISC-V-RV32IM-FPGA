module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0,  
);
    

    logic [DATA_WIDTH-1:0] instr;
    logic EQ;
    logic RegWrite;
    logic [2:0] ALUCtrl;
    logic ALUSrc;
    logic [2:0] ImmSrc;
    logic [1:0] PCSrc;
    logic [DATA_WIDTH-1:0] ImmOp;
    logic [DATA_WIDTH-1:0] PC;
    logic MemWrite;
    logic [DATA_WIDTH-1:0] pc_save;
    logic ByteWrite;
    logic [DATA_WIDTH-1:0] ALU_OUT;
    logic [1:0] ResultSrc;



    control control (
        .EQ(EQ),
        .instr(instr),
        .RegWrite(RegWrite),
        .ALUCtrl(ALUCtrl),
        .ALUSrc(ALUSrc),
        .ImmSrc(ImmSrc),
        .PCSrc(PCSrc),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc),
        .ByteWrite(ByteWrite)
    );

    signext sign_extension (
        .instr(instr),
        .ImmSrc(ImmSrc),
        .immext(ImmOp)
    );

    insmem Instr_Mem (
        .instr(instr),
        .addr(PC)
    );

    pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .Imm_op(ImmOp),
        .pc_src(PCSrc),
        .pc(PC),
        .ALU(ALU_OUT),
        .pc_save(pc_save)
    );

    regandalu Reg_and_ALU_block (
        .clk(clk),
        .A0(a0),
        .EQ(EQ),
        .AD3(instr[11:7]),
        .AD2(instr[24:20]),
        .AD1(instr[19:15]),
        .ImmOp(ImmOp),
        .ALUsrc(ALUSrc),
        .ALUctrl(ALUCtrl),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc), 
        
        .WE3(RegWrite),
        .ByteWrite(ByteWrite),
        .pc_save(pc_save),
        .ALU_OUT(ALU_OUT)
    );
    
endmodule
