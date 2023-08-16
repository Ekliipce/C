#include <stddef.h>

unsigned long fibo_iter(unsigned long n)
{
    unsigned long f1 = 0;
    unsigned long f2 = 1;
    unsigned long fn = f1 + f2;

    while (n--)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    return f1;
}
