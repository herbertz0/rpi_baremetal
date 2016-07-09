/******************************************************************************
*	main.s taken from Alex Chadwick
*
******************************************************************************/

/*
* Convention dictates that the symbol _start is used for the 
* entry point, so this all has the net effect of setting the entry point here.
* Ultimately, this is useless as the elf itself is not used in the final 
* result, and so the entry point really doesn't matter, but it aids clarity,
* allows simulators to run the elf, and also stops us getting a linker warning
* about having no entry point. 
*/


.section .boot

.globl _start
_start:
	add r0, r1

