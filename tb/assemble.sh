#!/bin/bash

# Usage: ./assemble.sh <file.s>

SCRIPT_DIR=$(dirname "$(realpath "$0")")

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    echo "Usage: ./assemble.sh <file.s>"
    exit 1
fi

input_file=$1
basename=$(basename "$input_file" | sed 's/\.[^.]*$//')

# Correct output locations:
output_file="$SCRIPT_DIR/tests/program.hex"
LOG_DIR="$SCRIPT_DIR/tests/test_out/$basename"

mkdir -p "$LOG_DIR"

# Assemble
riscv64-unknown-elf-as -R -march=rv32im -mabi=ilp32 \
    -o "a.out" "$input_file"

# Link
riscv64-unknown-elf-ld -melf32lriscv \
    -e 0xBFC00000 \
    -Ttext 0xBFC00000 \
    -o "a.out.reloc" "a.out"

# Extract binary
riscv64-unknown-elf-objcopy -O binary \
    -j .text "a.out.reloc" "a.bin"

# Disassembly
riscv64-unknown-elf-objdump -f -d --source -m riscv \
    a.out.reloc > "$LOG_DIR/program.dis"

# Format into hex (for insmem)
od -v -An -t x1 "a.bin" | tr -s '\n' | awk '{$1=$1};1' > "$output_file"

# Cleanup
rm -f a.out a.out.reloc a.bin
