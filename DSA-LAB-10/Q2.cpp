#include <iostream>
using namespace std;

int left(int i){ return 2 * i + 1; }
int right(int i){ return 2 * i + 2; }

bool checkMaxHeap(int* arr, int size){
    for(int i = 0; i < size / 2; i++){
        int parent = arr[i];
        int l = left(i);
        int r = right(i);

        if(l < size && parent < arr[l]) return false;
        if(r < size && parent < arr[r]) return false;
    }
    return true;
}

int main(void){
    int arr[] = {8, 7, 5, 4, 6};

    cout << (checkMaxHeap(arr, 5) ? "It is heap" : "It is not a heap");
}