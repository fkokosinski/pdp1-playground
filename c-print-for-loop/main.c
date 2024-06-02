static void putc(int);
static int get_char(int);

void _start(void)
{
	asm ("law 04000");
	asm ("dac 209");
	asm ("dac 208");

	int c;

	for (int i = 0; i != 8; i++) {
		c = get_char(i);
		putc(c);
	}

	asm ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm ("lio %0" : : "r"(c));
	asm ("tyo");
}

static int get_char(int c)
{
	if (c != 4)
		return 027;
	else
		return 030;
}
