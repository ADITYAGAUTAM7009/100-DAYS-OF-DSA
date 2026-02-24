/*
Name: Aditya Gautam
Problem: Reverse Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;    
    struct ListNode* curr = head;   
    struct ListNode* next = NULL;   

    while (curr != NULL) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;        
        curr = next;        
    }

    return prev;  
}

int main() {
    int n;
    scanf("%d", &n);   

    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;
    struct ListNode* newNode = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Reverse the linked list
    head = reverseList(head);

    // Print reversed list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}