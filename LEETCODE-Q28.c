/*
Name: Aditya Gautam
Problem: Palindrome Linked List
*/

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *nextNode = NULL;

    while (head != NULL) {
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {

    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Step 1: Find Middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse Second Half
    struct ListNode* secondHalf = reverse(slow);

    struct ListNode* firstHalf = head;

    // Step 3: Compare Both Halves
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}