module hazard_unit#(
    parameter reg_addressing_width = 5
)
(
    input logic [reg_addressing_width-1:0] rs1D, 
    input logic [reg_addressing_width-1:0] rs2D,
    input logic [reg_addressing_width-1:0] rs1E, 
    input logic [reg_addressing_width-1:0] rs2E,
    input logic [reg_addressing_width-1:0] rdM,
    input logic [reg_addressing_width-1:0] rdE, 
    input logic [reg_addressing_width-1:0] rdWB,
    input logic regWriteM,
    input logic [1:0] resultSrCE,
    input logic JumpE,
    input logic false_prediction,
    input logic WriteBack_Regfile,
    input logic [1:0] csr_typeD,
    input logic [1:0] csr_typeE,
    input logic [1:0] csr_typeM,
    input logic [1:0] csr_typeW,
    input logic [11:0] csr_addrD,
    input logic [11:0] csr_addrE,
    input logic [11:0] csr_addrM,
    input logic [11:0] csr_addrW,
    input logic trap_en,
    input logic [1:0] ResultSrcM, 
    input logic mret_en,
    output logic [1:0] selectline1,
    output logic [1:0] selectline2,
    output logic flush_d_exec,
    output logic flush_f_d,
    output logic flush_e_m,
    output logic F_Write,
    output logic PCWrite
);
    
    always_comb begin
        // default
        selectline1 = 2'b00;
        selectline2 = 2'b00;

        if (regWriteM && rdM != 0 && rdM == rs1E && ResultSrcM != 2'b01) begin 
            selectline1 = 2'b10; 
        end 
        else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs1E) begin
            selectline1 = 2'b01; 
        end

        if (regWriteM && rdM !=0 && rdM == rs2E && ResultSrcM != 2'b01) begin
            selectline2 = 2'b10; 
        end 
        else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs2E) begin
            selectline2 = 2'b01; 
        end
    end
    
    logic wStall;
    logic csrStall;


   

    // stall if load in execute or load in memory double stall for sync
    assign wStall = ( (resultSrCE == 2'b01) && (rdE != 0) && ((rdE == rs1D) || (rdE == rs2D)) ) || 
                    ( (ResultSrcM == 2'b01) && (rdM != 0) && ((rdM == rs1D) || (rdM == rs2D)) );
    
    assign csrStall = (|csr_typeD) && (
                        ( (|csr_typeE) && (csr_addrE == csr_addrD)) || 
                        ( (|csr_typeM) && (csr_addrM == csr_addrD)) ||  
                        ( (|csr_typeW) && (csr_addrW == csr_addrD)) 
                      );


    always_comb begin

        PCWrite      = 1;
        F_Write      = 1;
        flush_d_exec = 0;
        flush_f_d    = 0;
        flush_e_m    = 0;

        if(wStall || csrStall) begin
            PCWrite      = 0;
            F_Write      = 0;
            flush_d_exec = 1;
        end

        if(false_prediction || JumpE) begin
            PCWrite      = 1; 
            F_Write      = 1; 
            flush_f_d    = 1;
            flush_d_exec = 1;
        end

        if (trap_en) begin 
            flush_f_d    = 1'b1;
            flush_d_exec = 1'b1;
            flush_e_m    = 1'b1;
        end

        else if (mret_en) begin
            flush_f_d = 1'b1;
            flush_d_exec = 1'b1;
        end

    end

endmodule
