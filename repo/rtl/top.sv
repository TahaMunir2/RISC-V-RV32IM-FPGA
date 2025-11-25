module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);
    
//fetch stage logic
    logic [DATA_WIDTH-1:0] instr_f;
    logic [DATA_WIDTH-1:0] pc_f;
    logic [DATA_WIDTH-1:0] pc_save_f;

//decode stage logic
    logic [DATA_WIDTH-1:0] instr_d;
    logic [DATA_WIDTH-1:0] pc_d;
    logic [DATA_WIDTH-1:0] pc_save_d;

//exec stage logic


//mem stage logic


//writeback stage logic

    logic EQ;
    logic RegWrite;
    logic [2:0] ALUCtrl;
    logic ALUSrc;
    logic [1:0] ImmSrc;
    logic PCSrc;
    logic [DATA_WIDTH-1:0] ImmOp;

//extra logic: select line to the multiplexer selecting if we are writing from the datamem or from the ALU output
    logic reg_entry;

//fetch stage


//decode stage


//exec stage


//mem stage


//writeback stage



    control control (
        .EQ(EQ),
        .instr(instr),
        .RegWrite(RegWrite),
        .ALUCtrl(ALUCtrl),
        .ALUSrc(ALUSrc),
        .ImmSrc(ImmSrc),
        .PCSrc(PCSrc),
        .reg_entry(reg_entry)
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
        .pc(PC)
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
        .reg_entry(reg_entry), //additional input (select line of the additional multiplexer) -> coming from the control block
        .WE3(RegWrite)
    );

endmodule
