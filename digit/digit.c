#include <stddef.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;

    unsigned int digit = 0;

    for (int i = 0; i < k - 1; i++)
        n /= 10;
    digit = n % 10;

    return digit;
}
