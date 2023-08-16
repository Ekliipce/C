#include <stdio.h>

int main(void)
{
    char letter = 'a';
    for (size_t i = 0; i < 26; i++)
    {
        putchar(letter + i);
        if (i < 25)
            putchar(' ');
    }
    putchar('\n');

    return 0;
}
