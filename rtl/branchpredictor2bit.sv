module branchpredictor2bit #(
    parameter TARGET_BUFFER_SIZE = 64, //number of branches we store, which is relatively small (in practice we don't have a big table for branch prediction because accessing a table would waste a lot of time and would make the design inneficient)
    parameter INDEX_BITS = $clog2(TARGET_BUFFER_SIZE) //index size: how many bits we take from the PC to determine which specific branch we are refering to
)(
    input  logic clk,
    input  logic rst,
    input  logic enable,//enable signal for the FSM: we write in the FSM only when the instruction in the execute stage is a branch instruction
    input  logic [INDEX_BITS-1:0] update_index, //index of that branch PC
    input  logic actual_taken, //real outcome
    input  logic [INDEX_BITS-1:0] predict_index,//index from PC (we take the bus [7:2] corresponding to 6 bits from PC to identify the specific jump we are dealing with)
    output logic pred_taken//prediction output 
);

//state enumeration
    typedef enum logic [1:0] {
        STRONGLY_NOT_TAKEN = 2'b00,
        WEAKLY_NOT_TAKEN   = 2'b01,
        WEAKLY_TAKEN       = 2'b10,
        STRONGLY_TAKEN     = 2'b11
    } my_state;

    my_state array [TARGET_BUFFER_SIZE-1:0]; //current state

    // we removed current state as to not cause any timing issues with the fpga as we needed to loop through the entire array everytime

    //Advance state registers on clock or reset, FSM flip-flop
    always_ff @(negedge clk) begin
        if (rst) begin

            for (int i = 0; i <TARGET_BUFFER_SIZE; i++) begin //we initialize all the predictions to weakly not taken (no extreme initialization because we don't know about the branches yet)
                array[i] <= WEAKLY_NOT_TAKEN;
            end
        
        end else if (enable) begin

            case (array[update_index])
                STRONGLY_NOT_TAKEN:     array[update_index] <= actual_taken ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                WEAKLY_NOT_TAKEN:       array[update_index] <= actual_taken ? WEAKLY_TAKEN : STRONGLY_NOT_TAKEN;
                WEAKLY_TAKEN:           array[update_index] <= actual_taken ? STRONGLY_TAKEN : WEAKLY_NOT_TAKEN;
                STRONGLY_TAKEN:         array[update_index] <= actual_taken ? STRONGLY_TAKEN : WEAKLY_TAKEN;
                default:                array[update_index] <= STRONGLY_NOT_TAKEN;
            endcase

        end
    end

    //Output logic(Moore: depends only on current state)
    always_comb begin
        pred_taken= array[predict_index][1]; //1 for 10 or 11 (describing the states: WEAKLY_TAKEN (10) and STRONGLY_TAKEN(11) )
    end

endmodule

