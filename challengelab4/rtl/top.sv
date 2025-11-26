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


///extra logic for hazard unit
     logic [1:0] selectline1;
     logic [1:0] selectline2;
     logic flush_d_exec;
     logic flush_f_d;
     logic F_Write;
     logic PCWrite;
    
//extra logic for f_d pipeline
    logic [DATA_WIDTH-1:0] PCD;
    logic [DATA_WIDTH-1:0] PCD_save;

// d-e pipeline buses
    // data logic
     logic [DATA_WIDTH-1:0] RD1_d;
     logic [DATA_WIDTH-1:0] RD2_d;
     logic [DATA_WIDTH-1:0] pc_d;
     logic [DATA_WIDTH-1:0] Rd_d;
     logic [DATA_WIDTH-1:0] ImmExt_d;
     logic [DATA_WIDTH-1:0] pc_save_e;
     logic [DATA_WIDTH-1:0] RD1_e;
     logic [DATA_WIDTH-1:0] RD2_e;
     logic [DATA_WIDTH-1:0] pc_e;
     logic [DATA_WIDTH-1:0] Rd_e;
     logic [DATA_WIDTH-1:0] ImmExt_e;

    // control logic
     logic RegWrite_d;
     logic [1:0] ResultSrc_d;
     logic MemWrite_d;
     logic Jump_d;
     logic Branch_d;
     logic [3:0] ALUCtrl_d;
     logic ALUSrc_d;
     logic [1:0] SizeWrite_d;
     logic [1:0]LoadSize_d; 
     logic LoadUnsigned_d;
     logic ALUSrc2_d;
     logic RegWrite_e;
     logic [1:0] ResultSrc_e;
     logic MemWrite_e;
     logic Jump_e;
     logic Branch_e;
     logic [3:0] ALUCtrl_e;
     logic ALUSrc_e;
     logic [1:0] SizeWrite_e;
     logic [1:0]LoadSize_e; 
     logic LoadUnsigned_e;
     logic ALUSrc2_e;


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

    

    f-d_pipeline fd_pipeline(
        .clk(clk),
        .flush(),/////////SEE WHAT TO PUT HERE
        enable(F_Write),/////////SEE WHAT TO PUT HERE
        .instr_f(instr),
        .pc_f(PC),
        .pc_save_f(pc + 4),
        .instr_d(instr_d),
        .pc_d(PCD),
        .pc_save_d(PCD_save)
    );

    signext sign_extension (
        .instr(instr_d),
        .ImmSrc(ImmSrc),
        .immext(ImmExt_d)
    );


    d-e_pipeline de_pipeline(
         .clk(clk),
     .flush(flush_d_exec),
     enable,
    // data logic
      .pc_save_d (PCD_save),
      .RD1_d (instr_d[19:15]),
      .RD2_d(instr_d[24:20]),
      .pc_d(PCD),
      .Rd_d(instr_d[11:7]),
      .ImmExt_d(ImmExt_d),
      .pc_save_e(pc_save_e),
      .RD1_e(RD1_e),
      .RD2_e(RD2_e),
      .pc_e(pc_e),
      .Rd_e(Rd_e),
      .ImmExt_e(ImmExt_e),

    // control logic
     .RegWrite_d(RegWrite_d),
     .ResultSrc_d(ResultSrc_d),
     .MemWrite_d(MemWrite_d),
     .Jump_d(Jump_d),
     .Branch_d(Branch_d),
     .ALUCtrl_d(ALUCtrl_d),
     .ALUSrc_d(ALUSrc_d),
     .SizeWrite_d(SizeWrite_d),
     .LoadSize_d(LoadSize_d), 
     .LoadUnsigned_d(LoadUnsigned_d),
     .ALUSrc2_d(ALUSrc2_d),
     .RegWrite_e(RegWrite_e),
     .ResultSrc_e(ResultSrc_e),
     .MemWrite_e(MemWrite_e),
     .Jump_e(Jump_e),
     .Branch_e(Branch_e),
     .ALUCtrl_e(ALUCtrl_e),
     .ALUSrc_e(ALUSrc_e),
     .SizeWrite_e(SizeWrite_e),
     .LoadSize_e(LoadSize_e), 
     .LoadUnsigned_e(LoadUnsigned_e),
     .ALUSrc2_e(ALUSrc2_e)



    )
    control control (
        .EQ(EQ),
        .instr(instr_d),
        .RegWrite(RegWrite_d),
        .ALUCtrl(ALUCtrl_d),
        .ALUSrc(ALUSrc_d),
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
        .enable(enable);
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

