#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t k = 0; k < n - i - 1; k++)
            putchar(' ');
        for (size_t j = 0; j < 2 * i + 1; j++)
            putchar('*');
        putchar('\n');
    }

    for (size_t i = 0; i < n / 2; i++)
    {
        for (size_t k = 0; k < n - 1; k++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }

    return 0;
}
