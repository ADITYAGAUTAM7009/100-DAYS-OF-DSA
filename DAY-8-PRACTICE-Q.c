/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.
Name: Aditya Gautam
*/

#include <stdio.h>

// Very simple recursive function
int power(int a, int b)
{
    int t;   // temporary variable
    int r;   // result variable

    // Base case: if b is 0, answer is 1
    if (b == 0)
    {
        return 1;
    }

    // Call function for smaller power
    t = power(a, b - 1);

    // Multiply a one time
    r = a * t;

    // Return result
    return r;
}

int main()
{
    int a, b;

    // Ask user for input
    printf("Enter value of a and b: ");
    scanf("%d %d", &a, &b);

    // Print input
    printf("Input:\n");
    printf("%d %d\n", a, b);

    // Call function
    int ans = power(a, b);

    // Print output
    printf("Output:\n");
    printf("%d\n", ans);

    return 0;
}
