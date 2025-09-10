#include <iostream>
using namespace std;

void countingSort(int* arr, int size, int exp);

void radixSort(int* arr, int size){
    int maxNum = 999999;
    int exp = 1;
    while(maxNum / exp > 0){
        countingSort(arr, size, exp);
        exp *= 10;
    }
}

void countingSort(int* arr, int size, int exp){
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int output[size];

    for(int i = 0; i < size; i++){
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for(int i = 1; i < size; i++){
        count[i] = count[i] + count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--){
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

int main(void){
    int arr[] = {452913, 100234, 987654, 654321, 123456,321654, 213465, 564738, 879654, 135790};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "IDs before sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    radixSort(arr, n);

    cout << "IDs after sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}