
module insmem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 8
)(
    input logic [ADDRESS_WIDTH-1:0] addr,
    output logic [31:0] instr
);

// derek edit 17/11/2024: hardcode address_width to 16 instead of 32
// because verilator throws error with 32 bit memory
logic [DATA_WIDTH-1:0] romArray [2**16-1:0];

// derek edit 17/11/2024: take only 16 LSBs of address
// because verilator throws an error when we use 32 bits for rom address but 16 is ok
logic [15:0] instrAddr = addr[15:0];

// declare 16 MSBs of addr as unused
logic[15:0] unused;

initial begin
        $display("Loading Instruction Memory");

        // Comment out the top line and uncomment the bottom line 
        // To run the reference program
        $readmemh("program.hex", romArray);
        // $readmemh("tb/reference/pdf.hex", romArray);
end;

// derek edit 17/11/2024: instruction rom should be async not sync
always_comb begin
    unused = addr[31:16];
    unused = unused & 16'b0;
    instr = {romArray[instrAddr+3], romArray[instrAddr+2], romArray[instrAddr+1], romArray[instrAddr]};
end

endmodule

