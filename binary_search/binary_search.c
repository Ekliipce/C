#include <stddef.h>

int binary_search(const int vec[], size_t size, int elt)
{
    int index = -1;
    int min = 0;
    int max = size - 1;
    int mid = (max + min) / 2;

    while (elt != vec[mid] && min < max)
    {
        if (elt > vec[mid])
            min = mid + 1;
        else
            max = mid - 1;
        mid = min + (max - min) / 2;
    }

    if (elt == vec[mid])
        index = mid;

    return index;
}
