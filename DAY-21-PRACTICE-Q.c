/*
Name: Aditya Gautam
Problem: Create and Traverse Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            // First node
            head = newNode;
            temp = newNode;
        } else {
            // Link next node
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traverse and print the linked list
    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }

    return 0;
}