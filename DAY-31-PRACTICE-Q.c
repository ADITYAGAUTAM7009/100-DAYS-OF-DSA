/*
Name: Aditya Gautam
Problem: Implement Stack using Array with push, pop, and display operations
*/

#include <stdio.h>

#define MAX 100   // Maximum stack size

int stack[MAX];
int top = -1;     // Initially stack is empty

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
    top--;
}

// Display operation (Top to Bottom)
void display() {
    if (top == -1) {
        return;   // If empty, print nothing
    }
    
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if (type == 2) {
            pop();
        }
        else if (type == 3) {
            display();
        }
    }

    return 0;
}