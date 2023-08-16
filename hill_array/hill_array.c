#include <stddef.h>

int top_of_the_hill(int tab[], size_t len)
{
    int king = 0;
    int i = 0;

    while (tab[i] > king)
    {
        king = tab[i];
        i++;
    }

    for (size_t k = i - 1; k < len - 1; k++)
    {
        if (tab[k] < tab[k + 1])
            return -1;
    }

    return i - 1;
}
