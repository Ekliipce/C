#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int count_words(const char *file_in)
{
    if (file_in == NULL)
        return -1;

    FILE *f = fopen(file_in, "r");
    if (f == NULL)
        return -1;

    int count = 0;
    int getc = fgetc(f);

    while ((getc = fgetc(f)) != EOF)
    {
        if (getc != ' ' && getc != '\n' && getc != '\t')
        {
            count++;
            while ((getc != ' ' && getc != '\n' && getc != '\t')
                   && (getc != EOF))
                getc = fgetc(f);
        }
    }

    if (fclose(f) == EOF)
        return -1;

    return count;
}
