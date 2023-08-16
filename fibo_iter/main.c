#include <stdio.h>

unsigned long fibo_iter(unsigned long n);

int main(void)
{
    for (size_t i = 0; i < 100; i++)
        printf("%ld : %ld\n", i, fibo_iter(i));
}
