module regandalu#(
    DATA_WIDTH=32
    )(
    input logic clk,
    input logic WE3,
    input logic [4:0] AD3,
    input logic [4:0] AD2,
    input logic [4:0] AD1,
    input logic [2:0]             ALUctrl,
    input logic                   ALUsrc,
    input logic [DATA_WIDTH-1: 0] ImmOp,
    input logic reg_entry, //additional input (select line of the additional multiplexer)
    output logic                   EQ,
    output logic [DATA_WIDTH-1: 0] A0
    );
    
    logic [DATA_WIDTH-1: 0] output_ALU;
    logic [DATA_WIDTH-1: 0] ALUop1;
    logic [DATA_WIDTH-1: 0] ALUop2;
    logic [DATA_WIDTH-1: 0] regOp2;

//additional logic to implement to additional multiplexer block
    logic [DATA_WIDTH-1: 0] output_DataMem;
    logic [DATA_WIDTH-1: 0] write_to_reg;


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
