CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99

all: csv

csv: csv.o
	${CC} ${CFLAGS} -o $@ $^

clean:
	${RM} *.o