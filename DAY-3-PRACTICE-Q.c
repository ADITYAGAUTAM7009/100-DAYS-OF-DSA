/*
Problem: Linear Search with Comparison Count
Name: Aditya Gautam 
*/
#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int i;
    int comparisons = 0;
    int found = 0;

    // Read size of array
    scanf("%d", &n);

    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key to search
    scanf("%d", &k);

    // Linear Search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    // If key not found
    if (found == 0) {
        printf("Not Found\n");
    }

    // Print comparison count
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
