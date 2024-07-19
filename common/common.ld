OUTPUT_FORMAT("elf32-pdp1")
ENTRY(_start)

MEMORY
{
	ram (rwx) : ORIGIN = 0x0, LENGTH = 64K
}

STACK_SIZE = 01000;

SECTIONS
{
	.text 0x12c :
	{
		/* 
		 * We need to have crt0 at the start, because we depend on the
		 * `_start` symbol being at 0x12c.
		 *
		 * TODO: make this configurable/flexible in BFD dec-rim backend
		 */
		"../common/crt0.o"(.text)

		*(.text)
	} > ram

	.bss (NOLOAD) :
	{
		*(.bss .bss.*)
		*(COMMON)
	} > ram

	.data :
	{
		*(.data)
	} > ram

	.stack (NOLOAD) :
	{
		_stack_start = .;
		. += STACK_SIZE;
		_stack_end = .;
	} > ram
}
