#ifndef ListNode_H
#define ListNode_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
    void printList();
    void deleteList();
};

#endif      // ListNode_H
