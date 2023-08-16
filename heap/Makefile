CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99
OBJ=create.c add.c del.c pop.c print.c
LDLIBS=-fsanitize=address -g

library: lib
	ar csr libheap.a -c *.o

lib:
	${CC} ${CFLAGS} -c ${OBJ}

debug: ${OBJ} main.c
	${CC} ${CFLAGS} ${OBJ} main.c -o debug ${LDLIBS}

clean:
	${RM} *.o libdlist.a debug
