#include <stddef.h>
#include <stdlib.h>

int lca(int *values, int lenght, int p, int q)
{
    int root = values[0];
    int index_p;
    int index_q;
    int i = 0;

    for (int j = 0; j < lenght; j++)
    {
        if (values[j] == p)
            index_p = j;
        if (values[j] == q)
            index_q = j;
    }

    int *ancestor_q = calloc(sizeof(int), lenght);
    int *ancestor_p = calloc(sizeof(int), lenght);

    int curr_q = values[index_q];
    int curr_p = values[index_p];
    int lca = values[index_q];
    while (curr_q != root)
    {
        ancestor_q[i] = values[index_q];
        index_q = (index_q - 1) / 2;
        curr_q = values[index_q];
        i++;
    }

    int h = 0;
    while (curr_p != root)
    {
        ancestor_p[h] = values[index_p];
        index_p = (index_p - 1) / 2;
        curr_p = values[index_p];
        h++;
    }

    for (int j = 0; j < h; j++)
    {
        lca = ancestor_p[j];
        for (int k = 0; k < i; k++)
        {
            if (lca == ancestor_q[k])
            {
                free(ancestor_q);
                free(ancestor_p);

                return lca;
            }
        }
    }

    free(ancestor_q);
    free(ancestor_p);

    return root;
}
