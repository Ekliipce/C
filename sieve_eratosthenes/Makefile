CC=gcc
CFLAGS=-Wall -g -Wextra -Werror -std=c99 -pedantic

all: sieve.o

sieve.o: sieve.c
	$(CC) $(CFLAGS) -c -o sieve.o sieve.c

clean:
	$(RM) sieve.o
