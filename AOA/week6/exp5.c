#include <stdio.h>

void sortItemsByRatio(float ratio[], float p[], float w[], int size) {    // sorting using InsertionSort due to less no. of inputs
    int i, j;
    float temp2, tempp, tempw;
    for (i = 1; i < size; i++) {
        temp2 = ratio[i];
        tempp = p[i];
        tempw = w[i];
        j = i - 1;
        while (j >= 0 && ratio[j] < temp2) {  // descending order
            ratio[j + 1] = ratio[j];
            p[j + 1] = p[j];
            w[j + 1] = w[j];
            j = j - 1;
        }
        ratio[j + 1] = temp2;
        p[j + 1] = tempp;
        w[j + 1] = tempw;
    }
}

int main() {
    int capacity, n;
    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter number of items: ");
    scanf("%d", &n);

    float p[n], w[n], ratio[n];

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &p[i]);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &w[i]);
        ratio[i] = p[i] / w[i];
    }

    sortItemsByRatio(ratio, p, w, n);

    float total_p = 0.0;
    float current_w = 0.0;

    for (int i = 0; i < n; i++) {
        if (current_w + w[i] <= capacity) {
            current_w += w[i];
            total_p += p[i];
        } else {
            float remain = capacity - current_w;
            total_p += ratio[i] * remain;
            break;
        }
    }

    printf("Total profit obtained: %.2f\n", total_p);

    return 0;
}
