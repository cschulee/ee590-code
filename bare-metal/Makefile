
ARMGNU ?= arm-none-eabi
#ARMGNU ?= arm-linux-gnueabi

COPS = -Wall -O2 -nostdlib -nostartfiles -ffreestanding 

gcc : exec.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc
	rm -f *.clang.s

start.o : start.s
	$(ARMGNU)-as start.s -o start.o

exec.o : exec.c
	$(ARMGNU)-gcc $(COPS) -c exec.c -o exec.o

periph.o : periph.c
	$(ARMGNU)-gcc $(COPS) -c periph.c -o periph.o

exec.bin : memmap start.o periph.o exec.o 
	$(ARMGNU)-ld start.o periph.o exec.o -T memmap -o exec.elf
	$(ARMGNU)-objdump -D exec.elf > exec.list
	$(ARMGNU)-objcopy exec.elf -O ihex exec.hex
	$(ARMGNU)-objcopy exec.elf -O binary exec.bin



LOPS = -Wall -m32 -emit-llvm
LLCOPS0 = -march=arm 
LLCOPS1 = -march=arm -mcpu=arm1176jzf-s
LLCOPS = $(LLCOPS1)
COPS = -Wall  -O2 -nostdlib -nostartfiles -ffreestanding
OOPS = -std-compile-opts

clang : exec.clang.bin

exec.bc : exec.c
	clang $(LOPS) -c exec.c -o exec.bc

periph.bc : periph.c
	clang $(LOPS) -c periph.c -o periph.bc

exec.clang.elf : memmap start.o exec.bc periph.bc
	llvm-link periph.bc exec.bc -o exec.nopt.bc
	opt $(OOPS) exec.nopt.bc -o exec.opt.bc
	llc $(LLCOPS) exec.opt.bc -o exec.clang.s
	$(ARMGNU)-as exec.clang.s -o exec.clang.o
	$(ARMGNU)-ld -o exec.clang.elf -T memmap start.o exec.clang.o
	$(ARMGNU)-objdump -D exec.clang.elf > exec.clang.list

exec.clang.bin : exec.clang.elf
	$(ARMGNU)-objcopy exec.clang.elf exec.clang.hex -O ihex
	$(ARMGNU)-objcopy exec.clang.elf exec.clang.bin -O binary


