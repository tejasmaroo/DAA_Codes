#include <stdio.h>

// Function to find the maximum value that can be put in a knapsack of capacity W using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    // Create a table to store the maximum value that can be achieved with i items and j weight capacity
    int dp[n + 1][W + 1];

    // Initialize the table with zeros
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }

    // Build the table in bottom-up manner
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= W; j++) {
            // If the current item's weight is less than or equal to the current capacity, consider including it
            if (wt[i - 1] <= j) {
                // Choose the maximum value between including the current item and excluding it
                if (val[i - 1] + dp[i - 1][j - wt[i - 1]] > dp[i - 1][j]) {
                    dp[i][j] = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                // If the current item's weight exceeds the current capacity, exclude it
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W]; // Return the maximum value that can be achieved with n items and W capacity
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);

    int maxValue = knapsack(W, wt, val, n);

    printf("Maximum value in knapsack = %d\n", maxValue);

    return 0;
}
