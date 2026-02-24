/*
Name: Aditya Gautam
Problem: Delete First Occurrence of a Key
*/

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int main() {
    int n, x, key;
    struct Node *h = NULL, *t = NULL, *p, *c;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x; p->next = NULL;
        if (!h) h = t = p;
        else t->next = p, t = p;
    }

    scanf("%d", &key);

    c = h; p = NULL;
    if (c && c->data == key) h = c->next, free(c);
    else {
        while (c && c->data != key) p = c, c = c->next;
        if (c) p->next = c->next, free(c);
    }

    for (c = h; c; c = c->next) printf("%d ", c->data);
    return 0;
}