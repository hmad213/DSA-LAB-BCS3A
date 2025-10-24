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

    public:
        LinkedList() : head(nullptr) {}

        void addToHead(int value) {
            Node* newNode = new Node(value, head);
            head = newNode;
        }

        void addToTail(int value) {
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
                return;
            }

            Node* cur = head->next;
            Node* prev = head;

            while (cur) {
                if (cur->value == value) {
                    prev->next = cur->next;
                    delete cur;
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
            while (cur) {
                cout << cur->value << " ";
                cur = cur->next;
            }
        }

        int getSize(){
            int size = 0;
            Node* cur = head;
            while(cur != nullptr){
                cur = cur->next;
                size++;
            }
            return size;
        }

        Node* getHead(){return head;}
};

void swapNodes(LinkedList& l, int index1, int index2){
    Node* node1 = l[index1];
    Node* node2 = l[index2];
    swap(node1->value, node2->value);
}

int partition(LinkedList& l, int start, int end){  
    int pivot = l[end]->value;
    int i = start - 1;

    for(int j = start; j < end; j++) {  
        if (l[j]->value <= pivot) {  
            i++;
            swapNodes(l, i, j);
        }  
    }  
    
    swapNodes(l, i+1, end);

    return i + 1;
}

void quick(LinkedList& l, int start, int end){  
    if (start < end) {  
        int p = partition(l, start, end);
        quick(l, start, p - 1);  
        quick(l, p + 1, end);  
    }  
}

int main(void){
    LinkedList list;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int size = sizeof(arr) / sizeof(int);

    for(int i = 0; i < size; i++){
        list.addToTail(arr[i]);
    }

    cout << "Before sorting: " << endl;
    list.print();
    cout << endl;

    quick(list, 0, size - 1);

    cout << "After sorting: " << endl;
    list.print();
    cout << endl;
}