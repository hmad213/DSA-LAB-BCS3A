#include <iostream>
using namespace std;

void insertionSort(int* arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(void){
    int arr[6] = {2022, 2023, 2024, 2022, 2023, 2024};

    insertionSort(arr, 6);

    cout << "After Sorting: " << endl;

    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
}