#include <stddef.h>
#include <stdio.h>

static void tower_print(char first, char second)
{
    putchar(first);
    putchar('-');
    putchar('>');
    putchar(second);
    putchar('\n');
}

static void tower(unsigned n, char first, char second, char third)
{
    if (n == 1)
        tower_print(first, second);
    else
    {
        tower(n - 1, first, third, second);
        tower(1, first, second, third);
        tower(n - 1, third, second, first);
    }
}

void hanoi(unsigned n)
{
    char first_tower = '1';
    char second_tower = '2';
    char third_tower = '3';

    tower(n, first_tower, third_tower, second_tower);
}
