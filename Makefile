CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: midpoint

dist:
	mkdir -p Farid-Farajli-hpc-assignment4
	cp midpoint.c Makefile plot.py Farid-Farajli-hpc-assignment4
	tar -cf Farid-Farajli-hpc-assignment4.tar Farid-Farajli-hpc-assignment4
	gzip Farid-Farajli-hpc-assignment4.tar
	rm -rf Farid-Farajli-hpc-assignment4

clean:
	rm -rf midpoint Farid-Farajli-hpc-assignment4.tar.gz

.PHONY: all clean dist
