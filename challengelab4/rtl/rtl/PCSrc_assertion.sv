module PCSrc_assertion #(
    DATA_WIDTH = 32
)
(
input logic [2:0] funct3,
input logic Branch_e,
input logic Jump_e,
input logic EQ,
input logic LT,
input logic LTU,
input logic ALUSrcE,
output logic [1:0] PCSrcE
);


always_comb begin
    PCSrcE = 0; //Default: normal PC increment
    if(Branch_e) begin
    case (funct3)
                    //Branch If Equal (BEQ)
                    3'b000:begin
                            if (EQ) begin
                                PCSrcE = 2'b01;  // branch taken when rs1 == rs2
                            end
                            else begin
                                PCSrcE = 0;  // fall-through
                            end       
                    end
                    
                    3'b001:begin
                            if (EQ) begin
                                PCSrcE = 0;
                            end
                            else begin
                                PCSrcE = 2'b01;
                            end
                    end

                    //Less Then (Signed)
                    3'b100:begin
                            if (LT) begin
                                PCSrcE = 2'b01;  // branch when rs1 < rs2 (signed)
                            end
                            else begin
                                PCSrcE = 0;  // fall-through
                            end

                    end

                    3'b101:begin
                            if (LT) begin
                                PCSrcE = 0;  // no branch when rs1 < rs2
                            end
                            else begin
                                PCSrcE = 2'b01;  // branch when rs1 >= rs2 (signed)
                            end


                    end

                    //Less Then (Unsigned)
                    3'b110:begin

                            if (LTU) begin
                                PCSrcE = 2'b01;  // branch when rs1 < rs2 (unsigned)
                            end
                            else begin
                                PCSrcE = 0;  // fall-through
                            end


                    end
                    3'b111:begin
                            if (LTU) begin
                                PCSrcE = 0;  // no branch when rs1 < rs2
                            end
                            else begin
                                PCSrcE = 2'b01;  // branch when rs1 >= rs2 (unsigned)
                            end


                    end
                    default:begin
                        PCSrcE = 0;
                                
                    end
                endcase
    end

    else if(Jump_e) begin
        if (ALUSrcE) PCSrcE = 2'b10; // jalr
        else PCSrcE = 2'b01; // jalr
    end

end



endmodule
