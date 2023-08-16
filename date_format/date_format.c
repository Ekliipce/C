#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *date_format(const char *format)
{
    int i = 0;
    int len = 0;
    int tab[3] = { 0, 0, 0 };
    char *cpy = strdup(format);
    char *token;
    char *ptr = NULL;
    char r[1024] = { 0 };
    sprintf(r, "%s", format);
    time_t t = time(NULL);
    struct tm *date = gmtime(&t);

    for (; format[len] != '\0'; len++)
        ;
    if (len != 5)
    {
        free(cpy);
        return NULL;
    }

    char *result = malloc(sizeof(char) * 20);
    token = strtok_r(r, ":;,-_", &ptr);
    while (token)
    {
        if (token[0] == 'M')
            tab[i] = date->tm_mon + 1;
        else if (token[0] == 'D')
            tab[i] = date->tm_mday;
        else if (token[0] == 'Y')
            tab[i] = date->tm_year + 1900;
        else
        {
            free(cpy);
            free(token);
            return NULL;
        }

        token = strtok_r(NULL, ":;,-_", &ptr);
        i++;
    }

    sprintf(result, "%02d%c%02d%c%02d", tab[0], cpy[1], tab[1], cpy[3], tab[2]);

    free(cpy);
    free(token);

    return result;
}
