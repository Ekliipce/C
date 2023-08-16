#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrice_size, int **out)
{
    size_t m = matrice_size[0];
    size_t n = matrice_size[1];
    size_t p = matrice_size[2];

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < p; j++)
        {
            out[i][j] = 0;
            for (size_t k = 0; k < n; k++)
                out[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}
