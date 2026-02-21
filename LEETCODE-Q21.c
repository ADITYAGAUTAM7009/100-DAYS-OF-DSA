/*
Name: Aditya Gautam
Problem: Middle of the Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of singly linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Find middle node using slow & fast pointers (1-pass, O(1) space)
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // 1 step
        fast = fast->next->next;     // 2 steps
    }

    // slow points to middle (second middle if even length)
    return slow;
}

// Create linked list from input
struct ListNode* createList(int n) {
    struct ListNode *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Print list from given node
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct ListNode* head = createList(n);

    struct ListNode* mid = middleNode(head);

    // Print from middle to end (as per examples)
    printList(mid);

    return 0;
}
