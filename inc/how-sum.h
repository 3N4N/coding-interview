#ifndef HOW_SUM_H
#define HOW_SUM_H

#include <cstdbool>
#include <list>

#include "trival.h"

std::list<int> how_sum_topdown(int target, int *arr, int size);
std::list<int> how_sum_bottomup(int target, int *arr, int size);

#endif      // HOW_SUM_H
