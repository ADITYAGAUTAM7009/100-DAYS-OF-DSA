/*
Name: Aditya Gautam
Problem: Valid Parentheses
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10000

bool isValid(char* s) {
    
    char stack[MAX];   // Stack to store brackets
    int top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        
        char ch = s[i];
        
        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {  // Closing bracket
            
            if (top == -1)   // No opening bracket
                return false;
            
            char open = stack[top--];
            
            if ((open == '(' && ch != ')') ||
                (open == '{' && ch != '}') ||
                (open == '[' && ch != ']')) {
                return false;
            }
        }
    }
    
    // If stack empty → valid
    return (top == -1);
}

int main() {
    char s[MAX];
    
    scanf("%s", s);   // Input string
    
    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");
    
    return 0;
}