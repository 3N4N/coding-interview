#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <algorithm>
#include <stdbool.h>
#include <map>
#include <set>
#include <list>

class PriorityQueue {
public:
    int *heap;

    PriorityQueue(int size);
    ~PriorityQueue();
    void insert(int val);
    int remove();
    void sift_up(int idx);
    void sift_down(int idx);
};


#endif      // PRIORITY_QUEUE_H
