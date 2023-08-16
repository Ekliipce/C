#include "int_vector_bubble_sort.h"

#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;

    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    size_t size = vec.size;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (vec.data[j + 1] < vec.data[j])
                vec = swap(vec, j, j + 1);
        }
    }

    return vec;
}
