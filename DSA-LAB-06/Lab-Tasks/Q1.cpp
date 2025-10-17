#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    char stack[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool push(char item) {
        if (isFull()) {
            cout << "Cannot push, stack is full" << endl;
            return false;
        }
        top++;
        stack[top] = item;
        return true;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Cannot pop. Stack is empty" << endl;
            return '\0';
        }
        char item = stack[top];
        top--;
        return item;
    }

    char peek() {
        if(isEmpty()) {
            cout << "Cannot peek. Stack is empty" << endl;
            return '\0';
        }
        return stack[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

bool isPalindrome(string word){
    Stack s;
    for(int i = 0; i < word.length(); i++){
        s.push(word[i]);
    }
    s.display();

    for(int i = 0; i < word.length(); i++){
        char poppedChar = s.pop();
        char curChar = word[i];
        if(curChar != poppedChar) return false;
    }
    return true;
}

int main(void){
    string word = "BORROWROB";

    if(isPalindrome(word)){
        cout << "The word " << word << " is a palindrome!" << endl;
    }else{
        cout << "The word " << word << " is not a palindrome!" << endl;
    }
}