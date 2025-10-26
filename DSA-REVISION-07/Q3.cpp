#include <iostream>
using namespace std;

bool isSafe(int arr[4][4], int solArr[4][4], int x, int y){
    return ((x >= 0 && x < 4 && y >= 0 && y < 4 && arr[x][y] == 1 && solArr[x][y] == 0));
}

bool backtrack(int arr[4][4], int solArr[4][4], int x, int y, int targetX, int targetY){
    if(x == targetX && y == targetY){
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr, solArr, x, y)){
        solArr[x][y] = 1;

        if(backtrack(arr, solArr, x + 1, y, targetX, targetY)) return true;

        if(backtrack(arr, solArr, x, y + 1, targetX, targetY)) return true;

        if(backtrack(arr, solArr, x, y - 1, targetX, targetY)) return true;

        if(backtrack(arr, solArr, x - 1, y, targetX, targetY)) return true;

        solArr[x][y] = 0;
    }

    return false;
}

int main(void){
    int arr[4][4] = {{1, 1, 1, 1},
                    {0, 0, 0, 1},
                    {1, 1, 0, 1},
                    {1, 1, 1, 1}};

    int solArr[4][4] = {{0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};

    backtrack(arr, solArr, 0, 0, 2, 0);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }
}