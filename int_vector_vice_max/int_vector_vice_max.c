#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[1] > vec.data[0] ? vec.data[1] : vec.data[0];
    int vice = vec.data[1] < vec.data[0] ? vec.data[1] : vec.data[0];

    for (size_t i = 2; i < vec.size; i++)
    {
        if (max < vec.data[i])
        {
            vice = max;
            max = vec.data[i];
        }
    }

    return vice;
}
