#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;


struct Node {
    string key;           
    string value;    
    Node* next;        

    Node(string k, const string& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];  

    int hashFunction(string key) {
        int total = 0;
        for(int i = 0; i < key.size(); i++){
            total += key[i];
        }
        return total % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(string key, const string& str) {
        int index = hashFunction(key);

        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = str;  
                return;
            }
            current = current->next;
        }
        
        Node* newNode = new Node(key, str);
        newNode->next = table[index];
        table[index] = newNode;
    }

    string search(string key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        return "NOT FOUND";
    }


    void remove(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr && temp->key!=key) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr){
        	cout << "Key " << key << " not found\n";
		}
        if (prev == nullptr) {
            table[index] = temp->next;
        } 
		else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Key " << key << " deleted\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << " : ";
            Node* current = table[i];
            if (!current) {
                cout << "EMPTY";
            }
            while (current != nullptr) {
                cout << " -> [Key: " << current->key
                     << ", Name: " << current->value << "]";
                current = current->next;
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable h;

    h.insert("A", "aaaa");
    h.insert("B", "bbbb");
    h.insert("C", "cccc");
    h.insert("D", "dddd");

    h.display();
}