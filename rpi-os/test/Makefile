#Compiler options
CC=arm-none-eabi-gcc
CFLAGS=-O0 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -Wall -nostartfiles -g
LDFLAGS=-T linker.ld
#SRC=src/main.c
SRC=src/$(wildcard *.c)
OBJ=obj/main.o
#OBJ=onj/$(SRC:.c=.o)
EXEC=kernel

all: $(EXEC)

kernel: $(OBJ)
	arm-none-eabi-ld $(LDFLAGS) -o debug/$(EXEC).elf crt0.o $(OBJ)
	arm-none-eabi-objcopy debug/$(EXEC).elf -O binary $(EXEC).img

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -o $@ -c $<

disassemble:
	arm-none-eabi-objdump -d debug/$(EXEC).elf > debug/$(EXEC).list
	arm-none-eabi-nm -v debug/$(EXEC).elf > debug/$(EXEC).nm #Sort by addresses

clean:
	rm -rf debug/
	rm -rf obj/
	mkdir debug obj/