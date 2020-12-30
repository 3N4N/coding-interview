#include "fibonacci.h"
#include "build-order.h"
#include "binary-knapsack.h"
#include "find-duplicates.h"
#include "int-to-roman.h"
#include "matrix-product.h"
#include "median-sorted-arrays.h"
#include "priority-queue.h"
#include "grid-traveller.h"
#include "can-sum.h"
#include "how-sum.h"

#include <iostream>
#include <list>


using namespace std;

#define HOW_SUM

void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}

#ifdef BINARY_KNAPSACK
int main()
{
    int weights[] = {1, 2, 3};
    int values[] = {6, 10, 12};
    int max_weight = 5;
    int n = sizeof(values) / sizeof(values[0]);
    bool dp = true;

    cout << "Binary Knapsack w/ recursion   : " << binary_knapsack(weights, values, n, 5, !dp) << "\n";
    cout << "Binary Knapsack w/ DP          : " << binary_knapsack(weights, values, n, 5, dp) << "\n";

    return 0;
}
#endif      // BINARY_KNAPSACK

#ifdef FIBONACCI
int main()
{
    cout << "Fibonacci w/ recursion:   " << fibonacci_recursive(5) << "\n";
    cout << "Fibonacci w/ memoization: " << fibonacci_topdown(50) << "\n";
    cout << "Fibonacci w/ tabulation:  " << fibonacci_bottomup(50) << "\n";

    return 0;
}
#endif      // FIBONACCI

#ifdef BUILD_ORDER
int main()
{
    int rows = 5;
    int cols = 4;

    int deps[rows][cols] = { {-1, -1, -1, -1},
                      { 0, -1, -1, -1},
                      { 0, -1, -1, -1},
                      { 1,  2, -1, -1},
                      { 3, -1, -1, -1}};

    int **dependencies = new int*[rows];
    for (int i = 0; i < rows; i++)
        dependencies[i] = new int[cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            dependencies[i][j] = deps[i][j];
        }
    }

    list<int> order = build_order(dependencies, rows, cols);

    list<int>::iterator itr;
    for (itr = order.begin(); itr != order.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\n";

    for (int i = 0; i < rows; i++)
        delete [] dependencies[i];
    delete [] dependencies;

    return 0;
}

#endif      // BUILD_ORDER

#ifdef FIND_DUPLICATES

int main()
{
    int size = 4;
    int arr[size] = {2, 1, 2, 1};
    set<int> duplicates = find_duplicates(arr, size);

    set<int>::iterator itr;
    for (itr = duplicates.begin(); itr != duplicates.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\n";

    return 0;
}

#endif      // FIND_DUPLICATES

#ifdef INT_TO_ROMAN

int main()
{
    int numeral = 49;

    cout << numeral << " = " << int_to_roman(numeral) << "\n";

    return 0;
}

#endif      // INT_TO_ROMAN

#ifdef MATRIX_PRODUCT

int main()
{
    int mat[][3] = {-1, 2, 3, 4, 5, -6, 7, 8, 9};
    int rows = sizeof(mat)/sizeof(mat[0]);
    int cols = sizeof(mat[0])/sizeof(mat[0][0]);

    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            matrix[i][j] = mat[i][j];
        }
    }

    cout << "Max Product : " << mat_prod(matrix, rows, cols) << "\n";
    for (int i = 0; i < rows; i++)
        delete [] matrix[i];
    delete [] matrix;

    return 0;
}

#endif      // MATRIX_PRODUCT

#ifdef ARRAYS_MEDIAN
int main()
{
    bool recurse = true;

    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {0,0,0,0,10,10};
    cout << "Median: " << find_median(arr1, arr2, 6, 6, !recurse) << "\n";
    cout << "Median: " << find_median(arr1, arr2, 6, 6, recurse) << "\n";

    // int arr1[2] = {2, 3};
    // int arr2[2] = {0,10};
    // cout << "Median: " << find_median(arr1, arr2, 2, 2, !recurse) << "\n";
    // cout << "Median: " << find_median(arr1, arr2, 2, 2, recurse) << "\n";

    // int arr1[1] = {2};
    // int arr2[2] = {0,10};
    // cout << "Median: " << find_median(arr1, arr2, 1, 2, !recurse) << "\n";
    // cout << "Median: " << find_median(arr1, arr2, 1, 2, recurse) << "\n";

    return 0;
}
#endif      // ARRAYS_MEDIAN


#ifdef PRIORITY_QUEUE

int main()
{
    PriorityQueue pq(20);
    pq.insert(6);
    pq.insert(7);
    pq.insert(3);
    pq.insert(4);
    pq.insert(6);
    pq.insert(8);

    int size = pq.heap[0];

    cout << "Enqueue: ";
    for (int i = 1; i <= size; i++) {
        cout << pq.heap[i];
        i == size ? cout << "\n" : cout << ", ";
    }

    cout << "Dequeue: ";
    for (int i = 1; i <= size; i++) {
        cout << pq.remove();
        i == size ? cout << "\n" : cout << ", ";
    }

    return 0;
}

#endif      // PRIORITY_QUEUE

#ifdef GRID_TRAVELLER

int main()
{
    int rows = 3;
    int cols = 3;
    cout << "Grid traveller w/ recursion  : " << grid_traveller_recursive(rows, cols) << "\n";
    cout << "Grid traveller w/ memoization: " << grid_traveller_topdown(rows, cols) << "\n";
    cout << "Grid traveller w/ tabulation : " << grid_traveller_bottomup(rows, cols) << "\n";
    return 0;
}

#endif      // GRID_TRAVELLER

#ifdef CAN_SUM

int main()
{

    // int target = 7;
    // int size = 2;
    // int arr[] = { 2, 3 };

    // int target = 7;
    // int size = 4;
    // int arr[] = { 5, 3, 4, 7 };

    // int target = 7;
    // int size = 2;
    // int arr[] = { 2, 4 };

    // int target = 8;
    // int size = 3;
    // int arr[] = { 2, 3, 5 };

    int target = 300;
    int size = 2;
    int arr[] = { 7, 14 };

    // cout << (can_sum_recursive(target, arr, size) ? "True" : "False") << "\n";
    cout << (can_sum_topdown(target, arr, size) ? "True" : "False") << "\n";
    cout << (can_sum_bottomup(target, arr, size) ? "True" : "False") << "\n";

    return 0;
}

#endif      // CAN_SUM


#ifdef HOW_SUM

int main()
{

    int target = 7;
    int size = 2;
    int arr[] = { 2, 3 };

    // int target = 7;
    // int size = 4;
    // int arr[] = { 5, 3, 4, 7 };

    // int target = 7;
    // int size = 2;
    // int arr[] = { 2, 4 };

    // int target = 8;
    // int size = 3;
    // int arr[] = { 2, 3, 5 };

    // int target = 300;
    // int size = 2;
    // int arr[] = { 7, 14 };


    list<int> sum_list;
    sum_list = how_sum_topdown(target, arr, size);
    showlist(sum_list);
    sum_list = how_sum_bottomup(target, arr, size);
    showlist(sum_list);

    return 0;
}

#endif      // HOW_SUM
