#include "find-duplicates.h"

#include <iostream>
#include <stdbool.h>
#include <map>
#include <set>
#include <list>

using namespace std;

set<int> find_duplicates( int *arr, int size)
{

    /*
     * Since the array is of positive numbers,
     * we can encode the array indices with additional info,
     * e.g., multiplying the arr[i] with -1 if i was found
     * in the array, so that the next time we find i,
     * we can check arr[i] and see if it's negative.
     * If it's negative, it was already found and so is duplicate.
     */

    set<int> duplicates;

    for (int i = 0; i < size; i++) {
        // NOTE: Notice the use of abs().
        int idx = abs(arr[i]);
        if (arr[idx - 1] < 0) duplicates.insert(arr[i]);
        else arr[idx - 1] = -1 * arr[idx - 1];
    }

    return duplicates;
}
