CC=gcc
CFLAGS=-I.
SRC=src
BUILD=build
MAIN=main.c

all: $(SRC)/main.c
	mkdir -p build
	$(CC) -o $(BUILD)/riemann_sum $(SRC)/$(MAIN)

run: riemann_sum
	make all
	$(BUILD)/./riemann_sum

clear: 
	rm -f $(BUILD)/*.o $(BUILD)/riemann_sum