#define _GNU_SOURCE

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lign_max(char *lign)
{
    char *ptr = NULL;
    char *tmp = NULL;
    tmp = strtok_r(lign, ",", &ptr);
    int n = atoi(tmp);

    while (tmp != NULL)
    {
        int curr = atoi(tmp);
        if (curr > n)
            n = curr;

        tmp = strtok_r(NULL, ",", &ptr);
    }

    return n;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    char *lign = NULL;
    ssize_t read;
    size_t len = 0;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return 1;

    int i = 1;
    while ((read = getline(&lign, &len, file)) != -1)
    {
        printf("%d\n", lign_max(lign));
        i++;
    }

    free(lign);

    if (fclose(file) == EOF)
        return 1;

    return 0;
}