	.global _start
_start:
	# stack pointer
	law _stack_end
	dac 0131

	# jump to main
	jsp main

	# stop
	hlt
