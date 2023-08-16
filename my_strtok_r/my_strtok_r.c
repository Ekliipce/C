#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

static size_t my_strspn(const char *s, const char *accept)
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

static const char *my_strchr(const char *s, int c)
{
    char c2 = c;
    while (*s != c2)
    {
        if (!*s)
            return NULL;
        s++;
    }

    return s;
}

static size_t cspn(const char *s1, const char *s2)
{
    size_t spn = 0;
    while (*s1)
    {
        if (my_strchr(s2, *s1))
            return spn;
        else
        {
            s1++;
            spn++;
        }
    }

    return spn;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *tmp;

    if (str == NULL)
        str = *saveptr;

    if (str[0] == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    tmp = str + cspn(str, delim);
    if (*tmp == '\0')
    {
        *saveptr = tmp;
        return str;
    }

    *tmp = '\0';
    *saveptr = tmp + 1;

    return str;
}
