#include <stdio.h>

#include "list.h"

void list_print(struct list *l)
{
    struct list *curr = l;
    while (curr)
    {
        if (curr->next)
            printf("%d ", curr->data);
        else
            printf("%d", curr->data);
        curr = curr->next;
    }

    printf("\n");
}
