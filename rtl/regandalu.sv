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

        mux mux_immVSreg( 
        .in0(regOp2),
        .in1(ImmOp),
        .sel(ALUsrc),
        .out(ALUop2)
    );

        mux mux_pcVSreg( //additional mux
        .in0(regOp),
        .in1(pc_save),
        .sel(ALUsrc2),
        .out(ALUop1)
    );


    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUCtrl(ALUCtrl),
        .ALUout(output_ALU),
        .EQ(EQ),
        .LT(LT),
        .LTU(LTU)
    );

//data memory (Asynchronous input) :

    datamem datamem(
        .clk(clk),
        .A(output_ALU),
        .dout(output_DataMem),
        .MemWrite(MemWrite),
        .WD(regOp2),
        .SizeWrite(SizeWrite),
        .LoadSize(LoadSize), //additional output signal
        .LoadUnsigned(LoadUnsigned) //additional output signal        
    );



endmodule

