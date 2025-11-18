module datamem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 32
)(//removed the clock from the input because we are designing the datamem output to be asynchronous (when implementing store we might have to add the clock back in order to make the input to the data memory synchronous)
    input  logic [ADDRESS_WIDTH-1:0] A, 
    output logic [DATA_WIDTH-1:0]    dout
);

logic [7:0] ram_array [2**ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("sineram.mem", ram_array);
end

// SYNCHRONOUS OR ASYNCHRONOUS? This is the Asynchronous way (so the whole instruction executes only in 1 clock cycle)
always_comb begin
    dout[7:0] = rom_array[A];
    dout[8:15]= rom_array[A+1];
    dout[16:23] = rom_array[A+2];
    dout[24:31]= rom_array[A+3];
end
//byte addressing (and not word addressing)

endmodule
