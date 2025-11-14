module regfile#(
    DATA_WIDTH=32,
    REG_FILE_WIDTH=32
    )(
    input logic clk,
    input logic [DATA_WIDTH-1:0] WD3,
    input logic WE3,
    input logic [5:0] AD3,
    input logic [5:0] AD2,
    input logic [5:0] AD1,
    output logic [DATA_WIDTH-1: 0] RD1,
    output logic [DATA_WIDTH-1: 0] RD2,
    output logic [DATA_WIDTH-1: 0] A0 ///see remark below
    /*
    ??????????
    ////////////
    
    should this be an output? should I define it as a constant and then use it to access the array?
    
    //////////
    ??????????
    
    
     */
    );

    logic [DATA_WIDTH-1: 0] regfile_array [REG_FILE_WIDTH-1: 0];

    always_ff (@posedge clk) begin
        if(WE3) mem[AD3] = WD3;
    end
    
    always_comb begin
        RD1= mem[AD1];
        RD2= mem[AD2];
    end

endmodule


