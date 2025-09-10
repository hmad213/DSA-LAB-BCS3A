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

int main(void){
    int size = 10;
    int arr[size];

    cout << "Enter 10 numbers: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    selectionSort(arr, size);

    cout << "The 4 minimum elements are: " << endl;
    for(int i = 0; i < 4; i++){
        cout << arr[i] << " ";
    }
}