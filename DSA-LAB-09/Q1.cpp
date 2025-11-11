#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* right;
    Node* left;

    Node(int v, Node* right = nullptr, Node* left = nullptr) : value(v), right(right), left(left){}
};

void convertToAVL(Node* root) {
    if(!root->left){
        Node* next = root->right;
        root->right = next->left;
        next->left = root;
    }else if(!root->right){
        Node* next = root->left;
        root->left = next->right;
        next->right = root;
    }
}

int main() {
    Node* A = new Node(10);
    A->left = new Node(6);
    A->left->left = new Node(4);
    A->left->right = new Node(8);

    convertToAVL(A);

    Node* B = new Node(10);
    B->right = new Node(16);
    B->right->left = new Node(12);
    B->right->right = new Node(18);

    convertToAVL(B);
}