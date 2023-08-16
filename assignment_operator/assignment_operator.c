#include <stddef.h>

void plus_equal(int *a, int *b)
{
    if (a && b)
    {
        int n = *a;
        *a = *b + n;
    }
}

void minus_equal(int *a, int *b)
{
    if (a && b)
    {
        int n = *a;
        *a = n - *b;
    }
}

void mult_equal(int *a, int *b)
{
    if (a && b)
    {
        int n = *a;
        *a = n * (*b);
    }
}

int div_equal(int *a, int *b)
{
    if (!a || !b || *b == 0)
        return 0;

    int n = *a;
    int r = n % *b;
    *a = n / *b;

    return r;
}
