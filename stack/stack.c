#include "stack.h"

#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new = malloc(sizeof(struct stack));
    if (!new)
        return NULL;
    new->data = e;
    new->next = s;

    return new;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
        return NULL;

    struct stack *tmp = s->next;
    free(s);

    return tmp;
}

int stack_peek(struct stack *s) { return s->data; }
