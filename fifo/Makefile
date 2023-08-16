CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99
LDLIBS=-lasan

library: lib
	ar csr libfifo.a -c *.o

lib:
	${CC} ${CFLAGS} -c fifo.c

debug: CFLAGS+=-fsanitize=address -g
debug: fifo.c main.c
	${CC} ${CFLAGS} fifo.c main.c -o debug ${LDLIBS}



clean:
	${RM} *.o debug libfifo.a
