/*
Name: Aditya Gautam
Problem: Find Intersection of Two Linked Lists (Basic Version)
*/

/*
Problem: Find Intersection Point of Two Linked Lists
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int findIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    int diff = abs(len1 - len2);

    if (len1 > len2)
        while (diff--) h1 = h1->next;
    else
        while (diff--) h2 = h2->next;

    while (h1 && h2) {
        if (h1 == h2) return h1->data;  // address match
        h1 = h1->next;
        h2 = h2->next;
    }

    return -1;
}