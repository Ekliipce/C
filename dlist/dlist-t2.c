#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(struct dlist *list, size_t index)
{
    if (!list)
        return -1;

    struct dlist_item *curr = list->head;

    size_t i = 0;
    while (curr && i < index)
    {
        curr = curr->next;
        i++;
    }

    if (i == index && curr)
        return curr->data;
    else
        return -1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (!list || element < 0)
        return -1;

    struct dlist_item *curr = list->head;

    size_t i = 0;
    if (index == 0)
        return dlist_push_front(list, element);

    while (curr && i < index - 1)
    {
        curr = curr->next;
        i++;
    }

    if (i == index - 1 && curr)
    {
        struct dlist_item *tmp = curr->next;
        struct dlist_item *new = malloc(sizeof(struct dlist_item));
        if (!new)
            return -1;
        new->data = element;
        new->next = tmp;
        new->prev = curr;

        curr->next = new;
        tmp->prev = new;
        list->size++;

        return 1;
    }
    else
        return -1;
}

int dlist_find(const struct dlist *list, int element)
{
    if (!list || list->size == 0)
        return -1;

    struct dlist_item *curr = list->head;

    int i = 0;
    while (curr)
    {
        if (curr->data == element)
            return i;

        curr = curr->next;
        i++;
    }

    return -1;
}

static int remove_first(struct dlist *list)
{
    int data = -1;
    struct dlist_item *tmp = list->head;
    if (!list->head)
        return -1;

    data = list->head->data;
    list->head = list->head->next;

    if (list->head)
        list->head->prev = NULL;

    free(tmp);
    list->size--;

    return data;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    int data = -1;
    if (!list)
        return data;

    struct dlist_item *curr = list->head;

    size_t i = 0;
    if (index == 0)
        return remove_first(list);

    while (curr && i < index)
    {
        curr = curr->next;
        i++;
    }

    if (i == index && curr)
    {
        data = curr->data;
        struct dlist_item *next = curr->next;
        struct dlist_item *prev = curr->prev;

        if (next)
            next->prev = prev;
        prev->next = next;

        free(curr);
        list->size--;
    }

    return data;
}
