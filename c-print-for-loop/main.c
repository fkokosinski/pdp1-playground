static void putc(int);
static int get_char(int);

void _start(void)
{
	asm volatile ("law 04000");
	asm volatile ("dac 0131");
	asm volatile ("law 03000");
	asm volatile ("dac 0130");

	int c;

	for (int i = 0; i != 8; i++) {
		c = get_char(i);
		putc(c);
	}

	asm volatile ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm volatile ("lio %0" : : "r"(c) : "$io");
	asm volatile ("tyo");
}

static int get_char(int c)
{
	if (c != 4)
		return 027;
	else
		return 030;
}
