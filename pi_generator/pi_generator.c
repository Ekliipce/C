#include <stddef.h>

double pi_generator(int precision)
{
    double pi = 1;
    for (double i = precision; i > 0; i--)
    {
        pi *= i / (i * 2 + 1);
        pi += 1;
    }
    return pi * 2;
}
