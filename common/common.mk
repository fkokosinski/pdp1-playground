APP_NAME ?=	main
CCFLAGS ?=	-O0
objects-asm :=	$(patsubst %.S,%.o,$(wildcard *.S)) 
objects-c :=	$(patsubst %.c,%.o,$(wildcard *.c)) 
objects :=	$(objects-asm) $(objects-c) ../common/crt0.o

default: $(APP_NAME).rim

%.s: %.c
	$(realpath ../build-gcc/gcc/cc1) $(CCFLAGS) $<

%.o: %.S
	pdp1-elf-as $< -o $@

%.o: %.s
	pdp1-elf-as $< -o $@

$(APP_NAME).bin: $(realpath ../common/common.ld) $(objects)
	pdp1-elf-ld -L$(realpath ../build-gcc/gcc) -o $@ -T $^ -lgcc

%.rim: %.bin
	pdp1-elf-objcopy -O dec_rim $< $@

run: $(APP_NAME).rim
	pdp1 $(realpath ../common/startup.pdp1)

clean:
	rm -rf *.o *.s *.bin *.rim

.PHONY: default run clean
