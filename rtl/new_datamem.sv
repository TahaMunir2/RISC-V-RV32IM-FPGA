module new_datamem #(
    parameter ADDRESS_WIDTH = 32,
              MEM_BYTES     = 16384,  // 16KB default
              DATA_WIDTH    = 32
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

    //Byte-addressable memory (gonna be BRAM)
    logic [7:0] mem [0:MEM_BYTES-1];

    logic [$clog2(MEM_BYTES)-1:0] A_reg;
    logic [31:0] data;

    initial begin
        $display("Loading ram");
        $readmemh("reference/gaussian.mem", mem, 32'h10000);
    end

    //Synchronous read
    always_ff @(posedge clk) begin
        A_reg <= A[$clog2(MEM_BYTES)-1:0];

        // Read 4 bytes (little endian)
        data[7:0]   <= mem[A_reg];
        data[15:8]  <= mem[A_reg+1];
        data[23:16] <= mem[A_reg+2];
        data[31:24] <= mem[A_reg+3];

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
        mem[A] <= WD[7:0];
        end
        else if (SizeWrite == 2'b01) begin
            mem[A]   <= WD[7:0];
            mem[A+1] <= WD[15:8];
        end
        else if (SizeWrite == 2'b10) begin
            mem[A]   <= WD[7:0];
            mem[A+1] <= WD[15:8];
            mem[A+2] <= WD[23:16];
            mem[A+3] <= WD[31:24];
        end
    end
end

   

endmodule
