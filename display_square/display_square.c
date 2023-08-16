#include <stddef.h>
#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;

    if (width % 2 == 0)
        width++;

    if (width == 1)
    {
        putchar('*');
        putchar('\n');
        return;
    }

    for (int i = 0; i < width; i++)
        putchar('*');
    for (int i = 0; i < (width + 1) / 2 - 2; i++)
    {
        putchar('\n');
        putchar('*');
        for (int j = 0; j < width - 2; j++)
            putchar(' ');
        putchar('*');
    }
    putchar('\n');
    for (int i = 0; i < width; i++)
        putchar('*');
    putchar('\n');
}
