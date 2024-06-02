OUTPUT_FORMAT("elf32-pdp1")
ENTRY(_start)

MEMORY
{
	ram (rwx) : ORIGIN = 0x0, LENGTH = 64K
}

SECTIONS
{
	.text :
	{
		*(.text)
	} > ram

	.data 0x400 :
	{
		*(.data)
	} > ram
}
