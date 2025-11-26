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
        .sel(ALUsrc),
        .out(ALUop2)
    );

    mux mux_pcVSreg( //additional mux, because we never use data from a register and from pc_save in any instructiom
        .in0(SrcAE),
        .in1(pc_save),
        .sel(ALUsrc2),
        .out(ALUop1)
    );


    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUctrl(ALUControlE),
        .ALUout(output_ALU),
        .EQ(EQ)
    );


//extra wires added for the pipeline register:
    logic [DATA_WIDTH-1:0] PCPlus4M,
    logic [DATA_WIDTH-1:0] RdM,
    logic [DATA_WIDTH-1:0] ALUResultM,
    logic [DATA_WIDTH-1:0] WriteDataM,


em_pipeline em_pipeline(
    //control inputs coming from the previous pipeline register
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
    .LoadUnsigned_m(LoadUnsignedm)

    //inputs to the register processed in the execute stage
    .pc_save_e(PCPlus4E),
    .Rd_e(RdE),
    .ALU_Result_e(output_ALU),
    .Write_Data_e(SrcBE),

    //corresponding data outputs
    .pc_save_m(PCPlus4M),
    .Rd_m(RdM),
    .ALU_Result_m(ALUResultM),
    .Write_Data_m(WriteDataM),
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

//extra wires for the output of the memory-writeback pipeline register:
logic RegWriteW;
logic [1:0] ResultSrcW;
logic [DATA_WIDTH-1 :0] datamem_output;
logic [DATA_WIDTH-1 :0] ALUResultW;
logic [DATA_WIDTH-1 :0] ReadDataW;


mw_pipeline mw_pipeline(
    //inputs from the previous pipeline register: (control inputs)
    .RegWrite_m(RegWriteM),
    .ResultSrc_m(ResultSrcM),

    //corresponding outputs
    .RegWrite_w(RegWriteW),
    .ResultSrc_w(ResultSrcW),

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
        case (ResultSrc)
            2'b00: write_to_reg = ALUResultW;     // ALU
            2'b01: write_to_reg = ReadDataW; // Memory
            2'b10: write_to_reg = PCPlus4W;        // for jump instructions
            default: write_to_reg = 32'b0;
        endcase
    end


endmodule


