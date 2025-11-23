module forwarding#(
    parameter reg_addressing_width = 5
)
(
    input logic [reg_addressing_width-1:0] rs1, 
    input logic [reg_addressing_width-1:0] rs2,
    input logic [reg_addressing_width-1:0] rdM, 
    input logic [reg_addressing_width-1:0] rdWB,
    input logic regWriteM,
    input logic WriteBack_Regfile,    
    output logic [1:0] selectline1,
    output logic [1:0] selectline2
);

//select line conventions for the pipeline multiplexers (in the execute stage):
// no forwarding : select line = 00
//forwarding from the memory stage (consecutive instructions Read-After-Write) : select line = 01
//forwarding from the Write Back stage : select line = 10

always_comb begin
    //Default:no forwarding
    selectline1 = 2'b00;
    selectline2 = 2'b00;

    //Operand1 forwarding
    if (regWriteM && rdM != 0 && rdM == rs1) begin
        selectline1 = 2'b01;  //from MEM stage
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs1) begin
        selectline1 = 2'b10;  //from WB stage
    end

    // Operand 2 forwarding
    if (regWriteM && rdM !=0 && rdM == rs2) begin
        selectline2 = 2'b01;
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs2) begin
        selectline2 = 2'b10;
    end

end

endmodule