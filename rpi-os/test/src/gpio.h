#ifndef RPI_GPIO_H
#define RPI_GPIO_H
    #define GPIO_BASE   0x20200000UL

    #define GPFSEL0     (GPIO_BASE + 0x00)
    #define GPFSEL1     0x20200004UL//(GPIO_BASE + 0x04)
    #define GPFSEL2     (GPIO_BASE + 0x08)
    #define GPFSEL3     (GPIO_BASE + 0x0C)
    #define GPFSEL4     (GPIO_BASE + 0x10)
    #define GPFSEL5     (GPIO_BASE + 0x14)

    #define GPSET0      (GPIO_BASE + 0x1C)
    #define GPSET1      (GPIO_BASE + 0x20)

    #define GPCLR0      0x20200028UL//(GPIO_BASE + 0x28)
    #define GPCLR1      (GPIO_BASE + 0x2C)

    #define GPLEV0      (GPIO_BASE + 0x34)
    #define GPLEV1      (GPIO_BASE + 0x38)

    #define GPEDS0      (GPIO_BASE + 0x40)
    #define GPEDS1      (GPIO_BASE + 0x44)

    #define GPREN0      (GPIO_BASE + 0x4C)
    #define GPREN1      (GPIO_BASE + 0x50)

    #define GPFEN0      (GPIO_BASE + 0x58)
    #define GPFEN1      (GPIO_BASE + 0x5C)

    #define GPHEN0      (GPIO_BASE + 0x64)
    #define GPHEN1      (GPIO_BASE + 0x68)

    #define GPLEN0      (GPIO_BASE + 0x70)
    #define GPLEN1      (GPIO_BASE + 0x74)

    #define GPAREN0     (GPIO_BASE + 0x7C)
    #define GPAREN1     (GPIO_BASE + 0x80)

    #define GPAFEN0     (GPIO_BASE + 0x88)
    #define GPAFEN1     (GPIO_BASE + 0x8C)

    #define GPPUD       (GPIO_BASE + 0x94)

    #define GPPUDCLK0   (GPIO_BASE + 0x98)
    #define GPPUDCLK1   (GPIO_BASE + 0x9C)
#endif
