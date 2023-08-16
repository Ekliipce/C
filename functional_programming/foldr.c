#include <stddef.h>

#include "functional_programming.h"

int foldr_rec(int *array, size_t len, int (*func)(int, int), size_t n)
{
    if (n == len - 1)
        return func(array[n], 0);

    return func(array[n], foldr_rec(array, len, func, n + 1));
}

int foldr(int *array, size_t len, int (*func)(int, int))
{
    return foldr_rec(array, len, func, 0);
}
