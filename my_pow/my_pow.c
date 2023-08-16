#include <stddef.h>

int my_pow(int a, int b)
{
    int pow = 1;
    if (b == 0)
        return pow;
    else if (b == 1)
        return a;

    if (b % 2 == 0)
        pow = my_pow(a, b / 2) * my_pow(a, b / 2);
    else
        pow = a * my_pow(a, b / 2) * my_pow(a, b / 2);
    return pow;
}
