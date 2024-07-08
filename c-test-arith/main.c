int x = 21;
int y = 37;

void _start(void)
{
	/* TODO: handle sp/fp init better -- separate crt0.S? */
	asm volatile ("law 03000");
	asm volatile ("dac 0131");
	asm volatile ("law 04000");
	asm volatile ("dac 0130");

	/* test addition with two variables */
	*(volatile int *)(01000) = x + y;

	/* test addition with an immediate value */
	*(volatile int *)(01001) = x + 20;

	/* test addition with an immediate value equal 1 */
	*(volatile int *)(01002) = x + 1;

	/* test subtraction with two variables */
	*(volatile int *)(01003) = y - x;

	/* test subtraction with an immediate value */
	*(volatile int *)(01004) = y - 10;

	/* test multiplication with two variables */
	*(volatile int *)(01005) = x * y;

	/* test division with two variables */
	*(volatile int *)(01006) = y / x;

	/* test modulo with two variables */
	*(volatile int *)(01007) = y % x;

	/* test logical negation with a variable */
	*(volatile int *)(01010) = ~x;

	/* test logical and with two variables */
	*(volatile int *)(01011) = x & y;

	/* test logical and with an immediate value */
	*(volatile int *)(01012) = x & 12;

	/* test logical or with two variables */
	*(volatile int *)(01013) = x | y;

	/* test logical or with an immediate value */
	*(volatile int *)(01014) = x | 12;

	/* test logical xor with two variables */
	*(volatile int *)(01015) = x ^ y;

	/* test logical xor with an immediate value */
	*(volatile int *)(01016) = x ^ 12;

	/* test shift left */
	*(volatile int *)(01016) = x << 6;

	/* test shift right */
	*(volatile int *)(01017) = x >> 3;

	asm volatile ("hlt");
	__builtin_unreachable();
}
