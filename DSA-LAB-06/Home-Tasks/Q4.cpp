#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node* next;
    Node(T val) : value(val), next(nullptr) {}
};

template <typename T>
class Stack{
    private:
        Node<T>* head;
    public:
        Stack(){
            head = nullptr;
        }

        ~Stack(){
            Node<T>* cur = head,* prev = nullptr;
            while(cur != nullptr){
                prev = cur;
                cur = cur->next;
                delete prev;
            }
        }

        T top(){
            if(isEmpty()){
                throw invalid_argument("Empty stack");
            }
            return head->value;
        }

        void push(T value){
            Node<T>* newNode = new Node<T>(value);
            if(isEmpty()){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        T pop(){
            if(isEmpty()){
                throw invalid_argument("Empty stack");
            }

            Node<T>* temp = head;
            head = head->next;
            T retValue = temp->value;
            delete temp;
            return retValue;
        }

        bool isEmpty(){return head == nullptr;}
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
    }
    return 0;
}

double evaluateInfix(const string& expr) {
    Stack<string> values;
    Stack<string> ops;
    string token;

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isdigit(c) || c == '.') {
            token = "";
            while (i < expr.size() && (isdigit(expr[i]) || expr[i]=='.')) {
                token += expr[i++];
            }
            i--;
            values.push(token);
        }
        else if (c == '(') {
            ops.push(string(1, c));
        }
        else if (c == ')') {
            while (!ops.isEmpty() && ops.top()[0] != '(') {
                double b = stod(values.pop());
                double a = stod(values.pop());
                char op = ops.pop()[0];
                values.push(to_string(applyOp(a, b, op)));
            }
            if (!ops.isEmpty()) ops.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.isEmpty() && precedence(ops.top()[0]) >= precedence(c)) {
                double b = stod(values.pop());
                double a = stod(values.pop());
                char op = ops.pop()[0];
                values.push(to_string(applyOp(a, b, op)));
            }
            ops.push(string(1, c));
        }
        else {
            throw runtime_error(string("Invalid character: ") + c);
        }
    }

    while (!ops.isEmpty()) {
        double b = stod(values.pop());
        double a = stod(values.pop());
        char op = ops.pop()[0];
        values.push(to_string(applyOp(a, b, op)));
    }

    return stod(values.pop());
}

int main() {
    string expr = "12 + 13 - 5 * (0.5 + 0.5) + 1";

    try {
        double result = evaluateInfix(expr);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}