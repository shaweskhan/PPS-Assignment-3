/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int** matrixReshape(int** mat, int matSize,
                    int* matColSize, int r, int c,
                    int* returnSize, int** returnColumnSizes) {

    int m = matSize;
    int n = matColSize[0];

    if (m * n != r * c) {
        *returnSize = m;

        *returnColumnSizes = malloc(m * sizeof(int));

        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
        }

        return mat;
    }

    int** result = malloc(r * sizeof(int*));

    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < m * n; i++) {
        result[i / c][i % c] = mat[i / n][i % n];
    }

    return result;
}
