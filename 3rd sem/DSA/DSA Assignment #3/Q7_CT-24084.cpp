#include <bits/stdc++.h>
using namespace std;

/* Solve the classic N-Queens problem using recursion and backtracking. Place n queens on an n
x n chessboard such that no two queens attack each other. Print all possible solutions. */

void printBoard(vector<string> &board, int n) {
    for (int i = 0; i < n; i++) {
        cout << board[i] << endl;
    }
    cout << endl;
}

bool isSafe(vector<string> &board, int row, int col, int n) {
    // Check the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void solveNQueensUtil(vector<string> &board, int row, int n) {
    if (row == n) {
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q'; // Place queen
            solveNQueensUtil(board, row + 1, n); // Recur to place the next queen
            board[row][col] = '.'; // Backtrack
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<string> board(n, string(n, '.')); // Initialize an n x n chessboard with '.'
    solveNQueensUtil(board, 0, n); // Start solving from the first row
}

