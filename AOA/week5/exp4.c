#include <stdio.h>

int main() {
    int n, target;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter the coin denominations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the target amount: ");
    scanf("%d", &target);

    for (int i = 0; i < n - 1; i++) {       // sorting using Bubble Sort
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;

                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }

    int remaining_amt = target;
    int total_coins = 0;
    int num_coins[n];

    for (int i = 0; i < n; i++) {
        num_coins[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (coins[i] <= remaining_amt) {
            num_coins[i] = remaining_amt / coins[i];
            total_coins += num_coins[i];
            remaining_amt -= num_coins[i] * coins[i];
        }
    }

    if (total_coins > 0) {
        printf("Coins used:\n");
        for (int i = 0; i < n; i++) {
            if (num_coins[i] > 0) {
                printf("%d coin(s) of %d\n", num_coins[i], coins[i]);
            }
        }
    }

    if (remaining_amt == 0) {
        printf("Total coins used: %d\n", total_coins);
    } else {
        printf("The amount %d cannot be made with the given coins.\n", target);
    }

    return 0;
}
