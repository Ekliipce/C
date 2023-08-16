#include <stdio.h>

#include "complex.h"

void print_complex(struct complex a)
{
    if (a.img < 0)
        printf("complex(%0.2f - %0.2fi)\n", a.real, -a.img);
    else
        printf("complex(%0.2f + %0.2fi)\n", a.real, a.img);
}
