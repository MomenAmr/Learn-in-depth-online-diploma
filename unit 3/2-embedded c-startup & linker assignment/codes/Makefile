CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
COBJ=$(SRC:.c=.o)
AS=$(wildcard *.S)
ASOBJ=$(AS:.s=.o)
project=lab1

$(project).bin: $(project).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "========Build is Done========"

$(project).elf: $(ASOBJ) $(COBJ)
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(COBJ) -o $@ -Map=Map_file.map

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

clean:
	rm *.o *.elf *.bin
	@echo "========Clean is Done========"