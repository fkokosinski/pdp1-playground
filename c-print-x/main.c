int x = 027;

void _start(void)
{
	asm ("law 04000");
	asm ("dac 209");
	asm ("dac 208");

	asm ("lio %0" : : "r"(x));
	asm ("tyo");

	asm ("hlt");

	__builtin_unreachable();
}
