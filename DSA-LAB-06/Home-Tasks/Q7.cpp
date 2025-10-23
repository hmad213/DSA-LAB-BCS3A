#include <iostream>
using namespace std;

class Patron{
    public:
        int id;
        string name;

        Patron(int id, string name) : id(id), name(name) {}
        Patron() : Patron(-1, "") {}

        void display(){
            cout << "ID: " << id << ", Name: " << name << endl; 
        }
};

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

        void enqueue(T value){
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

        void display(){
            cout << "Queue contents from the front:" << endl;
            int i = front;
            while(i <= rear){
                arr[i].display();
                i++;
            }
        }

        bool isFull(){
            return rear == size - 1;
        }

        bool isEmpty(){
            return front == -1 || front > rear;
        }
};

int main(void){
    Queue<Patron> q(5);
    Patron patrons[4] = {{1, "Hammad"}, {2, "Ali"}, {3, "Ahmed"}, {4, "Akbar"}};
    for(int i = 0; i < 3; i++){
        q.enqueue(patrons[i]);
    }
    q.dequeue();
    q.enqueue(patrons[3]);
    q.display();
}