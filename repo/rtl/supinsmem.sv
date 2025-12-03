module supinsmem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH    = 8
)(
    input  logic [ADDRESS_WIDTH-1:0] addr,
    output logic [31:0]              instr1,   // first  instruction at addr
    output logic [31:0]              instr2    // second instruction at addr+4
);

  // Byte-addressable ROM
  logic [DATA_WIDTH-1:0] romArray [2**16-1:0];

  // Use only lower 16 bits as byte address into ROM
  logic [15:0] instrAddr = addr[15:0];
  logic [15:0] unused;

  initial begin
    $display("Loading Instruction Memory");
    $readmemh("program.hex", romArray);
  end

  always_comb begin
    // Zero-out upper address bits (kept from your original logic)
    unused = addr[31:16];
    unused = unused & 16'b0;

    // First instruction at addr
    instr1 = { romArray[instrAddr + 3],
               romArray[instrAddr + 2],
               romArray[instrAddr + 1],
               romArray[instrAddr + 0] };

    // Second, consecutive instruction at addr + 4
    instr2 = { romArray[instrAddr + 7],
               romArray[instrAddr + 6],
               romArray[instrAddr + 5],
               romArray[instrAddr + 4] };
  end

endmodule
