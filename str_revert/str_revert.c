#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t len = 0;

    if (!s)
        return 0;

    while (s[len] != 0)
        len++;
    return len;
}

void str_revert(char str[])
{
    char tmp;
    size_t len = my_strlen(str) - 1;
    for (size_t i = 0; i < (len + 1) / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
    }
}
