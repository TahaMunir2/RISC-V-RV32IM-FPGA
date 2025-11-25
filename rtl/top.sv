module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0  
);
    

    logic [DATA_WIDTH-1:0] instr;
    logic EQ;
    logic LT;
    logic LTU;
    logic RegWrite;
    logic [3:0] ALUCtrl;
    logic ALUSrc;
    logic ALUsrc2;
    logic [2:0] ImmSrc;
    logic [1:0] PCSrc;
    logic [DATA_WIDTH-1:0] ImmOp;
    logic [DATA_WIDTH-1:0] PC;
    logic MemWrite;
    logic [DATA_WIDTH-1:0] pc_save;
    logic [DATA_WIDTH-1:0] ALU_OUT;
    logic [1:0] ResultSrc;
    logic [1:0] SizeWrite;
    logic [1:0] LoadSize;
    logic LoadUnsigned;


    control control (
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .instr(instr),
        .RegWrite(RegWrite),
        .ResultSrc(ResultSrc),
        .ALUCtrl(ALUCtrl),
        .ALUSrc(ALUSrc),
        .ALUsrc2(ALUsrc2),
        .ImmSrc(ImmSrc),
        .PCSrc(PCSrc),
        .MemWrite(MemWrite),
        .SizeWrite(SizeWrite),
        .LoadSize(LoadSize),
        .LoadUnsigned(LoadUnsigned)
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
        .LT(LT),
        .LTU(LTU),   
        .AD3(instr[11:7]),
        .AD2(instr[24:20]),
        .AD1(instr[19:15]),
        .ImmOp(ImmOp),
        .ALUsrc2(ALUsrc2),
        .ALUsrc(ALUSrc),
        .ALUCtrl(ALUCtrl),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc), //additional input (select line of the additional multiplexer) -> coming from the control block
        .WE3(RegWrite),
        .SizeWrite(SizeWrite),
        .pc_save(pc_save),
        .ALU_OUT(ALU_OUT),
        .LoadSize(LoadSize),
        .LoadUnsigned(LoadUnsigned)
    );
    
endmodule
