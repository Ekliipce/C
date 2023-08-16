#include <stdio.h>

size_t levenshtein(const char *s1, const char *s2);

int main(void)
{
    const char *s1 = "pain au chocolat";
    const char *s2 = "chocolatine";

    printf("leven(%s, %s) = %ld\n", s2, s1, levenshtein(s1, s2));
    return 0;
}
