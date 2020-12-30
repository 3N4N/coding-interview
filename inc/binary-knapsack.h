#ifndef BINARY_KNAPSACK_H
#define BINARY_KNAPSACK_H

#include <iostream>
#include <cstdbool>

/**
 * Solves the binary knapsack problem.
 *
 * Given weights and values of n items,
 * put these items in a knapsack of capacity W
 * to get the maximum total value in the knapsack.
 *
 * \p size must be equal to the size of the arrays \p weights and \p values
 *
 * @param weights the array containing weights
 * @param values the array containing values
 * @param size the number of items
 * @param max_weight the capacity of the knapsack
 * @param dp whether to use dynamic programming or recursion
 * @return the maximum value bearable in the knapsack
 */
int binary_knapsack(int *weights, int *values, int size, int max_weight, bool dp);

#endif // BINARY_KNAPSACK_H
