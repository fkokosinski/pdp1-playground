#define NL 077

char *one = "one";
char *two = "one";

static void my_putc(int c)
{
	asm volatile("lio %0" : : "r"(c) : "$io");
	asm volatile("tyo");
}

static int strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void main(void)
{
	if (!strcmp(one, two)) {
		my_putc(022);
		my_putc(061);
		my_putc(044);
		my_putc(065);
	} else {
		my_putc(064);
		my_putc(071);
		my_putc(066);
		my_putc(066);
	}

	my_putc(NL);
}
