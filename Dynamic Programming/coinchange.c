#include <stdio.h>

// Function to find the minimum number of coins required to make a given amount using dynamic programming
void coinChange(int coins[], int n, int amount) {
    // Create a table to store the minimum number of coins required for amounts from 0 to the given amount
    int dp[amount + 1];

    // Initialize the table with maximum value (amount + 1)
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // Base case: Minimum number of coins required for amount 0 is 0
    dp[0] = 0;

    // Fill the table in bottom-up manner
    for (int i = 1; i <= amount; i++) {
        // Iterate through all coins
        for (int j = 0; j < n; j++) {
            // If the current coin is less than or equal to the amount
            if (coins[j] <= i) {
                // Update dp[i] if using current coin reduces the number of coins required
                dp[i] = (dp[i - coins[j]] + 1 < dp[i]) ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
    }

    // If dp[amount] is still amount + 1, it means no combination of coins is possible to make the given amount
    if (dp[amount] == amount + 1) {
        printf("No combination of coins can make the amount %d\n", amount);
        return;
    }

    // Print the minimum number of coins required to make the given amount
    printf("Minimum number of coins required to make amount %d: %d\n", amount, dp[amount]);
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    coinChange(coins, n, amount);

    return 0;
}
