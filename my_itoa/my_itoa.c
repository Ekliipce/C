#include <stddef.h>

static size_t my_strlen(char *s)
{
    int len = 0;
    for (; s[len] != 0; len++)
        ;
    return len;
}

static void reverse(char *s)
{
    char tmp;
    size_t len = my_strlen(s);
    for (size_t i = 0; i < len / 2; i++)
    {
        tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}

char *my_itoa(int value, char *s)
{
    int i = 0;
    int neg = 0;

    if (value == 0)
    {
        s[i] = '0';
        i++;
        s[i] = '\0';
        return s;
    }

    if (value < 0)
    {
        value = -value;
        neg++;
    }

    while (value != 0)
    {
        s[i] = '0' + value % 10;
        i++;
        value /= 10;
    }

    if (neg == 1)
    {
        s[i] = '-';
        i++;
    }

    s[i] = '\0';
    reverse(s);
    return s;
}
