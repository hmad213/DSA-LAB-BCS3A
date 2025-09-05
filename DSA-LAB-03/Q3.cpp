#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void addToHead(T value) {
            Node<T>* newNode = new Node<T>;
            newNode->value = value;

            if (head == nullptr) {
                newNode->next = nullptr;
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void addToTail(T value) {
            Node<T>* newNode = new Node<T>;
            newNode->value = value;

            if (tail == nullptr) {
                newNode->next = nullptr;
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->next = nullptr;
                tail = newNode;
            }
            size++;
        }

        void addInBetween(T value, int index) {
            Node<T>* newNode = new Node<T>;
            newNode->value = value;

            if (index == 0) {
                addToHead(value);
                return;
            } else if (index >= size) {
                addToTail(value);
                return;
            }

            Node<T>* cur = head;
            int i = 0;
            while (cur != nullptr) {
                if (i == index) {
                    newNode->next = cur->next;
                    cur->next = newNode;
                    size++;
                    return;
                }
                cur = cur->next;
                i++;
            }
        }

        void deleteValue(T value) {
            if (head == nullptr) {
                cout << "No such value exists" << endl;
                return;
            } else if (head->value == value) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                size--;
                return;
            }

            Node<T>* cur = head;
            Node<T>* prev = nullptr;

            while (cur != nullptr) {
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

        int search(T value) {
            Node<T>* cur = head;
            int index = 0;
            while (cur != nullptr) {
                if (cur->value == value) {
                    return index;
                }
                cur = cur->next;
                index++;
            }
            return -1;
        }

        void print() {
            Node<T>* cur = head;
            while (cur != nullptr) {
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }

        Node<T>* getHead() { return head; }
        Node<T>* getTail() { return tail; }
        int getSize() { return size;}
};

void reserveTicket(LinkedList<LinkedList<string>>& flights){
    cout << "Enter flight ID: ";
    int id;
    cin >> id;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int size = flights.getSize();
    if(id > size || id <= 0){
        cout << "ID is out of range!" << endl;
        return;
    }

    cout << "Enter passenger name: ";
    string name;
    getline(cin, name);

    Node<LinkedList<string>>* cur = flights.getHead();
    int index = 1;
    while(cur != nullptr && index < id){
        cur = cur->next;
        index++;
    }
    cur->value.addToTail(name);
}

void cancelTicket(LinkedList<LinkedList<string>>& flights){
    cout << "Enter flight ID: ";
    int id;
    cin >> id;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int size = flights.getSize();
    if(id > size || id <= 0){
        cout << "ID is out of range!" << endl;
        return;
    }

    cout << "Enter passenger name: ";
    string name;
    getline(cin, name);

    Node<LinkedList<string>>* cur = flights.getHead();
    int index = 1;
    while(cur != nullptr && index < id){
        cur = cur->next;
        index++;
    }

    LinkedList<string> passengerCur = cur->value;
    passengerCur.deleteValue(name);
}

void checkReservation(LinkedList<LinkedList<string>>& flights){
    cout << "Enter flight ID: ";
    int id;
    cin >> id;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int size = flights.getSize();
    if(id > size || id <= 0){
        cout << "ID is out of range!" << endl;
        return;
    }

    cout << "Enter passenger name: ";
    string name;
    getline(cin, name);

    Node<LinkedList<string>>* cur = flights.getHead();
    int index = 1;
    while(cur != nullptr && index < id){
        cur = cur->next;
        index++;
    }

    if(cur->value.search(name) == -1){
        cout << "The passenger does not have a reservation!" << endl;
    }else{
        cout << "The passenger has a reservation" << endl;
    }
}

void printFlightPassengers(LinkedList<LinkedList<string>>& flights){
    cout << "Enter flight ID: ";
    int id;
    cin >> id;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int size = flights.getSize();
    if(id > size || id <= 0){
        cout << "ID is out of range!" << endl;
        return;
    }

    Node<LinkedList<string>>* cur = flights.getHead();
    int index = 1;
    while(cur != nullptr && index < id){
        cur = cur->next;
        index++;
    }

    cur->value.print();
}

void printAllPassengers(LinkedList<LinkedList<string>>& flights){
    Node<LinkedList<string>>* cur = flights.getHead();
    int index = 1;
    while(cur != nullptr){
        cout << "Flight " << index++ << ": ";
        cur->value.print();
        cur = cur->next;
    }
}

int main(void){
    LinkedList<LinkedList<string>> flights;
    for(int i = 0; i < 5; i++){
        LinkedList<string> temp;
        flights.addToTail(temp);
    }

    int option = -1;
    while(option != 6){
        cout << "1: Reserve a ticket" << endl;
        cout << "2: Cancel a ticket" << endl;
        cout << "3: Check reservation of person" << endl;
        cout << "4: Print Flight passengers" << endl;
        cout << "5: Print all passengers" << endl;
        cout << "6: Exit" << endl;
        cout << "Choose an option: ";

        cin >> option;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        cout << endl;

        switch (option){
            case 1:
                reserveTicket(flights);
                break;
            case 2:
                cancelTicket(flights);
                break;
            case 3:
                checkReservation(flights);
                break;
            case 4:
                printFlightPassengers(flights);
                break;
            case 5:
                printAllPassengers(flights);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    }
}