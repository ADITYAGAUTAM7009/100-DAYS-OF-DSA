/*
Name: Aditya Gautam
Problem: Merge Two Sorted Linked Lists (Basic)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node* t = newNode(x);
        if (head == NULL) head = tail = t;
        else { tail->next = t; tail = t; }
    }
    return head;
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node *head = NULL, *tail = NULL;

    while (a != NULL && b != NULL) {
        int v;
        if (a->data < b->data) { v = a->data; a = a->next; }
        else { v = b->data; b = b->next; }

        struct Node* t = newNode(v);
        if (head == NULL) head = tail = t;
        else { tail->next = t; tail = t; }
    }

    while (a != NULL) { tail->next = newNode(a->data); tail = tail->next; a = a->next; }
    while (b != NULL) { tail->next = newNode(b->data); tail = tail->next; b = b->next; }

    return head;
}

void printList(struct Node* h) {
    while (h != NULL) { printf("%d ", h->data); h = h->next; }
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* l1 = createList(n);
    scanf("%d", &m);
    struct Node* l2 = createList(m);

    struct Node* ans = merge(l1, l2);
    printList(ans);
    return 0;
}