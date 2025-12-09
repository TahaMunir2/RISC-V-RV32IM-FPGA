module top #(
    DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 32,
     parameter BLOCK_SIZE = 8
) (
    input   logic clk,
    input   logic rst,
    input logic trigger,
    output  logic [DATA_WIDTH-1:0] a0    
);
    
//extra logic added when debugging (to map correctly for better presentation) :
    logic [4:0] Rs1D;
    logic [4:0] Rs2D;
    logic [4:0] RdD;
    logic [4:0] AD1;
    logic [4:0] AD2;

    assign Rs1D = InstrD[19:15];
    assign Rs2D = InstrD[24:20];
    assign RdD  = InstrD[11:7];
    assign AD1  = InstrD[19:15];
    assign AD2  = InstrD[24:20];
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
     logic flush_d_exec;
     logic flush_f_d;
     logic F_Write;
     logic PCWrite;
     logic [3:0] ALUCtrlD;
     logic ALUSrcD;
     logic ALUSrc2D;
     logic RegWriteE;
     logic [1:0] ResultSrcE;
     logic MemWriteE;
     logic [3:0] ALUCtrlE;
     logic ALUSrcE;
     logic [1:0] SizeWriteE;
     logic [1:0]LoadSizeE; 
     logic LoadUnsignedE;
     logic ALUSrc2E;
     logic [1:0] PCSrcE;

     logic enable_fd;
     logic enable_de;
     logic enable_em;
     logic enable_mw;
     logic enable_pc_block;
     logic enable_branch_predictor;

    logic stall_l1d, stall_l1i;

assign enable_fd = !(stall_l1i || stall_l1d);
assign enable_de = !(stall_l1i || stall_l1d);
assign enable_em = !(stall_l1i || stall_l1d);
assign enable_mw = !(stall_l1i || stall_l1d);
assign enable_branch_predictor = !(stall_l1i || stall_l1d);
assign enable_pc_block = !(stall_l1i || stall_l1d);


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

logic pred_takenF;
logic pred_takenD;
logic pred_takenE;

logic false_prediction;


    evalprediction evalprediction(
        .PCSrcE(PCSrcE),
        .BranchE(BranchE),
        .pred_taken(pred_takenE),
        .false_prediction(false_prediction)
    );


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
        .JumpE(JumpE),
        .false_prediction(false_prediction)
    );


    fd_pipeline fd_pip(
        .clk(clk),
        .rst(rst),
        .flush(flush_f_d),
        .enable(enable_fd && F_Write),
        .instr_f(InstrF),
        .pc_f(PCF),
        .pc_save_f(PCPlus4F),
        .instr_d(InstrD),
        .pc_d(PCD),
        .pc_save_d(PCPlus4D),
        .pred_takenF(pred_takenF),
        .pred_takenD(pred_takenD)
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
     .funct3E(funct3E),

//branch prediction logic propagating
    .pred_takenD(pred_takenD),
    .pred_takenE(pred_takenE)
    );


    PCSrcE_assertion PCSourceE(
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
        .LoadUnsigned(LoadUnsignedD),
        .l1d_enable(cache_data_enable)
    );


//we set default load size to 2'b10 because we always want to fetch a word :
logic [1:0] LoadSizeDefault =2'b10;
logic LoadUnsignedDefault = 0; //don't care

logic cache_instruction_enable ;
assign cache_instruction_enable =1'b1;

l1i_cache l1i_cache_inst (
    .clk(clk),
    .fetch(cache_instruction_enable),
    .addr(PCF),
    .line_from_mem(data_out_l2),
    .LoadSize(LoadSizeDefault),
    .LoadUnsigned(LoadUnsignedDefault),
    .ready(ready_i),
    .l2_addr(addr_i),
    .l2_fetch(fetch_i),
    .data_out(InstrF),
    .stall(stall_l1i)
);


logic cache_data_enable;

l1d_cache l1d_cache_inst (
    .clk(clk),
    .fetch(cache_data_enable),
    .addr(ALUResultM),
    .wd(WriteDataM),
    .line_from_mem(data_out_l2),
    .SizeWrite_m(SizeWriteM),
    .MemWrite_m(MemWriteM),
    .LoadSize(LoadSizeM),
    .LoadUnsigned(LoadUnsignedM),
    .ready(ready_d),
    .wb_ready(wb_ready_d),
    .data_out(ReadDataM),
    .write_back(l1write_back_data),
    .write_back_en(l1write_back_en),
    .write_back_addr(l1write_back_addr),
    .l2_addr(addr_d),
    .l2_fetch(fetch_d),
    .stall(stall_l1d)
);

logic                            fetch_i;
logic                            fetch_d;
logic [ADDRESS_WIDTH-1:0]        addr_i;
logic [ADDRESS_WIDTH-1:0]        addr_d;
logic [DATA_WIDTH*BLOCK_SIZE-1:0] line_from_mem;
logic [DATA_WIDTH*4-1:0]         l1write_back_data;
logic                            l1write_back_en;
logic [ADDRESS_WIDTH-1:0]        l1write_back_addr;
logic                            ready;
logic                            ready_i;
logic                            ready_d;
logic                            wb_ready_d;
logic [DATA_WIDTH*4-1:0]         data_out_l2;

l2_cache l2_cache_inst (
    .clk(clk),
    .fetch_i(fetch_i),
    .fetch_d(fetch_d),
    .addr_i(addr_i),
    .addr_d(addr_d),
    .line_from_mem(line_from_mem),
    .l1write_back_data(l1write_back_data),
    .l1write_back_en(l1write_back_en),
    .l1write_back_addr(l1write_back_addr),
    .ready(ready),
    .wb_ready(wb_ready_mainmem),
    .ready_i(ready_i),
    .ready_d(ready_d),
    .wb_ready_d(wb_ready_d),
    .data_out(data_out_l2),
    .write_back_data(w_data),
    .write_back_addr(w_addr),
    .write_back_en(w_en),
    .main_mem_addr(r_addr),
    .main_mem_fetch(r_en)
);

// Read Interface
logic [ADDRESS_WIDTH-1:0] r_addr;
logic                     r_en;

// Write Interface
logic [ADDRESS_WIDTH-1:0] w_addr;
logic                     w_en;
logic [4*DATA_WIDTH-1:0]  w_data;
logic                     wb_ready_mainmem;



mainmemory main_memory (
    .clk(clk),
    .r_addr(r_addr),
    .r_en(r_en),
    .dout(line_from_mem),
    .ready(ready),
    .w_addr(w_addr),
    .w_en(w_en),
    .w_data(w_data),
    .wb_ready(wb_ready_mainmem)
);


logic actual_taken;
logic [1:0] PCSrcF;

//demultiplexer to know if the branch is taken or not
    always_comb begin
        case (PCSrcE)

        2'b00 : actual_taken = 0;
        2'b01 : actual_taken = 1;
        default: actual_taken =0;//by default it is not taken (but in the case where PCSrcE is different from the values listed above we can consider this signal as a don't care because BranchE will be equal to 0)
        endcase
    end


    branchpredictor2bit branchpredictor (
        .clk(clk),
        .rst(rst),
        .enable(BranchE && enable_branch_predictor),//enable signal for the FSM: we write in the FSM only when the instruction in the execute stage is a branch instruction
        .update_index(PCE[7:2]), //index of that branch PC
        .actual_taken(actual_taken), //real outcome
        .predict_index(PCF[7:2]),//index from PC (we take the bus [7:2] corresponding to 6 bits from PC to identify the specific jump we are dealing with)
        .pred_taken(pred_takenF)//prediction output 
    );


logic [31:0] target;

    PCSrcF_assertion PCSourceF(
        .JumpE(JumpE),
        .BranchE(BranchE),
        .opcodeF(InstrF[6:0]),
        .PCSrcE(PCSrcE),
        .predictionF(pred_takenF),
        .predictionE(pred_takenE),
        .false_prediction(false_prediction),
        .targetF(PCF + {{20{InstrF[31]}}, InstrF[7], InstrF[30:25], InstrF[11:8], 1'b0}),
        .targetE(PCE + ExtImmE),
        .FinalTarget(target),
        .PCSrcF(PCSrcF)
    );


    pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .enable(PCWrite && enable_pc_block),
        .Imm_op(target), //very important line 
        .pc_src(PCSrcF),
        .pc(PCF),
        .pc_saved(PCPlus4E), //in the case the predictor forecasted a jump and made a false guess
        .pc_save(PCPlus4F),
        .ALU(ALUResultE)
    );

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
    .enable(enable_em),
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



mw_pipeline mw_pipeline(
    //inputs from the previous pipeline register: (control inputs)
    .RegWrite_m(RegWriteM),
    .ResultSrc_m(ResultSrcM),

    //corresponding outputs
    .RegWrite_w(RegWriteW),
    .ResultSrc_w(ResultSrcW),
    .rst(rst),
    .clk(clk),
    .enable(enable_mw),
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



