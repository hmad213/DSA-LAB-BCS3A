#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || (board[i] - col) == (i - row) || (board[i] - col) == (row - i))
            return false;
    }
    return true;
}

bool solveNQueens(int board[], int n, int row = 0) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solveNQueens(board, n, row + 1))
                return true;

            board[row] = -1;
        }
    }
    return false;
}

int main() {
    int board[N];
    for (int i = 0; i < N; i++) board[i] = -1;

    if (solveNQueens(board, N))
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++)
                cout << (board[r] == c ? "Q " : ". ");
            cout << '\n';
        }
    else
        cout << "No solution found.\n";

    return 0;
}