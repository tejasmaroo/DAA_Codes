#include <stdio.h>
#include <stdbool.h>

#define N 8 // Define the board size (N x N)

// Function to print the board configuration
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, then return false
    return false;
}

// Function to solve N-Queens problem
void solveNQueens() {
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    // Print the board configuration
    printBoard(board);
}

int main() {
    solveNQueens();

    return 0;
}
