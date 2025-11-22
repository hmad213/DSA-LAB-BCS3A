#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<int> table[TABLE_SIZE]; 

    int hashFunction(int key) {
        return (key * 119) % TABLE_SIZE;
    }

public:

    void insert(int key) {
        int index = hashFunction(key);

        for (int x : table[index]) {
            if (x == key) {
                cout << "Key " << key << " already exists" << endl;
                return;
            }
        }

        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);

        for (int x : table[index]) {
            if (x == key)
                return true;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                cout << "Key " << key << " deleted" << endl;
                return;
            }
        }

        cout << "Key " << key << " not found" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << " : ";

            if (table[i].empty()) {
                cout << "EMPTY" << endl;
                continue;
            }

            for (int x : table[i]) {
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable h;

    h.insert(12);
    h.insert(3);
    h.insert(5);
    h.insert(37);

    h.display();
}