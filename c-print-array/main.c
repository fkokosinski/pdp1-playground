static void putc(int);
static int get_char(int);

static int x[] = {027, 030, 031};
static int i = 0;

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm ("law 03000");
	asm ("dac 209");
	asm ("law 04000");
	asm ("dac 208");
	
	/* check with no iterators */
	putc(x[0]);
	putc(x[1]);
	putc(x[2]);

	/* check with global iterator */
	for (i = 0; i < 3; i++)
		putc(x[i]);

	/* check with local iterator w/o func call */
	for (int j = 0; j < 3; j++) {
		asm ("lio %0" : : "r"(x[j]));
		asm ("tyo");
	}

	/* check with local iterator w/ func call */
	for (int j = 0; j < 3; j++)
		putc(x[j]);

	asm ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm ("lio %0" : : "r"(c));
	asm ("tyo");
}
