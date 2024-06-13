static void putc(int);

int x;
int y;
int z;

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm ("law 03000");
	asm ("dac 209");
	asm ("law 04000");
	asm ("dac 208");

	x = 21;
	y = 37;

	z = x << 3;
	if (z == 168)
		putc(027);
	
	z = y >> 3;
	if (z == 4)
		putc(027);

	asm ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm ("lio %0" : : "r"(c));
	asm ("tyo");
}
