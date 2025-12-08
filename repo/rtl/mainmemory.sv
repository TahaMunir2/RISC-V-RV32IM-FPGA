module main_memory #(
    parameter ADDRESS_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter RAM_SIZE = 131072,
    parameter ROM_SIZE = 4096
)(
    input   logic                          clk,
    
    // Read Interface
    input   logic   [ADDRESS_WIDTH-1:0]    r_addr, 
    input   logic                          r_en,
    output  logic   [8*DATA_WIDTH-1:0]     dout,
    output  logic                          ready,

    // Write Interface
    input   logic   [ADDRESS_WIDTH-1:0]    w_addr,
    input   logic                          w_en,
    input   logic   [4*DATA_WIDTH-1:0]     w_data,
    output  logic                          wb_ready
);

    logic [7:0]               ram_array [RAM_SIZE-1:0];
    logic [7:0]               rom_array [ROM_SIZE-1:0];
    logic [DATA_WIDTH-1:0]    timer_top; // timer interrupt bottom bits
    logic [DATA_WIDTH-1:0]    timer_bottom; // timer interrupt top bits
    logic [DATA_WIDTH-1:0]    gpio; // gpio memory address


    logic [DATA_WIDTH-1:0] RAM_TOP;
    logic [DATA_WIDTH-1:0] ROM_BASE;
    logic [DATA_WIDTH-1:0] ROM_TOP; 
    
    assign RAM_TOP = RAM_SIZE - 1; 
    assign ROM_BASE = 32'hBFC00000;
    assign ROM_TOP = 32'hBFC00FFF;

    initial begin
        timer_bottom = 32'h0;
        timer_top = 32'h0;
        gpio = 32'h0;
        
        $readmemh("gaussian.mem", ram_array);
        $readmemh("program.hex", rom_array);
    end


    always_ff @(posedge clk) begin
        ready <= 0;
        dout  <= '0;

        if (r_en) begin
            ready <= 1;

            if (r_addr <= RAM_TOP) begin
                dout[255:248] <= ram_array[r_addr];
                dout[247:240] <= ram_array[r_addr + 1];
                dout[239:232] <= ram_array[r_addr + 2];
                dout[231:224] <= ram_array[r_addr + 3];
                dout[223:216] <= ram_array[r_addr + 4];
                dout[215:208] <= ram_array[r_addr + 5];
                dout[207:200] <= ram_array[r_addr + 6];
                dout[199:192] <= ram_array[r_addr + 7];
                dout[191:184] <= ram_array[r_addr + 8];
                dout[183:176] <= ram_array[r_addr + 9];
                dout[175:168] <= ram_array[r_addr + 10];
                dout[167:160] <= ram_array[r_addr + 11];
                dout[159:152] <= ram_array[r_addr + 12];
                dout[151:144] <= ram_array[r_addr + 13];
                dout[143:136] <= ram_array[r_addr + 14];
                dout[135:128] <= ram_array[r_addr + 15];
                dout[127:120] <= ram_array[r_addr + 16];
                dout[119:112] <= ram_array[r_addr + 17];
                dout[111:104] <= ram_array[r_addr + 18];
                dout[103:96]  <= ram_array[r_addr + 19];
                dout[95:88]   <= ram_array[r_addr + 20];
                dout[87:80]   <= ram_array[r_addr + 21];
                dout[79:72]   <= ram_array[r_addr + 22];
                dout[71:64]   <= ram_array[r_addr + 23];
                dout[63:56]   <= ram_array[r_addr + 24];
                dout[55:48]   <= ram_array[r_addr + 25];
                dout[47:40]   <= ram_array[r_addr + 26];
                dout[39:32]   <= ram_array[r_addr + 27];
                dout[31:24]   <= ram_array[r_addr + 28];
                dout[23:16]   <= ram_array[r_addr + 29];
                dout[15:8]    <= ram_array[r_addr + 30];
                dout[7:0]     <= ram_array[r_addr + 31];
            end

            else if (r_addr >= ROM_BASE && r_addr <= ROM_TOP) begin
                logic [31:0] offset;
                offset = r_addr - ROM_BASE;

                dout[255:248] <= rom_array[offset];
                dout[247:240] <= rom_array[offset + 1];
                dout[239:232] <= rom_array[offset + 2];
                dout[231:224] <= rom_array[offset + 3];
                dout[223:216] <= rom_array[offset + 4];
                dout[215:208] <= rom_array[offset + 5];
                dout[207:200] <= rom_array[offset + 6];
                dout[199:192] <= rom_array[offset + 7];
                dout[191:184] <= rom_array[offset + 8];
                dout[183:176] <= rom_array[offset + 9];
                dout[175:168] <= rom_array[offset + 10];
                dout[167:160] <= rom_array[offset + 11];
                dout[159:152] <= rom_array[offset + 12];
                dout[151:144] <= rom_array[offset + 13];
                dout[143:136] <= rom_array[offset + 14];
                dout[135:128] <= rom_array[offset + 15];
                dout[127:120] <= rom_array[offset + 16];
                dout[119:112] <= rom_array[offset + 17];
                dout[111:104] <= rom_array[offset + 18];
                dout[103:96]  <= rom_array[offset + 19];
                dout[95:88]   <= rom_array[offset + 20];
                dout[87:80]   <= rom_array[offset + 21];
                dout[79:72]   <= rom_array[offset + 22];
                dout[71:64]   <= rom_array[offset + 23];
                dout[63:56]   <= rom_array[offset + 24];
                dout[55:48]   <= rom_array[offset + 25];
                dout[47:40]   <= rom_array[offset + 26];
                dout[39:32]   <= rom_array[offset + 27];
                dout[31:24]   <= rom_array[offset + 28];
                dout[23:16]   <= rom_array[offset + 29];
                dout[15:8]    <= rom_array[offset + 30];
                dout[7:0]     <= rom_array[offset + 31];
            end

            else if (r_addr[31:16] == 16'h8000) begin
                if (r_addr == 32'h80001000) begin
                    dout[255:224] <= timer_bottom;
                    dout[223:192] <= timer_top;
                end
                else if (r_addr == 32'h80002000) begin
                    dout[255:224] <= gpio;
                end
            end
        end
    end


    always_ff @(posedge clk) begin
        wb_ready <= 0;

        if (w_en) begin
            wb_ready <= 1;


            if (w_addr <= RAM_TOP) begin
                ram_array[w_addr]      <= w_data[127:120];
                ram_array[w_addr + 1]  <= w_data[119:112];
                ram_array[w_addr + 2]  <= w_data[111:104];
                ram_array[w_addr + 3]  <= w_data[103:96];
                ram_array[w_addr + 4]  <= w_data[95:88];
                ram_array[w_addr + 5]  <= w_data[87:80];
                ram_array[w_addr + 6]  <= w_data[79:72];
                ram_array[w_addr + 7]  <= w_data[71:64];
                ram_array[w_addr + 8]  <= w_data[63:56];
                ram_array[w_addr + 9]  <= w_data[55:48];
                ram_array[w_addr + 10] <= w_data[47:40];
                ram_array[w_addr + 11] <= w_data[39:32];
                ram_array[w_addr + 12] <= w_data[31:24];
                ram_array[w_addr + 13] <= w_data[23:16];
                ram_array[w_addr + 14] <= w_data[15:8];
                ram_array[w_addr + 15] <= w_data[7:0];
            end

            else if (w_addr >= ROM_BASE && w_addr <= ROM_TOP) begin
                logic [31:0] offset;
                offset = w_addr - ROM_BASE;

                rom_array[offset]      <= w_data[127:120];
                rom_array[offset + 1]  <= w_data[119:112];
                rom_array[offset + 2]  <= w_data[111:104];
                rom_array[offset + 3]  <= w_data[103:96];
                rom_array[offset + 4]  <= w_data[95:88];
                rom_array[offset + 5]  <= w_data[87:80];
                rom_array[offset + 6]  <= w_data[79:72];
                rom_array[offset + 7]  <= w_data[71:64];
                rom_array[offset + 8]  <= w_data[63:56];
                rom_array[offset + 9]  <= w_data[55:48];
                rom_array[offset + 10] <= w_data[47:40];
                rom_array[offset + 11] <= w_data[39:32];
                rom_array[offset + 12] <= w_data[31:24];
                rom_array[offset + 13] <= w_data[23:16];
                rom_array[offset + 14] <= w_data[15:8];
                rom_array[offset + 15] <= w_data[7:0];
            end

            else if (w_addr[31:16] == 16'h8000) begin
                if (w_addr == 32'h80001000) begin
                    timer_bottom <= w_data[127:96];
                    timer_top <= w_data[95:64];
                end
                else if (w_addr == 32'h80002000) begin
                    gpio <= w_data[127:96];
                end
            end
        end
    end

endmodule
