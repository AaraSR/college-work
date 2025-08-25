<<<<<<< HEAD
// hello world

#include <stdio.h>

int main (void) {
    //Happy to be here

    printf("this is my branch - aara");
    printf("L M A O - om");
    return 0;
}
=======
#include <stdio.h>
#include <math.h>

#define size 5

void insertionSort(float arr[]) {
    int i, j;
    float temp2;   // FIX: must be float
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
    int maxWeight = 10;
    float maxProfit = 0.0;   // FIX: must be float
    float pbyw[size];
    float pbyw_copy[size];

    int objects[size] = {1, 2, 3, 4, 5};
    int weights[size] = {3, 8, 2, 5, 1};
    float profits[size] = {10.0, 15.0, 10.0, 12.0, 8.0};

    // calculate profit/weight ratio
    for (int i = 0; i < size; i++) {
        pbyw[i] = profits[i] / weights[i];
        pbyw_copy[i] = pbyw[i];
        printf("%.1f ", pbyw[i]);
    }
    printf("\n");

    insertionSort(pbyw_copy);  // sort ratios descending

    int i = 0;
    while (maxWeight > 0 && i < size) {
        int k = 0;
        while (pbyw_copy[i] != pbyw[k] && k < size - 1) {
            k++;
        }

        if (weights[k] <= maxWeight) {
            // take full item
            maxWeight -= weights[k];
            maxProfit += profits[k];
        } else {
            // take fraction
            maxProfit += pbyw[k] * maxWeight;
            maxWeight = 0;
        }
        i++;
    }

    printf("Max Profit: %.2f\n", maxProfit);
    return 0;
}
>>>>>>> main
