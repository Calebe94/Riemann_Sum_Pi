CC=gcc
CFLAGS=-I.
MAIN=main.c

all: main.c
	$(CC) -o riemann_sum $(MAIN)

run: riemann_sum
	make all
	./riemann_sum

clear: 
	rm -f *.o riemann_sum