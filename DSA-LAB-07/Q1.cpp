#include <iostream>
using namespace std;

class Student{
    public:
        int score;
        string name;

        Student(int score, string name) : score(score), name(name) {}
        Student() : Student(-1, "") {}

        void display(){
            cout << "Name: " << name << ", Score: " << score << endl;
        }
};

struct Node {
    Student value;
    Node* next;

    Node(string name, int score, Node* nxt = nullptr) : value(score, name), next(nxt) {}
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void addToHead(string name, int score) {
            Node* newNode = new Node(name, score, head);
            head = newNode;
        }

        void addToTail(string name, int score) {
            Node* newNode = new Node(name, score);
            if (!head) {
                head = newNode;
                return;
            }
            Node* cur = head;
            while (cur->next != nullptr) cur = cur->next;
            cur->next = newNode;
        }

        void addAtIndex(string name, int score, int index) {
            if (index == 0) {
                addToHead(name, score);
                return;
            }

            Node* cur = head;
            int i = 1;

            while (cur && i < index) {
                cur = cur->next;
                i++;
            }

            if (!cur) {
                addToTail(name, score);
            } else {
                cur->next = new Node(name, score, cur->next);
            }
        }

        void deleteValue(string name, int score) {
            if (!head) {
                cout << "List is empty!" << endl;
                return;
            }

            if (head->value.score == score && head->value.name == name) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* cur = head->next;
            Node* prev = head;

            while (cur) {
                if (cur->value.score == score && cur->value.name == name) {
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
                cur->value.display();
                cur = cur->next;
            }
        }

        Node* getHead(){return head;}
};

int getMax(LinkedList& l) {  
    Node* cur = l.getHead();
    int max = INT_MIN;
    while(cur != nullptr){
        if(cur->value.score > max){
            max = cur->value.score;
        }
        cur = cur->next;
    }
    return max;
}

void countingSort(LinkedList& input, int n, int place)
{  
    LinkedList output;
    for(int i = 0; i < n; i++){
        output.addToTail("", 0);
    }
    int count[10] = {0};    

    for (int i = 0; i < n; i++)  
        count[(input[i]->value.score / place) % 10]++;  
        
    for (int i = 1; i < 10; i++)  
        count[i] += count[i - 1];  

    for (int i = n - 1; i >= 0; i--) {  
        output[count[(input[i]->value.score / place) % 10] - 1]->value = input[i]->value;  
        count[(input[i]->value.score / place) % 10]--;  
    }  

    for (int i = 0; i < n; i++)  
        input[i]->value = output[i]->value;  
}  

void radixsort(LinkedList& input, int n) {   
    int max = getMax(input);  

    for (int place = 1; max / place > 0; place *= 10)  
    countingSort(input, n, place);  
}  

int main() {
    LinkedList l;
    l.addToHead("Ayan", 90);
    l.addToHead("Zameer", 60);
    l.addToHead("Sara", 70);
    l.addToHead("Sohail", 30);
    l.addToHead("Ahmed", 20);

    cout << "Before sort:" << endl;
    l.print();

    radixsort(l, 5);

    cout << endl;
    cout << "After sort:" << endl;
    l.print();
}