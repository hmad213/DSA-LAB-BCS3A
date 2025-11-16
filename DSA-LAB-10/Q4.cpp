#include <iostream>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
int left(int i)   { return 2 * i + 1; }
int right(int i)  { return 2 * i + 2; }

void heapifyDown(int arr[], int size, int i) {
    int largest = i;
    int L = left(i);
    int R = right(i);

    if (L < size && arr[L] > arr[largest])
        largest = L;

    if (R < size && arr[R] > arr[largest])
        largest = R;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, size, largest);
    }
}

void heapifyUp(int arr[], int size, int i){
    while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void convert(int arr[], int size){
    for(int i = size / 2 - 1; i >= 0; i--){
        heapifyDown(arr, size, i);
    }
}

int main(void){
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before: " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    convert(arr, size);

    cout << "After" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}