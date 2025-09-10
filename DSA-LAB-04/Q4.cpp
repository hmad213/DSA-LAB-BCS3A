#include <iostream>
using namespace std;

void selectionSort(int* arr, int size){
    for(int i = 0; i < size; i++){
        int minIndex = i;

        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

bool checkDuplicates(int* arr, int size){
    int prev = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] == prev){
            return true;
        }
        prev = arr[i];
    }
    return false;
}

int main(void){
    int arr1[5] = {5, 2, 3, 1, 4};
    int arr2[7] = {10, 43, 76, 25, 93, 10, 5};

    cout << "Array 1: " << endl;
    for(int i = 0; i < 5; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    selectionSort(arr1, 5);

    cout << (checkDuplicates(arr1, 5) ? "Duplicates found!" : "Duplicates not found!") << endl;
    cout << endl;

    cout << "Array 2: " << endl;
    for(int i = 0; i < 7; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    selectionSort(arr2, 7);

    cout << (checkDuplicates(arr2, 7) ? "Duplicates found!" : "Duplicates not found!") << endl;
    cout << endl;
}