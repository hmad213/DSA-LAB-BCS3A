#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int value, Node* nxt = nullptr) : value(value), next(nxt) {}
};

class LinkedList {
    private:
        Node* head;
        int size;

    public:
        LinkedList() : head(nullptr), size(0) {}

        void addToHead(int value) {
            Node* newNode = new Node(value, head);
            head = newNode;
            size++;
        }

        void addToTail(int value) {
            size++;
            Node* newNode = new Node(value);
            if (!head) {
                head = newNode;
                return;
            }
            Node* cur = head;
            while (cur->next != nullptr) cur = cur->next;
            cur->next = newNode;
        }

        void addAtIndex(int value, int index) {
            if (index == 0) {
                addToHead(value);
                return;
            }

            Node* cur = head;
            int i = 1;

            while (cur && i < index) {
                cur = cur->next;
                i++;
            }

            if (!cur) {
                addToTail(value);
            } else {
                cur->next = new Node(value, cur->next);
                size++;
            }
        }

        void deleteValue(int value) {
            if (!head) {
                cout << "List is empty!" << endl;
                return;
            }

            if (head->value == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                size--;
                return;
            }

            Node* cur = head->next;
            Node* prev = head;

            while (cur) {
                if (cur->value == value) {
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
        
        void deleteAtIndex(int index) {
            if (!head) {
                cout << "List is empty!" << endl;
                return;
            }

            if (index == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
                size--;
                return;
            }

            Node* cur = head->next;
            Node* prev = head;
            int i = 1;

            while (cur && i < index) {
                prev = cur;
                cur = cur->next;
                i++;
            }

            if (!cur) {
                cout << "Index out of bounds!" << endl;
                return;
            }

            prev->next = cur->next;
            delete cur;
            size--;
        }

        Node* operator[](int index){
            if(index < 0) throw invalid_argument("index should be greater than 0");
            int i = 0;
            Node* cur = head;
            while(i < index && cur != nullptr){
                cur = cur->next;
                i++;
            }

            if(cur == nullptr){
                throw invalid_argument("index too high");
            }else{
                return cur;
            }
        }

        void print() {
            Node* cur = head;
            cout << "HEAD -> ";
            while (cur) {
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }

        int getSize(){return size;}
        Node* getHead(){return head;}
};

void bubbleSort(LinkedList& list){
    int size = list.getSize();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            Node* node1 = list[j];
            Node* node2 = list[j + 1];
            if(node1->value > node2->value){
                swap(node1->value, node2->value);
            }
        }
    }
}

void performOperation(LinkedList& list1, LinkedList& list2){
    Node* head1 = list1.getHead();
    Node* head2 = list2.getHead();
    int i = 0;
    while(head1 != nullptr && head2 != nullptr){
        if(i % 2 == 0){
            list1.addAtIndex(head2->value, i + 1);
            list2.deleteAtIndex(0);
            head2 = list2.getHead();
        }
        head1 = head1->next;
        i++;
    }
}

int main(void){
    int arr[] = {10, 5, 7, 3, 6, 2, 9, 1};
    int size = sizeof(arr) / sizeof(int);
    LinkedList list;

    for(int i = 0; i < size; i++){
        list.addToTail(arr[i]);
    }

    cout << "Before sorting: " << endl;
    list.print();

    bubbleSort(list);

    cout << endl;
    cout << "After sorting: " << endl;
    list.print();

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7, 8};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    LinkedList list1, list2;

    for(int i = 0; i < size1; i++){
        list1.addToTail(arr1[i]);
    }
    for(int i = 0; i < size2; i++){
        list2.addToTail(arr2[i]);
    }

    cout << endl;
    cout << "Before Operation: " << endl;
    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();

    performOperation(list1, list2);

    cout << endl;
    cout << "After Operation: " << endl;
    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();
}