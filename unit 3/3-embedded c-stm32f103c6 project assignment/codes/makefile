CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
COBJ=$(SRC:.c=.o)
project=lab2

$(project).bin: $(project).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "========Build is Done========"

$(project).elf: $(ASOBJ) $(COBJ)
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(COBJ) -o $@ -Map=Map_file.map

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@

clean:
	rm *.o *.elf *.bin
	@echo "========Clean is Done========"