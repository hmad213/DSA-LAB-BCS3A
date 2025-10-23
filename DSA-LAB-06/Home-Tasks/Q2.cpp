#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node* next;
    Node(T val) : value(val), next(nullptr) {}
};

template <typename T>
class Stack{
    private:
        Node<T>* head;
    public:
        Stack(){
            head = nullptr;
        }

        ~Stack(){
            Node<T>* cur = head,* prev = nullptr;
            while(cur != nullptr){
                prev = cur;
                cur = cur->next;
                delete prev;
            }
        }

        T top(){
            if(isEmpty()){
                throw invalid_argument("Empty stack");
            }
            return head->value;
        }

        void push(T value){
            Node<T>* newNode = new Node<T>(value);
            if(isEmpty()){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        T pop(){
            if(isEmpty()){
                throw invalid_argument("Empty stack");
            }

            Node<T>* temp = head;
            head = head->next;
            T retValue = temp->value;
            delete temp;
            return retValue;
        }

        bool isEmpty(){return head == nullptr;}
};

int main(void){
    Stack<string> s;
    string arr[5] = {"Instagram", "LinkedIn", "Twitter", "Facebook", "Google"};
    for(int i = 0; i < 5; i++){
        s.push(arr[i]);
    }

    string temp = s.pop();
    cout << "Back button pressed! Returning to " << temp << endl;
    temp = s.pop();
    cout << "Back button pressed! Returning to " << temp << endl;
}