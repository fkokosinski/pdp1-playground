APP_NAME ?=	main
objects-asm :=	$(patsubst %.S,%.o,$(wildcard *.S)) 
objects-c :=	$(patsubst %.c,%.o,$(wildcard *.c)) 
objects :=	$(objects-asm) $(objects-c)

default: $(APP_NAME).rim

%.s: %.c
	../pdp1-gcc/host-x86_64-pc-linux-gnu/gcc/cc1 $<

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
