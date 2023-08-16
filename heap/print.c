#include <stdio.h>

#include "heap.h"

void mini_atoi(int n)
{
    if (n < 10)
        putchar('0' + n);
    else
    {
        mini_atoi(n / 10);
        putchar('0' + n % 10);
    }
}

void _print_heap(const struct heap *heap, size_t i)
{
    if (i >= heap->size)
        return;

    if (i != 0)
        putchar(' ');
    mini_atoi(heap->array[i]);

    _print_heap(heap, 2 * i + 1);
    _print_heap(heap, 2 * i + 2);
}

void print_heap(const struct heap *heap)
{
    _print_heap(heap, 0);
    putchar('\n');
}
