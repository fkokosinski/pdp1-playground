static void putc(int);
static int get_char(int);

void main(void)
{
	int c;

	for (int i = 0; i != 8; i++) {
		c = get_char(i);
		putc(c);
	}
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
