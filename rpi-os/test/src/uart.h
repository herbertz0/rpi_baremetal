#ifndef RPI_UART_H
#define RPI_UART_H

    #define UART0_DR      (unsigned int*) 0x2020100
    #define UART0_RSRECR  (unsigned int*) 0x2020104
    #define UART0_FR      (unsigned int*) 0x2020118
    #define UART0_ILPR    (unsigned int*) 0x2020120
    #define UART0_IBRD    (unsigned int*) 0x2020124
    #define UART0_FBRD    (unsigned int*) 0x2020128
    #define UART0_LCRH    (unsigned int*) 0x202012c
    #define UART0_CR      (unsigned int*) 0x2020130
    #define UART0_IFLS    (unsigned int*) 0x2020134
    #define UART0_IMSC    (unsigned int*) 0x2020138
    #define UART0_RIS     (unsigned int*) 0x202013c
    #define UART0_MIS     (unsigned int*) 0x2020140
    #define UART0_ICR     (unsigned int*) 0x2020144
    #define UART0_DMACR   (unsigned int*) 0x2020148
    #define UART0_ITCR    (unsigned int*) 0x2020180
    #define UART0_ITIP    (unsigned int*) 0x2020184
    #define UART0_ITOP    (unsigned int*) 0x2020188
    #define UART0_TDR     (unsigned int*) 0x202018c

#endif
