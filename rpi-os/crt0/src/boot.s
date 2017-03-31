.section ".text.boot"

.global _start

// r0, r1 & r2 are reserved for kernel arguments so not used
_start:
    // Set the stack pointer
    mov sp, #0x8000

    // Clear .bss
	b _cstartup
