#include "hash_map.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct hash_map *hash_map_init(size_t size)
{
    if (size == 0)
        return NULL;

    struct hash_map *new = malloc(sizeof(struct hash_map));
    if (!new)
        return NULL;

    new->data = calloc(size, sizeof(struct pair_list *));
    if (!new->data)
        return NULL;

    new->size = size;
    return new;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map || hash_map->size == 0)
        return;

    struct pair_list *tmp = NULL;
    struct pair_list *curr = NULL;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        tmp = hash_map->data[i];
        while (tmp)
        {
            curr = tmp->next;
            free(tmp);
            tmp = curr;
        }
    }

    free(hash_map->data);
    free(hash_map);
}

static size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}

static int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    size_t size = (len1 > len2) ? len1 : len2;

    for (size_t i = 0; i < size; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        else
            continue;
    }

    return 0;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    size_t index = hash(key) % hash_map->size;

    struct pair_list *tmp = hash_map->data[index];
    while (tmp)
    {
        if (my_strcmp(key, tmp->key) == 0)
        {
            tmp->value = value;
            if (updated)
                *updated = true;
            return true;
        }
        tmp = tmp->next;
    }

    struct pair_list *new = malloc(sizeof(struct pair_list));
    if (!new)
        return false;
    new->key = key;
    new->value = value;

    new->next = hash_map->data[index];
    hash_map->data[index] = new;

    if (updated)
        *updated = false;

    return true;
}

const char *hash_map_get(const struct hash_map *hash_table, const char *key)
{
    if (!hash_table || hash_table->size == 0)
        return NULL;

    struct pair_list *curr = NULL;
    size_t index = hash(key) % hash_table->size;
    curr = hash_table->data[index];
    while (curr)
    {
        if (curr->key == key)
            return curr->value;
        curr = curr->next;
    }

    return NULL;
}

void free_list(struct pair_list *list)
{
    if (!list)
        return;
    free_list(list->next);
    free(list);
}

bool hash_map_remove(struct hash_map *hash_tab, const char *key)
{
    if (!hash_tab || hash_tab->size == 0)
        return false;

    size_t index = hash(key) % hash_tab->size;
    struct pair_list *curr = hash_tab->data[index];

    if (curr)
    {
        if (curr->key == key)
        {
            hash_tab->data[index] = curr->next;
            free(curr);
            return true;
        }

        while (curr->next)
        {
            struct pair_list *tmp = curr->next->next;
            if (curr->next->key == key)
            {
                free(curr->next);
                curr->next = tmp;
                return true;
            }
            curr = curr->next;
        }
    }

    return false;
}
