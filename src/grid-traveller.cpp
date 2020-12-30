#include "grid-traveller.h"

#include <iostream>

using namespace std;

int grid_traveller_recursive(int rows, int cols)
{
    if (rows == 0 || cols == 0) return 0;
    if (rows == 1 && cols == 1) return 1;

    return grid_traveller_recursive(rows - 1, cols) + grid_traveller_recursive(rows, cols - 1);
}

template <int rows, int cols>
int grid_traveller_recursive_td(int row, int col, int (&table)[rows][cols])
{
    if(table[row][col] != -1) return table[row][col];
    if (row == 0 || col == 0) return 0;
    if (row == 1 && col == 1) return 1;

    table[row][col] = grid_traveller_recursive_td(row - 1, col, table)
                    + grid_traveller_recursive_td(row, col - 1, table);
    return table[row][col];
}

int grid_traveller_topdown(int rows, int cols)
{
    int table[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = -1;
        }
    }

    return grid_traveller_recursive(rows - 1, cols)
         + grid_traveller_recursive(rows, cols - 1);
}

int grid_traveller_bottomup(int rows, int cols)
{
    int table[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) table[i][j] = 0;
            else if (i == 0 || j == 0) table[i][j] = 1;
            else table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }

    return table[rows - 1][cols - 1];
}
