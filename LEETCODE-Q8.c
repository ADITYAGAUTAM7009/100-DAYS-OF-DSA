/*
Problem: Power of Two
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if number is power of two
bool isPowerOfTwo(int n)
{
    // If n is 0 or negative, it cannot be power of two
    if (n <= 0)
        return false;

    // Keep dividing n by 2 while it is divisible by 2
    while (n % 2 == 0)
    {
        n = n / 2;
    }

    // If we finally get 1, it is power of two
    if (n == 1)
        return true;
    else
        return false;
}

int main()
{
    int n;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Print input
    printf("Input:\n");
    printf("n = %d\n", n);

    // Check and print result
    if (isPowerOfTwo(n))
    {
        printf("Output:\ntrue\n");
    }
    else
    {
        printf("Output:\nfalse\n");
    }

    return 0;
}
