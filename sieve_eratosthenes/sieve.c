#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n < 2)
        return;

    int arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = 0;

    int nprime = 2;
    for (; nprime <= n; nprime++)
    {
        for (int j = nprime * nprime; j <= n; j += nprime)
            arr[j] = 1;
        if (arr[nprime] == 0)
            printf("%d\n", nprime);
    }
}
