/*
Problem: Polynomial Using Linked List
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

int main() {
    int n, i;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL, *temp;

    for (i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &temp->coeff, &temp->exp);
        temp->next = NULL;

        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    temp = head;
    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}