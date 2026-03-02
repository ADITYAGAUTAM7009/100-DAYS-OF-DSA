/*
Problem: Add Two Numbers II (Forward Order)
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Create new node
struct ListNode* newNode(int x) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

// Add two numbers (without reversing lists)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int s1[100], s2[100];
    int top1 = 0, top2 = 0;

    // Store digits of first list
    while (l1) {
        s1[top1++] = l1->val;
        l1 = l1->next;
    }

    // Store digits of second list
    while (l2) {
        s2[top2++] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* head = NULL;

    // Add like normal addition from last
    while (top1 > 0 || top2 > 0 || carry) {

        int sum = carry;

        if (top1 > 0) sum += s1[--top1];
        if (top2 > 0) sum += s2[--top2];

        struct ListNode* node = newNode(sum % 10);
        node->next = head;
        head = node;

        carry = sum / 10;
    }

    return head;
}

// Print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n1, n2, x;

    // First list
    scanf("%d", &n1);
    struct ListNode *l1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        struct ListNode* node = newNode(x);
        if (!l1) l1 = tail1 = node;
        else { tail1->next = node; tail1 = node; }
    }

    // Second list
    scanf("%d", &n2);
    struct ListNode *l2 = NULL, *tail2 = NULL;

    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        struct ListNode* node = newNode(x);
        if (!l2) l2 = tail2 = node;
        else { tail2->next = node; tail2 = node; }
    }

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}