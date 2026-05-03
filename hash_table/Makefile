build:
	@gcc -o m.out main.c ./src/*.c -Wall -lm
vg:
	@valgrind --leak-check=yes ./m.out

all: build vg


.PHONY: build vg all
