#include <iostream>
using namespace std;

template <typename T>
class Queue{
    private:
        T* arr;
        int front;
        int rear;
        int size;
    public:
        Queue(int s){
            size = s;
            front = -1;
            rear = -1;
            arr = new T[size];
        }

        ~Queue(){
            delete[] arr;
        }

        void enqueue(int value){
            if(isFull()){
                throw invalid_argument("Queue Full!");
            }
            if(front == -1) front = 0;
            arr[++rear] = value;
        }

        T dequeue(){
            if(isEmpty()){
                throw invalid_argument("Queue Empty!");
            }
            return arr[front++];
        }

        bool isFull(){
            return rear == size - 1;
        }

        bool isEmpty(){
            return front == -1 || front > rear;
        }
};

int main(void){
    Queue<int> q(100);
    int IDs[] = {13, 7, 4, 1, 6, 8, 10};
    for(int i = 0; i < 7; i++){
        q.enqueue(IDs[i]);
        cout << "Customer ID " << IDs[i] << " has been enqueued!" << endl;
    }

    cout << endl;

    for(int i = 0; i < 7; i++){
        int temp = q.dequeue();
        cout << "Customer ID " << temp << " has been dequeued!" << endl;
    }
}