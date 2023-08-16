#include <stddef.h>

int my_atoi(const char *str)
{
    int res = 0;
    int is_neg = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            continue;

        if (str[i] == '-')
        {
            if (str[i + 1] == ' ' || str[i + 1] == '-' || str[i + 1] == '+')
                return 0;
            else
            {
                is_neg = 1;
                continue;
            }
        }

        if (str[i] == '+')
        {
            if (str[i + 1] == ' ' || str[i + 1] == '-' || str[i + 1] == '+')
                return 0;
            else
                continue;
        }

        if ('0' <= str[i] && str[i] <= '9')
        {
            if (str[i + 1] == ' ')
                return 0;
            else
                res = res * 10 + str[i] - '0';
        }
        else
            return 0;
    }

    if (is_neg == 0)
        return res;
    return -res;
}