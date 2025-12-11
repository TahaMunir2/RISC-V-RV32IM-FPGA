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

Each block contains one valid bit and each set has one used bit. The valid bit indicates whether the data in that cache block is meaningful or not, thus the valid bit is initialised to 0. The used bit indicates the most recently block, which is helpful in determining which block to evict when the set is full (LRU logic).

#### Valid bit initialisation:
```SystemVerilog
initial begin
    for (int i = 0; i < 128; i++) begin
        cache[i].used           = 1'b0;
        cache[i].block0.valid   = 1'b0;
        cache[i].block1.valid   = 1'b0;
    end
end
```
#### 2 way associative LRU eviction victim logic:
For a 2 way associative cache, the LRU replacement policy is fairly straightforward:
- `cache[set].used` = `0` → block 0 was most recently used → replace block 1
- `cache[set].used` = `1` → block 1 was most recently used → replace block 0
```SystemVerilog
//way determination
if (!valid0 && !valid1)     way = 1'b0; //both bits are invalid, we choose the default 
else if (!valid0)           way = 1'b0; //way0 is invalid
else if (!valid1)           way = 1'b1; //way1 is invalid
else way = ~cache[set].used; //both bits are valid, we take into account which way was least recently used (LRU logic)
```
#### Instruction cache reading
When a read request is sent to the instruction cache, it determines whether there is a hit or miss on the request using the following logic:

```SystemVerilog
// hit detection
hit0 = (cache[set].block0.tag == tag_bits && cache[set].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
hit1 = (cache[set].block1.tag == tag_bits && cache[set].block1.valid && fetch);
miss = ~(hit0 | hit1) && fetch;
```

If the read request is a hit, the instruction cache outputs the data stored at the matching address.

```SystemVerilog
//way determination
way = hit1;   // if hit1 = 1 then way = 1 if hit1 = 0 then way = 0 as hit0 = 1

// On a hit: enable read from cache
rd_en = 1'b1;
```
However, if the read request is a miss, the instruction cache stalls the rest of the circuit (other than the memory modules) and sends a fetch request to the L2 cache.

Next, the instruction cache waits for the L2 cache to assert ready, signaling that the fetch request has been fulfilled. It then stores the data returned by the L2 cache and sets the block’s valid bit to high.
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

The data cache performs all the same core functions as the instruction cache—reading, LRU-based eviction, and loading lines from the L2 cache—while also supporting several additional operations specific to data handling.

#### Additional Load Options
Our data cache supports different load sizes, with the cache being able to load only a single byte, 2 bytes (or half a word), and a full word (4 bytes). Additionally, the data cache supports loading both unsigned and signed integers, implementing sign extension when required. The cache uses the byte offset of the requested address to determine which byte lane to read from.

- `LoadSize` = `2'b00` → only load 1 byte
- `LoadSize` = `2'b01` → load 2 bytes
- `LoadSize` = `2'b10` → load 4 bytes (full word)
- `LoadUnsigned` = `1'b0` → load with sign extension
- `LoadUnsigned` = `1'b1` → load without sign extension


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

Furthermore, for store-byte and store half word operations, the processor places the byte or half word in wd[7:0] or wd[15:0] respectively, regardless of its true offset. Therefore the cache must use the address’s byte offset to shift the byte or half word into the correct position.

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



---

## 3. Schematic

---

## 4. Testing & Verification

### 4.1 L1 Instruction Cache Testing

---

### 4.2 L1 Data Cache Testing

---

### 4.3 L2 Cache Testing

---
