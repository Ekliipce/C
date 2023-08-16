#include <stddef.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static int pivot_choice(int len)
{
    if (len >= 2)
        return len / 2;
    else
        return 0;
}

static int partition(int *tab, int len)
{
    int pivot = pivot_choice(len);
    int j = 0;

    swap(tab + pivot, tab + len - 1);

    for (int i = 0; i < len - 1; i++)
    {
        if (tab[i] <= tab[len - 1])
        {
            swap(tab + i, tab + j);
            j++;
        }
    }

    swap(tab + len - 1, tab + j);

    return j;
}

void quicksort(int *tab, int len)
{
    if (!tab || len <= 1)
        return;

    int pivot = 0;

    pivot = partition(tab, len);
    quicksort(tab, pivot);
    quicksort(tab + pivot, len - pivot);
}
