#include <stddef.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet)
        return 1;

    int occ;

    for (size_t i = 0; alphabet[i] != '\0'; i++)
    {
        occ = 0;

        for (size_t k = 0; str[k] != '\0'; k++)
        {
            if (str[k] == alphabet[i])
                occ++;
        }

        if (occ == 0)
            return 0;
    }

    return 1;
}
