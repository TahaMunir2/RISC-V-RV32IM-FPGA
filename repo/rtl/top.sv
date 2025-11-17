module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);

    logic instr,
    logic EQ,
    logic RegWrite,
    logic [2:0] ALUCtrl,
    logic ALUSrc,
    logic [1:0] ImmSrc,
    logic PCsrc,
    logic ImmOp,
    logic PC,

    control control (
        .instr(instr),
        .RegWrite(RegWrite),
        .ALUCtrl(ALUCtrl),
        .ALUSrc(ALUSrc),
        .ImmSrc(ALUSrc),
        .ImmSrc(ImmSrc),
        .PCsrc(PCsrc)
    );

    signext sign_extension (
        .instr(instr),
        .ImmSrc(ImmSrc),
        .immext(Immop)
    );

    insmem Instr_Mem (
        .instr(instr),
        .addr(PC)
    );

    pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .Imm_op(Immop),
        .pc_src(PCsrc),
        .PC(PC)
    );

    regandalu Reg_and_ALU_block (
        .clk(clk),
        .a0(a0),
        .EQ(EQ),
        .AD3(instr[11:7]),
        .AD2(instr[24:20]),
        .AD1(instr[19:15]),
        .ImmOp(ImmOp),
        .ALUsrc(ALUSxrc),
        .ALUctrl(ALUCtrl),
        .WE3(RegWrite)
    );

    
endmodule
