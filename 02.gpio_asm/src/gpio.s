/******************************************************************************
*	gpio.s
*
******************************************************************************/

// ACT LED: GPIO 16

// Constants: Manual p 90
.equ GPFSEL0, 0x20200000
.equ GPFSEL1, 0x20200004
.equ GPFSEL2, 0x20200008
.equ GPFSEL3, 0x2020000C
.equ GPFSEL4, 0x20200010
.equ GPFSEL5, 0x20200014

.equ GPSET0, 0x2020001C
.equ GPSET1, 0x20200020

.equ GPCLR0, 0x20200028
.equ GPCLR1, 0x2020002C

.equ FSEL16, 18


.global gpio_init_statusled
.global gpio_set_statusled
.global gpio_clear_statusled

// Sets the pin as output
gpio_init_statusled:
	ldr r0,=GPFSEL1
	ldr r1, [r0] // Load previous value

	// Clear bits
	mov r2, #0b111
	lsl r2, #FSEL16
	bic r1, r1, r2

	// Write new value
	mov r2, #1
	lsl r2, #FSEL16
	orr r1, r1, r2

	str r1, [r0]
	mov pc, lr

// Outputs logical 1
gpio_set_statusled:
	ldr r0, =GPSET0
	ldr r1, [r0] // Load previous value

	mov r2, #1
	lsl r2, #16
	orr r1, r1, r2

	str r1, [r0]
	mov pc, lr

// Outputs logical 0
gpio_clear_statusled:
	ldr r0, =GPCLR0
	ldr r1, [r0] // Load previous value

	mov r2, #1
	lsl r2, #16
	orr r1, r1, r2
	
	str r1, [r0]
	mov pc, lr
