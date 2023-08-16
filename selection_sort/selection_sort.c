#include <stddef.h>

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned index_min = start;
    for (size_t i = start; i < size; i++)
    {
        if (arr[i] < arr[index_min])
            index_min = i;
    }

    return index_min;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
        return;

    unsigned index_min = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        index_min = array_min(arr, i, size);
        int tmp = arr[i];
        arr[i] = arr[index_min];
        arr[index_min] = tmp;
    }
}
