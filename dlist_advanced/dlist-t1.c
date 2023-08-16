#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *new = malloc(sizeof(struct dlist));
    if (!new)
        return NULL;

    new->size = 0;
    new->head = NULL;
    new->tail = new->head;

    return new;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (!list || element < 0)
        return 0;

    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;
    new->prev = NULL;
    new->data = element;

    if (!list->head)
        new->next = NULL;
    else
    {
        list->head->prev = new;
        new->next = list->head;
    }

    list->head = new;
    list->size++;

    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    if (!list)
        return 0;
    return list->size;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *curr = list->head;

    while (curr)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (!list || element < 0)
        return 0;

    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;
    new->next = NULL;
    new->prev = list->tail;
    new->data = element;

    if (!list->tail)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        list->tail->next = new;
        list->tail = new;
    }

    list->size++;

    return 1;
}
