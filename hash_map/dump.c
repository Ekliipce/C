#include <stdio.h>

#include "hash_map.h"

void hash_map_dump(struct hash_map *hash)
{
    if (!hash || hash->size == 0)
        return;

    struct pair_list *curr = hash->data[0];
    for (size_t i = 0; i < hash->size; i++)
    {
        if (hash->data[i])
        {
            curr = hash->data[i];
            while (curr)
            {
                if (curr->next)
                    printf("%s: %s, ", curr->key, curr->value);
                else
                    printf("%s: %s", curr->key, curr->value);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}
