#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;
    Node(int value, Node* next = nullptr, Node* prev = nullptr) : value(value), next(next), prev(prev) {}
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~DoublyLinkedList(){
            Node* cur = head, *prev = nullptr;
            while(cur != nullptr){
                prev = cur;
                cur = cur->next;
                delete prev;
            }
        }

        void insertAtHead(int val){
            Node* newNode = new Node(val);
            size++;
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                return;
            }

            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

        void insertAtTail(int val){
            Node* newNode = new Node(val);
            size++;
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                return;
            }

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void removeFromHead(){
            if(head == nullptr){
                return;
            }

            size--;
            Node* temp = head;

            if(head == tail){
                head = nullptr;
                tail = nullptr;
                delete temp;
                return;
            }

            head->next->prev = nullptr;
            head = head->next;
            delete temp;
        }

        void removeFromTail(){
            if(head == nullptr){
                return;
            }

            size--;
            Node* temp = tail;

            if(head == tail){
                head = nullptr;
                tail = nullptr;
                delete temp;
                return;
            }

            tail->prev->next = nullptr;
            tail = tail->prev;
            delete temp;
        }

        void removeFromPosition(int index){
            if(index < 0){
                return;
            }

            if(head == nullptr){
                return;
            }

            if(index == 0){
                removeFromHead();
                return;
            }

            int i = 0;
            Node* cur = head;
            while(i < index && cur != nullptr){
                cur = cur->next;
                i++;
            }

            if(cur == tail){
                removeFromTail();
                return;
            }

            if(i == index){
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                size--;
                return;
            }
        }

        void print(){
            cout << "HEAD -> ";
            Node* cur = head;
            while(cur != nullptr){
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }

        void reverse(Node* root){
            if(root == nullptr){
                swap(head, tail);
                return;
            }

            swap(root->next, root->prev);

            reverse(root->prev);
        }

        Node* getHead(){return head;}
        Node* getTail(){return tail;}
        int getSize(){return size;}
};

int main(void){
    int arr[] = {10, 5, 7, 3, 6, 2, 9, 1};
    int size = sizeof(arr) / sizeof(int);
    DoublyLinkedList list;

    for(int i = 0; i < size; i++){
        list.insertAtTail(arr[i]);
    }
    cout << "Original list: " << endl;
    list.print();

    list.removeFromHead();

    cout << endl;
    cout << "List after removing from front: " << endl;
    list.print();

    list.removeFromTail();

    cout << endl;
    cout << "List after removing from end: " << endl;
    list.print();

    list.removeFromPosition(2);

    cout << endl;
    cout << "List after removing from index 2: " << endl;
    list.print();

    list.reverse(list.getHead());

    cout << endl;
    cout << "List after reversing: " << endl;
    list.print();
}