#include <iostream>
using namespace std;

const int SIZE = 100;

struct Node {
    int sum;       
    int a, b;      
    Node* next;
    Node(int s, int x, int y) {
        sum = s;
        a = x;
        b = y;
        next = nullptr;
    }
};

// Simple Hash Map with Chaining
class HashMap {
private:
    Node* table[SIZE];

    int hash(int key) {
        return (key * 141) % SIZE;
    }

public:
    HashMap() {
        for(int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    void insert(int sum, int a, int b) {
        int index = hash(sum);
        Node* newNode = new Node(sum, a, b);
        newNode->next = table[index];
        table[index] = newNode;
    }

    Node* get(int sum) {
        int index = hash(sum);
        Node* curr = table[index];
        while(curr) {
            if(curr->sum == sum)
                return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    ~HashMap() {
        for(int i = 0; i < SIZE; i++) {
            Node* curr = table[i];
            while(curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }
};

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    HashMap map;
    bool found = false;

    for(int i = 0; i < n-1 && !found; i++) {
        for(int j = i+1; j < n && !found; j++) {
            int sum = arr[i] + arr[j];

            Node* existing = map.get(sum);
            if(existing) {
                if(existing->a != arr[i] && existing->a != arr[j] &&
                   existing->b != arr[i] && existing->b != arr[j]) {
                    cout << "(" << existing->a << ", " << existing->b << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    found = true;
                    break;
                }
            } else {
                map.insert(sum, arr[i], arr[j]);
            }
        }
    }

    if(!found)
        cout << "No pairs found" << endl;

    return 0;
}
