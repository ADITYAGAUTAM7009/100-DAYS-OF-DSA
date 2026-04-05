/*
Problem: Remove Cycle from Singly Linked List
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool removeLoop(struct Node* head) {

    if (!head || !head->next) return true;

    struct Node *slow = head, *fast = head;

    // Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (slow != fast) return true;  // No loop

    // Find start of loop
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;  // Break loop

    return true;
}

int main() {
    printf("Use removeLoop(head) inside driver.\n");
    return 0;
}