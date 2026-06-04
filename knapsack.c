#include <stdio.h>
#include <stdlib.h>

// Structure for an item
struct Item {
    int value;
    int weight;
};

// Comparator function to sort by value/weight ratio (descending)
int compare(const void* a, const void* b) {
    struct Item* i1 = (struct Item*)a;
    struct Item* i2 = (struct Item*)b;

    double r1 = (double)i1->value / i1->weight;
    double r2 = (double)i2->value / i2->weight;

    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

// Fractional Knapsack function
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Step 1: Sort items by ratio
    qsort(arr, n, sizeof(arr[0]), compare);

    double totalValue = 0.0;

    // Step 2: Pick items
    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            // Take full item
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // Take fraction
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

// Driver code
int main() {
    struct Item arr[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 50;

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
