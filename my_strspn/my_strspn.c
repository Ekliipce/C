#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    for (; s[i] != '\0'; i++)
    {
        size_t j = 0;
        for (; accept[j] != '\0'; j++)
        {
            if (s[i] == accept[j])
                break;
        }

        if (accept[j] == '\0')
            return i;
    }

    return i;
}