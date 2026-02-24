/*
Problem: Linear Search with Comparison Count
Name: Aditya Gautam
*/
#include <stdio.h>

int main() {
    int n, i, k;
    int arr[100];
    int comparisons = 0;
    int found = 0;

    // Step 1: Read size of array
    scanf("%d", &n);

    // Step 2: Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Read key to search
    scanf("%d", &k);

    // Step 4: Linear Search
    for (i = 0; i < n; i++) {
        comparisons++;              // each comparison
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    // Step 5: If not found
    if (found == 0) {
        printf("Not Found\n");
    }

    // Step 6: Print comparisons
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
