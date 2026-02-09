#include <stdio.h>

int main()
{
    char s[100];
    int i, len = 0;

    // Take input
    scanf("%s", s);

    // Print input
    printf("Input:\n");
    printf("%s\n", s);

    // Find length manually
    while (s[len] != '\0')
    {
        len++;
    }

    // Print output
    printf("Output:\n");

    // Print reversed string
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }

    return 0;
}
