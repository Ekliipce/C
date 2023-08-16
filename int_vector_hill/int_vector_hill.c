#include "int_vector_hill.h"

#include <stddef.h>

int int_vector_hill(struct int_vector vec)
{
    int king = 0;
    int i = 0;

    while (vec.data[i] > king)
    {
        king = vec.data[i];
        i++;
    }

    for (size_t k = i; k < vec.size - 1; k++)
    {
        if (vec.data[k] < vec.data[k + 1])
            return -1;
    }

    return i - 1;
}
