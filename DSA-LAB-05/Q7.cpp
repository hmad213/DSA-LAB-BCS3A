#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool lionInMaze(int** arr, int x, int y, int n, int** solArr) {
    if((x == (n - 1)) && (y == (n - 1))) {
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr, x, y, n)) {
        solArr[x][y] = 1;

        if(lionInMaze(arr, x + 1, y, n, solArr)){
            return true;
        }

        if(lionInMaze(arr, x, y + 1, n, solArr)){
            return true;
        }

        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main(void){
    const int n = 5;
    
    int** maze = new int*[n];
    int mazeData[n][n] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    
    for(int i = 0; i < n; i++) {
        maze[i] = new int[n];
        for(int j = 0; j < n; j++) {
            maze[i][j] = mazeData[i][j];
        }
    }
    
    int** solution = new int*[n];
    for(int i = 0; i < n; i++) {
        solution[i] = new int[n];
        for(int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
    }
    
    if(lionInMaze(maze, 0, 0, n, solution)) {
        cout << "Path found! Solution matrix:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path exists from start to destination!" << endl;
    }
    
    // Clean up memory
    for(int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;
    
    return 0;
}