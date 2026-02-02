/*
Problem: Best Time to Buy and Sell Stock
Name: Aditya Gautam
*/

#include <stdio.h>

int main() {
    int n;
    int prices[100];
    int minPrice, maxProfit = 0;

    // Input number of days
    printf("Enter number of days: ");
    scanf("%d", &n);

    // Input stock prices
    printf("Enter stock prices: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    // Initialize minimum price with first day's price
    minPrice = prices[0];

    // Calculate maximum profit
    for(int i = 1; i < n; i++) {

        // Update minimum price
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Update maximum profit
        if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    // Print result
    printf("Maximum Profit: %d", maxProfit);

    return 0;
}
