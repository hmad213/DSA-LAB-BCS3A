#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int value, Node* right = nullptr, Node* left = nullptr) : value(value), right(right), left(left){}
};

class BST{
    public:
        Node* root;

        bool isValid(Node* node) {
        if (node == nullptr) return true;

        if (node->left != nullptr) {
            if (node->left->value >= node->value) return false;
        }

        if (node->right != nullptr) {
            if (node->right->value <= node->value) return false;
        }

        return isValid(node->left) && isValid(node->right);
    }
};

int main(void){
    BST bst;

    bst.root = new Node(10);
    bst.root->left = new Node(5);
    bst.root->right = new Node(20);
    bst.root->right->left = new Node(25);
    bst.root->right->right = new Node(30);

    if(bst.isValid(bst.root)){
        cout << "Binary search tree is valid!" << endl;
    }else{
        cout << "Binary search tree is not valid!" << endl;
    }
}