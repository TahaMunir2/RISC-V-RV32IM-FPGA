# Hierarchical Cache

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Overall Hierarchy](#21-overall-hierarchy)
  - [2.2 L1 Instruction Cache](#22-l1-instruction-cache)
  - [2.3 L1 Data Cache](#23-l1-data-cache)
  - [2.4 L2 Cache](#24-l2_cache)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 L1 Instruction Cache Testing](#41-l1-instruction-cache-testing)
  - [4.2 L1 Data Cache Testing](#42-l1-data-cache-testing)
  - [4.3 L2 Cache Testing](#43-l2-cache-testing)
---

## 1. Overview

Caches are relatively small and fast memory components that are used to improve processer performance by decreasing the time taken per fetch and writeback (on average). Caches provide quick and efficient access to a small portion of the main memory, and are also able to be written to and write back to main memory if need be.

Caches exploit spatial and temporal locality in order to improve fetch and writeback speed. Spatial locality is the principle that accessing one memory location increases the likelihood that adjacent memory locations (in the virtual memory space) will be accessed shortly afterward. On the other hand, the concept of temporal locality is that recently accessed data is also highly likely to be re-accessed due to the inherently cyclic nature of programming.

In our design, we have implemented a 2-way associative L1 instruction cache and L1 data cache, as well as a 4-way associative L2 cache. We have decideed not to implement further lower level memory (other than main memory) such as an L3 cache or an L4 cache as these typically handle data from different cores or processors, of which we have neither.

---

## 2. Implementation

### 2.1 Overall Hierarchy

The overall memory hierarchy is as such:

-insert overall hierarchy img

As shown in the diagram above, the processor reads and writes from the L1 caches, which read from and write to the L2 cache, which reads from and writes to main memory.

We have also decided to implement the cache controller and cache array in the same SystemVerilog sheet for all of the caches due to simplicity when integrating all of the submodules into the CPU.

---

### 2.2 L1 Instruction Cache
The instruction cache is reponsible for temporarily storing instructions so that they can be quickly accessed by the processor (control path).

The specifications for our instruction cache are as follows:

| Parameter | Selected Value |
| --------- | -------------- |
| Total Cache Size | 4096 kB |
| Number of Sets | 128 |
| Associativity | 2-way |
| Block Size | 4 words |

The instruction cache supports read requests from the processer and writing from the L2 cache, but does not support writing from the processor, as we are not expecting the processor to change and write over an instruction.


#### Valid and Used bit
Each block contains one valid bit and each set has one used bit. The valid bit indicates whether the data in that cache block is meaningful or not, thus the valid bit is initialised to 0. The used bit indicates the most recently block, which is helpful in determining which block to evict when the set is full (LRU logic).

Valid bit initialisation:
```SystemVerilog
initial begin
    for (int i = 0; i < 128; i++) begin
        cache[i].used           = 1'b0;
        cache[i].block0.valid   = 1'b0;
        cache[i].block1.valid   = 1'b0;
    end
end
```


#### Instruction cache reading
When a read request is sent to the instruction cache, it determines whether there is a hit or miss on the request using the following logic:

Hit/miss detection:
```SystemVerilog
// hit detection
hit0 = (cache[set].block0.tag == tag_bits && cache[set].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
hit1 = (cache[set].block1.tag == tag_bits && cache[set].block1.valid && fetch);
miss = ~(hit0 | hit1) && fetch;
```

If the read request is a hit, the instruction cache outputs the data stored at the matching address.

Read way determination:
```SystemVerilog
//way determination
way = hit1;   // if hit1 = 1 then way = 1 if hit1 = 0 then way = 0 as hit0 = 1

// On a hit: enable read from cache
rd_en = 1'b1;
```
However, if the read request is a miss, the instruction cache stalls the rest of the circuit (other than the memory modules) and sends a fetch request to the L2 cache.


#### Load from L2
On a miss the instruction cache needs to decide which way to store the fetched data into. For cold misses, our cache defaults to replacing block 0 if both bits are invalid, or block 1 if block0.valid = 1. However, for capacity misses, our cache uses an LRU replacement policy.

![alt text](image.png)

Cold miss eviction:
- `!cache[set].block0.valid && !cache[set].block1.valid` → both blocks are invalid → replace block 0
- `cache[set].block0.valid && !cache[set].block1.valid` → block 1 is invalid → replace block 1
- `!cache[set].block0.valid && cache[set].block1.valid` → block 0 is invalid → replace block 0 (this case will never happen but is added as a safety net)
- `cache[set].block0.valid && cache[set].block1.valid` → both blocks are valid → us LRU logic

For a 2 way associative cache, the LRU replacement policy is fairly straightforward:
- `cache[set].used` = `0` → block 0 was most recently used → replace block 1
- `cache[set].used` = `1` → block 1 was most recently used → replace block 0

Eviction logic:
```SystemVerilog
//way determination
if (!valid0 && !valid1)     way = 1'b0; //both bits are invalid, we choose the default 
else if (!valid0)           way = 1'b0; //way0 is invalid
else if (!valid1)           way = 1'b1; //way1 is invalid
else way = ~cache[set].used; //both bits are valid, we take into account which way was least recently used (LRU logic)
```

Next, the instruction cache waits for the L2 cache to assert ready, signaling that the fetch request has been fulfilled. It then stores the data returned by the L2 cache and sets the block’s valid bit to high.

Load from L2 logic:
```SystemVerilog
// On a miss, disable read and write and stall the rest of the circuit, and let L2 cache retrieve the data before writing it in.
if (!ready) begin
    rd_en      = 1'b0;
    wr_en      = 1'b0;
    stall      = 1'b1;
    l2_fetch   = 1'b1;              
end

// When L2 cache asserts ready: fill the line (as L2 cache has retrieved the data), but don't read from cache this cycle
else begin
    rd_en      = 1'b0;
    wr_en      = 1'b1;
    stall      = 1'b1;
    write_data = line_from_mem;
end
```

---

### 2.3 L1 Data Cache

The data cache is reponsible for storing data so that it can be quickly accessed by the processor (datapath). It also performs write-backs more efficiently, further increasing processor performance.

The specifications for our data cache are as follows:

| Parameter | Selected Value |
| --------- | -------------- |
| Total Cache Size | 4096 kB |
| Number of Sets | 128 |
| Associativity | 2-way |
| Block Size | 4 words |

The data cache performs all the same core functions as the instruction cache—reading, LRU-based eviction, stalling, and loading lines from the L2 cache, while also supporting several additional operations specific to data handling.


#### Additional Load Options
Our data cache supports different load sizes, with the cache being able to load only a single byte, 2 bytes (or half a word), and a full word (4 bytes). Additionally, the data cache supports loading both unsigned and signed integers, implementing sign extension when required. The cache uses the byte offset of the requested address to determine which byte lane to read from.

- `LoadSize` = `2'b00` → only load 1 byte
- `LoadSize` = `2'b01` → load 2 bytes
- `LoadSize` = `2'b10` → load 4 bytes (full word)
- `LoadUnsigned` = `1'b0` → load with sign extension
- `LoadUnsigned` = `1'b1` → load without sign extension

Load type logic:
```SystemVerilog
// lw logic
case (LoadSize)
    // LB / LBU
    2'b00: begin
        bottom_bit = 8 * byte_offset;
        if (LoadUnsigned)
            data_out = {24'b0, data_out[bottom_bit[4:0] +:8]};
        else
            data_out = {{24{data_out[bottom_bit[4:0] + 7]}}, data_out[bottom_bit[4:0] +:8]};
    end

    // LH / LHU
    2'b01: begin
        bottom_bit = 16 * byte_offset;
        if (LoadUnsigned)
            data_out = {16'b0, data_out[bottom_bit[4:0] +:16]};
        else
            data_out = {{16{data_out[bottom_bit[4:0] + 15]}},data_out[bottom_bit[4:0]+:16]};
    end

    // LW
    default: begin
        data_out = data_out;
    end
endcase
```


#### Writeback from Processor

When the processor wants to write data back, it sends a write request to the data cache. This uses the same hit detection logic as used in a read request.

If the write request hits in the cache, the data cache writes the processor’s input data directly into the corresponding cache address.

Write way determination:
```SystemVerilog
//way determination
way = hit1;   // if hit1 = 1 then way = 1 if hit1 = 0 then way = 0 as hit0 = 1

if (MemWrite_m) begin // sb logic, determine size
    wr_en = 1'b1;
    wmask = '1;
    write_data = {4{wd_aligned}};
```
It then sets the block’s dirty bit to high. This bit indicates whether the processor has modified the data in that block.


#### Additional Write Options
Alongside its extended load options, the data cache also supports multiple write sizes. Using the Size_Write_m input, the cache can store 1 byte, 2 bytes (half-word), or a full 4-byte word from the processor. This operation uses a write mask to determine which bytes should be overwritten. The cache uses the byte offset of the requested address to determine which byte lane to write to.

- `SizeWrite_m` = `2'b00` → only store 1 byte → wmask = from bottom_bit to next 8 bits
- `SizeWrite_m` = `2'b01` → store 2 bytes → wmask = from bottom_bit to next 16 bits
- `SizeWrite_m` = `2'b10` → store 4 bytes (full word) → wmask = from bottom_bit to next 32 bits

Store size logic:
```SystemVerilog
if(SizeWrite_m == 2'b00) begin //sb
    bottom_bit = block_offset * 32 + byte_offset * 8;
    wmask[bottom_bit[6:0] +: 8] = '0;
end

else if(SizeWrite_m == 2'b01) begin // sh
    bottom_bit = block_offset * 32 + byte_offset * 8;
    wmask[bottom_bit[6:0] +: 16] = '0;
end

else if(SizeWrite_m == 2'b10) begin // sw
    bottom_bit = block_offset * 32;
    wmask[bottom_bit[6:0] +: 32] = '0;
end

wmask = ~wmask;
```

Furthermore, for store byte and store half word operations, the processor places the byte or half word in wd[7:0] or wd[15:0] respectively, regardless of its true offset. Therefore the cache must use the address’s byte offset to shift the byte or half word into the correct position.

Byte shifting:
```SystemVerilog
logic [DATA_WIDTH-1:0] wd_aligned;
assign wd_aligned = wd << (byte_offset * 8);
```


#### Writeback to L2
Before evicting a block, the data cache must first determine if the data has been changed since it was originally fetched. This allows the processor to write back only to the cache, updating the L2 cache and main memory only when the data is evicted. This avoids unnecessary writes to main memory and improves efficiency. The cache achieves this using the dirty bit described earlier.

- `cache[set].block0.dirty` = `0` → block 0 has not been written to by the processor → no need to write back data from block 0 when evicted
- `cache[set].block0.dirty` = `1` → block 0 has been written to by the processor → need to write back data from block 0 when evicted
- `cache[set].block1.dirty` = `0` → block 1 has not been written to by the processor → no need to write back data from block 1 when evicted
- `cache[set].block1.dirty` = `1` → block 1 has been written to by the processor → need to write back data from block 1 when evicted

If the evicted block’s dirty bit is high, the cache asserts writeback_en, loads the block’s data into write_back, and loads the address corresponding to the block’s first word into write_back_addr. It holds these signals until wb_ready goes high, confirming the L2 cache has received the write-back data, and then resets the block’s dirty bit.

Furthermore, the data cache prevents dirty blocks from being overwritten, ensuring that no data is lost when fetching new data from the L2 cache. If, during an L2 fetch, the destination block is dirty, the data cache delays the write until wb_ready is asserted and dirty bit is cleared, confirming that the dirty data has been preserved and can be safely overwritten.

---

### 2.4 L2 Cache

The L2 cache serves as an intermediate level of memory between the fast L1 caches and the much slower main memory. Its larger size allows it to store more data than the L1 caches, reducing the likelihood of costly misses. By acting as a secondary buffer, it improves overall system performance by balancing access speed with storage capacity.

The specifications for our L2 cache are as follows:

| Parameter | Selected Value |
| --------- | -------------- |
| Total Cache Size | 32 MB |
| Number of Sets | 256 |
| Associativity | 4-way |
| Block Size | 8 words |

The L2 cache supports reading, handling write-backs, and fetching data from main memory.


#### Arbiter Logic

The L2 cache can accept fetch requests from either the instruction cache or the data cache, but not simultaneously, as it has only a single read port. We employ a simple arbiter to manage these requests, prioritising those from the data cache. Since both caches stall the pipeline on a miss until the L2 cache responds to their request, the instruction cache cannot experience starvation. If both L1 caches issue fetch requests to the L2 cache, the instruction cache will spin and continue stalling until the data cache’s request is completed, after which its request is serviced immediately.

For data-cache requests, the L1 write-back enable signal is driven by the data cache’s write_back_en output, ensuring that the L2 cache handles any write-back operations the data cache issues. For instruction-cache requests, however, the write-back enable signal is always set to 0, since instructions are not modified by the processor and the instruction cache will never generate a write-back.

| {fetch_i, fetch_d} | req_i | req_d | addr | l1writeback enable | 
| ------------------ | ----- | ----- | ---- | ------------------ |
| 00 | 0 | 0 | X | X |
| 01 | 0 | 1 | addr_d | write_back_en |
| 10 | 1 | 0 | addr_i | 0 |
| 11 | 0 | 1 | addr_d | write_back_en |

```SystemVerilog
//arbiter logic
if (!fetch_i && !fetch_d) begin
    fetch = 0;
    l1write = 0;
end

else if (fetch_i && !fetch_d) begin
    fetch = 1;
    addr = addr_i;
    l1write = 0;
    req_i = 1;
end

else if (!fetch_i && fetch_d) begin
    fetch = 1;
    addr = addr_d;
    l1write = l1write_back_en;
    req_d = 1;
end

else if (fetch_i && fetch_d) begin
    fetch = 1;
    addr = addr_d;
    l1write = l1write_back_en;
    req_d = 1;
end
```


#### Read Logic

In many respects, the L2 cache’s read logic mirrors that of the L1 caches. The primary differences are that hit detection must check four ways rather than two, and the cache returns four words at once instead of one. This leverages spatial locality by anticipating that neighboring words will likely be accessed soon, thereby reducing the miss rate.

Hit detection:
```SystemVerilog
assign tag_bits_rd = addr[ADDRESS_WIDTH-1:13];
assign set_rd = addr[12:5];
assign block_offset_rd = addr[4:2];
```
```SystemVerilog
hit0_wb = (cache[set_wb].block0.tag == tag_bits_wb && cache[set_wb].block0.valid);
hit1_wb = (cache[set_wb].block1.tag == tag_bits_wb && cache[set_wb].block1.valid);
hit2_wb = (cache[set_wb].block2.tag == tag_bits_wb && cache[set_wb].block2.valid);
hit3_wb = (cache[set_wb].block3.tag == tag_bits_wb && cache[set_wb].block3.valid);
miss_wb = ~(hit0_wb | hit1_wb | hit2_wb | hit3_wb);
```

The read logic also updates the used bits for our LRU mechanism, which will be discussed in more detail later.

Read logic for block 0:
```SystemVerilog   
if (way == 2'b00) begin
    case(block_offset_rd[2])
    1'b0: data_out <= cache[set].block0[127:0];
    1'b1: data_out <= cache[set].block0[255:128];
    endcase
    cache[set].u01 <= 1;
    cache[set].u02 <= 1;
    cache[set].u03 <= 1;
end
```

Upon finishing a read, the L2 cache signals to the requesting cache — data or instruction — that its fetch has been completed by asserting either ready_i (to wake the i cache) or ready_d (to wake the d cache). If the data cache is the recipient, it must additionally confirm that the target block is clean before storing the incoming data, forming a handshake with the L2 cache.

Ready assertion:
```SystemVerilog
//assert ready on the correct L1 cache
if (req_d) begin
    ready_d <= 1;
end

else if (req_i) begin
    ready_i <= 1;
end
```

However, as with the L1 caches, an L2 miss requires issuing a fetch request to main memory and storing the returned data before forwarding it to the requesting L1 cache.


#### Load from Main Memory

As with the L1 caches, our L2 cache uses a default block replacement order of 0–3 on cold misses, and applies LRU logic to choose a block for eviction on capacity misses when storing data fetched from main memory. However, because the L2 cache is 4-way associative, the LRU replacement logic is slightly more complex.

To implement this logic, our initial approach was to use a matrix:

| i \ j |   0   |   1   |   2   |   3   |
|-------|-------|-------|-------|-------|
| **0** |   -   | u01   | u02   | u03   |
| **1** | u10   |   -   | u12   | u13   |
| **2** | u20   | u21   |   -   | u23   |
| **3** | u30   | u31   | u32   |   -   |

where u01 means that 0 was used more recently than 1.

Conceptually, determining the least recently used way can be expressed using pseudocode similar to the following:
```
victim = 0;
for each way k in {0,1,2,3}:
    if M[k][0] == 0 and M[k][1] == 0 and M[k][2] == 0 and M[k][3] == 0 (ignoring M[k][k]):
        victim = k;
        break;
```

However, because the upper triangle contains all the necessary information and the lower triangle can be inferred from it, we chose to implement only the upper half of the matrix.

Furthermore, given that our cache is only 4-way associative, we opted to brute force the solution instead of restructuring the approach above to rely exclusively on the upper triangle of the matrix.This led to the eviction victim block selection logic shown below:

Eviction logic:  
```SystemVerilog
if (!valid0)      way_rd = 2'b00;
else if (!valid1) way_rd = 2'b01;
else if (!valid2) way_rd = 2'b10;          
else if (!valid3) way_rd = 2'b11;
else begin
    evict = 1;

    if (cache[set_rd].u01) begin
        if (cache[set_rd].u12) begin
            if (cache[set_rd].u23) begin
                way_rd = 2'b11;
            end
            else way_rd = 2'b10;
        end
        else if (cache[set_rd].u13) begin
            way_rd = 2'b11;
        end
        else way_rd = 2'b01;
    end

    else if (cache[set_rd].u02) begin
        if (cache[set_rd].u23) begin
            way_rd = 2'b11;
        end
        else way_rd = 2'b10;
    end

    else if (cache[set_rd].u03) begin
        way_rd = 2'b11;
    end

    else way_rd = 2'b00;
end
```

The L2 cache also includes a dirty bit, which indicates whether an evicted block should be stored into the L2 writeback buffer. Once the writeback completes, the L2 cache clears the block’s dirty bit. It then spins until the block is clean and main memory asserts ready, after which it enables the write path and loads the data from main memory.

Write enable logic for block0:
```SystemVerilog
if (way_rd == 2'b00) begin
    if (cache[set_rd].block0.dirty && (l2write_buffer == 0)) begin 
        l2write_back_data_buffer_next = cache[set_rd].block0[255:0];
        l2write_back_addr_buffer_next = {{cache[set_rd].block0.tag}, {set_rd}, {5'b0}};
        clean = 1;
        l2write_buffer_next = 2'b10;
    end

    else if (!cache[set_rd].block0.dirty && ready) begin
        wr_en = 1;
        write_data = line_from_mem;
        wmask = '1;
        way = way_rd;
        tag_bits = tag_bits_rd;
        set = set_rd;
        block_offset = block_offset_rd;
    end
end
```


#### L1 Writeback

As discussed earlier, the L2 cache includes a write-back buffer to handle write-back requests from the L1 data cache. This buffer uses next-state logic to store and output the required information.

l1write_buffer logic:
```SystemVerilog
logic [DATA_WIDTH*4-1:0] l1write_back_data_buffer;
logic [DATA_WIDTH*4-1:0] l1write_back_data_buffer_next;
logic l1write_buffer;
logic l1write_buffer_next;
logic [ADDRESS_WIDTH-1:0] l1write_back_addr_buffer;
logic [ADDRESS_WIDTH-1:0] l1write_back_addr_buffer_next;
```

Upon receiving a write-back request from the data cache, if the L1 write-back buffer is empty, the L2 cache loads the buffer with the provided data and address, asserts l1write_buffer to indicate that the buffer is full, and raises wb_ready_d to confirm to the data cache that the write-back data has been successfully captured.


| l1write_buffer | l1write | action |
| --- | --- | --- |
| 0 | 0 | do nothing as no writeback request has been issued |
| 0 | 1 | fill in the buffer as a writeback request has been issued, and the buffer is empty |
| 1 | 0 | do nothing as no writeback request has been issued |
| 1 | 1 | do not fill as the buffer is already full |


l1write_buffer fill logic:
```SystemVerilog
if (l1write && !l1write_buffer) begin
    wb_ready_d_next = 1;

    l1write_buffer_next = l1write;
    l1write_back_data_buffer_next = l1write_back_data;
    l1write_back_addr_buffer_next = l1write_back_addr;
end
```


The L1 write buffer also performs its own hit/miss check using the address stored in the buffer.

If the L1 writeback buffer detects a hit, it writes the data to the matching address. However, because the cache has only one internal way selection unit and a single write path, it cannot perform write-back buffer operations concurrently with L1 reads or main memory loads. We have decided to give these operations priority, so the buffer must wait until the cache is idle before issuing a write. When issuing a write from the L1 writeback buffer, we also assert wr_wb to indicate that the write originates from the L1 cache. This ensures that the target block is correctly marked as dirty.


l1write_buffer hit logic:
```SystemVerilog
if (l1write_buffer && !rd_en && !wr_en && !miss_wb) begin
    wr_en = 1;
    wr_wb = 1;
    write_data = {2{l1write_back_data_buffer}};
    l1write_buffer_next = l1write_buffer - 1;

    if (hit0_wb) way = 2'b00;
    else if (hit1_wb) way = 2'b01;
    else if (hit2_wb) way = 2'b10;
    else if (hit3_wb) way = 2'b11;

    tag_bits = tag_bits_wb;
    set = set_wb;
    block_offset = block_offset_wb;

    if (block_offset_wb == 3'b000) begin
        wmask = {{128{1'b0}}, {128{1'b1}}};
    end
    else if (block_offset_wb == 3'b100) begin
        wmask = {{128{1'b1}}, {128{1'b0}}};
    end
end
```

However, L1 writeback buffer misses need to be handled differently.


#### Writeback to Main Memory

The L2 cache includes a 4 word writeback data port to main memory. This port handles both L1 writeback misses, which are forwarded directly through the L2 and dirty lines evicted from the L2 cache itself. Since L2 writebacks consist of 8 words instead of 4, they must be issued as two separate 4-word writes to main memory. The l2write_buffer[1:0] signal indicates the number of 4-word segments that are still pending.

We prioritize the L1 writeback buffer over the L2 buffer because it is smaller and easier to drain, and because L1 misses occur far more frequently than combined L1+L2 misses. Giving it priority reduces the likelihood of stalling the processor.

When main memory asserts wb_ready for the L2 cache, indicating it can accept another writeback, the L2 cache asserts write_back_en, outputs the appropriate writeback address and data, and then decrements the number of remaining words in its writeback buffer by one.


| l2write_buffer | l1write_buffer | wb_ready | write_back_data | write_back_addr | write_back_en |
| --- | --- | --- | --- | --- | --- |
| 00 | 0 | 0 | X | X | 0 |
| 00 | 0 | 1 | X | X | 0 |
| 00 | 1 | 0 | X | X | 0 |
| 00 | 1 | 1 | l1_write_buffer_data | l1_write_buffer_addr | 1 |
| 01 | 0 | 0 | X | X | 0 |
| 01 | 0 | 1 | l2_write_buffer_data[127:0] (bottom 4 words) | l2_write_buffer_addr | 1 |
| 01 | 1 | 0 | X | X | 0 |
| 01 | 1 | 1 | l1_write_buffer_data | l1_write_buffer_addr | 1 |
| 10 | 0 | 0 | X | X | 0 |
| 10 | 0 | 1 | l2_write_buffer_data[255:128] (top 4 words) | address of the bottom byte of the top 4 words | 1 |
| 10 | 1 | 0 | X | X | 0 |
| 10 | 1 | 1 | l1_write_buffer_data | l1_write_buffer_addr | 1 |


L2 writeback logic:
```SystemVerilog
if ((l1write_buffer && miss_wb) && wb_ready) begin
    write_back_en_next = 1;
    write_back_data_next = l1write_back_data_buffer;
    write_back_addr = l1write_back_addr_buffer;
    l1write_buffer_next = l1write_buffer - 1;
end

else if ((l2write_buffer == 2'b10) && wb_ready) begin
    write_back_en_next = 1;
    write_back_data_next = l2write_back_data_buffer[127:0];
    write_back_addr = l2write_back_addr_buffer;
    l2write_buffer_next = l2write_buffer - 1;
end

else if ((l2write_buffer == 2'b01) && wb_ready) begin
    write_back_en_next = 1;
    write_back_data_next = l2write_back_data_buffer[255:128];
    write_back_addr = {l2write_back_addr_buffer[31:5], 1'b1, l2write_back_addr_buffer[3:0]};
    l2write_buffer_next = l2write_buffer - 1;
end
```

There is also a critical edge case that must be addressed to ensure data integrity. When the writeback buffer is full and its stored address matches the address returned by main memory during a load, the returning data is obsolete and risks being written into the cache, despite the cache still registering a miss. Because the write operation and the deassertion of l1write_buffer occur synchronously, the L2 cache could, in the same cycle, write stale memory data into the cache while simultaneously forwarding the newer data to main memory. This would propagate incorrect values to the L1 caches and eventually to the processor. To mitigate this, we implemented a specific ad-hoc fix for this situation.


Specific patch for edge case:
```SystemVerilog
if (wr_en && l1write_buffer && (addr[31:4] == l1write_back_addr_buffer[31:4])) begin
    wr_wb = 1;
    l1write_buffer_next = l1write_buffer - 1;
    if (block_offset_wb == 3'b000) begin
        write_data[127:0] = l1write_back_data_buffer;
    end
    else if (block_offset_wb == 3'b100) begin
        write_data[255:128] = l1write_back_data_buffer;
    end
end
```

---

## 3. Schematic

---

## 4. Testing & Verification

### 4.1 L1 Instruction Cache Testing

We created a c++ testbench (l1i_cache_tb.cpp) that isolates the instruction cache module and verifies all of the intended logic, including loading to the processor and storing from the L2 cache. All tests were combined into a single test case to eliminate the need to reinitialise the cache with appropriate values, particularly those required to avoid cold misses before each individual test.
**Tests performed:**
- **Stall Assertion on Cold Miss:** Cache should assert stall when valid = 0
- **Stall Assertion on Capacity Miss:** Cache should assert stall when set capacity is full
- **Load logic:** Loading a whole word from the instruction cache
- **Store logic:** Storing a whole block from the L2 cache into the data cache
- **Correct LRU Replacement Policy:** Ensuring that the instruction cache picks the correct victim based on our LRU replacement policy

#### Running the code

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Run the test:
   ```bash
   ./doit.sh tests/l1i_cache_tb.cpp
   ```

Here are the results:

---

### 4.2 L1 Data Cache Testing
We also created a c++ testbench (l1d_cache_tb.cpp) to isolate the data cache module and verify all of the intended logic, including loading to the processor, writebacks from the processor, writebacks to the L2 cache and storing from the L2 cache. Given the increased length and complexity of the code, we chose not to place all tests in a single test case, even though this required reinitializing all values for each individual test.
**Tests performed:**
- **Stall Assertion on Cold Miss:** Cache should assert stall when valid = 0
- **Stall Assertion on Capacity Miss:** Cache should assert stall when set capacity is full
- **Load full word logic:** Loading a whole word from the data cache
- **Load half word logic:** Loading half a word from the data cache
- **Load byte logic:** Loading a single byte from the data cache
- **Load signed/unsigned logic:** Loading a signed/unsigned integer from the data cache
- **Store logic:** Storing a whole block from the L2 cache into the data cache
- **Store half word logic:** Storing a whole block from the L2 cache
- **Correct LRU Replacement Policy:** Ensuring that the instruction cache picks the correct victim based on our LRU replacement policy
- **Write full word** Writing a full word from the processor
- **Write half word** Writing a half word from the processor
- **Write byte** Writing a single byte from the processor

#### Running the code

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Run the test:
   ```bash
   ./doit.sh tests/l1d_cache_tb.cpp
   ```

Here are the results:


---

### 4.3 L2 Cache Testing
We also created a c++ testbench (l2_cache_tb.cpp) to isolate the data cache module and verify all of the intended logic, including loading to the l1d and i cache, writebacks from the data cache, writebacks to main memory and storing from main memory. This time, since the code was slightly more long and complicated, we decided to not include everything in the same test case despite having to reinitialise all of the values for each case.
**Tests performed:**
- **Fetch request from data cache:** Ensuring that the L2 cache successfully fulfills fetch requests from the data cache
- **Fetch request from instruction cache:** Ensuring that the L2 cache successfully fulfills fetch requests from the instruction cache
- **Fetch request from both data and instruction cache:** Ensuring that the L2 cache gives priority to the data cache fetch request, but ultimately fulfills both requests
- **Correct LRU Replacement Policy:** Ensuring that the instruction cache picks the correct victim based on our LRU replacement policy
- **L1 writeback** Ensuring that a writeback from L1 is written into L2 on a hit, or passed onto main memory on a miss
- **L2 writeback** Ensuring that dirty L2 writebacks are successful (2 4 word writebacks as described earlier)

#### Running the code

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Run the test:
   ```bash
   ./doit.sh tests/l2_cache_tb.cpp
   ```
Here are the results:
---
