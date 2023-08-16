#include <assert.h>
#include <stddef.h>

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *stk = data;
    const char *tmp = key;

    for (size_t i = 0; i < data_len; i++)
        stk[i] += (tmp[i % key_len]);
}
