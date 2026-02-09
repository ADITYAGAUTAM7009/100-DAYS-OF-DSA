/*
Problem: Reverse String 
Name: Aditya Gautam
*/

#include <stdio.h>

// Function to reverse the string in-place
void reverseString(char* s, int sSize)
{
    int i = 0;
    int j = sSize - 1;
    char temp;

    while (i < j)
    {
        // Swap s[i] and s[j]
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        // Move pointers
        i++;
        j--;
    }
}

int main()
{
    char s[100];
    int len = 0;

    // Take input (no spaces)
    scanf("%s", s);

    // Print input
    printf("Input:\n");
    printf("%s\n", s);

    // Find length of string
    while (s[len] != '\0')
    {
        len++;
    }

    // Reverse the string
    reverseString(s, len);

    // Print output
    printf("Output:\n");
    printf("%s\n", s);

    return 0;
}
