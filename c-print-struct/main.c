static void putc(int);

static struct {
	int field1;
	char field2;
	short field3;
} x;

void _start(void)
{
	asm ("law 04000");
	asm ("dac 209");
	asm ("dac 208");

	x.field1 = 027;
	x.field2 = 030;
	x.field3 = 031;

	putc(x.field1);
	putc(x.field2);
	putc(x.field3);


	asm ("hlt");
	__builtin_unreachable();
}

static void putc(int c) {
	asm ("lio %0" : : "r"(c));
	asm ("tyo");
}
