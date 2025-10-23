#include <iostream>
#include <cctype>
using namespace std;

template <typename T>
class Stack{
    private:
        T* arr;
        int size;
        int capacity;
    public:
        Stack(int c){
            arr = new T[c];
            capacity = c;
            size = 0;
        }

        ~Stack(){
            delete[] arr;
        }

        T top() {
            if (isEmpty()){
                throw invalid_argument("Empty stack");
            }
            
            return arr[size - 1];
        }

        void push(T value){
            if(isFull()){
                throw invalid_argument("Full stack");
            }

            arr[size++] = value;
        }

        T pop(){
            if(isEmpty()){
                throw invalid_argument("Empty stack");
            }

            return arr[--size];
        }

        bool isEmpty(){return size == 0;}
        bool isFull(){return size == capacity;}
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string& expr) {
    Stack<char> s(expr.size());
    string output;

    for (int i = 0; i < expr.size(); i++) {
        char ch = expr[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            output += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                output += s.pop();
            }
            if (!s.isEmpty()) s.pop();
        }
        else {
            while (!s.isEmpty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) && isRightAssociative(ch) ||
                   (precedence(s.top()) >= precedence(ch) && !isRightAssociative(ch)))) {
                output += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        output += s.pop();
    }

    return output;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
}