#include <stddef.h>

static size_t my_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;

    return len;
}

static int is_equal(char c1, char c2)
{
    if ((('a' <= c1 && c1 <= 'z') || ('A' <= c1 && c1 <= 'Z'))
        && (('a' <= c2 && c2 <= 'z') || ('A' <= c2 && c2 <= 'Z')))
    {
        if (c1 == c2 || 'a' + c1 - 'A' == c2 || 'a' + c2 - 'A' == c1)
            return 1;
        else
            return 0;
    }
    return 0;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    size_t size = 0;

    if (len1 > len2)
        size = len1;
    else
        size = len2;

    for (size_t i = 0; i < size; i++)
    {
        if (is_equal(s1[i], s2[i]))
            continue;
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        else
            continue;
    }

    return 0;
}
