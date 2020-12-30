#include "matrix-product.h"


#include <iostream>

using namespace std;

int mat_prod(int **mat, int rows, int cols)
{
    /*
     * We need to keep track of both max product and min products
     * because if the next entry is negative, multiplying with it
     * would produce a positive number.
     */
    int maxtab[rows][cols];
    int mintab[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) {
                maxtab[i][j] = mat[0][0];
                mintab[i][j] = mat[0][0];
            }
            else if (i == 0) {
                maxtab[i][j] = max(maxtab[i][j-1] * mat[i][j],
                                   mintab[i][j-1] * mat[i][j]);
                mintab[i][j] = min(maxtab[i][j-1] * mat[i][j],
                                   mintab[i][j-1] * mat[i][j]);
            }
            else if (j == 0) {
                maxtab[i][j] = max(maxtab[i-1][j] * mat[i][j],
                                   mintab[i-1][j] * mat[i][j]);
                mintab[i][j] = min(maxtab[i-1][j] * mat[i][j],
                                   mintab[i-1][j] * mat[i][j]);
            }
            else {
                maxtab[i][j] = max(max(maxtab[i-1][j] * mat[i][j],
                                       maxtab[i][j-1] * mat[i][j]),
                                   max(mintab[i-1][j] * mat[i][j],
                                       mintab[i][j-1] * mat[i][j]));
                mintab[i][j] = min(min(maxtab[i-1][j] * mat[i][j],
                                       maxtab[i][j-1] * mat[i][j]),
                                   min(mintab[i-1][j] * mat[i][j],
                                       mintab[i][j-1] * mat[i][j]));
            }
#ifdef DEBUG
            cout << "(" << maxtab[i][j] << "," << mintab[i][j] << "), ";
#endif
        }
#ifdef DEBUG
        cout << "\n";
#endif
    }

    return maxtab[rows - 1][cols - 1];
}
