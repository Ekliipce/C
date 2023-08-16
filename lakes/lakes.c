#include <stddef.h>
#include <stdlib.h>

void fill_lake(char **map, int i, int j)
{
    if (map[i][j] == '#')
        return;
    else if (map[i][j] == '.')
    {
        map[i][j] = '#';

        fill_lake(map, i + 1, j);
        fill_lake(map, i - 1, j);
        fill_lake(map, i, j - 1);
        fill_lake(map, i, j + 1);
    }
    return;
}

int lakes(char **map, int widht, int height)
{
    int count = 0;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < widht; j++)
            if (map[i][j] == '.')
            {
                fill_lake(map, i, j);
                count++;
            }

    return count;
}
