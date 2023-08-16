#include <stdio.h>
#include <stdlib.h>

int *zigzag(size_t n)
{
    if (n == 0)
        return NULL;
    int *arr = calloc(n * n, sizeof(int));

    size_t i = 0;
    size_t j = 0;
    size_t xmax = n - 1;
    int count = 1;

    while (j != xmax || i != xmax)
    {
        if ((i == 0 || i == n - 1) && j != xmax)
        {
            arr[i * n + j++ + 1] = count++;

            if (i == 0)
            {
                while (j != 0)
                    arr[(i++ + 1) * n + j-- - 1] = count++;
            }
            else if (i == xmax)
            {
                while (j != n - 1)
                    arr[(i-- - 1) * n + j++ + 1] = count++;
            }
        }

        else if ((j == 0 || j == n - 1) && i != xmax)
        {
            arr[(i++ + 1) * n + j] = count++;

            if (j == xmax)
            {
                while (i != xmax)
                    arr[(i++ + 1) * n + j-- - 1] = count++;
            }
            else if (j == 0)
            {
                while (i != 0)
                    arr[(i-- - 1) * n + j++ + 1] = count++;
            }
        }
    }

    return arr;
}
