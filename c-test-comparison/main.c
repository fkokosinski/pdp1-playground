static void putc(int);

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm ("law 03000");
	asm ("dac 209");
	asm ("law 04000");
	asm ("dac 208");
	
	int x = 30;
	int y = 30;

	/* test if `==` works */
	if (x == y)
		putc(061); // a
	if (x != y)
		putc(062); // b

	/* test if `!=` works */
	x = 21;
	y = 37;
	if (x != y)
		putc(063); // c
	if (x == y)
		putc(064); // d

	/* test if `<` works */
	if (x < y)
		putc(065); // e
	y = 21;
	if (x < y)
		putc(066); // f
	
	/* test if `>` works */
	x = 41;
	y = 37;
	if (x > y)
		putc(067); // g
	x = 37;
	if (x > y)
		putc(070); // h
	x = 21;
	if (x > y)
		putc(071); // i

	asm ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm ("lio %0" : : "r"(c));
	asm ("tyo");
}
