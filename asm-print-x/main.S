/* Simple asm program that prints out 'x' on standard output */

.section .data
x:
	/* 027 is 'x' in FIO DEC encoding */
	.byte 027

.section .text
.global main
main:
	/* load IO register with *x */
	lio x
	tyo

	/* halt */
	hlt
