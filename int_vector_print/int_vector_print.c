#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    size_t i;
    for (i = 0; i < vec.size; i++)
    {
        if (i < vec.size - 1)
            printf("%d ", vec.data[i]);
        else
            printf("%d", vec.data[vec.size - 1]);
    }
    printf("\n");
}
