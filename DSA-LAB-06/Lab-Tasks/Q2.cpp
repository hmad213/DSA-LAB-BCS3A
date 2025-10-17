#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Transaction{
    private:
        int id;
        double amount;
        string description;
        bool isSale;
    public:
        static int count;
        Transaction(double a, string d){
            id = ++count;
            amount = a;
            description = d;

            if(amount >= 0){
                isSale = true;
            }else{
                isSale = false;
            }
        }

        void shortenDescription(){
            if(description.size() > 20){
                description = description.substr(0, 20) + "...";
            }
        }

        void applyDiscount(){
            if(amount < 500){
                return;
            }else if(amount < 1000){
                amount *= 0.95;
            }else if(amount < 1500){
                amount *= 0.85;
            }else{
                amount *= 0.70;
            }
        }

        void reverseTransaction(){
            amount *= -1;
            description += "[REVERSED]";
            isSale = !isSale;
        }

        int getID(){return id;}
        double getAmount(){return amount;}
        string getDescription(){return description;}
        bool getIsSale(){return isSale;}
};

int Transaction::count = 0;

template <typename T>
struct Node{
    T value;
    Node* next;
    Node(T v) : value(v), next(nullptr){}
};

template <typename T>
class Stack{
    private:
        Node<T>* top;
    public:
        Stack(){
            top = nullptr;
        }

        void push(T value){
            Node<T>* temp = new Node<T>(value);
            if(top == nullptr){
                top = temp;
                return;
            }

            temp->next = top;
            top = temp;
        }

        T pop(){
            if(top == nullptr){
                cout << "Stack is Empty!" << endl;
                throw invalid_argument("Empty stack!");
            }

            Node<T>* temp = top;
            top = top->next;
            T retValue = temp->value;
            delete temp;
            return retValue;
        }

        T peek(){
            if(top == nullptr){
                cout << "Stack is Empty!" << endl;
                throw invalid_argument("Empty stack!");
            }

            return top->value;
        }

        bool isEmpty(){return top == nullptr;}
        Node<T>* getTop(){return top;}

       ~Stack(){
            while(top != nullptr){
                Node<T>* temp = top;
                top = top->next;
                delete temp;
            }
        }
};

void displayStackTransactions(Stack<Transaction*>& s){
    cout << "Top" << endl;
    Node<Transaction*>* cur = s.getTop();
    while(cur != nullptr){
        cout << "[id = " << cur->value->getID() << ", amount = " << cur->value->getAmount() << ", description = " << cur->value->getDescription() << ", flag = " << cur->value->getIsSale() << "]" << endl;
        cur = cur->next;
    }
    cout << "Bottom" << endl;
}

double getTransactionsTotal(Stack<Transaction*>& s){
    Node<Transaction*>* cur = s.getTop();
    double total = 0;
    while(cur != nullptr){
        total += cur->value->getAmount();
        cur = cur->next;
    }
    return total;
}

int main(void){
    srand(time(0));

    Transaction arr[4] = {Transaction(1200, "Blue Jacket"), Transaction(450, "Cotton Socks"), Transaction(1700, "Leather Jacket"), Transaction(-300, "Defective Shirt")};

    Stack<Transaction*> s;

    for (int i = 3; i >= 0; --i) {
        int randomIndex = rand() % (i + 1);

        swap(arr[randomIndex], arr[i]);

        arr[i].applyDiscount();
        arr[i].shortenDescription();
        s.push(&arr[i]);
    }

    cout << "Total: " << getTransactionsTotal(s) << endl;

    Transaction* temp = s.pop();
    int prevAmount = temp->getAmount();
    temp->reverseTransaction();

    cout << "Popped Transaction: " << temp->getDescription() << endl;
    cout << "Amount changed from " << prevAmount << " to " << temp->getAmount() << endl;
    cout << "Flag updated to " << temp->getIsSale() << endl;

    displayStackTransactions(s);

}