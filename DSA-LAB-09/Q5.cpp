#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    int height;
    
    Node(int v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r), height(1){}
};

class AVL{
    private:
        Node* root;
    public:
        AVL(){
            root = nullptr;
        }

        int getHeight(Node* node){
            return (!node ? 0 : node->height);
        }

        int getBalanced(Node* node){
            return node ? getHeight(node->left) - getHeight(node->right) : 0;
        }

        Node* rotateLeft(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;

            y->left = x;
            x->right = T2;

            x->height = 1 + max(getHeight(x->right), getHeight(x->left));
            y->height = 1 + max(getHeight(y->right), getHeight(y->left));

            return y;
        }

        Node* rotateRight(Node* y){
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            x->height = 1 + max(getHeight(x->right), getHeight(x->left));
            y->height = 1 + max(getHeight(y->right), getHeight(y->left));

            return x;
        }

        Node* insertNode(int value, Node* node){
            if (node == nullptr) return new Node(value);

            if(value > node->value){
                node->right = insertNode(value, node->right);
            }else{
                node->left = insertNode(value, node->left);
            }

            node->height = 1 + max(getHeight(node->right), getHeight(node->left));

            int balance = getBalanced(node);

            if(balance > 1 && getBalanced(node->left) >= 0){
                cout << "LEFT-LEFT" << endl;
                return rotateRight(node);
            }

            if(balance > 1 && getBalanced(node->left) < 0){
                cout << "LEFT-RIGHT" << endl;
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }

            if(balance < -1 && getBalanced(node->right) < 0){
                cout << "RIGHT-RIGHT" << endl;
                return rotateLeft(node);
            }

            if(balance < -1 && getBalanced(node->right) >= 0){
                cout << "RIGHT-LEFT" << endl;
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }

            return node;
        }

        void insertHelper(int value){
            root = insertNode(value, root);
        }

        int getRootHeight(){
            return root ? root->height : 0;
        }

        int kthSmallest(Node* node, int& k) {
            if (!node) return -1;
            int val = kthSmallest(node->left, k);
            if (k == 0) return val;
            k--;
            if (k == 0) return node->value;
            return kthSmallest(node->right, k);
        }

        int getKthSmallest(int k) {
            return kthSmallest(root, k);
        }

        int kthLargest(Node* node, int& k) {
            if (!node) return -1;
            int val = kthLargest(node->right, k);
            if (k == 0) return val;
            k--;
            if (k == 0) return node->value;
            return kthLargest(node->left, k);
        }

        int getKthLargest(int k) {
            return kthLargest(root, k);
        }

        Node* getRoot() {return root;}
};

int main() {
    AVL tree;
    tree.insertHelper(10);
    tree.insertHelper(20);
    tree.insertHelper(30);
    tree.insertHelper(40);
    tree.insertHelper(50);
    tree.insertHelper(15);

    cout << "AVL Tree Height: " << tree.getRootHeight() << endl;
    cout << "Left Subtree Height: " << tree.getHeight(tree.getRoot()->left) << endl;
    cout << "Right Subtree Height: " << tree.getHeight(tree.getRoot()->right) << endl;

    int k = 3;
    cout << k << "th Smallest: " << tree.getKthSmallest(k) << endl;
    cout << k << "th Largest: " << tree.getKthLargest(k) << endl;

    return 0;
}