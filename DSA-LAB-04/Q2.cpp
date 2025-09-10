#include <iostream>
#include <cmath>
using namespace std;

void sortArray(int* arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    for(int i = size - 1; i > floor(size / 2.0); i--){
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
    }
}

int main(void){
    int arr[9] = { 20, 12, 15, 2, 10, 1, 13, 9, 5};

    sortArray(arr, 9);

    cout << "After sorting:" << endl;
    for(int i = 0; i < 9; i++){
        cout << arr[i] << " "; 
    }
}