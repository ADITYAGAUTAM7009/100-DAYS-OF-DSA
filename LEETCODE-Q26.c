/*
Name: Aditya Gautam
Problem: Design MyLinkedList (Full Working Version with Main)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

/* Create Linked List */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

/* Get value at index */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    return curr->val;
}

/* Add at head */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

/* Add at tail */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL) {
        obj->head = node;
    } else {
        Node* curr = obj->head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = node;
    }
    obj->size++;
}

/* Add at index */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;

    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++)
        curr = curr->next;

    node->next = curr->next;
    curr->next = node;
    obj->size++;
}

/* Delete at index */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    obj->size--;
}

/* Free entire list */
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

/* Display list */
void display(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

/* Main function to test */
int main() {

    MyLinkedList* obj = myLinkedListCreate();

    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);   // List: 1 2 3

    display(obj);

    printf("Value at index 1: %d\n", myLinkedListGet(obj, 1));

    myLinkedListDeleteAtIndex(obj, 1);   // List: 1 3

    display(obj);

    printf("Value at index 1: %d\n", myLinkedListGet(obj, 1));

    myLinkedListFree(obj);

    return 0;
}