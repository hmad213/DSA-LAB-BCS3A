#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class CircularLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        CircularLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void insertAtEnd(int value){
            Node* newNode = new Node;
            newNode->value = value;

            if(head == nullptr){
                head = newNode;
                tail = newNode;
                tail->next = head;
                return;
            }

            tail->next = newNode;
            tail = tail->next;
            tail->next = head;
        }

        void insertAtStart(int value){
            Node* newNode = new Node;
            newNode->value = value;

            if(head == nullptr){
                head = newNode;
                tail = newNode;
                tail->next = head;
                return;
            }

            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

        void insertAtIndex(int index, int value) {
            if (index == 0) {
                insertAtStart(value);
                return;
            }

            Node* newNode = new Node;
            newNode->value = value;

            Node* cur = head;
            int i = 0;

            while (i < index - 1 && cur->next != head) {
                cur = cur->next;
                i++;
            }

            if (cur == tail) {
                insertAtEnd(value);
                return;
            }

            newNode->next = cur->next;
            cur->next = newNode;
        }

        void deleteValue(int value){
            if(head == nullptr){
                return;
            }

            if (head == tail && head->value == value) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            
            if(head->value == value){
                Node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
                return;
            }

            Node* cur = head->next;
            Node* prev = head;

            while (cur != head) {
                if(cur->value == value){
                    prev->next = cur->next;

                    if (cur == tail) {
                        tail = prev;
                    }

                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur->next;
            }
        }

        void print(){
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }

            cout << "Head -> ";
            Node* cur = head;
            do{
                cout << cur->value << " -> ";
                cur = cur->next;
            }while(cur != head);

            if(tail->next == head){
                cout << "..." << endl;
            }
        }
};

int main(void) {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtStart(5);

    cll.print();  

    cll.deleteValue(5);
    cll.deleteValue(30);
    cll.deleteValue(100);

    cll.print();

    return 0;
}
