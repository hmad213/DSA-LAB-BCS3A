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

        LinkedList extractAlternate(){
            LinkedList list;
            if(head == nullptr){
                return list;
            }

            Node* cur = head;
            Node* prev = nullptr;
            int index = 0;
            while(cur != nullptr){
                if(index % 2 == 1){
                    if(cur == tail){
                        tail = prev;
                    }
                    prev->next = cur->next;
                    list.addToTail(cur->value);
                    delete cur;
                    cur = prev->next;
                }else{
                    prev = cur;
                    cur = cur->next;
                }
    
                index++;
            }

            return list;
        }

        void reverse(){
            if(head == nullptr){
                return;
            }

            tail = head;
            Node* cur = head->next;
            Node* prev = head;
            tail->next = nullptr;
            while(cur != nullptr){
                Node* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            head = prev;
        }

        LinkedList concatLists(LinkedList& list){
            LinkedList concatList;

            Node* cur = head;
            while(cur != nullptr){
                concatList.addToTail(cur->value);
                cur = cur->next;
            }

            cur = list.head;
            while(cur != nullptr){
                concatList.addToTail(cur->value);
                cur = cur->next;
            }

            return concatList;
        }


        Node* getHead(){return head;}
        Node* getTail(){return tail;}
};

int main(void){
    LinkedList l1;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++){
        l1.addToTail(arr[i]);
    }
    l1.print();

    LinkedList l2 = l1.extractAlternate();
    l2.print();

    l2.reverse();
    l2.print();

    LinkedList l3 = l1.concatLists(l2);

    l3.print();
}