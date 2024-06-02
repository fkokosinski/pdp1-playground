static void putc(int);
static int get_char(int);

static int x[] = {027, 030, 031};

void _start(void)
{
	asm ("law 04000");
	asm ("dac 209");
	asm ("dac 208");

	putc(x[0]);
	putc(x[1]);
	putc(x[2]);

	asm ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm ("lio %0" : : "r"(c));
	asm ("tyo");
}
