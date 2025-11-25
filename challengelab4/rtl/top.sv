module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);
    

    logic [DATA_WIDTH-1:0] instr;
    logic EQ;
    logic RegWrite;
    logic [2:0] ALUCtrl;
    logic ALUSrc;
    logic [1:0] ImmSrc;
    logic PCSrc;
    logic [DATA_WIDTH-1:0] ImmOp;
    logic [DATA_WIDTH-1:0] PC;
    logic reg_entry;
    logic [DATA_WIDTH-1:0] instr_d;

//extra logic added because we splitted the register file , alu and data memory block
    logic [DATA_WIDTH-1: 0] output_ALU;
    logic [DATA_WIDTH-1: 0] ALUop1;
    logic [DATA_WIDTH-1: 0] ALUop2;
    logic [DATA_WIDTH-1: 0] regOp2;
    logic [DATA_WIDTH-1: 0] output_DataMem;
    logic [DATA_WIDTH-1: 0] write_to_reg;

/*
module f-d_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic flush,
    input logic enable,
    input logic [DATA_WIDTH-1:0] instr_f,
    input logic [DATA_WIDTH-1:0] pc_f,
    input logic [DATA_WIDTH-1:0] pc_save_f,
    output logic [DATA_WIDTH-1:0] instr_d,
    output logic [DATA_WIDTH-1:0] pc_d,
    output logic [DATA_WIDTH-1:0] pc_save_d
);
*/

    fd_pipeline fd_pipeline(
        .clk(clk),
        .flush(),/////////SEE WHAT TO PUT HERE
        input logic enable,/////////SEE WHAT TO PUT HERE
        .instr_f(instr),
        .pc_f(PC),
        .pc_save_f(pc + 4),
        .instr_d(instr_d),
        .pc_d(),
        output logic [DATA_WIDTH-1:0] pc_save_d  
    );
    control control (
        .EQ(EQ),
        .instr(instr_d),
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


    regfile regfile(
        .clk(clk),
        .WD3(write_to_reg), //it is not anymore always the output of the ALU , it can be both (output of ALU and output of DataMem depending on the instruction)
        .AD3(AD3),
        .AD2(AD2),
        .AD1(AD1),
        .WE3(WE3),
        .RD1(ALUop1),
        .RD2(regOp2),
        .A0(A0)
    );

    mux mux(
        .in0(regOp2),
        .in1(ImmOp),
        .sel(ALUsrc),
        .out(ALUop2)
    );

    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUctrl(ALUctrl),
        .ALUout(output_ALU),
        .EQ(EQ)
    );

//additional blocks to the initial top module:

//1) data memory (Asynchronous input) :

    datamem datamem(
        .A(output_ALU),
        .dout(output_DataMem)
    );

//2) multiplexer to select where to write in the regfile from
    mux mux_entry_regfile(
        .in0(output_ALU),
        .in1(output_DataMem),
        .sel(reg_entry), //input taken from the control block
        .out(write_to_reg)
    );


endmodule

