CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

all: midpoint

midpoint: midpoint.o
	${CC} -o $@ midpoint.o -lm

dist:
	mkdir -p Farid-Farajli-hpc-assignment4
	cp midpoint.c Makefile plot.py Farid-Farajli-hpc-assignment4
	tar -cf Farid-Farajli-hpc-assignment4.tar Farid-Farajli-hpc-assignment4
	gzip Farid-Farajli-hpc-assignment4.tar
	rm -rf Farid-Farajli-hpc-assignment4

clean:
	rm -rf *.o midpoint Farid-Farajli-hpc-assignment4.tar.gz

.PHONY: all clean dist
