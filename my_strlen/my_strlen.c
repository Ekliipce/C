#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t len = 0;

    if (s == NULL)
        return 0;

    while (s[len] != 0)
        len++;
    return len;
}
