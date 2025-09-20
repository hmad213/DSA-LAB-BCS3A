#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveNFlags(int board[N][N], int row, int& maxFlags, int bestSolution[N][N]) {
    if (row == N) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
        
        if (count > maxFlags) {
            maxFlags = count;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    bestSolution[i][j] = board[i][j];
                }
            }
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            
            solveNFlags(board, row + 1, maxFlags, bestSolution);
            
            board[row][col] = 0;
        }
    }

    solveNFlags(board, row + 1, maxFlags, bestSolution);
}

int main() {
    int board[N][N] = {0};
    int bestSolution[N][N] = {0};
    int maxFlags = 0;

    solveNFlags(board, 0, maxFlags, bestSolution);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bestSolution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}