#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return l;

    new->data = e;
    new->next = l;

    return new;
}

struct list *list_find(struct list *l, int e)
{
    struct list *curr = l;

    while (curr)
    {
        if (curr->data == e)
            return curr;

        curr = curr->next;
    }

    return NULL;
}

struct list *list_remove(struct list *l, int e)
{
    if (!l)
        return NULL;

    struct list *curr = l;

    if (curr->data == e)
    {
        struct list *tmp = curr->next;
        free(curr);
        return tmp;
    }

    while (curr->next)
    {
        if (curr->next->data == e)
        {
            struct list *tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
            return l;
        }

        curr = curr->next;
    }

    return l;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (!l || e > l->data)
        return list_add(l, e);

    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return l;

    new->data = e;
    new->next = NULL;

    struct list *curr = l;

    while (curr->next && curr->next->data > e)
        curr = curr->next;

    new->next = curr->next;
    curr->next = new;

    return l;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (!l)
        return NULL;

    struct list *curr = l;

    if (predicate(curr->data) == 1)
    {
        struct list *tmp = curr->next;
        free(curr);
        return list_remove_if(tmp, predicate);
    }

    while (curr->next)
    {
        if (predicate(curr->next->data) == 1)
            curr->next = list_remove(curr->next, curr->next->data);
        curr = curr->next;
    }

    return l;
}
