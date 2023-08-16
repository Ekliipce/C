#include "fifo.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *new = malloc(sizeof(struct fifo));
    if (!new)
        return NULL;

    new->head = NULL;
    new->tail = new->head;
    new->size = 0;

    return new;
}

size_t fifo_size(struct fifo *fifo)
{
    size_t size = 0;
    struct list *curr = fifo->head;

    while (curr)
    {
        size++;
        curr = curr->next;
    }

    return size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    if (!fifo)
        return;

    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return;
    new->next = NULL;
    new->data = elt;

    if (!fifo->head)
        fifo->head = new;
    else
    {
        struct list *curr = fifo->head;
        while (curr->next)
            curr = curr->next;

        curr->next = new;
    }

    fifo->tail = new->next;
    fifo->size++;
}

int fifo_head(struct fifo *fifo) { return fifo->head->data; }

void fifo_pop(struct fifo *fifo)
{
    if (!fifo || fifo->size == 0)
        return;

    struct list *tmp = fifo->head;

    if (fifo->head->next)
    {
        fifo->head = fifo->head->next;
        free(tmp);
    }
    else
    {
        free(fifo->head);
        fifo->head = NULL;
    }

    fifo->size--;
}

void fifo_clear(struct fifo *fifo)
{
    if (!fifo || fifo->size == 0)
        return;

    struct list *curr = fifo->head;
    while (curr)
    {
        struct list *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    fifo->head = NULL;
    fifo->tail = fifo->head;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    if (!fifo)
        return;

    fifo_clear(fifo);
    free(fifo->head);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *curr = fifo->head;

    while (curr)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}
