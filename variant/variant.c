#include "variant.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left->type == right->type)
    {
        if (left->type == TYPE_INT && left->value.int_v == right->value.int_v)
            return true;
        else if (left->type == TYPE_FLOAT
                 && left->value.float_v == right->value.float_v)
            return true;
        else if (left->type == TYPE_CHAR
                 && left->value.char_v == right->value.char_v)
            return true;
        else if (left->type == TYPE_STRING
                 && strcmp(left->value.str_v, right->value.str_v) == 0)
            return true;
        else
            return false;
    }
    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type != type)
            continue;

        if (array[i].value.int_v == value.int_v
            || array[i].value.float_v == value.float_v
            || array[i].value.char_v == value.char_v
            || strcmp(array[i].value.str_v, value.str_v) == 0)
            return i;
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_FLOAT)
            sum += array[i].value.float_v;
        else if (array[i].type == TYPE_INT)
            sum += array[i].value.int_v;
        else
            continue;
    }

    return sum;
}
