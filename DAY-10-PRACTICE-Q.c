/*
Problem: Check if a string is palindrome
Name: Aditya Gautam
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100], rev[100];
    int i, len;

    // Input string
    scanf("%s", s);

    len = strlen(s);

    // Reverse the string
    for (i = 0; i < len; i++) {
        rev[i] = s[len - 1 - i];
    }
    rev[len] = '\0';  // end of string

    // Compare original and reversed
    if (strcmp(s, rev) == 0) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
