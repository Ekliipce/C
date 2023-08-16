#include <criterion/criterion.h>

#include "my_itoa.h"

Test(simple, one_digit)
{
    char *s = malloc(1);
    s = my_itoa(1, s);
    cr_assert_str_eq(s, "1");
    free(s);
}

Test(simple, five_digit)
{
    char *s = malloc(5);
    s = my_itoa(12345, s);
    cr_assert_str_eq(s, "12345");
    free(s);
}

Test(simple, negative_digit)
{
    char *s = malloc(2);
    s = my_itoa(-1, s);
    cr_assert_str_eq(s, "-1");
    free(s);
}

Test(simple, negative_digits)
{
    char *s = malloc(6);
    s = my_itoa(-12345, s);
    cr_assert_str_eq(s, "-12345");
    free(s);
}
