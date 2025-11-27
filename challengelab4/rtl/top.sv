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
    logic [DATA_WIDTH-1:0] PC_save;
    logic reg_entry;
    logic [DATA_WIDTH-1:0] instr_d;

//extra logic added because we splitted the register file , alu and data memory block
    logic [DATA_WIDTH-1: 0] output_ALU;
    logic [DATA_WIDTH-1: 0] ALUop1;
    logic [DATA_WIDTH-1: 0] ALUop2;
    logic [DATA_WIDTH-1: 0] regOp2;
    logic [DATA_WIDTH-1: 0] output_DataMem;
    logic [DATA_WIDTH-1: 0] write_to_reg;

    logic                   LT;
    logic                   LTU;
    logic [1:0] ResultSrc; //adding the aditional output representing the select line of the additional multiplexer in the regaludmem block
     logic MemWrite;
     logic [1:0]SizeWrite; //!!!!!!!!!!!!!!!CHANGE from ByteWrite to SizeWrite (size of that signal changed) !!!!!!!!!!!!!!!!!!!!!!!!!
     logic ALUsrc2; //additional output signal
     logic [1:0]LoadSize; //additional output signal
     logic LoadUnsigned; //additional output signal


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
     logic [DATA_WIDTH-1:0] PCPlus4dE;
     logic [DATA_WIDTH-1:0] RD1_e;
     logic [DATA_WIDTH-1:0] RD2_e;
     logic [DATA_WIDTH-1:0] pc_e;
     logic [DATA_WIDTH-1:0] RdE;
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
     logic RegWriteE;
     logic [1:0] ResultSrcE;
     logic MemWriteE;
     logic Jump_e;
     logic Branch_e;
     logic [3:0] ALUCtrl_e;
     logic ALUSrc_e;
     logic [1:0] SizeWriteE;
     logic [1:0]LoadSizeE; 
     logic LoadUnsignedE;
     logic ALUSrc2_e;
     logic enable_de;
     assign enable_de = 1;
     logic [2:0] function3_d;
     logic [2:0] function3_e;
     logic PCSrcE;




     

//extra wires added for the pipeline register:
    logic [DATA_WIDTH-1:0] PCPlus4M;
    logic [DATA_WIDTH-1:0] RdM;
    logic [DATA_WIDTH-1:0] ALUResultM;
    logic [DATA_WIDTH-1:0] WriteDataM;
     logic RegWriteM;
     logic [1:0] ResultSrCM;
     logic MemWriteM;
     logic [1:0] SizeWriteM;
     logic [1:0]LoadSizeM; 
     logic LoadUnsignedm;
//extra wires for the output of the memory-writeback pipeline register:
logic RegWriteW;
logic [1:0] ResultSrcW;
logic [DATA_WIDTH-1 :0] datamem_output;
logic [DATA_WIDTH-1 :0] ALUResultW;
logic [DATA_WIDTH-1 :0] ReadDataW;
logic [DATA_WIDTH-1 :0] RdW;
logic [DATA_WIDTH-1:0] PCPlus4W;
logic [DATA_WIDTH-1:0] ResultW;




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

    hazard_unit hazard_unit (
        .rs1D(RD1_d), 
        .rs2D(RD2_d),
        .rs1E(RD1_e), 
        .rs2E(RD2_e),
        .rdM(RdM),
        .rdE(RdE), 
        .rdWB(RdW),
        .regWriteM(RegWriteM),
        .resultSrCE(ResultSrcE),
        .resultSrCM(ResultSrCM),
        .WriteBack_Regfile(RegWriteW),    
        .selectline1(ForwardAE),
        .selectline2(ForwardBE),
        .flush_d_exec(flush_d_exec),
        .flush_f_d(flush_f_d),
        .F_Write(F_Write),
        .PCWrite(PCWrite),
        .PCSrcE(PCSrcE)

    );

    fd_pipeline fd_pip(
        .clk(clk),
        .rst(rst),
        .flush(flush_f_d),/////////SEE WHAT TO PUT HERE
        .enable(F_Write),/////////SEE WHAT TO PUT HERE
        .instr_f(instr),
        .pc_f(PC),
        .pc_save_f(PC_save),
        .instr_d(instr_d),
        .pc_d(PCD),
        .pc_save_d(PCD_save)
    );

    signext sign_extension (
        .instr(instr_d),
        .ImmSrc(ImmSrc),
        .immext(ImmExt_d)
    );


    de_pipeline de_pip(
         .clk(clk),
    .rst(rst),
     .flush(flush_d_exec),
     .enable(enable_de),
    // data logic
      .pc_save_d (PCD_save),
      .RD1_d (instr_d[19:15]),
      .RD2_d(instr_d[24:20]),
      .pc_d(PCD),
      .Rd_d(instr_d[11:7]),
      .ImmExt_d(ImmExt_d),
      .pc_save_e(PCPlus4dE),
      .RD1_e(RD1_e),
      .RD2_e(RD2_e),
      .pc_e(pc_e),
      .Rd_e(RdE),
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
     .RegWrite_e(RegWriteE),
     .ResultSrc_e(ResultSrcE),
     .MemWrite_e(MemWriteE),
     .Jump_e(Jump_e),
     .Branch_e(Branch_e),
     .ALUCtrl_e(ALUCtrl_e),
     .ALUSrc_e(ALUSrc_e),
     .SizeWrite_e(SizeWriteE),
     .LoadSize_e(LoadSizeE), 
     .LoadUnsigned_e(LoadUnsignedE),
     .ALUSrc2_e(ALUSrc2_e),//ALUSrc2 not ou
     .funct3_d(function3_d),
     .funct3_e(function3_e)
    );

    PCSrc_assertion PCSource(
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .Branch_e(Branch_e),
        .funct3(function3_e),
        .Jump_e(Jump_e),
        .PCSrcE(PCSrcE)
    );
    
    control control (
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .instr(instr_d),
        .RegWrite(RegWrite_d),
        .ALUCtrl(ALUCtrl_d),
        .ALUSrc(ALUSrc_d),
        .ImmSrc(ImmSrc),
        .PCSrc(PCSrc),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .SizeWrite(SizeWrite),
        .ALUsrc2(ALUsrc2),
        .LoadSize(LoadSize),
        .LoadUnsigned(LoadUnsigned),
        .Branch(Branch_d),
        .function3(function3_d)

    );


    insmem Instr_Mem (
        .instr(instr),
        .addr(PC)
    );

    logic [DATA_WIDTH-1:0] ALU;

    pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .enable(PCWrite),
        .Imm_op(ImmOp),
        .pc_src(PCSrcE),
        .pc(PC),
        .pc_save(PC_save),
        .ALU(ALU)
    );

     logic [DATA_WIDTH-1:0] WD3;
     logic WE3;
     logic [4:0] AD3;
     logic [4:0] AD2;
     logic [4:0] AD1;

    regfile regfile(
        .clk(clk),
        .WD3(ResultW), //it is not anymore always the output of the ALU , it can be both (output of ALU and output of DataMem depending on the instruction)
        .AD3(AD3),
        .AD2(AD2),
        .AD1(AD1),
        .WE3(WE3),
        .RD1(ALUop1),
        .RD2(regOp2),
        .A0(a0)
    );

  
//select lines of the muxes for forwarding (outputs of the hazard unit):
logic [1:0] ForwardAE;
logic [1:0] ForwardBE;
logic [DATA_WIDTH-1: 0] SrcAE;
logic [DATA_WIDTH-1: 0] SrcBE;


//forwarding muxes:

mux4 forwardingRS1(
    .in0(output_ALU),
    .in1(ResultW),
    .in2(ALUResultM),
    .in3(output_ALU), //unused input, by default we set it to be the output of the ALU
    .select_line(ForwardAE), //input taken from the hazard unit
    .out(SrcAE)    
);

mux4 forwardingRS2(
    .in0(output_ALU),
    .in1(ResultW),
    .in2(ALUResultM),
    .in3(output_ALU), //unused input, by default we set it to be the output of the ALU
    .select_line(ForwardBE), //input taken from the hazard unit
    .out(SrcBE)    
);

    mux mux_immVSreg( 
        .in0(SrcBE),
        .in1(ImmOp),
        .sel(ALUSrc_e),
        .out(ALUop2)
    );

    mux mux_pcVSreg( //additional mux, because we never use data from a register and from pc_save in any instructiom
        .in0(SrcAE),
        .in1(pc_save_e),
        .sel(ALUsrc2),
        .out(ALUop1)
    );


    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUout(output_ALU),
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .ALUCtrl(ALUCtrl_e)
    );





em_pipeline em_pipeline(
    //control inputs coming from the previous pipeline register
    .rst(rst),
    .clk(clk),
    .RegWrite_e(RegWriteE),
    .ResultSrc_e(ResultSrcE),
    .MemWrite_e(MemWriteE),
    .SizeWrite_e(SizeWriteE),
    .LoadSize_e(LoadSizeE), 
    .LoadUnsigned_e(LoadUnsignedE),
    
    //control outputs:
    .RegWrite_m(RegWriteM),
    .ResultSrc_m(ResultSrCM),
    .MemWrite_m(MemWriteM),
    .SizeWrite_m(SizeWriteM),
    .LoadSize_m(LoadSizeM), 
    .LoadUnsigned_m(LoadUnsignedm),

    //inputs to the register processed in the execute stage
    .pc_save_e(PCPlus4dE),
    .Rd_e(RdE),
    .ALU_Result_e(output_ALU),
    .Write_Data_e(SrcBE),

    //corresponding data outputs
    .pc_save_m(PCPlus4M),
    .Rd_m(RdM),
    .ALU_Result_m(ALUResultM),
    .Write_Data_m(WriteDataM)
);

//data memory (Asynchronous input) :

    datamem datamem(
        .clk(clk),
        .A(ALUResultM),
        .dout(output_DataMem),
        .MemWrite(MemWrite),
        .WD(regOp2),
        .SizeWrite(SizeWrite),
        .LoadSize(LoadSize), //additional output signal
        .LoadUnsigned(LoadUnsigned) //additional output signal        
    );



mw_pipeline mw_pipeline(
    //inputs from the previous pipeline register: (control inputs)
    .RegWrite_m(RegWriteM),
    .ResultSrc_m(ResultSrCM),

    //corresponding outputs
    .RegWrite_w(RegWriteW),
    .ResultSrc_w(ResultSrcW),
    .rst(rst),
    .clk(clk),

//inputs to the register processed in the memory stage
    .pc_save_m(PCPlus4M),
    .Rd_m(RdM),
    .ALU_Result_m(ALUResultM),
    .dout_m(datamem_output), 

//corresponding outputs:

    .pc_save_w(PCPlus4W),
    .Rd_w(RdW),
    .ALU_Result_w(ALUResultW),
    .dout_w(ReadDataW)
);

    always_comb begin
        case (ResultSrcW)
            2'b00: ResultW = ALUResultW;     // ALU
            2'b01: ResultW = ReadDataW; // Memory
            2'b10: ResultW = PCPlus4W;        // for jump instructions
            default: ResultW = 32'b0;
        endcase
    end


endmodule

