// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        return true;
    }
    return false;
    
}