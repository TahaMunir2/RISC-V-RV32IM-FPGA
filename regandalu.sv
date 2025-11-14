module regandalu#(
    DATA_WIDTH=32
    )(
    input logic clk,
    input logic WE3,
    input logic [5:0] AD3,
    input logic [5:0] AD2,
    input logic [5:0] AD1,
    input logic                  ALUctrl,
    input logic                  ALUsrc,
    input logic [DATA_WIDTH-1: 0] ImmOp,
    output logic                   EQ
    );
    
    logic [DATA_WIDTH-1: 0] output_ALU;
    logic [DATA_WIDTH-1: 0] ALUop1;
    logic [DATA_WIDTH-1: 0] ALUop2;
    logic [DATA_WIDTH-1: 0] regOp2;

    regfile regfile(
        .clk(clk),
        .WD3(output_ALU),
        .AD3(AD3),
        .AD2(AD2),
        .AD1(AD1),
        .RD1(ALUop1),
        .RD2(regOp2)
    )

    mux mux(
        .in0(regOp2),
        .in1(ImmOp),
        .sel(ALUsrc),
        .out(ALUop2)
    )

    alu alu(
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUctrl(ALUctrl),
        .ALUout(output_ALU),
        .EQ(EQ)
    )


endmodule


