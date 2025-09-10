#include <iostream>
using namespace std;

void bubbleSort(string* arr, int size){
    bool swap = true;
    for(int i = 0; i < size && swap; i++){
        swap = false;
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }
    }
}

int main(void){
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};

    bubbleSort(arr, 5);
    cout << "After Sorting:" << endl;

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}