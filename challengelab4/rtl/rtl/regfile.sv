module regfile#(
    DATA_WIDTH=32,
    REG_FILE_WIDTH=32
    )(
    input logic clk,
    input logic trigger,
    input logic [DATA_WIDTH-1:0] WD3,
    input logic WE3,
    input logic [4:0] AD3,
    input logic [4:0] AD2,
    input logic [4:0] AD1,
    output logic [DATA_WIDTH-1: 0] RD1,
    output logic [DATA_WIDTH-1: 0] RD2,
    output logic [DATA_WIDTH-1: 0] A0 
    );

    logic [DATA_WIDTH-1: 0] regfile_array [REG_FILE_WIDTH-1: 0];

    assign regfile_array[25] = trigger ;//s9 is a saved register type (it represents the value of trigger: the signal that starts the program)

    always_ff @(negedge clk) begin
        if(WE3) regfile_array[AD3] <= WD3;
    end
    
    always_comb begin
        RD1= regfile_array[AD1];
        RD2= regfile_array[AD2];
        A0 = regfile_array[10];
    end

endmodule

