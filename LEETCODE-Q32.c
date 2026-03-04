/*
Name: Aditya Gautam
Problem: Min Stack (Push, Pop, Top, GetMin in O(1))
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 30000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

/* Create stack */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

/* Push element */
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0 || val < obj->minStack[obj->top - 1])
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
}

/* Pop element */
void minStackPop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

/* Get top element */
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

/* Get minimum element */
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

/* Free memory */
void minStackFree(MinStack* obj) {
    free(obj);
}

int main() {
    
    MinStack* minStack = minStackCreate();

    minStackPush(minStack, -2);
    minStackPush(minStack, 0);
    minStackPush(minStack, -3);

    printf("%d\n", minStackGetMin(minStack)); // -3

    minStackPop(minStack);

    printf("%d\n", minStackTop(minStack));    // 0
    printf("%d\n", minStackGetMin(minStack)); // -2

    minStackFree(minStack);

    return 0;
}