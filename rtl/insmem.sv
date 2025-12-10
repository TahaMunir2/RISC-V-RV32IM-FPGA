module insmem #(
    parameter DATA_WIDTH = 32,
)(
    input  logic [DATA_WIDTH-1:0] addr,
    output logic [DATA_WIDTH-1:0] instr
);

    logic [7:0] rom_array [2**12-1:0];

    initial begin
        $display("Loading rom.", );
        $readmemh("program.hex", rom_array, 32'hBFC00000);
    end

    logic [ADDR_WIDTH-1 : 0] local_addr;

    always_comb begin // asynchronous read
        local_addr = addr - BASE_ADDR;
        if (addr >= BASE_ADDR && local_addr < (MEM_DEPTH - 3)) begin
            instr = {
                rom_array[local_addr + 3], 
                rom_array[local_addr + 2], 
                rom_array[local_addr + 1], 
                rom_array[local_addr]
            };
        end else begin
            instr = 32'b0; 
        end
    end
endmodule
