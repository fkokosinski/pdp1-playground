static void putc();

static void foo(int);

void main(void)
{
	foo(20);
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
