#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;

    int count = 0;
    long *arr = calloc(n, sizeof(long));
    if (!arr)
        return;

    long nprime = 2;
    for (; nprime * nprime <= n - 1; nprime++)
    {
        for (int j = nprime * nprime; j <= n - 1; j += nprime)
            arr[j] = 1;
    }

    for (int i = 2; i <= n - 1; i++)
    {
        if (arr[i] == 0)
            count++;
    }

    printf("%d\n", count);
    free(arr);
}
