#include <assert.h>

#include "heap.h"

int pop(struct heap *heap)
{
    if (!heap || heap->size == 0)
        assert(0);

    int max = heap->array[0];
    int tmp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->array[heap->size - 1] = tmp;
    heap->size--;
    build_heap(heap);

    return max;
}
