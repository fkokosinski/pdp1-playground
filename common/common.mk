APP_NAME ?=	main
CCFLAGS ?=	-O0
objects-asm :=	$(patsubst %.S,%.o,$(wildcard *.S)) 
objects-c :=	$(patsubst %.c,%.o,$(wildcard *.c)) 
objects :=	$(objects-asm) $(objects-c)

default: $(APP_NAME).rim

%.s: %.c
	../build-gcc/gcc/cc1 $(CCFLAGS) $<

%.o: %.S
	pdp1-elf-as $< -o $@

%.o: %.s
	pdp1-elf-as $< -o $@

$(APP_NAME).bin: ../common/common.ld $(objects)
	pdp1-elf-ld -o $@ -T $^

%.rim: %.bin
	pdp1-elf-objcopy -O dec_rim $< $@

run: $(APP_NAME).rim
	pdp1 ../common/startup.pdp1

clean:
	rm -rf *.o *.s *.bin *.rim

.PHONY: default run clean
