static void putc(int);
static void puti(int);
static int fib(int);

/* TODO: this sample fails to compile on higher -O values */

#define F_DIGITS	20
#define LCOMMA		033
#define SPACE		0
#define LZERO		020
#define LMINUS		054

void main(void)
{
	int n;

	for (int i = 0; i < F_DIGITS ; i++) {
		puti(fib(i));
		if (i < F_DIGITS - 1) {
			putc(LCOMMA);
			putc(SPACE);
		}
	}
}

static void putc(int c)
{
	asm volatile ("lio %0" : : "r"(c) : "$io");
	asm volatile ("tyo");
}

static void puti(int num)
{
	if (num == 0) {
		putc(LZERO);
		return;
	}

	/* handle negative numbers */
	if (num < 0) {
		putc(LMINUS);
		num = -num;
	}

	/* calculate how many digits */
	int divisor = 1;
	while (num / divisor >= 10)
		divisor *= 10;

	/* print digits from most sig to least sig */
	while (divisor > 0) {
		int digit = num / divisor;
		/* 0 is non-ASCII */
		putc((digit == 0) ? LZERO : digit);

		num %= divisor;
		divisor /= 10;
	}
}

static int fib(int n)
{
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}
