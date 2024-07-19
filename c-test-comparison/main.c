static void putc(int);

void main(void)
{
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
}

static void putc(int c) {
	asm volatile ("lio %0" : : "r"(c) : "$io");
	asm volatile ("tyo");
}
