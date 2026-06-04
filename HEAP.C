#include <stdio.h>

int b[20][20];
int cnt = 0;

int ok(int n, int r, int c) {
    int i, j;

    for (i = 0; i < r; i++)
        if (b[i][c])
            return 0;

    for (i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return 0;

    for (i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
        if (b[i][j])
            return 0;

    return 1;
}

void show(int n) {
    int i, j;

    printf("\nSolution %d:\n", ++cnt);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%c ", b[i][j] ? 'Q' : '.');
        printf("\n");
    }
}

void put(int n, int r) {
    int c;

    if (r == n) {
        show(n);
        return;
    }

    for (c = 0; c < n; c++) {
        if (ok(n, r, c)) {
            b[r][c] = 1;
            put(n, r + 1);
            b[r][c] = 0;
        }
    }
}

int main() {
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    put(n, 0);

    if (cnt == 0)
        printf("No solution\n");

    return 0;
}
NQueen.c
Displaying NQueen.c.
