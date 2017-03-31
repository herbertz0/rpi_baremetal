#Compiler options
CC=arm-none-eabi-gcc
CFLAGS=-O0 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -Wall -nostartfiles -g
SRC=src/cstartup.c src/boot.s
OBJ=obj/cstartup.o obj/boot.o
EXEC=crt0.o

all: crt0.o

crt0.o: $(OBJ)
	arm-none-eabi-ld -r $(LDFLAGS) -o crt0.o obj/boot.o obj/cstartup.o

obj/boot.o:
	$(CC) $(CFLAGS) -o obj/boot.o -c src/boot.s

obj/cstartup.o:
	$(CC) $(CFLAGS) -o obj/cstartup.o -c src/cstartup.c

clean:
	rm -rf obj/
	mkdir obj

