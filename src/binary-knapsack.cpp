#include "binary-knapsack.h"

#include <iostream>

using namespace std;

int binary_knapsack_recursive(int *weights, int *values, int n, int max_weight);
int binary_knapsack_dynamic(int *weights, int *values, int n, int max_weight);

int binary_knapsack(int *weights, int *values, int idx, int max_weight, bool dp)
{
    if (dp) return binary_knapsack_dynamic(weights, values, idx, max_weight);
    return binary_knapsack_dynamic(weights, values, idx, max_weight);
}

int binary_knapsack_recursive(int *weights, int *values, int idx, int max_weight)
{
    /* idx points to the current item being considered*/

    if (idx == 0 || max_weight == 0) return 0;

    /*
     * If the weight of an item if greater than the maximum capacity
     * of the knapsack, then we can't carry it.
     */
    if (weights[idx - 1] > max_weight)
        return binary_knapsack_recursive(weights, values, idx - 1, max_weight);

    /*
     * For each item we find out if the total value
     * is greater if we take that item or if we leave it.
     */
    return max(values[idx - 1] +
               binary_knapsack_recursive(weights, values, idx-1, max_weight - weights[idx - 1]),
               binary_knapsack_recursive(weights, values, idx-1, max_weight));
}

int binary_knapsack_dynamic(int *weights, int *values, int n, int max_weight)
{
    int W = max_weight;
    int table[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (weights[i - 1] > max_weight)
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(values[i - 1] + table[i - 1][j - weights[i - 1]],
                                  table[i - 1][W]);
#ifdef DEBUG
            cout << table[i][j] << " ";
#endif
        }
#ifdef DEBUG
        cout << "\n";
#endif
    }

    return table[n][W];
}
