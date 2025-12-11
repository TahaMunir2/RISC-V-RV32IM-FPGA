module top #(
    parameter DATA_WIDTH = 32
) (
    input  logic                   clk,
    input  logic                   rst,
    input  logic                   trigger,
    output logic [DATA_WIDTH-1:0]  a0,
    output logic [9:0]             leds
);

    logic [4:0] Rs1D, Rs2D, RdD;
    logic [4:0] Rs1E, Rs2E, RdE;
    logic [DATA_WIDTH-1 : 0] RD1E, RD2E, RD1D, RD2D;
    logic [DATA_WIDTH-1 : 0] ExtImmE, ExtImmD;
    logic [1 : 0] ResultSrcD, ResultSrcM;
    logic [DATA_WIDTH-1:0] RD1D_Correct, RD2D_Correct;
    

    logic [DATA_WIDTH-1 : 0] InstrF;          
    logic [DATA_WIDTH-1 : 0] InstrF_raw;       
    logic RegWriteD;
    logic [DATA_WIDTH-1 : 0] ReadDataM, WriteDataE;
    logic EQ, LT, LTU;

    logic [DATA_WIDTH-1:0] PCF, PCD, PCE;
    logic [DATA_WIDTH-1 : 0] PCPlus4F, PCPlus4D, PCPlus4E;


    logic BranchD, BranchE, JumpD, JumpE;
    logic [2:0] funct3D, funct3E;
    logic [2:0] ImmSrcD;

    logic [DATA_WIDTH-1: 0] ALUResultE, ALUop1;
    logic MemWriteD;
    logic [1:0] SizeWriteD;
    logic [1:0] LoadSizeD;
    logic LoadUnsignedD;


    logic flush_d_exec, flush_f_d;
    logic F_Write, PCWrite;

    logic [4:0] ALUCtrlD, ALUCtrlE;
    logic ALUSrcD, ALUSrcE;
    logic ALUSrc2D, ALUSrc2E;
    logic ALUSrc3D, ALUSrc3E;
    logic RegWriteE;
    logic [1:0] ResultSrcE;
    logic MemWriteE;
    logic [1:0] SizeWriteE;
    logic [1:0] LoadSizeE; 
    logic LoadUnsignedE;
    logic enable_de = 1;
    logic [1:0] PCSrcE;


    logic [DATA_WIDTH-1:0] PCPlus4M;
    logic [4:0] RdM;
    logic [DATA_WIDTH-1:0] ALUResultM;
    logic [DATA_WIDTH-1:0] WriteDataM;
    logic RegWriteM, MemWriteM;
    logic [1:0] SizeWriteM;
    logic [1:0] LoadSizeM; 
    logic LoadUnsignedM;

    logic RegWriteW;
    logic [1:0] ResultSrcW;
    logic [DATA_WIDTH-1 :0] ALUResultW, ReadDataW, ResultW;
    logic [4:0] RdW;
    logic [DATA_WIDTH-1:0] PCPlus4W;


    logic pred_takenF, pred_takenD, pred_takenE;
    logic false_prediction;


    logic [11:0] csr_addrD, csr_addrE, csr_addrM, csr_addrW;
    logic [1:0] csr_typeD, csr_typeE, csr_typeM, csr_typeW;
    logic [31:0] CSR_read, CSR_write;
    logic [31:0] ALUResultE_internal; 
    

    logic mret_en, trap_en, timer_interrupt, timer_write_en;
    logic [DATA_WIDTH-1:0] handler_address;
    logic flush_e_m;

    assign csr_addrD = InstrF[31:20];


    logic kill_cycle;

    logic [DATA_WIDTH-1:0] InstrD_Saved;
    logic Stall_Active;


    always_ff @(posedge clk) begin
        if (rst) begin
            Stall_Active <= 0;
            InstrD_Saved <= 0;
        end else begin
            Stall_Active <= flush_d_exec; 

            if (flush_d_exec && !Stall_Active) begin
                InstrD_Saved <= InstrF_raw;
            end
        end
    end

    

  
    always_ff @(posedge clk) begin
        if (rst) 
            kill_cycle <= 0;
        else 
            kill_cycle <= (JumpE || false_prediction || trap_en || mret_en); 
           
    end
assign InstrF = (kill_cycle || rst) ? 32'h00000013 : 
                (Stall_Active) ? InstrD_Saved : InstrF_raw;


always_comb begin
   
        if (RegWriteW && (Rs1D != 0) && (Rs1D == RdW)) 
            RD1D_Correct = ResultW;
        else 
            RD1D_Correct = RD1D;

    
        if (RegWriteW && (Rs2D != 0) && (Rs2D == RdW)) 
            RD2D_Correct = ResultW;
        else 
            RD2D_Correct = RD2D;
    end




assign predictionF = 1'b0;   


assign targetF = 32'b0;      


assign false_prediction = (PCSrcE != 2'b00);


    logic gpio_wen;
    assign gpio_wen = MemWriteM && (ALUResultM[DATA_WIDTH-1:0] == 32'h80002000);

    gpio gpio(
        .clk(clk),
        .rst(rst),
        .we(gpio_wen),
        .data(WriteDataM),
        .leds(leds)
    );
	 

	 

    logic [1:0] ForwardAE; 
    logic [1:0] ForwardBE;

    hazard_unit hazard_unit (
        .rs1D(Rs1D), 
        .rs2D(Rs2D),
        .rs1E(Rs1E), 
        .rs2E(Rs2E),
        .rdM(RdM),
        .ResultSrcM(ResultSrcM),
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
        .false_prediction(false_prediction),
        .csr_typeD(csr_typeD),
        .csr_typeE(csr_typeE),
        .csr_typeM(csr_typeM),
        .csr_typeW(csr_typeW),
        .csr_addrD(csr_addrD),
        .csr_addrE(csr_addrE),
        .csr_addrM(csr_addrM),
        .csr_addrW(csr_addrW),
        .mret_en(mret_en),
        .trap_en(trap_en),
        .flush_e_m(flush_e_m)
    );

    

    fd_pipeline fd_pip(
        .clk(clk),
        .rst(rst),
        .flush(flush_f_d),
        .enable(F_Write),
        .pc_f(PCF),
        .pc_save_f(PCPlus4F),
        .pc_d(PCD),
        .pc_save_d(PCPlus4D),
        .pred_takenF(pred_takenF),
        .pred_takenD(pred_takenD)
    );

    signext sign_extension (
        .instr(InstrF),
        .ImmSrc(ImmSrcD),
        .immext(ExtImmD)
    );

    logic [31:0] PCE_special;


    de_pipeline de_pip(
        .clk(clk),
        .rst(rst),
        .flush(flush_d_exec), 
        .enable(enable_de),
        .pc_save_d (PCPlus4D),
        .RD1_d     (RD1D_Correct),
        .RD2_d     (RD2D_Correct),
        .pc_d      (PCD),
        .pc_e      (PCE),
        .pc_e_spc  (PCE_special),
        .Rd_d      (RdD),
        .ImmExt_d  (ExtImmD),
        .Rs1D      (Rs1D),
        .Rs2D      (Rs2D),
        .csr_addrD (csr_addrD),
        // Gated signals for flush
        .RegWrite_d     (RegWriteD & ~flush_f_d),
        .ResultSrc_d    (ResultSrcD),
        .MemWrite_d     (MemWriteD & ~flush_f_d),
        .BranchD        (BranchD   & ~flush_f_d),
        .JumpD          (JumpD     & ~flush_f_d),
        .csr_typeD      (csr_typeD & {2{~flush_f_d}}), 

        .ALUCtrl_d      (ALUCtrlD),
        .ALUSrc_d       (ALUSrcD),
        .SizeWrite_d    (SizeWriteD),
        .LoadSize_d     (LoadSizeD), 
        .LoadUnsigned_d (LoadUnsignedD),
        .ALUSrc2_d      (ALUSrc2D),
        .ALUSrc3D       (ALUSrc3D),
        .funct3D        (funct3D),
        .pred_takenD    (pred_takenD),

        .pc_save_e      (PCPlus4E),
        .RD1_e          (RD1E),
        .RD2_e          (RD2E),
        .Rd_e           (RdE),
        .ImmExt_e       (ExtImmE),
        .Rs1E           (Rs1E),
        .Rs2E           (Rs2E),
        .csr_addrE      (csr_addrE),
        .RegWrite_e     (RegWriteE),
        .ResultSrc_e    (ResultSrcE),
        .MemWrite_e     (MemWriteE),
        .ALUCtrl_e      (ALUCtrlE),
        .ALUSrc_e       (ALUSrcE),
        .SizeWrite_e    (SizeWriteE),
        .LoadSize_e     (LoadSizeE), 
        .LoadUnsigned_e (LoadUnsignedE),
        .ALUSrc2_e      (ALUSrc2E),
        .ALUSrc3E       (ALUSrc3E),
        .BranchE        (BranchE),
        .JumpE          (JumpE),
        .funct3E        (funct3E),
        .csr_typeE      (csr_typeE),
        .pred_takenE    (pred_takenE)
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
        .instr(InstrF),
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
        .ALUSrc3(ALUSrc3D),
        .csr_type(csr_typeD),
        .mret_en(mret_en)
    );

    logic actual_taken;
    logic [1:0] PCSrcF;

    always_comb begin
        case (PCSrcE)
            2'b00 : actual_taken = 0;
            2'b01 : actual_taken = 1;
            default: actual_taken = 0; 
        endcase
    end

  logic [DATA_WIDTH-1:0] BTB_TargetF; 

	 
    logic [DATA_WIDTH-1:0] target;

    PCSrcF_assertion PCSourceF(
        .JumpE(JumpE),
        .BranchE(BranchE),
        .opcodeF(InstrF[6:0]), 
        .PCSrcE(PCSrcE),
        .predictionF(pred_takenF),
        .predictionE(pred_takenE),
        .false_prediction(false_prediction),
        
        .targetF(BTB_TargetF), 
        
        .targetE(PCE + ExtImmE),
        .FinalTarget(target),
        .PCSrcF(PCSrcF)
    );

    pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .enable(PCWrite),
        .Imm_op(target), 
        .pc_src(PCSrcF),
        .pc(PCF),
        .handler_address(handler_address),
        .mret_en(mret_en),
        .trap_en(trap_en),
        .pc_saved(PCPlus4E), 
        .pc_save(PCPlus4F),
        .ALU(ALUResultE)
    );

    logic [4:0] AD2, AD1;

    regfile regfile(
        .clk(clk),
        .WD3(ResultW), 
        .AD3(RdW),
        .AD2(AD2),
        .AD1(AD1),
        .WE3(RegWriteW),
        .RD1(RD1D),
        .RD2(RD2D),
        .A0(a0)
    );

    logic [DATA_WIDTH-1: 0] SrcAE, SrcBE;

    mux4 forwardingRS1(
        .in0(RD1E),
        .in1(ResultW),
        .in2(ALUResultM),
        .in3(RD1E), 
        .select_line(ForwardAE), 
        .out(SrcAE)    
    );

    mux4 forwardingRS2(
        .in0(RD2E),
        .in1(ResultW),
        .in2(ALUResultM),
        .in3(RD2E), 
        .select_line(ForwardBE), 
        .out(WriteDataE)    
    );

    mux mux_immVSreg( 
        .in0(WriteDataE),
        .in1(ExtImmE),
        .sel(ALUSrcE),
        .out(SrcBE)
    );

    mux mux_pcVSreg( 
        .in0(SrcAE),
        .in1(PCPlus4E),
        .sel(ALUSrc2E),
        .out(ALUop1)
    );

    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(SrcBE),
        .ALUout(ALUResultE_internal),
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU),
        .ALUCtrl(ALUCtrlE)
    );

    timer timer (
        .clk(clk),
        .rst(rst),
        .we(timer_write_en),
        .addr(ALUResultM),
        .data(WriteDataM),
        .timer_interrupt(timer_interrupt)
    );

    assign ALUResultE = (|csr_typeE) ? CSR_read : ALUResultE_internal; 
    assign CSR_write = (ALUSrc3E) ? ExtImmE : SrcAE; 
    assign timer_write_en = MemWriteM && (ALUResultM[31:4] == 28'h8000100);

    csr csr ( 
        .clk(clk),
        .rst(rst),
        .PCE(PCE),
        .mret_en(mret_en),
        .trap_en(trap_en),
        .external_interrupt(trigger),
        .timer_interrupt(timer_interrupt),
        .handler_address(handler_address),
        .CSR_OP(csr_typeE),
        .addr(csr_addrE),
        .en(|csr_typeE), 
        .wd(CSR_write),
        .dout(CSR_read)
    );

    em_pipeline em_pipeline(
        .rst(rst),
        .clk(clk),
        .flush(flush_e_m),
        .RegWrite_e(RegWriteE),
        .ResultSrc_e(ResultSrcE),
        .MemWrite_e(MemWriteE),
        .SizeWrite_e(SizeWriteE),
        .LoadSize_e(LoadSizeE), 
        .LoadUnsigned_e(LoadUnsignedE),
        .csr_typeE(csr_typeE),
        .RegWrite_m(RegWriteM),
        .ResultSrc_m(ResultSrcM),
        .MemWrite_m(MemWriteM),
        .SizeWrite_m(SizeWriteM),
        .LoadSize_m(LoadSizeM), 
        .LoadUnsigned_m(LoadUnsignedM),
        .csr_typeM(csr_typeM),
        .pc_save_e(PCPlus4E),
        .Rd_e(RdE),
        .ALU_Result_e(ALUResultE),
        .Write_Data_e(WriteDataE),
        .csr_addrE(csr_addrE),
        .pc_save_m(PCPlus4M),
        .Rd_m(RdM),
        .ALU_Result_m(ALUResultM),
        .Write_Data_m(WriteDataM),
        .csr_addrM(csr_addrM)
    );

    logic MemWrite_allowed;
    assign MemWrite_allowed = MemWriteM && (ALUResultM[31:28] != 4'h8);

	new_insmem #(
		 .MEM_BYTES (4096),
		 .BASE_ADDR (32'hBFC00000)
	) imem (
		 .clk  (clk),
		 .addr (PCF),          
		 .instr(InstrF_raw)      
	);

    new_datamem #(
		 .MEM_BYTES (131072),
		 .BASE_ADDR (32'h0000000)
	) dmem (
		 .MemWrite     (MemWrite_allowed),
		 .WD           (WriteDataM),
		 .SizeWrite    (SizeWriteM),
		 .A            (ALUResultM),
		 .LoadSize     (LoadSizeM),
		 .LoadUnsigned (LoadUnsignedM),
		 .clk          (clk),
		 .dout         (ReadDataM)
	);

    mw_pipeline mw_pipeline(
        .RegWrite_m(RegWriteM),
        .ResultSrc_m(ResultSrcM),
        .csr_typeM(csr_typeM),
        .RegWrite_w(RegWriteW),
        .ResultSrc_w(ResultSrcW),
        .rst(rst),
        .clk(clk),
        .csr_typeW(csr_typeW),
        .pc_save_m(PCPlus4M),
        .Rd_m(RdM),
        .ALU_Result_m(ALUResultM),
        .csr_addrM(csr_addrM),
        .pc_save_w(PCPlus4W),
        .Rd_w(RdW),
        .ALU_Result_w(ALUResultW),
        .csr_addrW(csr_addrW)
    );

    assign ReadDataW = ReadDataM;
    always_comb begin
        case (ResultSrcW)
            2'b00: ResultW = ALUResultW;
            2'b01: ResultW = ReadDataW;
            2'b10: ResultW = PCPlus4W;
            default: ResultW = 32'b0;
        endcase
    end

    always_comb begin
        Rs1D = InstrF[19:15];
        Rs2D = InstrF[24:20];
        RdD  = InstrF[11:7];
        AD2  = InstrF[24:20];
        AD1  = InstrF[19:15];
    end

endmodule