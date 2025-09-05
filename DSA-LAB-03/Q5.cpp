#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
struct Node{
    T value;        
    Node* next;
};

template <typename T>
class LinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void addToHead(T value){
            Node<T>* newNode = new Node<T>;
            newNode->value = value;

            if(head == nullptr){
                newNode->next = nullptr;
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void addToTail(T value){
            Node<T>* newNode = new Node<T>;
            newNode->value = value;

            if(tail == nullptr){
                newNode->next = nullptr;
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                newNode->next = nullptr;
                tail = newNode;
            }
            size++;
        }

        void addInBetween(T value, int index){
            Node<T>* newNode = new Node<T>;
            newNode->value = value;

            if(index == 0){
                addToHead(value);
                return;
            }else if(index >= size){
                addToTail(value);
                return;
            }

            Node<T>* cur = head;
            int i = 0;
            while(cur != nullptr){
                if(i == index){
                    newNode->next = cur->next;
                    cur->next = newNode;
                    size++;
                    return;
                }
                cur = cur->next;
                i++;
            }
        }

        void deleteValue(T value){
            if(head == nullptr){
                cout << "No such value exists" << endl;
                return;
            }else if(head->value == value){
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                size--;
                return;
            }

            Node<T>* cur = head;
            Node<T>* prev = nullptr;

            while(cur != nullptr){
                if(cur->value == value){
                    prev->next = cur->next;
                    delete cur;
                    size--;
                    return;
                }
                prev = cur;
                cur = cur->next;
            }

            cout << "No such value exists!" << endl;
        }

        void print(){
            Node<T>* cur = head;
            while(cur != nullptr){
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }

        void reverse(){
            if(head == nullptr){
                return;
            }

            tail = head;
            Node<T>* prev = head;
            Node<T>* cur = head->next;
            while(cur != nullptr){
                Node<T>* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            tail->next = nullptr;
            head = prev;
        }

        bool isPalindrome(){
            if(head == nullptr){
                return false;
            }

            int mid = floor(size / 2.0);

            LinkedList first;
            LinkedList last;

            Node<T>* cur = head;
            int index = 1;
            while(cur != nullptr){
                if(index > mid){
                    last.addToHead(cur->value);
                }else{
                    first.addToTail(cur->value);
                }
                index++;
                cur = cur->next;
            }
            
            Node<T>* fCur = first.getHead(), *lCur = last.getHead();

            while(fCur != nullptr){
                if(fCur->value != lCur->value) return false;
                fCur = fCur->next;
                lCur = lCur->next;
            }
            return true;
        }

        Node<T>* getHead(){return head;}
        Node<T>* getTail(){return tail;}
};

int main(void){
    LinkedList<int> l1;
    int arr1[] = {1, 0, 2, 0};

    for(int i = 0; i < (sizeof(arr1) / sizeof(int)); i++){
        l1.addToTail(arr1[i]);
    }

    l1.print();
    cout << (l1.isPalindrome() ? "The list is a palindrome!" : "The list is not a palindrome") << endl;
    cout << endl;

    l1.addToTail(1);

    l1.print();
    cout << (l1.isPalindrome() ? "The list is a palindrome!" : "The list is not a palindrome") << endl;
    cout << endl;

    LinkedList<string> l2;
    string arr2[] = {"B", "O", "R", "R", "O", "W", "O", "R", "R", "O", "B"};

    for(int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++){
        l2.addToTail(arr2[i]);
    }

    l2.print();
    cout << (l2.isPalindrome() ? "The list is a palindrome!" : "The list is not a palindrome") << endl;
    cout << endl;
}