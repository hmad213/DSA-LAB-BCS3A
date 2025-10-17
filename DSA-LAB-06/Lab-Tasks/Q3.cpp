#include <iostream>
using namespace std;

class Order {
    private:
        int id;
        string itemName;
        int quantity;
    public:
        Order() : id(-1), itemName(""), quantity(0) {}
        Order(int i, string name, int q) : id(i), itemName(name), quantity(q) {}

        void print() const {
            cout << "Order ID: " << id 
                << ", Item: " << itemName 
                << ", Quantity: " << quantity << endl;
        }
};

template <typename T>
struct Node {
    T value;
    Node* next;
    Node(T v) : value(v), next(nullptr) {}
};

template <typename T>
class Queue {
    private:
        Node<T>* front;
        Node<T>* rear;
        int size;
    public:
        Queue() : front(nullptr), rear(nullptr), size(0) {}

        bool isEmpty() const {return front == nullptr;}

        void enqueue(const T& val) {
            Node<T>* newNode = new Node<T>(val);
            if (rear != nullptr) {
                rear->next = newNode;
            }
            rear = newNode;
            if (front == nullptr) {
                front = rear;
            }
            size++;
        }

        T dequeue() {
            if (isEmpty()) {
                throw runtime_error("Queue is empty! Cannot dequeue.");
            }
            Node<T>* temp = front;
            T retVal = temp->value;
            front = front->next;
            if (front == nullptr) rear = nullptr;
            delete temp;
            size--;
            return retVal;
        }

        Node<T>* getFront(){return front;}

        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }
};

void printOrderQueue(Queue<Order>& q){
    Node<Order>* cur = q.getFront();
    while(cur != nullptr){
        cur->value.print();
        cur = cur->next;
    }
}

int main() {
    Queue<Order> orderQueue;

    orderQueue.enqueue(Order(1, "Burger", 2));
    orderQueue.enqueue(Order(2, "Fries", 3));
    orderQueue.enqueue(Order(3, "Pizza", 1));

    printOrderQueue(orderQueue);

    cout << "\nProcessing an order:\n";
    Order processed = orderQueue.dequeue();
    processed.print();

    cout << "\nRemaining orders:\n";
    printOrderQueue(orderQueue);

    return 0;
}