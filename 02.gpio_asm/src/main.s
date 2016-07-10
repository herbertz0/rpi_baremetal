/******************************************************************************
*	main.s
******************************************************************************/


.section .boot

.globl _start
_start:
	bl gpio_init_statusled
	bl gpio_clear_statusled

halt:
	b halt
