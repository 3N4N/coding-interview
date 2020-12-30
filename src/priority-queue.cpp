#include "priority-queue.h"

#include <iostream>
#include <algorithm>
#include <stdbool.h>
#include <map>
#include <set>
#include <list>

using namespace std;

PriorityQueue::PriorityQueue(int size)
{
    heap = new int[size];
    heap[0] = 0;
}

PriorityQueue::~PriorityQueue()
{
    if(heap) delete[] heap;
}

void PriorityQueue::insert(int val)
{
    int idx = ++heap[0];
    heap[idx] = val;

    sift_up(idx);
}

int PriorityQueue::remove()
{
    int retval = heap[1];
    int len = heap[0]--;
    swap(heap[1], heap[len]);
    heap[len] = 0;

    sift_down(1);
    return retval;
}

void PriorityQueue::sift_up(int idx)
{
    int parent = idx / 2;
    if (idx > 1 && heap[idx] > heap[parent]) {
        swap(heap[idx], heap[parent]);
        sift_up(parent);
    }
}

void PriorityQueue::sift_down(int idx)
{
    if (idx > heap[0]) return;
    int lchild = idx * 2;
    int rchild = idx * 2 + 1;
    if (heap[idx] < heap[lchild] || heap[idx] < heap[rchild]) {
        int child = heap[lchild] > heap[rchild] ? lchild : rchild;
        swap(heap[idx], heap[child]);
        sift_down(child);
    }
}
