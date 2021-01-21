#include "ListNode.h"
#include <iostream>

ListNode::ListNode()
{
    val = 0;
    next = nullptr;
}

ListNode::ListNode(int val)
{
    this->val = val;
    this->next = nullptr;
}

ListNode::ListNode(int val, ListNode *next)
{
    this->val = val;
    this->next = next;
}

void ListNode::printList()
{
    ListNode *lptr = this;

    while(lptr != nullptr) {
        std::cout << lptr->val << ' ';
        lptr = lptr->next;
    }

    std::cout << '\n';
}

void ListNode::deleteList()
{
    ListNode *curr = this;
    ListNode *prev;

    while(curr != nullptr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}
