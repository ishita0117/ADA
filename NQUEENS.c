#include <stdio.h>
#include <stdbool.h>

#define N 8 // Change this value to solve for different board sizes (e.g., 4, 8, 10)

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// A utility function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N-Queens problem
bool solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {

        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {

            // Place this queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove queen from board[i][col] (Backtrack)
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

int main() {
    // Initialize the board with 0s
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist for N = %d\n", N);
        return 0;
    }

    printf("One of the valid solutions for %dx%d board:\n\n", N, N);
    printSolution(board);
    return 0;
}
