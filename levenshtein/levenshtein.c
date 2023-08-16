#include <stddef.h>

static int min(int a, int b, int c)
{
    int min;
    if (a <= b && a <= c)
        min = a;
    else if (b <= a && b <= c)
        min = b;
    else
        min = c;

    return min;
}

static size_t my_strlen(const char *str)
{
    size_t len = 0;
    for (; str[len] != '\0'; len++)
        continue;

    return len;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len = my_strlen(s1) + 1;
    size_t len2 = my_strlen(s2) + 1;

    unsigned int arr[(len2 + 1)][(len + 1)];

    arr[0][0] = 0;

    for (size_t i = 1; i <= len2; i++)
        arr[i][0] = arr[(i - 1)][0] + 1;
    for (size_t j = 1; j <= len; j++)
        arr[0][j] = arr[0][j - 1] + 1;

    for (size_t i = 1; i <= len2; i++)
    {
        for (size_t j = 1; j <= len; j++)
        {
            int add = 1;
            if (s1[j - 1] == s2[i - 1])
                add = 0;

            int a = arr[(i - 1)][j];
            int b = arr[i][(j - 1)];
            int c = arr[(i - 1)][j - 1];

            arr[i][j] = min(a + 1, b + 1, c + add);
        }
    }

    return arr[len2][len];
}
