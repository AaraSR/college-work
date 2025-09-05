#include <stdio.h>
#include <math.h>

#define size 10

void insertionSort(float arr[]) {
    int i, j;
    float temp2;
    for (i = 1; i < size; i++) {
        temp2 = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < temp2) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp2;
    }
}

int main () {
    int n;
    int maxWeight = 10;
    float maxProfit = 0.0;
    float pbyw[size], pbyw_copy[size];
    
    // int weights[size] = {3, 8, 2, 5, 1};
    // float profits[size] = {10.0, 15.0, 10.0, 12.0, 8.0};

    int objects[size] = {};
    printf("Enter the number of elements of objects(max. 10): ");
    scanf("%d", &n);
    printf("\nObjects: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i+1);
        objects[i];
    }
    printf("\n");

    // weights[] array defining
    float weights[n];
    printf("Weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &weights[i]);
    }

    // profits[] array defining
    float profits[n]; 
    printf("Profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &profits[i]);
    }    

    // calculating profit-by-weight
    printf("Profit by Weight: ");
    for (int i = 0; i < n; i++) {
        pbyw[i] = profits[i] / weights[i];
        pbyw_copy[i] = pbyw[i];
        printf("%.1f ", pbyw[i]);
    }
    printf("\n");

    insertionSort(pbyw_copy);

    int i = 0;
    while (maxWeight > 0 && i < size) {
        int k = 0;
        while (pbyw_copy[i] != pbyw[k] && k < n) {
            k++;
        }

        if (weights[k] <= maxWeight) {
            // taking the whole weight (if possible)
            maxWeight -= weights[k];
            maxProfit += profits[k];
        } else {
            // else take the frac of whole weight
            maxProfit += pbyw[k] * maxWeight;
            maxWeight = 0;
        }
        i++;
    }

    printf("Max Profit: %.2f\n", maxProfit);
    return 0;
}
