#include "can-sum.h"

#include <iostream>
#include <list>

using namespace std;

bool can_sum_recursive(int target, int *arr, int size)
{
    if (target == 0) return true;
    if (target < 0) return false;
    int remainder;

    for (int i = 0; i < size; i++) {
        remainder = target - arr[i];
        if (can_sum_recursive(remainder, arr, size))
            return true;
    }
    return false;
}

bool mem_can_sum(int target, int *arr, int size, Trival *table)
{
    if (target == 0) return true;
    if (target < 0) return false;
    if (table[target] != Trival::nil) return table[target] == Trival::tru ? true : false;
    int remainder;

    for (int i = 0; i < size; i++) {
        remainder = target - arr[i];
        if (mem_can_sum(remainder, arr, size, table) == true) {
            table[target] = Trival::tru;
            return true;
        }
    }

    table[target] = Trival::fls;
    return false;
}

bool can_sum_topdown(int target, int *arr, int size)
{
    Trival table[target + 1];
    for (int i = 0; i <= target; i++)
        table[i] = Trival::nil;

    return mem_can_sum(target, arr, size, table);
}

bool can_sum_bottomup(int target, int *arr, int size)
{
    bool table[target + 1];
    for (int i = 0; i <= target; i++)
        table[i] = false;
    table[0] = true;

    for (int i = 1; i <= target; i++) {
        if (table[i] == false) continue;
        for (int j = 0; j < size; j++) {
            if (i + arr[j] <= target)
                table[i + arr[j]] = true;
        }
    }

    return table[target];
}
