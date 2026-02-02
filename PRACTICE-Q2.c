/*
Problem: Delete an element at a given 1-based position from an array
Name: Aditya Gautam
*/

#include <stdio.h>

int main() {
    int n, pos;
    int arr[100];   // assuming maximum size

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete (1-based)
    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);

    // Shift elements to the left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    printf("Updated array: ");
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
