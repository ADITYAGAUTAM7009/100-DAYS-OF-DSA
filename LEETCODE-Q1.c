/*
Problem: Insert an element at a given 1-based position in an array
Name: Aditya Gautam
*/

#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];   // assuming maximum size

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);

    // Input element to insert
    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Shift elements to the right
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element at correct position
    arr[pos - 1] = x;

    // Print updated array
    printf("Updated array: ");
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
