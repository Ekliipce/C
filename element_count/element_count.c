#include <stddef.h>

size_t element_count(int *begin, int *end)
{
    size_t i = 0;
    for (int *p = begin; p < end; p++)
        i++;
    return i;
}
