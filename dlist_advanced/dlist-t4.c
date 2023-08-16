#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_clear(struct dlist *list)
{
    size_t size = list->size;
    for (size_t i = 0; i < size; i++)
        dlist_remove_at(list, 0);
}

void dlist_shift(struct dlist *list, int offset)
{
    if (!list || list->size < 2)
        return;

    if (offset > 0)
    {
        for (int i = 0; i < offset; i++)
        {
            struct dlist_item *tmp = list->tail;
            list->tail = list->tail->prev;
            list->tail->next = NULL;

            tmp->next = list->head;
            tmp->prev = NULL;
            list->head->prev = tmp;
            list->head = list->head->prev;
        }
    }
    else if (offset < 0)
    {
        for (int i = 0; i > offset; i--)
        {
            struct dlist_item *tmp = list->head;
            list->head = list->head->next;
            list->head->prev = NULL;

            tmp->prev = list->tail;
            tmp->next = NULL;
            list->tail->next = tmp;
            list->tail = list->tail->next;
        }
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list || element < 0)
        return -1;
    if (list->size == 0)
    {
        dlist_push_back(list, element);
        return 1;
    }

    size_t i = 0;
    struct dlist_item *curr = list->head;

    while (curr && curr->data < element)
    {
        i++;
        curr = curr->next;
    }

    if (!curr)
        dlist_push_back(list, element);
    else
        dlist_insert_at(list, element, i);

    return 1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list)
        return 0;

    size_t i = 0;
    struct dlist_item *curr = list->head;

    while (curr)
    {
        if (curr->data == element)
            break;
        i++;
        curr = curr->next;
    }

    if (curr)
    {
        dlist_remove_at(list, i);
        return 1;
    }
    else
        return 0;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (!list)
        return NULL;

    struct dlist *l2 = dlist_init();
    struct dlist_item *curr = list->head;

    while (curr)
    {
        dlist_push_back(l2, curr->data);
        curr = curr->next;
    }

    return l2;
}
