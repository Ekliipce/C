#include <stddef.h>
#include <stdio.h>

unsigned long fact(unsigned n)
{
    unsigned long fact = 1;

    if (n == 0)
        return 1;
    for (size_t i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
