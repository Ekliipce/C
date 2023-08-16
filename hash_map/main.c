#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "hash_map.h"

int main(void)
{
    struct hash_map *hash = hash_map_init(6);
    hash_map_dump(hash);

    bool updated = true;
    hash_map_insert(hash, "ski", "winter", &updated);
    assert(updated == false);
    hash_map_insert(hash, "ski", "winter2", &updated);
    assert(updated == true);

    hash_map_insert(hash, "vim", "winter", NULL);

    hash_map_insert(hash, "greater", "winter", NULL);
    hash_map_insert(hash, "acu", "love", NULL);
    hash_map_insert(hash, "cry", "winter", NULL);
    hash_map_insert(hash, "fr", "winter2", NULL);
    hash_map_insert(hash, "eng", "winter", NULL);
    hash_map_insert(hash, "killl", "winter", NULL);
    hash_map_insert(hash, "fromagee", "winter", NULL);
    hash_map_insert(hash, "fromagee", "winter2", NULL);

    hash_map_dump(hash);

    printf("search = %s\n", hash_map_get(hash, "fr"));
    if (!hash_map_get(hash, "splif"))
        printf("no exist\n");

    hash_map_remove(hash, "ski");
    hash_map_remove(hash, "cry");

    hash_map_dump(hash);

    printf("\n");
    hash_map_remove(hash, "greater");
    hash_map_remove(hash, "greaterrrrrrr");
    hash_map_remove(hash, "killl");
    hash_map_remove(hash, "fr");
    hash_map_remove(hash, "acu");
    hash_map_remove(hash, "eng");
    hash_map_remove(hash, "vim");

    hash_map_dump(hash);

    hash_map_free(hash);

    return 0;
}
