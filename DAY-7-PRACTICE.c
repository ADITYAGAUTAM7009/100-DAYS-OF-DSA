/*
Problem: Recursive Fibonacci
Name: Aditya Gautam 
*/
#include <stdio.h>
// Recursive function to find nth Fibonacci number
int fib(int n) {
    if (n == 0)
        return 0;          
    if (n == 1)
        return 1;         
    return fib(n - 1) + fib(n - 2);  
}
int main() {
    int n;

    // Ask for input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print result
    printf("The %d-th Fibonacci number is: %d", n, fib(n));

    return 0;
}
