#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

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

static int *fill_arr(struct dlist *list)
{
    int *arr = malloc(sizeof(int) * list->size);
    struct dlist_item *curr = list->head;

    for (size_t i = 0; i < list->size; i++)
        arr[i] = 0;

    int i = 0;
    while (curr)
    {
        arr[i] = curr->data;
        i++;
        curr = curr->next;
    }

    return arr;
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    int *tab1 = fill_arr(list1);
    int *tab2 = fill_arr(list2);

    size_t len = list1->size;
    size_t len2 = list2->size;

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
            if (tab1[j - 1] == tab2[i - 1])
                add = 0;

            int a = arr[(i - 1)][j];
            int b = arr[i][(j - 1)];
            int c = arr[(i - 1)][j - 1];

            arr[i][j] = min(a + 1, b + 1, c + add);
        }
    }

    free(tab1);
    free(tab2);

    return arr[len2][len];
}
