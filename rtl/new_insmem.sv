module new_insmem #(
    parameter ADDRESS_WIDTH = 32,
    parameter DATA_WIDTH    = 32
)(
    input  logic                     clk,
    input  logic [ADDRESS_WIDTH-1:0] addr,
    output logic [DATA_WIDTH-1:0]    instr
);

    // 1024 words = 4096 bytes
    localparam MEM_DEPTH = 1024;

    // Use a clean array
    logic [31:0] romArray [0:MEM_DEPTH-1];

    // --- LOAD THE FILE ---
    // Use the absolute path like before
    initial begin
        $readmemh("C:/riscv_de10/program.hex", romArray);
    end

    // --- MAPPING ---
    logic [9:0] word_index;
    assign word_index = addr[11:2];

    logic [31:0] raw_data;

    // --- STEP 1: PURE RAM READ (The Hardware Part) ---
    // This is simple enough for Quartus to recognize as Block RAM
    always_ff @(posedge clk) begin
        raw_data <= romArray[word_index];
    end

    // --- STEP 2: ADDRESS CHECK (The Logic Part) ---
    // We do the safety check *outside* the memory block
    // 0xBFC00... is the valid range
    assign instr = (addr[31:12] == 20'hBFC00) ? raw_data : 32'h00000000;

endmodule