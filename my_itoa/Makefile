cc=gcc
ccflags=-std=c99 -Werror -Wall -Wextra -pedantic
ldlibs=-lcriterion

test: test.o my_itoa.o
	$(cc) $(ldlibs)  test.o my_itoa.o -o test

test.o: test.c
	$(cc) $(ccflags) -c -o test.o test.c

my_itoa.o: my_itoa.c
	$(cc) $(ccflags) -c -o my_itoa.o my_itoa.c

clean:
	$(RM) test test.o my_itoa.o
