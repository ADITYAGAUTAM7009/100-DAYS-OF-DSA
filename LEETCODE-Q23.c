/*
PROBLEM : Linked List Cycle
NAME : Aditya Gautam
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of singly linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while ((fast != NULL) && (fast->next != NULL)) {
        fast = fast->next->next;  // move 2 steps
        slow = slow->next;        // move 1 step

        if (fast == slow) {
            return true;          // cycle found
        }
    }
    return false;                 // no cycle
}

int main() {
    // Create nodes
    struct ListNode *a = malloc(sizeof(struct ListNode));
    struct ListNode *b = malloc(sizeof(struct ListNode));
    struct ListNode *c = malloc(sizeof(struct ListNode));

    // Assign values
    a->val = 1;
    b->val = 2;
    c->val = 3;

    // Link nodes: 1 -> 2 -> 3
    a->next = b;
    b->next = c;
    c->next = b;   // Create cycle here (3 -> 2)

    // Test
    if (hasCycle(a))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}