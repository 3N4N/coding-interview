#ifndef ListNode_H
#define ListNode_H

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
    void printList();
};

#endif      // ListNode_H
