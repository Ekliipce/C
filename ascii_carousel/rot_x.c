#include <stddef.h>

static void pos_x(char *s, int x)
{
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            if (s[i] + x > 'z')
                s[i] = (s[i] + x - 'z' - 1) + 'a';
            else
                s[i] = s[i] + x;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (s[i] + x > 'Z')
                s[i] = (s[i] + x - 'Z' - 1) + 'A';
            else
                s[i] += x;
        }
    }
}

static void neg_x(char *s, int x)
{
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            if (s[i] + x < 'a')
                s[i] = 'z' - ('a' - s[i] - x - 1);
            else
                s[i] += x;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (s[i] + x < 'A')
                s[i] = 'Z' - ('A' - s[i] - x + 1);
            else
                s[i] += x;
        }
    }
}

void rot_x(char *s, int x)
{
    if (!s)
        return;

    if (x > 0)
        pos_x(s, x);
    else
        neg_x(s, x);
}
