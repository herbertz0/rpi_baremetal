#include <inttypes.h>
#include "gpio.h"
#include "uart.h"
#define GPPUD (GPIO_BASE + 0x94)
#define GPPUDCLK0 (GPIO_BASE + 0x98)

void register_write(unsigned int* reg, uint32_t data)
{
    *reg = data;
}

uint32_t register_read(unsigned int* reg)
{
    return *reg;
}

void uart_putc(unsigned char byte)
{
	while ( register_read(UART0_FR) & (1 << 5) ) { }
	register_write(UART0_DR, byte);
}

unsigned char uart_getc()
{
    // Wait for UART to have recieved something.
    while ( register_read(UART0_FR) & (1 << 4) ) { }
    return register_read(UART0_DR);
}

static inline void delay(int32_t count)
{
	asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
		 : : [count]"r"(count) : "cc");
}

void uart_init()
{
    register_write(UART0_CR, 0x00); // Disable uart
	// Disable pull up/down for all GPIO pins & delay for 150 cycles.
//	register_write((unsigned int*)GPPUD, 0x00000000);
//	delay(150);

	// Disable pull up/down for pin 14,15 & delay for 150 cycles.
//	register_write((unsigned int*)GPPUDCLK0, (1 << 14) | (1 << 15));
//	delay(150);

	// Write 0 to GPPUDCLK0 to make it take effect.
//	register_write((unsigned int*)GPPUDCLK0, 0x00000000);
//    register_write(UART0_ICR, 0x7FF); // Clear interrupts

    // Set integer & fractional part of baud rate.
	// Divider = UART_CLOCK/(16 * Baud)
	// Fraction part register = (Fractional part * 64) + 0.5
	// UART_CLOCK = 3000000; Baud = 115200.

	// Divider = 3000000 / (16 * 115200) = 1.627 = ~1.
	// Fractional part register = (.627 * 64) + 0.5 = 40.6 = ~40.
//	register_write(UART0_IBRD, 1);
//	register_write(UART0_FBRD, 40);

	// Enable FIFO & 8 bit data transmissio (1 stop bit, no parity).
//	register_write(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));

	// Mask all interrupts.
//	register_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

	// Enable UART0, receive & transfer part of UART.
//	register_write(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}

void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags )
{


    uart_putc('c');
    while (1);
}
