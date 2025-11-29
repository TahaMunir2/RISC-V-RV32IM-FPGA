module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    input logic trigger,
    output  logic [DATA_WIDTH-1:0] a0    
);
    
//extra logic added when debugging (to map correctly for better presentation) :
    logic [4:0] Rs1D = InstrD[19:15];
    logic [4:0] Rs2D = InstrD[24:20];
    logic [4:0] RdD = InstrD[11:7];
    logic [4:0] Rs1E;
    logic [4:0] Rs2E;
    logic [4:0] RdE;
    logic [DATA_WIDTH-1 : 0] RD1E;
    logic [DATA_WIDTH-1 : 0] RD2E;
    logic [DATA_WIDTH-1 : 0] RD1D;
    logic [DATA_WIDTH-1 : 0] RD2D;
    logic [DATA_WIDTH-1 : 0]  ExtImmE;
    logic [DATA_WIDTH-1 : 0] ExtImmD;
    logic [1 : 0] ResultSrcD;
    logic [1 : 0] ResultSrcM;
    logic [DATA_WIDTH-1 : 0] InstrF;
    logic RegWriteD;
    logic [DATA_WIDTH-1 : 0] ReadDataM;
    logic [DATA_WIDTH-1 : 0] WriteDataE;
    logic [DATA_WIDTH-1:0] InstrD;
    logic EQ;
    
    //adding the wires to propagate the PC value from the fetch stage to the execute stage 
    //(where it is added to the value of ExtImm (which is ExtImmE in the execution stage and brought back as the input ImmOp for the PCblock))
    logic [DATA_WIDTH-1:0] PCF;
    logic [DATA_WIDTH-1:0] PCD;
    logic [DATA_WIDTH-1:0] PCE;

    logic [DATA_WIDTH-1 : 0] PCPlus4F;
    logic [DATA_WIDTH-1 : 0] PCPlus4D;
    logic [DATA_WIDTH-1 : 0] PCPlus4E;

//logic for branch and jump
    logic BranchD;
    logic BranchE;
    logic JumpD;
    logic JumpE;
    logic [2:0] funct3D;
    logic [2:0] funct3E;

    logic [2:0] ImmSrcD;


//extra logic added because we splitted the register file , alu and data memory block
    logic [DATA_WIDTH-1: 0] ALUResultE;
    logic [DATA_WIDTH-1: 0] ALUop1;

    //logic [DATA_WIDTH-1: 0] write_to_reg; Not used here : the namings come from the pipeline stage

    logic                   LT;
    logic                   LTU;
    //logic [1:0] ResultSrc; Not used here : the namings come from the pipeline stage
     logic MemWriteD;
     logic [1:0]SizeWriteD; //!!!!!!!!!!!!!!!CHANGE from ByteWrite to SizeWrite (size of that signal changed) !!!!!!!!!!!!!!!!!!!!!!!!!
     //logic ALUsrc2; //additional output signal
     logic [1:0]LoadSizeD; //additional output signal
     logic LoadUnsignedD; //additional output signal


///extra logic for hazard unit
     //logic [1:0] selectline1;
     //logic [1:0] selectline2;
     logic flush_d_exec;
     logic flush_f_d;
     logic F_Write;
     logic PCWrite;
    
// d-e pipeline buses
    // data logic
     //logic [DATA_WIDTH-1:0] RD1_d;
     //logic [DATA_WIDTH-1:0] RD2_d;
     //logic [DATA_WIDTH-1:0] pc_d;
     //logic [4:0] Rd_d;
     //logic [DATA_WIDTH-1:0] PCPlus4dE;
     //logic [DATA_WIDTH-1:0] RD1_e;
     //logic [DATA_WIDTH-1:0] RD2_e;
     //logic [DATA_WIDTH-1:0] pc_e;
     //logic [DATA_WIDTH-1:0] ImmExt_e;

    // control logic
     //logic RegWrite_d;
     //logic [1:0] ResultSrc_d;
     //logic MemWrite_d;
     //logic Branch_d;
     logic [3:0] ALUCtrlD;
     logic ALUSrcD;
     //logic [1:0] SizeWrite_d;
     //logic [1:0]LoadSize_d; 
     //logic LoadUnsigned_d;
     logic ALUSrc2D;
     logic RegWriteE;
     logic [1:0] ResultSrcE;
     logic MemWriteE;
     //logic Branch_e;
     logic [3:0] ALUCtrlE;
     logic ALUSrcE;
     logic [1:0] SizeWriteE;
     logic [1:0]LoadSizeE; 
     logic LoadUnsignedE;
     logic ALUSrc2E;
     logic enable_de;
     assign enable_de = 1;
     logic [1:0] PCSrcE;




     

//extra wires added for the pipeline register:
    logic [DATA_WIDTH-1:0] PCPlus4M;
    logic [4:0] RdM;
    logic [DATA_WIDTH-1:0] ALUResultM;
    logic [DATA_WIDTH-1:0] WriteDataM;
     logic RegWriteM;
     logic MemWriteM;
     logic [1:0] SizeWriteM;
     logic [1:0]LoadSizeM; 
     logic LoadUnsignedM;

//extra wires for the output of the memory-writeback pipeline register:
logic RegWriteW;
logic [1:0] ResultSrcW;
logic [DATA_WIDTH-1 :0] ALUResultW;
logic [DATA_WIDTH-1 :0] ReadDataW;
logic [4:0] RdW;
logic [DATA_WIDTH-1:0] PCPlus4W;
logic [DATA_WIDTH-1:0] ResultW;



    hazard_unit hazard_unit (
        .rs1D(Rs1D), 
        .rs2D(Rs2D),
        .rs1E(Rs1E), 
        .rs2E(Rs2E),
        .rdM(RdM),
        .rdE(RdE), 
        .rdWB(RdW),
        .regWriteM(RegWriteM),
        .resultSrCE(ResultSrcE),
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
        .instr_f(InstrF),
        .pc_f(PCF),
        .pc_save_f(PCPlus4F),
        .instr_d(InstrD),
        .pc_d(PCD),
        .pc_save_d(PCPlus4D)
    );

    signext sign_extension (
        .instr(InstrD),
        .ImmSrc(ImmSrcD),
        .immext(ExtImmD)
    );


    de_pipeline de_pip(
    .clk(clk),
    .rst(rst),
     .flush(flush_d_exec),
     .enable(enable_de),
    // data logic
      .pc_save_d (PCPlus4D),
      .RD1_d (RD1D),
      .RD2_d(RD2D),
      .pc_d(PCD),
      .pc_e(PCE), //added signal 
      .Rd_d(RdD),
      .ImmExt_d(ExtImmD),
      .pc_save_e(PCPlus4E),
      .RD1_e(RD1E),
      .RD2_e(RD2E),
      .Rd_e(RdE),
      .ImmExt_e(ExtImmE),
      .Rs1E(Rs1E),
      .Rs2E(Rs2E),
      .Rs1D(Rs1D),
      .Rs2D(Rs2D),

    // control logic
     .RegWrite_d(RegWriteD),
     .ResultSrc_d(ResultSrcD),
     .MemWrite_d(MemWriteD),
     //.Branch_d(Branch_d),
     .ALUCtrl_d(ALUCtrlD),
     .ALUSrc_d(ALUSrcD),
     .SizeWrite_d(SizeWriteD),
     .LoadSize_d(LoadSizeD), 
     .LoadUnsigned_d(LoadUnsignedD),
     .ALUSrc2_d(ALUSrc2D),
     .RegWrite_e(RegWriteE),
     .ResultSrc_e(ResultSrcE),
     .MemWrite_e(MemWriteE),
     //.Branch_e(Branch_e),
     .ALUCtrl_e(ALUCtrlE),
     .ALUSrc_e(ALUSrcE),
     .SizeWrite_e(SizeWriteE),
     .LoadSize_e(LoadSizeE), 
     .LoadUnsigned_e(LoadUnsignedE),
     .ALUSrc2_e(ALUSrc2E),//ALUSrc2 not ou
     .BranchD(BranchD),
     .JumpD(JumpD),
     .BranchE(BranchE),
     .JumpE(JumpE),
     .funct3D(funct3D),
     .funct3E(funct3E)
    );


    PCSrc_assertion PCSource(
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .Branch_e(BranchE),
        .Jump_e(JumpE),
        .funct3(funct3E),
        .PCSrcE(PCSrcE),
        .ALUSrcE(ALUSrcE)
    );


    control control (
        .instr(InstrD),
        .RegWrite(RegWriteD),
        .ALUCtrl(ALUCtrlD),
        .ALUSrc(ALUSrcD),
        .ImmSrc(ImmSrcD),
        .Branch(BranchD),
        .Jump(JumpD),
        .funct3OUT(funct3D),
        .ResultSrc(ResultSrcD),
        .MemWrite(MemWriteD),
        .SizeWrite(SizeWriteD),
        .ALUsrc2(ALUSrc2D),
        .LoadSize(LoadSizeD),
        .LoadUnsigned(LoadUnsignedD)
    );


    insmem Instr_Mem (
        .instr(InstrF),
        .addr(PCF)
    );


    pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .enable(PCWrite),
        .Imm_op(PCE + ExtImmE), //very important line 
        .pc_src(PCSrcE),
        .pc(PCF),
        .pc_save(PCPlus4F),
        .ALU(ALUResultE)
    );

     logic [4:0] AD2 = InstrD[24:20];
     logic [4:0] AD1 = InstrD[19:15];

    regfile regfile(
        .clk(clk),
        .trigger(trigger),
        .WD3(ResultW), //it is not anymore always the output of the ALU , it can be both (output of ALU and output of DataMem depending on the instruction)
        .AD3(RdW),
        .AD2(AD2),
        .AD1(AD1),
        .WE3(RegWriteW),
        .RD1(RD1D),
        .RD2(RD2D),
        .A0(a0)
    );

  
//select lines of the muxes for forwarding (outputs of the hazard unit):
logic [1:0] ForwardAE;
logic [1:0] ForwardBE;
logic [DATA_WIDTH-1: 0] SrcAE;
logic [DATA_WIDTH-1: 0] SrcBE;


//forwarding muxes:

mux4 forwardingRS1(
    .in0(RD1E),
    .in1(ResultW),
    .in2(ALUResultM),
    .in3(RD1E), //unused input, by default we set it to be the output of the ALU
    .select_line(ForwardAE), //input taken from the hazard unit
    .out(SrcAE)    
);

mux4 forwardingRS2(
    .in0(RD2E),
    .in1(ResultW),
    .in2(ALUResultM),
    .in3(RD2E), //unused input, by default we set it to be the output of the ALU
    .select_line(ForwardBE), //input taken from the hazard unit
    .out(WriteDataE)    
);

    mux mux_immVSreg( 
        .in0(WriteDataE),
        .in1(ExtImmE),
        .sel(ALUSrcE),
        .out(SrcBE)
    );

    mux mux_pcVSreg( //additional mux, because we never use data from a register and from pc_save in any instructiom
        .in0(SrcAE),
        .in1(PCPlus4E),
        .sel(ALUSrc2E),
        .out(ALUop1)
    );


    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(SrcBE),
        .ALUout(ALUResultE),
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .ALUCtrl(ALUCtrlE)
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
    .ResultSrc_m(ResultSrcM),
    .MemWrite_m(MemWriteM),
    .SizeWrite_m(SizeWriteM),
    .LoadSize_m(LoadSizeM), 
    .LoadUnsigned_m(LoadUnsignedM),

    //inputs to the register processed in the execute stage
    .pc_save_e(PCPlus4E),
    .Rd_e(RdE),
    .ALU_Result_e(ALUResultE),
    .Write_Data_e(WriteDataE),

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
        .dout(ReadDataM),
        .MemWrite(MemWriteM),
        .WD(WriteDataM),
        .SizeWrite(SizeWriteM),
        .LoadSize(LoadSizeM), //additional output signal
        .LoadUnsigned(LoadUnsignedM) //additional output signal        
    );



mw_pipeline mw_pipeline(
    //inputs from the previous pipeline register: (control inputs)
    .RegWrite_m(RegWriteM),
    .ResultSrc_m(ResultSrcM),

    //corresponding outputs
    .RegWrite_w(RegWriteW),
    .ResultSrc_w(ResultSrcW),
    .rst(rst),
    .clk(clk),

//inputs to the register processed in the memory stage
    .pc_save_m(PCPlus4M),
    .Rd_m(RdM),
    .ALU_Result_m(ALUResultM),
    .dout_m(ReadDataM), 

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



