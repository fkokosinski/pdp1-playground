/* initialized global var */
int x = 027;

/* unitialized global var - gcc should emit `.skip` */
int y;

void main(void)
{
	asm volatile ("lio %0" : : "r"(x) : "$io");
	asm volatile ("tyo");

	y = 027;
	asm volatile ("lio %0" : : "r"(y) : "$io");
	asm volatile ("tyo");
}
