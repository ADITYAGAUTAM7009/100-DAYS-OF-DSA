/*
Problem: Fibonacci Number
Name: Aditya Gautam
*/

#include <stdio.h>
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;  
        a = b;      
        b = c;      
    }

    return b; 
}

int main() {
    int n;

    // Input
    printf("Enter n: ");
    scanf("%d", &n);

    // Output
    printf("F(%d) = %d\n", n, fib(n));

    return 0;
}
