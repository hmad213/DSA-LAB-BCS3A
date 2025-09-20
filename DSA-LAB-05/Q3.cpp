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

        int getRecursiveLength(Node* cur, int index = 0){
            if(cur == nullptr){
                return index;
            }

            return getRecursiveLength(cur->next, index + 1);
        }

        Node* getHead(){return head;}
};

int main(void){
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList list;

    for(int i = 0; i < 5; i++){
        list.addToTail(arr[i]);
    }

    cout << "Length through recursion: " << list.getRecursiveLength(list.getHead());
}