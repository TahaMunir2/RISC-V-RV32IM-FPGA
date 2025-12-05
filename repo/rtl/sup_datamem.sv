module sup_datamem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 32
)(//removed the clock from the input because we are designing the datamem output to be asynchronous (when implementing store we might have to add the clock back in order to make the input to the data memory synchronous)
    input  logic [ADDRESS_WIDTH-1:0] A1, 
    input logic [1:0]LoadSize1, //additional output signal
    input logic LoadUnsigned1, //additional output signal
    output logic [DATA_WIDTH-1:0]    dout1,

    input  logic [ADDRESS_WIDTH-1:0] A2,
    input logic [1:0]LoadSize2, //additional output signal
    input logic LoadUnsigned2, //additional output signal
    output logic [DATA_WIDTH-1:0]    dout2
);

logic [7:0] ram_array [2**17-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("reference/testing.mem", ram_array, 32'h00000);
end


//Asynchronized reading from memory
always_comb begin
    logic [31:0] data1;
    logic [31:0] data2;
    
    //we read 4 bytes (little endian)
    data1[7:0]   =ram_array[A1];
    data1[15:8]  = ram_array[A1+1];
    data1[23:16] =ram_array[A1+2];
    data1[31:24] = ram_array[A1+3];

    // Select load size
    case (LoadSize1)

        // LB / LBU
        2'b00: begin
            if (LoadUnsigned1)
                dout1 = {24'b0,data1[7:0]};
            else
                dout1 = {{24{data1[7]}}, data1[7:0]};
        end

        // LH / LHU
        2'b01: begin
            if (LoadUnsigned1)
                dout1 = {16'b0, data1[15:0]};
            else
                dout1 = {{16{data1[15]}},data1[15:0]};
        end

        // LW
        default: begin
            dout1 = data1;
        end
    endcase

//we duplicate the reading logic:
    
    //we read 4 bytes (little endian)
    data2[7:0]   =ram_array[A2];
    data2[15:8]  = ram_array[A2+1];
    data2[23:16] =ram_array[A2+2];
    data2[31:24] = ram_array[A2+3];

    // Select load size
    case (LoadSize2)

        // LB / LBU
        2'b00: begin
            if (LoadUnsigned2)
                dout2 = {24'b0,data2[7:0]};
            else
                dout2 = {{24{data2[7]}}, data2[7:0]};
        end

        // LH / LHU
        2'b01: begin
            if (LoadUnsigned2)
                dout2 = {16'b0, data2[15:0]};
            else
                dout2 = {{16{data2[15]}},data2[15:0]};
        end

        // LW
        default: begin
            dout2 = data2;
        end
    endcase
end

endmodule

