module insmem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 8
)(
    input  logic                     clk,  
    input  logic [ADDRESS_WIDTH-1:0] addr,
    output logic [31:0]              instr
);

    logic [DATA_WIDTH-1:0] romArray [2**16-1:0];

    logic [15:0] instrAddr;
    assign instrAddr = addr[15:0];

    logic [15:0] unused;
    assign unused = addr[31:16]; 

    initial begin
        $display("Loading Instruction Memory");
        $readmemh("program.hex", romArray);
    end

    always_ff @(posedge clk) begin
        instr <= {romArray[instrAddr+3], 
                  romArray[instrAddr+2], 
                  romArray[instrAddr+1], 
                  romArray[instrAddr]};
    end

endmodule
