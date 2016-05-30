
ARMGNU ?= arm-none-eabi

COPS = -Wall -O2 -nostdlib -nostartfiles -ffreestanding 

gcc : exec.bin

all : gcc

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