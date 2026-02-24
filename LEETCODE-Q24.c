/*
Problem: Remove All Elements with Given Value from Linked List
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *prev = NULL, *temp = head;

    // Remove from start
    while (head != NULL && head->val == val) {
        struct ListNode* del = head;
        head = head->next;
        free(del);
    }

    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (temp->val == val) {
            struct ListNode* del = temp;
            prev->next = temp->next;
            temp = temp->next;
            free(del);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// Helper: append node at end
void append(struct ListNode **head, int x) {
    struct ListNode *n = malloc(sizeof(struct ListNode));
    n->val = x;
    n->next = NULL;

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct ListNode *t = *head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

// Helper: print list
void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, x, val;
    struct ListNode *head = NULL;
    // Input number of nodes
    scanf("%d", &n);

    // Input list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }

    // Input value to remove
    scanf("%d", &val);

    // Remove elements
    head = removeElements(head, val);

    // Print result
    printList(head);

    return 0;
}