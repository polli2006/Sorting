app: prak7.o func.o
	gcc -o app prak7.o func.o
prak7.o: prak7.c
	gcc -c -m32 -o prak7.o prak7.c
func.o: func.asm
	nasm -f elf32 -o func.o func.asm
all: app
clean:
	rm prak7.o func.o app
