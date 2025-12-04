module sup_regfile #(
    parameter DATA_WIDTH = 32,
    parameter REG_FILE_WIDTH = 32
)(
    input  logic clk,

    // special trigger input
    input  logic trigger,

    // WRITE PORT 1
    input  logic [DATA_WIDTH-1:0] WD1,
    input  logic WE1,
    input  logic [4:0] AD1W,

    // WRITE PORT 2
    input  logic [DATA_WIDTH-1:0] WD2,
    input  logic WE2,
    input  logic [4:0] AD2W,

    // READ PORT 1
    input  logic [4:0] AD1R,
    output logic [DATA_WIDTH-1:0] RD1,

    // READ PORT 2
    input  logic [4:0] AD2R,
    output logic [DATA_WIDTH-1:0] RD2,

    // READ PORT 3
    input  logic [4:0] AD3R,
    output logic [DATA_WIDTH-1:0] RD3,

    // READ PORT 4
    input  logic [4:0] AD4R,
    output logic [DATA_WIDTH-1:0] RD4,

    // Always expose x10
    output logic [DATA_WIDTH-1:0] A0
);

    // REGISTER ARRAY
    logic [DATA_WIDTH-1:0] regfile_array [REG_FILE_WIDTH-1:0];

    // CONSTANT ASSIGN
    assign regfile_array[25] = {31'b0, trigger};

    // WRITE OPERATION — MULTIPLE WRITE PORTS
    always_ff @(negedge clk) begin
        if (WE1) regfile_array[AD1W] <= WD1;
        if (WE2) regfile_array[AD2W] <= WD2;
    end

    // READ OPERATION — PURE COMBINATIONAL
    always_comb begin
        RD1 = regfile_array[AD1R];
        RD2 = regfile_array[AD2R];
        RD3 = regfile_array[AD3R];
        RD4 = regfile_array[AD4R];
        A0  = regfile_array[10]; // x10 a0 ABI mapping
    end
endmodule

