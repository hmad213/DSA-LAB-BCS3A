#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    int front;
    int rear;
    int size;
    T* arr;

public:
    CircularQueue(int s) {
        size = s;
        arr = new T[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    bool isEmpty(){
        return front == -1;
    }

    void enqueue(T value) {
        if (isFull()) {
            throw invalid_argument("Queue Full");
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
    }

    T dequeue() {
        if (isEmpty()) {
            throw invalid_argument("Queue Empty");
        }

        T retItem = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return retItem;
    }
};

int main(void){
    CircularQueue<string> msgQueue(3);
    string messages[] = {"Hello", "How are you?", "Goodbye", "See you later"};
    for(int i = 0; i < 3; i++) msgQueue.enqueue(messages[i]);

    cout << "Message \"" << msgQueue.dequeue() << "\" has been dequeued" << endl;
    msgQueue.enqueue(messages[3]);
    cout << "Message \"" << msgQueue.dequeue() << "\" has been dequeued" << endl;
    cout << "Message \"" << msgQueue.dequeue() << "\" has been dequeued" << endl;
    cout << "Message \"" << msgQueue.dequeue() << "\" has been dequeued" << endl;
}