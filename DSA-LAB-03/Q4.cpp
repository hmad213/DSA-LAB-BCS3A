#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void addToHead(int value){
            Node* newNode = new Node;
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

        void addToTail(int value){
            Node* newNode = new Node;
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

        void addInBetween(int value, int index){
            Node* newNode = new Node;
            newNode->value = value;

            if(index == 0){
                addToHead(value);
                return;
            }else if(index >= size){
                addToTail(value);
                return;
            }
            
            Node* cur = head;
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

        void deleteValue(int value){
            if(head == nullptr){
                cout << "No such value exists" << endl;
                return;
            }else if(head->value == value){
                Node* temp = head;
                head = head->next;
                delete temp;
                size--;
                return;
            }

            Node* cur = head;
            Node* prev = nullptr;

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
            Node* cur = head;
            while(cur != nullptr){
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }

        void setEvenBeforeOdd(){
            LinkedList even;
            LinkedList odd;
            Node* cur = head;

            while(cur != nullptr){
                if(cur->value % 2 == 0){
                    even.addToTail(cur->value);
                }else{
                    odd.addToTail(cur->value);
                }
                cur = cur->next;
            }
            if(even.getHead() == nullptr){
                head = odd.getHead();
            }else if(odd.getHead() == nullptr){
                head = even.getHead();
            }else{
                head = even.getHead();
                tail = even.getTail();
                tail->next = odd.getHead();
                tail = odd.getTail();
            }
        }

        Node* getHead(){return head;}
        Node* getTail(){return tail;}
};

int main(void){
    int arr1[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    LinkedList l1;

    for(int i = 0; i < (sizeof(arr1) / sizeof(int)); i++){
        l1.addToTail(arr1[i]);
    }

    l1.print();
    l1.setEvenBeforeOdd();
    l1.print();

    cout << endl;

    int arr2[] = {8, 12, 10};
    LinkedList l2;

    for(int i = 0; i < (sizeof(arr2) / sizeof(int)); i++){
        l2.addToTail(arr2[i]);
    }

    l2.print();
    l2.setEvenBeforeOdd();
    l2.print();

    cout << endl;

    int arr3[] = {1, 3, 5, 7};
    LinkedList l3;

    for(int i = 0; i < (sizeof(arr3) / sizeof(int)); i++){
        l3.addToTail(arr3[i]);
    }

    l3.print();
    l3.setEvenBeforeOdd();
    l3.print();

    cout << endl;
}