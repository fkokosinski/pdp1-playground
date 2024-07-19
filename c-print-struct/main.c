static void putc(int);

static struct {
	int field1;
	char field2;
	short field3;
} x;

void main(void)
{
	x.field1 = 027;
	x.field2 = 030;
	x.field3 = 031;

	putc(x.field1);
	putc(x.field2);
	putc(x.field3);
}

static void putc(int c) {
	asm volatile ("lio %0" : : "r"(c) : "$io");
	asm volatile ("tyo");
}
