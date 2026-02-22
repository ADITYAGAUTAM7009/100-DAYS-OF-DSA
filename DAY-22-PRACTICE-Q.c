/*
Name: Aditya Gautam
Problem: Create and Traverse Singly Linked List (Very Basic)
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);   // number of nodes

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);  // read value
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;      // first node
            temp = newNode;
        } else {
            temp->next = newNode; // link new node
            temp = newNode;       // move temp
        }
    }

    // Traverse and print
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}