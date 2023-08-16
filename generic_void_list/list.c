#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new_list = malloc(sizeof(struct list));
    if (new_list == NULL)
        return NULL;

    new_list->data = malloc(data_size);
    if (new_list->data == NULL)
    {
        free(new_list);
        return NULL;
    }

    memcpy(new_list->data, value, data_size);
    new_list->next = list;

    return new_list;
}

size_t list_length(struct list *list)
{
    if (list == NULL)
        return 0;

    int len = 1;
    struct list *curr = list;

    while (curr->next)
    {
        len++;
        curr = curr->next;
    }

    return len;
}

void list_destroy(struct list *list)
{
    if (list == NULL)
        return;

    struct list *curr = list;

    while (curr->next)
    {
        curr = curr->next;
        free(list->data);
        free(list);
        list = curr;
    }

    free(curr->data);
    free(curr);
}
