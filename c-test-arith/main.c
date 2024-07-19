int x = 21;
int y = 37;

void main(void)
{
	/* test addition with two variables */
	*(volatile int *)(02000) = x + y;

	/* test addition with an immediate value */
	*(volatile int *)(02001) = x + 20;

	/* test addition with an immediate value equal 1 */
	*(volatile int *)(02002) = x + 1;

	/* test subtraction with two variables */
	*(volatile int *)(02003) = y - x;

	/* test subtraction with an immediate value */
	*(volatile int *)(02004) = y - 10;

	/* test multiplication with two variables */
	*(volatile int *)(02005) = x * y;

	/* test division with two variables */
	*(volatile int *)(02006) = y / x;

	/* test modulo with two variables */
	*(volatile int *)(02007) = y % x;

	/* test logical negation with a variable */
	*(volatile int *)(02010) = ~x;

	/* test logical and with two variables */
	*(volatile int *)(02011) = x & y;

	/* test logical and with an immediate value */
	*(volatile int *)(02012) = x & 12;

	/* test logical or with two variables */
	*(volatile int *)(02013) = x | y;

	/* test logical or with an immediate value */
	*(volatile int *)(02014) = x | 12;

	/* test logical xor with two variables */
	*(volatile int *)(02015) = x ^ y;

	/* test logical xor with an immediate value */
	*(volatile int *)(02016) = x ^ 12;

	/* test shift left */
	*(volatile int *)(02017) = x << 6;

	/* test shift right */
	*(volatile int *)(02020) = x >> 3;
}
