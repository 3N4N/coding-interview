#include "median-sorted-arrays.h"

#include <iostream>
#include <stdbool.h>

using namespace std;

float find_median_brute(int *arr1, int *arr2, int size1, int size2);
float find_median_recurse(int *arr1, int *arr2, int size1, int size2);

float find_median(int *arr1, int *arr2, int size1, int size2, bool recurse)
{
    if (recurse) return find_median_recurse(arr1, arr2, size1, size2);
    return find_median_brute(arr1, arr2, size1, size2);
}

float find_median_brute(int *arr1, int *arr2, int size1, int size2)
{
    int size = size1 + size2;
    int *arr = new int[size];
    int m = 0;
    int n = 0;

    for (int i = 0; i < size1 + size2; i++) {
        arr[i] = arr1[m] < arr2[n] ? arr1[m++] : arr2[n++];
    }

    int idx = (size % 2) ? size / 2 : size / 2 - 1;
    return (size % 2) ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

float find_median_recurse(int *arr1, int *arr2, int size1, int size2)
{
    float med1, med2;
    int idx1, idx2, start1, start2;

    if (size1 <= 2 || size2 <= 2) return find_median_brute(arr1, arr2, size1, size2);

    idx1 = (size1 % 2) ? size1 / 2 : size1 / 2 - 1;
    idx2 = (size2 % 2) ? size2 / 2 : size2 / 2 - 1;
    med1 = (size1 % 2) ? arr1[idx1] : (arr1[idx1] + arr1[idx1 + 1]) / 2.0;
    med2 = (size2 % 2) ? arr2[idx2] : (arr2[idx2] + arr2[idx2 + 1]) / 2.0;

    if (med1 == med2 ) return med1;

    size1 = (size1 % 2) ? idx1 + 1 : idx1 + 1 + 1;
    size2 = (size2 % 2) ? idx2 + 1 : idx2 + 1 + 1;
    start1 = (med1 > med2) ? 0 : idx1;
    start2 = (med2 > med1) ? 0 : idx2;

    return find_median_recurse(arr1 + start1, arr2 + start2, size1, size2);
}
