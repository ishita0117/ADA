#include <stdio.h>

int main() {
    int n = 4; // Number of items
    int wt[4] = {3, 4, 6, 5}; // Weights of items
    int val[4] = {2, 3, 1, 4}; // ✅ Fixed: correct size
    int W = 8; // Capacity of knapsack

    int K[5][9]; // DP table (n+1 x W+1)

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // Base case
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            // If weight of current item can be included
            else if (wt[i - 1] <= w) {
                int include = val[i - 1] + K[i - 1][w - wt[i - 1]];
                int exclude = K[i - 1][w];

                // Take maximum
                if (include > exclude)
                    K[i][w] = include;
                else
                    K[i][w] = exclude;
            }
            // If item cannot be included
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    printf("Maximum value = %d\n", K[n][W]);

    return 0;
}
