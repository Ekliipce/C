#include <stddef.h>

static size_t my_strlen(const char *s)
{
    size_t len = 0;

    if (!s)
        return 0;

    while (s[len] != '\0')
        len++;
    return len;
}

int palindrome(const char *s)
{
    if (!s)
        return 0;

    size_t len = my_strlen(s);
    size_t j = len - 1;

    if (len == 0)
        return 1;

    for (size_t i = 0; i < j; i++, j--)
    {
        while (!('a' <= s[i] && s[i] <= 'z') && !('A' <= s[i] && s[i] && 'Z')
               && !('0' <= s[i] && s[i] <= '9'))
            i++;
        while (!('a' <= s[j] && s[j] <= 'z') && !('A' <= s[j] && s[j] && 'Z')
               && !('0' <= s[i] && s[i] <= '9'))
            j--;
        if (s[i] != s[j])
            return 0;
    }

    return 1;
}
