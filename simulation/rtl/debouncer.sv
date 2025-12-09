module debouncer #(
    parameter TIMER_WIDTH = 20 // 2^20 is 20ms at 50MHz
)(
    input  logic clk,
    input  logic rst,
    input  logic trigger,      // noisy bouncy signal
    output logic trigger_clean // clean signal with no noise
);

    logic [TIMER_WIDTH-1:0] timer;

    logic safety_stage, stable_input; // we need these to prevent metastability as this adds a 1 clock cycle delay for the signal to stabilise before we put it into our logic circuit

    always_ff @(posedge clk) begin // stability stage added for safekeeping
        if (rst) begin
            safety_stage <= 0; 
            stable_input <= 0;
        end else begin
            safety_stage <= trigger; 
            stable_input <= safety_stage; // adds a 1 clock cycle delay to stabilise the input
        end
    end

    always_ff @(posedge clk) begin
        if (rst) begin 
            timer <= '0; 
            trigger_clean <= 0;
        end
        else begin
            if (stable_input) begin   // if trigger is high we can start timing
                if (trigger_clean == 0) begin // if we are still waiting for stability
                    timer <= timer + 1;  // increment the timer
                    if (&timer) trigger_clean <= 1; //  if we hit the max value of the timer output the clean value
                end
            end 
            else begin // if trigger is low we can turn it off
                timer <= 0; 
                trigger_clean <= 0; 
            end
        end
    end

endmodule