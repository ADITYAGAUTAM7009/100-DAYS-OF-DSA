/* 
Program Name: Find Maximum and Minimum in an Array
Problem: Given n integers, find the maximum and minimum value.
*/

#include <stdio.h>

int main() {
    int n;

    // Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Take array input
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is max and min
    int max = arr[0];
    int min = arr[0];

    // Compare with remaining elements
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Print result at the end
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
