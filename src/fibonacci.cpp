#include "fibonacci.h"


#include <iostream>

using namespace std;

uint64_t fibonacci_recursive(int n)
{
    return n == 1 || n == 2 ? 1 : fibonacci_recursive(n - 1)
                                + fibonacci_recursive(n - 2);
}

uint64_t _fibonacci_topdown(int n, uint64_t *table)
{
    if (table[n] != -1) return table[n];
    if (n == 1 || n == 2) return 1;
    table[n] = _fibonacci_topdown(n - 1, table)
                + _fibonacci_topdown(n - 2, table);

    return table[n];
}

uint64_t fibonacci_topdown(int n)
{
    uint64_t table[n + 1];
    for (int i = 0; i < n+1; i++) table[i] = -1;
    return _fibonacci_topdown(n, table);
}

uint64_t fibonacci_bottomup(int n)
{
    uint64_t table[n];
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i < n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }

    return table[n - 1];
}


