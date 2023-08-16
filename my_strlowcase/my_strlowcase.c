#include <stddef.h>

void my_strlowcase(char *str)
{
    int add = 'A' - 'a';
    for (size_t i = 0; str[i] != 0; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] -= add;
    }
}
