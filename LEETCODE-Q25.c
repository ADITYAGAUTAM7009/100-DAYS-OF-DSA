/*
Name: Aditya Gautam
Problem: Linked List Cycle II (Find the start of the cycle)
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct ListNode *head = NULL, *tail = NULL, *arr[10005];
    for (int i = 0; i < n; i++) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        scanf("%d", &node->val);
        node->next = NULL;
        arr[i] = node;
        if (!head) head = tail = node;
        else tail = tail->next = node;
    }

    scanf("%d", &pos);
    if (pos != -1) tail->next = arr[pos];

    struct ListNode *res = detectCycle(head);
    if (!res) printf("No cycle");
    else {
        int idx = 0;
        for (struct ListNode *t = head; t != res; t = t->next) idx++;
        printf("Tail connects to node index %d", idx);
    }
    return 0;
}