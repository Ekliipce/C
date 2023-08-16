CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99
OBJ=dlist-t1.c dlist-t2.c dlist-t3.c

library: lib
	ar csr libdlist.a -c *.o

lib:
	${CC} ${CFLAGS} -c ${OBJ}

clean:
	${RM} *.o libdlist.a
