static void putc();

static void foo(int);

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm ("law 03000");
	asm ("dac 209");
	asm ("law 04000");
	asm ("dac 208");

	foo(20);

	asm ("hlt");
	__builtin_unreachable();
}

static void putc() {
	asm ("lio %0" :  : "r"(027) : "io");
	asm ("tyo");
}

static void foo(int n)
{
	if (n != 0) {
		putc();
		foo(n - 1);
	}
}
