module regfile#(
    DATA_WIDTH=32,
    REG_FILE_WIDTH=32
    )(
    input logic clk,
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


    always_ff @(negedge clk) begin
        if(WE3) begin
            if(AD3 == 0) regfile_array[0] <= '0; // X0 is always 0
            else regfile_array[AD3] <= WD3;
        end
    end
    
    always_comb begin
        RD1= regfile_array[AD1];
        RD2= regfile_array[AD2];
        A0 = regfile_array[10];
    end

endmodule

