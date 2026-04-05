/*
Name: Aditya Gautam
Problem: Evaluate Reverse Polish Notation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

/* Push element into stack */
void push(int x)
{
    stack[++top] = x;
}

/* Pop element from stack */
int pop()
{
    return stack[top--];
}

/* Function to evaluate RPN expression */
int evalRPN(char *tokens[], int tokensSize)
{
    for(int i = 0; i < tokensSize; i++)
    {
        /* If token is an operator */
        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0)
        {
            int b = pop();
            int a = pop();

            if(strcmp(tokens[i], "+") == 0)
                push(a + b);

            else if(strcmp(tokens[i], "-") == 0)
                push(a - b);

            else if(strcmp(tokens[i], "*") == 0)
                push(a * b);

            else
                push(a / b);
        }
        else
        {
            /* Convert string to integer and push */
            push(atoi(tokens[i]));
        }
    }

    return pop();
}

/* Driver Code for Testing */
int main()
{
    char *tokens[] = {"2","1","+","3","*"};
    int size = 5;

    int result = evalRPN(tokens, size);

    printf("Result = %d\n", result);

    return 0;
}