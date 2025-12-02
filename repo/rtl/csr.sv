module csr #( 
    parameter ADDRESS_WIDTH = 12,
    parameter DATA_WIDTH = 32,
    parameter REGFILE_WIDTH = 4096
)(
    input logic clk,
    input logic [1:0] CSR_OP,
    input logic [ADDRESS_WIDTH-1:0] addr,
    input logic en,
    input logic [DATA_WIDTH-1:0] wd,
    output logic [DATA_WIDTH-1:0] dout
);

    logic[DATA_WIDTH-1:0] temp;
    logic[DATA_WIDTH-1:0] regfile_array [REGFILE_WIDTH-1:0];
    assign dout = regfile_array[addr];

    always_comb begin
        temp = dout;
        case(CSR_OP)
            2'b01: temp =  wd; // CSSRW(I)
            2'b10: temp = temp | wd;   // CSRRS(I)  
            2'b11: temp = temp & (~wd); // CSRRC(I)
            default: temp = dout;
        endcase
    end
    
    always_ff @(negedge clk) begin
        if(en) regfile_array[addr] <= temp;

    end

endmodule
