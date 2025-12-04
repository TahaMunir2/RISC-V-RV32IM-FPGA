module src_operand_validity_logic #(
    parameter ROB_TAG_WIDTH = 6
)(
    // RAT lookup result
    input  logic                      rat_has_producer,   // 1 if register has in-flight producer in RAT
    input  logic [ROB_TAG_WIDTH-1:0]  rat_tag,            // ROB tag from RAT (valid if rat_has_producer=1)
    
    // ROB lookup result (looked up using rat_tag)
    input  logic                      rob_entry_ready,    // 1 if ROB entry at rat_tag is ready to commit
    
    // Outputs
    output logic                      operand_valid,      // 1 if operand value is available now
    output logic                      fetch_from_regfile  // 1 = fetch from regfile, 0 = fetch from ROB
);

    always_comb begin
        // Default values
        operand_valid      = 1'b0;
        fetch_from_regfile = 1'b0;
        
        if (!rat_has_producer) begin
            // Case 1: No producer in RAT
            // The architectural register file has the correct value
            operand_valid      = 1'b1;  // Operand is valid
            fetch_from_regfile = 1'b1;  // Fetch from register file
            
        end
        else begin
            // Case 2: Has producer in RAT (in-flight instruction)
            // Need to check ROB to see if result is ready
            
            if (rob_entry_ready) begin
                // Case A: ROB entry is ready to commit
                // Value is available in the ROB
                operand_valid      = 1'b1;  // Operand is valid
                fetch_from_regfile = 1'b0;  // Fetch from ROB (not regfile)
                
            end
            else begin
                // Case B: ROB entry is NOT ready to commit
                // Must wait for CDB broadcast
                // The issuing logic should record rat_tag so CDB can 
                // forward the value when the producer completes
                operand_valid      = 1'b0;  // Operand NOT valid yet
                fetch_from_regfile = 1'b0;  // Don't care, but defaulted to 0
            end
        end
    end

endmodule

