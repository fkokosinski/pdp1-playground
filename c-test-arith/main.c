static void putc(int);

int x;
int y;
int z;

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm volatile ("law 03000");
	asm volatile ("dac 0131");
	asm volatile ("law 04000");
	asm volatile ("dac 0130");

	x = 21;
	y = 37;

	z = x << 3;
	if (z == 168)
		putc(027);
	
	z = y >> 3;
	if (z == 4)
		putc(027);

	asm volatile ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm volatile ("lio %0" : : "r"(c) : "$io");
	asm volatile ("tyo");
}
