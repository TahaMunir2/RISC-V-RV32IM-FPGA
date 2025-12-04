module top_memtest(
    input  logic clk
);

    // Instruction memory instance
    new_insmem #(
        .ADDRESS_WIDTH (32),
        .MEM_BYTES     (8192),
        .DATA_WIDTH    (8),
        .BASE_ADDR     (32'hBFC0_0000)  // or 0xBFC0_1000 if that’s your spec
    ) imem (
        .clk        (clk),
        .write_en   (1'b0),
        .addr       (32'hBFC0_0000),
        .write_data (32'b0),
        .instr      ()
    );

    // Data memory instance
    new_datamem #(
        .ADDRESS_WIDTH (32),
        .MEM_BYTES     (16384),
        .DATA_WIDTH    (32),
        .BASE_ADDR     (32'h0002_0000)
    ) dmem (
        .MemWrite     (1'b0),
        .WD           (32'b0),
        .SizeWrite    (2'b10),
        .A            (32'h0002_0000),
        .LoadSize     (2'b10),
        .LoadUnsigned (1'b1),
        .clk          (clk),
        .dout         ()
    );

endmodule
