#include <iostream>
using namespace std;

class TodoList{
    private:
        int id;
        string title;
    public:
        TodoList(int id, string t) : id(id), title(t){}
        TodoList() : id(-1), title("") {}

        void print(){
            cout << "ID: " << id << ", Title: " << title << endl;
        }
};

template <typename T>
class Stack{
    private:
        T* arr;
        int size;
        int capacity;
    public:
        Stack(int c){
            arr = new T[c];
            capacity = c;
            size = 0;
        }

        ~Stack(){
            delete[] arr;
        }

        T top() {
            if (isEmpty()){
                throw invalid_argument("Empty stack");
            }
            
            return arr[size - 1];
        }

        void push(T value){
            if(isFull()){
                throw invalid_argument("Full stack");
            }

            arr[size++] = value;
        }

        T pop(){
            if(isEmpty()){
                throw invalid_argument("Empty stack");
            }

            return arr[--size];
        }

        bool isEmpty(){return size == 0;}
        bool isFull(){return size == capacity;}
};

int main(){
    TodoList todo1(1, "Clean house"), todo2(2, "Study DSA"), todo3(3, "Complete assignments");
    Stack<TodoList> s(10);

    s.push(todo2);
    s.push(todo1);
    s.push(todo3);

    cout << "Popped todo lists: " << endl;
    TodoList temp = s.pop();
    temp.print();
    temp = s.pop();
    temp.print();
    temp = s.pop();
    temp.print();
}