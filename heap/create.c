#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *new = malloc(sizeof(struct heap));
    if (!new)
        return NULL;

    new->size = 0;
    new->capacity = 8;
    new->array = malloc(sizeof(int) * new->capacity);

    return new;
}
