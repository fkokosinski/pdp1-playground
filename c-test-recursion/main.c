static void putc();

static void foo(int);

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm volatile ("law 03000");
	asm volatile ("dac 0131");
	asm volatile ("law 04000");
	asm volatile ("dac 0130");

	foo(20);

	asm volatile ("hlt");
	__builtin_unreachable();
}

static void putc() {
	asm volatile ("lio %0" :  : "r"(027) : "$io");
	asm volatile ("tyo");
}

static void foo(int n)
{
	if (n != 0) {
		putc();
		foo(n - 1);
	}
}
