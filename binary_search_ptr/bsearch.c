#include <stddef.h>

int len(int *begin, int *end)
{
    int len = 0;
    for (int *p = begin; p < end; p++)
        len++;
    return len;
}

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
        return NULL;

    int *index = begin;
    int min = 0;
    int max = len(begin, end) - 1;
    int mid = min + (max - min) / 2;

    if (begin >= end && elt < *begin)
        return begin;
    if (elt > *(end - 1))
        return end;

    while (elt != begin[mid] && min < max)
    {
        if (elt > begin[mid])
            min = mid + 1;
        else
            max = mid - 1;
        mid = min + (max - min) / 2;
    }

    index = begin + mid;

    return index;
}
