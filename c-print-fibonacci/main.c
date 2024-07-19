static void putc(int);
static void puti(int);
static int fib(int);

/* TODO: this sample fails to compile on higher -O values */

void main(void)
{
	int n;

	for (int i = 0; i < 20; i++) {
		puti(fib(i));
		putc(033);
	}
}

static void putc(int c)
{
	asm volatile ("lio %0" : : "r"(c) : "$io");
	asm volatile ("tyo");
}

/* TODO: this is printing out digits in reverse order; fix it */
static void puti(int i)
{
	int mod;

	do {
		mod = i % 10;
		putc((mod == 0) ? 020 : mod);
		i /= 10;
	} while (i != 0);
}

static int fib(int n)
{
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}
