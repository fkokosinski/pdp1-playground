/* initialized global var */
int x = 027;

/* unitialized global var - gcc should emit `.skip` */
int y;

void _start(void)
{
	asm volatile ("law 04000");
	asm volatile ("dac 0131");
	asm volatile ("law 03000");
	asm volatile ("dac 0130");

	asm volatile ("lio %0" : : "r"(x) : "$io");
	asm volatile ("tyo");

	y = 027;
	asm volatile ("lio %0" : : "r"(y) : "$io");
	asm volatile ("tyo");

	asm volatile ("hlt");

	__builtin_unreachable();
}
