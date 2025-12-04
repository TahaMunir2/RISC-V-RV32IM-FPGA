module new_insmem #(
    parameter ADDRESS_WIDTH = 32,
              MEM_BYTES     = 8192,  //8KB default
              DATA_WIDTH = 8
)(
    input  logic                     clk,
    input  logic                     write_en,  //enable for UART/program loader
    input  logic [ADDRESS_WIDTH-1:0] addr,
    input  logic [31:0]              write_data,//loader writes whole words
    output logic [31:0]              instr      //fetched instruction
);

    //Byte-addressable memory (going to be BRAM)
    logic [DATA_WIDTH-1:0] mem [0:MEM_BYTES-1];

    //Registered address for synchronous read
    logic [$clog2(MEM_BYTES)-1:0] addr_reg;

    //Initil program load (from .hex file)
    initial begin
        $display("Loading Instruction Memory");
        $readmemh("program.hex", mem);
    end

    //Fetch instruction
    always_ff @(posedge clk) begin
        addr_reg <= addr[$clog2(MEM_BYTES)-1:0];
        instr <= { mem[addr_reg+3],
                   mem[addr_reg+2],
                   mem[addr_reg+1],
                   mem[addr_reg+0] };
    end

    //Synchronous WRITE for dynamic loading
    //Writes entire 32-bit words into memory, byte by byte
    always_ff @(posedge clk) begin
        if (write_en) begin
            mem[addr[$clog2(MEM_BYTES)-1:0]] <= write_data[7:0];
            mem[addr[$clog2(MEM_BYTES)-1:0]+1] <= write_data[15:8];
            mem[addr[$clog2(MEM_BYTES)-1:0]+2] <= write_data[23:16];
            mem[addr[$clog2(MEM_BYTES)-1:0]+3] <= write_data[31:24];
        end
    end

endmodule
