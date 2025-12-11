module branchpredictor2bit #(
    parameter TARGET_BUFFER_SIZE = 64, 
    parameter INDEX_BITS = $clog2(TARGET_BUFFER_SIZE),
    parameter DATA_WIDTH = 32
)(
    input  logic clk,
    input  logic rst,
    input  logic enable,               // Enable signal (BranchE from Execute stage)
    input  logic [INDEX_BITS-1:0] update_index,  // Index from PCE (Execute stage)
    input  logic actual_taken,         // Real outcome from Execute stage
    input  logic [DATA_WIDTH-1:0] update_target, // [NEW] The calculated target address from Execute stage
    
    input  logic [INDEX_BITS-1:0] predict_index, // Index from PCF (Fetch stage)
    output logic pred_taken,           // Prediction output 
    output logic [DATA_WIDTH-1:0] pred_target    // [NEW] Predicted target address for Fetch stage
);

    // State enumeration
    typedef enum logic [1:0] {
        STRONGLY_NOT_TAKEN = 2'b00,
        WEAKLY_NOT_TAKEN   = 2'b01,
        WEAKLY_TAKEN       = 2'b10,
        STRONGLY_TAKEN     = 2'b11
    } my_state;

    my_state array [TARGET_BUFFER_SIZE-1:0]; // The 2-bit counter history
    logic [DATA_WIDTH-1:0] target_buffer [TARGET_BUFFER_SIZE-1:0]; // [NEW] The BTB (stores addresses)

    // Advance state registers on clock or reset
    // Keeping negedge as per your original design (though posedge is standard for pipelines)
    always_ff @(negedge clk) begin 
        if (rst) begin
            for (int i = 0; i < TARGET_BUFFER_SIZE; i++) begin
                array[i] <= WEAKLY_NOT_TAKEN;
                target_buffer[i] <= {DATA_WIDTH{1'b0}}; // Reset targets to 0
            end
        
        end else if (enable) begin
            // 1. Update the State bits (Saturation Counter)
            case (array[update_index])
                STRONGLY_NOT_TAKEN: array[update_index] <= actual_taken ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                WEAKLY_NOT_TAKEN:   array[update_index] <= actual_taken ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
                WEAKLY_TAKEN:       array[update_index] <= actual_taken ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
                STRONGLY_TAKEN:     array[update_index] <= actual_taken ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
                default:            array[update_index] <= STRONGLY_NOT_TAKEN;
            endcase

            // 2. Update the Target Buffer [NEW]
            // If the branch was actually taken, we learn *where* it goes.
            // We store the calculated target from the Execute stage into our memory.
            if (actual_taken) begin
                target_buffer[update_index] <= update_target;
            end
        end
    end

    // Output logic (Moore)
    always_comb begin
        // 1 for 10 or 11 (WEAKLY_TAKEN and STRONGLY_TAKEN)
        pred_taken = array[predict_index][1];
        
        // [NEW] Output the stored address associated with this PC index
        pred_target = target_buffer[predict_index]; 
    end

endmodule
