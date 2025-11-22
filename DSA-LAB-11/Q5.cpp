#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    bool isOccupied;

    Student() {
        rollNumber = -1;
        name = "";
        isOccupied = false;
    }
};

class StudentHashTable {
private:
    static const int TABLE_SIZE = 15;
    Student table[TABLE_SIZE];

    int hashFunction(int rollNumber) {
        return rollNumber % TABLE_SIZE;
    }

public:
    void InsertRecord(int rollNumber, const string& name) {
        int index = hashFunction(rollNumber);
        int attempt = 0;

        while(attempt < TABLE_SIZE) {
            int newIndex = (index + attempt*attempt) % TABLE_SIZE;

            if(!table[newIndex].isOccupied) {
                table[newIndex].rollNumber = rollNumber;
                table[newIndex].name = name;
                table[newIndex].isOccupied = true;
                cout << "Inserted (" << rollNumber << ", " << name << ") at index " << newIndex << endl;
                return;
            }

            attempt++;
        }

        cout << "Hash table is full! Cannot insert record." << endl;
    }

    void SearchRecord(int rollNumber) {
        int index = hashFunction(rollNumber);
        int attempt = 0;

        while(attempt < TABLE_SIZE) {
            int newIndex = (index + attempt*attempt) % TABLE_SIZE;

            if(table[newIndex].isOccupied && table[newIndex].rollNumber == rollNumber) {
                cout << "Record found: " << table[newIndex].name << endl;
                return;
            }

            if(!table[newIndex].isOccupied) {
                break;
            }

            attempt++;
        }

        cout << "Record not found" << endl;
    }

    void Display() {
        cout << "Hash Table:" << endl;
        for(int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << " : ";
            if(table[i].isOccupied)
                cout << "(" << table[i].rollNumber << ", " << table[i].name << ")";
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    StudentHashTable sht;

    sht.InsertRecord(10, "Ali");
    sht.InsertRecord(25, "Bilal");
    sht.InsertRecord(40, "Hammad");
    sht.InsertRecord(55, "Amna");

    sht.Display();

    cout << endl;
    sht.SearchRecord(25);  
    sht.SearchRecord(15);  

    return 0;
}
