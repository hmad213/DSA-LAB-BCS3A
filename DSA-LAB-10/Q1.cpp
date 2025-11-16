#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* arr;
    int capacity;
    int heapSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }
public:
    MaxHeap(int c) {
        capacity = c;
        arr = new int[c];
        heapSize = 0;
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void heapifyDown(int i) {
        int largest = i;
        int L = left(i);
        int R = right(i);

        if (L < heapSize && arr[L] > arr[largest])
            largest = L;

        if (R < heapSize && arr[R] > arr[largest])
            largest = R;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i){
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    bool isEmpty() const { return heapSize == 0; }
    bool isFull()  const { return heapSize == capacity; }

    void insert(int key){
        if(isFull()){
            cout << "Heap overflow" << endl;
            return;
        }

        int i = heapSize;
        arr[i] = key;
        heapSize++;

        heapifyUp(i);
    }

    void print(){
        for (int i = 0; i < heapSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void deleteAt(int i) {
        if (i < 0 || i >= heapSize) {
            cout << "Invalid index" << endl;
            return;
        }

        arr[i] = arr[heapSize - 1];
        heapSize--;

        heapifyDown(i);

        heapifyUp(i);
    }

    void update_key(int i, int new_val){
        if (i < 0 || i >= heapSize) {
            cout << "Invalid index" << endl;
            return;
        }

        arr[i] = new_val;

        heapifyDown(i);

        heapifyUp(i);
    }
};

int main(void){
    MaxHeap heap(100);

    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    heap.insert(8);

    heap.print();

    heap.update_key(2, 9);

    heap.print();
}