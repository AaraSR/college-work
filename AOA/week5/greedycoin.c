#include <stdio.h>

void greedyCoinChange(int coins[], int numCoins, int TargetAmt) {
    int i, j;

    for(i = 0; i < numCoins - 1; i++) {     // sorting in desceding order, using Bubble Sort
        for (j = 0; j < numCoins - 1 - i; j++) {
            if (coins[j] < coins[j + 1]) {
                // swapping the larger with smaller ('if' any)
                int temp = coins[j + 1];
                coins[j + 1] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // balance left
    int balanceAmt = TargetAmt;

    // selecting and printing the coins with highest denomination
    printf("Selected coins: ");
    for(i = 0; i < numCoins; i++) {
        while (balanceAmt >= coins[i]) {
            printf("%d ", coins[i]);
            balanceAmt -= coins[i];
        }

        
    }

    (balanceAmt == 0) ? 
    printf("\nNo Balance left!\n") : 
    printf("\nExact change not possible, Remaining Amount: %d \n", balanceAmt);
}

int main(void) {
    int coins[10] = {};
    int numCoins;
    int TargetAmt; 

    printf("GREEDY COIN CHANGE\nEnter the Target Amount: ");
    scanf("%d", &TargetAmt);

    printf("\nEnter the number of coins: ");
    scanf("%d", &numCoins);

    printf("\nEnter the coins: ");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }
    
    greedyCoinChange(coins, numCoins, TargetAmt);

    return 0;
}