build:
	@gcc -o main -Wall -Werror -Wextra ./main.c ./binary_tree.c ./binary_tree.h
vg:
	@valgrind --leak-check=yes ./main

all: build vg

.PHONY: build vg
