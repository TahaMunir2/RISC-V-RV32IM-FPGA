module mux4 #(
    parameter DATA_WIDTH =32;
)(
    input logic [DATA_WIDTH-1: 0] in0,
    input logic [DATA_WIDTH-1: 0] in1,
    input logic [DATA_WIDTH-1: 0] in2,
    input logic [DATA_WIDTH-1: 0] in3,
    input logic [1:0] select_line,
    output logic [DATA_WIDTH-1:0] out
);

mux muxA (
    .in0(in0),
    .in1(in1),
    .sel(select_line[0]),
    .out(out)
)

mux muxB(
    .in0(in2),
    .in1(in3),
    .sel(select_line[1]),
    .out(out)
)



endmodule

