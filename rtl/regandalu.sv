module regandalu#(
    DATA_WIDTH=32
    )(
    input logic clk,
    input logic WE3,
    input logic MemWrite,
    input logic [1:0] SizeWrite, //changed from ByteWrite to SizeWrite
    input logic [1:0]LoadSize, //additional output signal
    input logic LoadUnsigned, //additional output signal
    input logic [DATA_WIDTH-1:0] pc_save,
    input logic [4:0] AD3,
    input logic [4:0] AD2,
    input logic [4:0] AD1,
    input logic [3:0]             ALUCtrl, //changed to 4 bits
    input logic                   ALUsrc,
    input logic [DATA_WIDTH-1: 0] ImmOp,
    input logic [1:0] ResultSrc, //additional input (select line of the additional multiplexer)
    input logic ALUsrc2,
    output logic                   EQ,
    output logic                   LT, //additional signal for branching
    output logic                   LTU, //additional signal for branching
    output logic [DATA_WIDTH-1: 0] A0,
    output logic [DATA_WIDTH-1:0] ALU_OUT
    );
    
    logic [DATA_WIDTH-1: 0] output_ALU;
    logic [DATA_WIDTH-1: 0] ALUop1;
    logic [DATA_WIDTH-1: 0] ALUop2;
    logic [DATA_WIDTH-1: 0] regOp2;
    logic [DATA_WIDTH-1: 0] regOp;  

//additional logic to implement to additional multiplexer block
    logic [DATA_WIDTH-1: 0] output_DataMem;
    logic [DATA_WIDTH-1: 0] write_to_reg;

    assign ALU_OUT = output_ALU;
    
    always_comb begin
        case (ResultSrc)
            2'b00: write_to_reg = output_ALU;     // ALU
            2'b01: write_to_reg = output_DataMem; // Memory
            2'b10: write_to_reg = pc_save;        // for jump instructions
            default: write_to_reg = 32'b0;
        endcase
    end


    regfile regfile(
        .clk(clk),
        .WD3(write_to_reg), //it is not anymore always the output of the ALU , it can be both (output of ALU and output of DataMem depending on the instruction)
        .AD3(AD3),
        .AD2(AD2),
        .AD1(AD1),
        .WE3(WE3),
        .RD1(regOp),
        .RD2(regOp2),
        .A0(A0)
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




endmodule

