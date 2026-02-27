/*
Name: Aditya Gautam
Problem: MyLinkedList 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* head = NULL;

int get(int index){
    Node* t = head;
    while(t && index--){
        t = t->next;
    }
    return t ? t->val : -1;
}

void addAtHead(int val){
    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->next = head;
    head = n;
}

void addAtTail(int val){
    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;

    if(!head){ head = n; return; }

    Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}

void addAtIndex(int index, int val){
    if(index==0){ addAtHead(val); return; }

    Node* t = head;
    while(t && --index) t = t->next;
    if(!t) return;

    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->next = t->next;
    t->next = n;
}

void deleteAtIndex(int index){
    if(!head) return;

    if(index==0){
        Node* t = head;
        head = head->next;
        free(t);
        return;
    }

    Node* t = head;
    while(t->next && --index) t = t->next;
    if(!t->next) return;

    Node* d = t->next;
    t->next = d->next;
    free(d);
}