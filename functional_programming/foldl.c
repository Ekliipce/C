#include <stddef.h>

#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    int sum = 0;
    for (size_t n = 0; n < len; n++)
        sum = func(sum, array[n]);

    return sum;
}
