#include <stddef.h>

static void _heapify(int *array, size_t i, size_t m)
{
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    size_t g = l;

    if (l < m && array[l] > array[i])
        g = l;
    else
        g = i;

    if (r < m && array[r] > array[g])
        g = r;

    if (g != i)
    {
        int tmp = array[i];
        array[i] = array[g];
        array[g] = tmp;
        _heapify(array, g, m);
    }
}

void heapify(int *array, size_t size)
{
    size_t n = 0;

    if (size > 1)
        n = (size / 2) - 1;

    size_t i = n;
    for (; i > 0; i--)
        _heapify(array, i, size);
    _heapify(array, i, size);
}

void heap_sort(int *array, size_t size)
{
    if (size < 1)
        return;

    heapify(array, size);
    for (size_t i = size - 1; i > 0; i--)
    {
        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;

        _heapify(array, 0, i);
    }
}
