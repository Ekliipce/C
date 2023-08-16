#include <stddef.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    int *ptr = malloc(sizeof(int) * size);
    for (size_t i = 0; i < size; i++)
        ptr[i] = init;

    return ptr;
}
