module new_insmem #(
    parameter ADDRESS_WIDTH     = 32,
    parameter MEM_BYTES         = 4096,  
    parameter DATA_WIDTH        = 8,
    parameter BASE_ADDR         = 32'hBFC00000

)(
    input  logic                     clk,
    input  logic [ADDRESS_WIDTH-1:0] addr,
    output logic [31:0]              instr      
);

    logic [DATA_WIDTH-1:0] romArray[0:MEM_BYTES-1];

    logic [ADDRESS_WIDTH-1:0] full_local_addr;
    logic [$clog2(MEM_BYTES)-1:0] valid_index;

    assign full_local_addr = addr - BASE_ADDR;
    assign valid_index = full_local_addr[$clog2(MEM_BYTES)-1:0];

    initial begin
        $display("Loading Instruction Memory");
        $readmemh("program.hex", romArray);
    end

    //Fetch instruction
    always_ff @(posedge clk) begin // check to make sure we aren't accessing memory we aren't allowed to
        if (addr > BASE_ADDR - 1 && full_local_addr < MEM_BYTES - 3) instr <= {romArray[valid_index+3], romArray[valid_index+2], romArray[valid_index+1], romArray[valid_index]};
        else instr <= 32'h00000000; // no-op for invalid pc
        end

endmodule
