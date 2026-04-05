/*
Name: Aditya Gautam
Problem: Implement Queue using Two Stacks
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int in[100];
    int out[100];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->in[++obj->top1] = x;
}

void shift(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->out[++obj->top2] = obj->in[obj->top1--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    shift(obj);
    return obj->out[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    shift(obj);
    return obj->out[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* q = myQueueCreate();

    myQueuePush(q, 1);
    myQueuePush(q, 2);

    printf("Peek: %d\n", myQueuePeek(q));  // 1
    printf("Pop: %d\n", myQueuePop(q));    // 1
    printf("Empty: %d\n", myQueueEmpty(q)); // 0 (false)

    myQueueFree(q);
    return 0;
}