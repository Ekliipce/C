#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    if (!list)
        return;

    struct dlist_item *curr = list->head;

    while (curr)
    {
        curr->data *= curr->data;
        curr = curr->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    if (!list)
        return;

    struct dlist_item *p1 = list->tail;
    struct dlist_item *p2 = list->head;

    while (p1 && p2 && p1 > p2)
    {
        int tmp = p1->data;
        p1->data = p2->data;
        p2->data = tmp;

        p1 = p1->prev;
        p2 = p2->next;
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (!list || list->size == 0)
        return dlist_init();

    struct dlist_item *curr = list->head;

    size_t i = 0;
    while (curr && i < index)
    {
        curr = curr->next;
        i++;
    }

    if (i == index && curr)
    {
        struct dlist_item *tmp = curr->prev;
        tmp->next = NULL;

        struct dlist *new = dlist_init();
        new->tail = list->tail;
        new->head = curr;
        new->size = list->size - i;
        list->size = i;

        curr->prev = NULL;

        return new;
    }
    else
        return NULL;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (!list1 && !list2)
        return;
    if (!list1)
    {
        list1 = list2;
        return;
    }

    for (struct dlist_item *curr = list2->head; curr; curr = list2->head)
    {
        dlist_push_back(list1, curr->data);
        dlist_remove_at(list2, 0);
    }
}
