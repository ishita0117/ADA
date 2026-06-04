#include <stdio.h>

#define LEFT  -1
#define RIGHT  1

void printPerm(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int mobile(int a[], int dir[], int n) {
    int m = 0, pos = -1;

    for (int i = 0; i < n; i++) {

        // moving left
        if (dir[a[i]] == LEFT && i > 0 && a[i] > a[i - 1]) {
            if (a[i] > m) {
                m = a[i];
                pos = i;
            }
        }

        // moving right
        if (dir[a[i]] == RIGHT && i < n - 1 && a[i] > a[i + 1]) {
            if (a[i] > m) {
                m = a[i];
                pos = i;
            }
        }
    }

    return pos;
}

void johnsonTrotter(int n) {
    int a[20], dir[21];

    // initial permutation
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    // all directions = LEFT
    for (int i = 1; i <= n; i++)
        dir[i] = LEFT;

    printPerm(a, n);

    while (1) {

        int pos = mobile(a, dir, n);

        // no mobile element
        if (pos == -1)
            break;

        int x = a[pos];

        // swap according to direction
        if (dir[x] == LEFT) {
            int t = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = t;
            pos--;
        }
        else {
            int t = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = t;
            pos++;
        }

        // reverse direction of larger elements
        for (int i = 0; i < n; i++) {
            if (a[i] > x)
                dir[a[i]] *= -1;
        }

        printPerm(a, n);
    }
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
