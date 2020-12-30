#include "how-sum.h"

#include <iostream>
#include <list>

using namespace std;

bool _how_sum_topdown(int target, int *arr, int size, list<int> *table[])
{
    if (target == 0) return true;
    if (target < 0) return false;
    if (table[target] != nullptr)
        return true;
    int remainder;

    for (int i = 0; i < size; i++) {
        remainder = target - arr[i];
        if (_how_sum_topdown(remainder, arr, size, table) == true) {
            if (table[target] == nullptr) {
                table[target] = new list<int>();
            }
            if (remainder != 0) {
                list<int>::iterator itr;
                for (itr = table[remainder]->begin();
                     itr != table[remainder]->end();
                     itr++) {
                    table[target]->push_back(*itr);
                }
            }
            table[target]->push_back(arr[i]);
            return true;
        }
    }

    return false;
}

list<int> how_sum_topdown(int target, int *arr, int size)
{
    list<int> *table[target + 1];
    for (int i = 0; i <= target; i++) {
        table[i] = nullptr;
    }

    _how_sum_topdown(target, arr, size, table);

    list<int> retlist;

    if (table[target] != nullptr) {
        list<int>::iterator itr;
        for (itr = table[target]->begin(); itr != table[target]->end(); itr++) {
            retlist.push_back(*itr);
        }
    }

    for (int i = 0; i <= target; i++) {
        delete table[i];
    }

    return retlist;
}

list<int> how_sum_bottomup(int target, int *arr, int size)
{
    /** Table storing results of sub-problems.*/
    list<int> table[target + 1];

    for (int i = 0; i <= target; i++) {
        /* If the current entry is empty,
         * then it's already invalid.
         * But if the current entry is for target=0,
         * then the entry is valid even though its empty,
         * because we can make 0 by summing zero elements
         * from an given set of numbers.*/
        if (i != 0 && table[i].empty()) continue;
        for (int j = 0; j < size; j++) {
            if (!table[i + arr[j]].empty()) continue;
            if (i + arr[j] <= target) {
                list<int>::iterator itr;
                for (itr = table[i].begin(); itr != table[i].end(); itr++)
                    table[i + arr[j]].push_back(*itr);
                table[i + arr[j]].push_back(arr[j]);
            }
        }
    }

    return table[target];
}
