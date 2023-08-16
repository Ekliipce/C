#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_sort(struct dlist *list)
{
    if (!list || list->size < 2)
        return;

    size_t n = list->size;

    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = 0; j < n - i - 1; j++)
        {
            struct dlist_item *curr_j = list->head;
            struct dlist_item *curr_k = list->head->next;
            for (size_t k = 0; k < j; k++)
            {
                curr_j = curr_j->next;
                curr_k = curr_k->next;
            }

            int a = dlist_get(list, j);
            int b = dlist_get(list, j + 1);
            if (a > b)
            {
                curr_j->data = b;
                curr_k->data = a;
            }
        }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_concat(list1, list2);
    dlist_sort(list1);
}
