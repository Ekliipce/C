#include "complex.h"

struct complex neg_complex(struct complex a)
{
    struct complex z = {
        .real = -a.real,
        .img = -a.img,
    };

    return z;
}

struct complex add_complex(struct complex a, struct complex b)
{
    float a1 = a.real;
    float b1 = a.img;
    float c = b.real;
    float d = b.img;

    struct complex z = { .real = a1 + c, .img = b1 + d };

    return z;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    float a1 = a.real;
    float b1 = a.img;
    float c = b.real;
    float d = b.img;

    struct complex z = { .real = a1 - c, .img = b1 - d };

    return z;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    float a1 = a.real;
    float b1 = a.img;
    float c = b.real;
    float d = b.img;

    struct complex z = { .real = a1 * c - b1 * d, .img = a1 * d + c * b1 };

    return z;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float a1 = a.real;
    float b1 = a.img;
    float c = b.real;
    float d = b.img;

    struct complex z = { .real = (a1 * c + b1 * d) / (c * c + d * d),
                         .img = (b1 * c - a1 * d) / (c * c + d * d) };

    return z;
}
