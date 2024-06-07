/* Simple asm program that prints out 'hello, world' on standard output */

.section .data
i:
	.skip 1, 0
ptr:
	.byte str
len:
	.byte end - str
str:
	/* TOOD: use .ascii-derived FIODEC directive here */
	.byte 070
	.byte 065
	.byte 043
	.byte 043
	.byte 046
	.byte 033
	.byte 000
	.byte 026
	.byte 046
	.byte 051
	.byte 043
	.byte 064
end:

.section .text
.global _start
_start:
	/* load IO register with *ptr and print it */
	lio.i ptr
	tyo

	/* ptr++, i++ */
	idx ptr
	idx i

	/* if (i == len) goto _start */
	lac i
	sas len
	jmp _start

	/* halt */
	hlt
