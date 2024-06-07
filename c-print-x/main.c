/* initialized global var */
int x = 027;

/* unitialized global var - gcc should emit `.skip` */
int y;

void _start(void)
{
	asm ("law 04000");
	asm ("dac 209");
	asm ("dac 208");

	asm ("lio %0" : : "r"(x));
	asm ("tyo");

	y = 027;
	asm ("lio %0" : : "r"(y));
	asm ("tyo");

	asm ("hlt");

	__builtin_unreachable();
}
