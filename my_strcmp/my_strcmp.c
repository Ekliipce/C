#include <stddef.h>

static size_t my_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;

    return len;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    size_t size = 0;

    if (len1 < len2)
        size = len1;
    else
        size = len2;

    for (size_t i = 0; i < size; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        else
            continue;
    }

    if (len1 == len2)
        return 0;
    else
        return -1;
}
