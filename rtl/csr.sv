module csr #( 
    parameter ADDRESS_WIDTH = 12,
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic rst,
    input logic [1:0] CSR_OP, // what time of csr operation we are doing
    input logic [ADDRESS_WIDTH-1:0] addr,
    input logic en,
    input logic [DATA_WIDTH-1:0] wd,
    input logic external_interrupt, // signals that there is an external interrupt
    input logic timer_interrupt, // signals there is a timer interrupt
    input logic [DATA_WIDTH-1:0] PCE,  // used for saving into mepc
    input logic mret_en, // to tell us the the trap handler has finished executing and we can return
    output logic [DATA_WIDTH-1:0] dout,
    output logic trap_en, // go to trap handler
    output logic [DATA_WIDTH-1:0] handler_address // address of trap handler
);

    logic[DATA_WIDTH-1:0] temp; // to not actually change the csr unless we have an enable signal
    logic [ADDRESS_WIDTH-1:0] mapped_address; // to translate the assembly address to our simplified array
    logic[DATA_WIDTH-1:0] csr_array[7]; // we only need 6 defined registers for interupts and we can have 1 extra scratch register 
    logic global_en;
    logic int_ext_en; 
    logic int_tim_en;
    logic int_ext_p;
    logic int_tim_p; 

    always_comb begin
        case(addr)
            12'h300: mapped_address = 0; // mstatus 
            12'h304: mapped_address = 1; // mie
            12'h305: mapped_address = 2; // mtvec
            12'h341: mapped_address = 3; // mepc
            12'h342: mapped_address = 4; // mcause
            12'h344: mapped_address = 5; // mip
            default: mapped_address = 6; // scratch register
        endcase

        dout = csr_array[mapped_address]; 

        handler_address =   mret_en ? csr_array[3] : csr_array[2]; // are we going or returning

    end

    assign global_en = csr_array[0][3]; // the MIE bit allows all interrupts to occur
    assign int_ext_en = csr_array[1][11]; // the MEIE bit tells us if an external interrupt can occur
    assign int_tim_en = csr_array[1][7]; // the MTIE bit tells us if an external interrupt can occur
    assign int_ext_p = csr_array[5][11]; // the MEIP bit tells us if theres an external interrupt pending
    assign int_tim_p = csr_array[5][7]; // the MTIP bit tells us if theres an timer interrupt pending

    assign trap_en = (global_en && ((int_ext_en && int_ext_p) || (int_tim_en && int_tim_p) ) );
    // if interrupts are enabled and there is a certain type of interrupt pending and that type is enabled then enter the trap handler

    always_comb begin
        temp = dout;
        case(CSR_OP)
            2'b01: temp =  wd; // CSSRW(I)
            2'b10: temp = temp | wd;   // CSRRS(I)  
            2'b11: temp = temp & (~wd); // CSRRC(I)
            default: temp = dout; // stay the same
        endcase
    end
    
    always_ff @(posedge clk) begin



        if(rst) begin

            csr_array[0] <= 32'b0; // mstatus
            csr_array[1] <= 32'b0; // mie
            csr_array[2] <= 32'b0; // mtvec
            csr_array[3] <= 32'b0; // mepc
            csr_array[4] <= 32'b0; // mcause
            csr_array[5] <= 32'b0; // mip
            csr_array[6] <= 32'b0; // scratch register
       
        end else begin
            
            csr_array[5][11] <= external_interrupt; // initialise pending que
            csr_array[5][7] <= timer_interrupt; 

            if(trap_en) begin

                csr_array[3] <= PCE; // save the instruction we are on into mepc
                csr_array[0][7] <= csr_array[0][3]; // save the value of MIE into MPIE
                csr_array[0][3] <= 1'b0; // disable interrupts while we handle this one

                if(int_ext_en && int_ext_p) csr_array[4] <= 32'h8000000B; // standard cause code for MEI
                else if (int_tim_en && int_tim_p) csr_array[4] <= 32'h80000007; // standard cause code for MT
           
            end else if (mret_en) begin
                
                csr_array[0][3] <= csr_array[0][7]; // get back enable value
                csr_array[0][7] <= 1'b1; // reset to 1
                
                end

            else if(en) csr_array[mapped_address] <= temp; // we only fully write into the scratch register

        end
    end

endmodule
