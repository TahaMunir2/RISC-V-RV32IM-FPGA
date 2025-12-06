module insmem #(
    parameter ADDRESS_WIDTH = 32,
    parameter DATA_WIDTH    = 8,
    parameter BASE_ADDR     = 32'hBFC00000
)(
    input logic [ADDRESS_WIDTH-1:0] addr,
    output logic [31:0] instr
);

    logic [DATA_WIDTH-1:0] romArray [0:4095];

    initial begin
        $display("Loading Instruction Memory");
        $readmemh("program.hex", romArray);
    end

    logic [ADDRESS_WIDTH-1:0] local_addr;
    assign local_addr = addr - BASE_ADDR;


    always_comb begin
        if (addr >= BASE_ADDR && local_addr < 4096) begin // check to make sure we aren't accessing memory we aren't allowed to
            instr = {romArray[local_addr+3], romArray[local_addr+2], romArray[local_addr+1], romArray[local_addr]};
        end else instr = 32'h00000000; // no-op for invalid pc
    end

endmodule
