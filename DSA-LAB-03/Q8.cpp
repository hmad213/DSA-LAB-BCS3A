#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* prev;
    Node* next;
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void addToTail(int value){
            Node* newNode = new Node;
            newNode->value = value;

            if(head == nullptr){
                newNode->next = nullptr;
                newNode->prev = nullptr;
                head = newNode;
                tail = newNode;
                return;
            }

            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        void print(){
            Node* cur = head;
            while(cur != nullptr){
                cout << cur->value << " <-> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }

        Node* getHead(){return head;}
        Node* getTail(){return tail;}

        friend DoublyLinkedList concatLists(DoublyLinkedList &l1, DoublyLinkedList &l2);
};

DoublyLinkedList concatLists(DoublyLinkedList &l1, DoublyLinkedList &l2){
    DoublyLinkedList l3;
    Node* cur = l1.head;
    while(cur != nullptr){
        l3.addToTail(cur->value);
        cur = cur->next;
    }

    cur = l2.head;
    while(cur != nullptr){
        l3.addToTail(cur->value);
        cur = cur->next;
    }

    return l3;
}

int main(void) {
    DoublyLinkedList l1, l2;

    l1.addToTail(1);
    l1.addToTail(2);
    l1.addToTail(3);

    l2.addToTail(4);
    l2.addToTail(5);

    cout << "List 1: ";
    l1.print();

    cout << "List 2: ";
    l2.print();

    DoublyLinkedList l3 = concatLists(l1, l2);
    cout << "Concatenated List: ";
    l3.print();
}