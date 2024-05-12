#include <stdio.h>

void findMinCoins(int coins[], int numCoins, int amount) {
    int coinCount = 0;
    
    // Start from the highest denomination coin
    for (int i = numCoins - 1; i >= 0; i--) {
        // Find the maximum number of coins of this denomination that can be used
        while (amount >= coins[i]) {
            amount -= coins[i];
            coinCount++;
        }
        // Print the number of coins used for this denomination
        if (coinCount > 0) {
            printf("%d coin(s) of denomination %d\n", coinCount, coins[i]);
        }
        coinCount = 0; // Reset coin count for next denomination
    }

    if (amount > 0) {
        printf("Remaining amount cannot be made up with available coins.\n");
    }
}

int main() {
    // Denominations of coins available
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    // Amount for which we need to find the minimum number of coins
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("Minimum number of coins required:\n");
    findMinCoins(coins, numCoins, amount);

    return 0;
}
