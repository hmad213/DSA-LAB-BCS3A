#include <iostream>
using namespace std;

class Product{
    public:
        string name;
        double price;
        string description;
        bool availability;

        Product(string n, double p, string d, bool a) : name(n), price(p), description(d), availability(a) {}
        Product() : Product("", 0, "", false) {}

        void display(){
            cout << "Name: " << name << ", Price: " << price << ", Description: " << description << "Availability: " << availability << endl;
        }
};

int partition(Product arr[], int start, int end)  {  
    double pivot = arr[end].price;
    int i = start - 1; 

    for(int j = start; j < end; j++) {  
        if (arr[j].price <= pivot) {  
            i++;
            swap(arr[i], arr[j]);
        }  
    }  
    
    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quicksort(Product arr[], int start, int end){  
    if (start < end){  
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);  
        quicksort(arr, p + 1, end);  
    }  
}

int main(void) {
    Product arr[] = {{"Product 1", 10.99, "This is product 1.", true}, {"Product 2", 2.99, "This is product 2.", false}, {"Product 3", 5.99, "This is product 3.", true}};
    cout << "After sorting: " << endl;
    quicksort(arr, 0, 2);
    for(int i = 0; i < 3; i++){
        arr[i].display();
    }
}