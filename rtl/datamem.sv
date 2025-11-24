module datamem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 32
)(//removed the clock from the input because we are designing the datamem output to be asynchronous (when implementing store we might have to add the clock back in order to make the input to the data memory synchronous)
    input  logic                     MemWrite,
    input  logic [ADDRESS_WIDTH-1:0] WD,
    input  logic [1:0]                    SizeWrite,
    input  logic [ADDRESS_WIDTH-1:0] A, 
    input logic [1:0]LoadSize, //additional output signal
    input logic LoadUnsigned, //additional output signal
    input  logic                     clk,
    output logic [DATA_WIDTH-1:0]    dout
);

logic [7:0] ram_array [2**17-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("sineram.mem", ram_array, 32'h10000);
end


//Asynchronized reading from memory
always_comb begin
    logic [31:0] data;
    
    // Read 4 bytes (little endian)
    data[7:0]   =ram_array[A];
    data[15:8]  = ram_array[A+1];
    data[23:16] =ram_array[A+2];
    data[31:24] = ram_array[A+3];

    // Select load size
    case (LoadSize)

        // LB / LBU
        2'b00: begin
            if (LoadUnsigned)
                dout = {24'b0,data[7:0]};
            else
                dout = {{24{data[7]}}, data[7:0]};
        end

        // LH / LHU
        2'b01: begin
            if (LoadUnsigned)
                dout = {16'b0, data[15:0]};
            else
                dout = {{16{data[15]}},data[15:0]};
        end

        // LW
        default: begin
            dout = data;
        end
    endcase
end


//Synchronized Writing in memory
//byte addressing (and not word addressing)

always_ff @(posedge clk) begin
    if (MemWrite) begin
        if (SizeWrite == 2'b00) begin
        ram_array[A] <= WD[7:0];
        end
        else if (SizeWrite == 2'b01) begin
            ram_array[A]   <= WD[7:0];
            ram_array[A+1] <= WD[15:8];
        end
        else if (SizeWrite == 2'b10) begin
            ram_array[A]   <= WD[7:0];
            ram_array[A+1] <= WD[15:8];
            ram_array[A+2] <= WD[23:16];
            ram_array[A+3] <= WD[31:24];
        end
    end
end

endmodule
