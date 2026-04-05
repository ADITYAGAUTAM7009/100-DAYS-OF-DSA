/*
Problem: Add Two Numbers 
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of singly linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = 
        (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to add two numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;
    
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = carry;
        
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        struct ListNode* newNode = createNode(sum % 10);
        
        carry = sum / 10;
        
        tail->next = newNode;
        tail = newNode;
    }
    
    return dummy.next;
}

// Function to print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

// Main function
int main() {
    int n1, n2, x;

    // Input first list size
    scanf("%d", &n1);
    struct ListNode *l1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        struct ListNode* node = createNode(x);
        if (!l1) l1 = tail1 = node;
        else { tail1->next = node; tail1 = node; }
    }

    // Input second list size
    scanf("%d", &n2);
    struct ListNode *l2 = NULL, *tail2 = NULL;

    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        struct ListNode* node = createNode(x);
        if (!l2) l2 = tail2 = node;
        else { tail2->next = node; tail2 = node; }
    }

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}