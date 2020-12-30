#ifndef CAN_SUM_H
#define CAN_SUM_H

#include <cstdbool>
#include "trival.h"

bool can_sum_recursive(int target, int *arr, int size);
bool can_sum_topdown(int target, int *arr, int size);
bool can_sum_bottomup(int target, int *arr, int size);

#endif      // CAN_SUM_H
