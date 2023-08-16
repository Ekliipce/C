#include "heap.h"
#include "stdlib.h"

static void heapify(struct heap *heap, size_t i, size_t m)
{
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    size_t g;

    if (l < m && heap->array[l] > heap->array[i])
        g = l;
    else
        g = i;

    if (r < m && heap->array[r] > heap->array[g])
        g = r;

    if (g != i)
    {
        int tmp = heap->array[i];
        heap->array[i] = heap->array[g];
        heap->array[g] = tmp;
        heapify(heap, g, m);
    }
}

void build_heap(struct heap *heap)
{
    size_t n;

    if (heap->size <= 1)
        n = 0;
    else
        n = (heap->size / 2) - 1;

    size_t i = n;
    for (; i > 0; i--)
        heapify(heap, i, heap->size);
    heapify(heap, i, heap->size);
}

void add(struct heap *heap, int val)
{
    if (!heap)
        return;

    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
        if (!heap)
            return;
    }

    heap->array[heap->size] = val;
    heap->size++;
    build_heap(heap);
}
