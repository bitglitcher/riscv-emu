#all: ../script.ld jal_test.s
all:
	#riscv64-unknown-elf-as test.s  -march=rv32i -o test.o
	#riscv64-unknown-elf-ld -L="/mnt/c/Users/camin/Documents/opt/riscv/lib/gcc/riscv64-unknown-elf/10.2.0/rv32i/ilp32" -b elf32-littleriscv -m elf32lriscv -T script.ld test.o crt0.o -o test_linked.o
	riscv64-unknown-elf-gcc -T ../script.ld -lm -lgcc -static -march=rv32i -mabi=ilp32 -nostartfiles -ffreestanding  test.s -O0 -o test_linked.o
	riscv64-unknown-elf-objcopy -F elf32-littleriscv test_linked.o -O binary ROM.bin
	riscv64-unknown-elf-objdump -ds test_linked.o