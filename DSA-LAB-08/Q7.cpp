#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(int value, Node *left = nullptr, Node *right = nullptr) : value(value), left(left), right(right) {}
};

class BST{
    private:
        Node *root;

        void clear(Node *root){
            if (root == nullptr){
                return;
            }
            clear(root->left);
            clear(root->right);
            delete root;
        }

        Node *recursiveInsert(int value, Node *root){
            if (root == nullptr)
                return new Node(value);

            if (value < root->value)
                root->left = recursiveInsert(value, root->left);
            else if (value > root->value)
                root->right = recursiveInsert(value, root->right);
            return root;
        }

        Node *findSuccesor(Node *root){
            while (root && root->left)
                root = root->left;
            return root;
        }

        Node *recursiveRemove(int value, Node *root){
            if (root == nullptr)
                return nullptr;

            if (value > root->value){
                root->right = recursiveRemove(value, root->right);
            }
            else if (value < root->value){
                root->left = recursiveRemove(value, root->left);
            }
            else{
                if (root->left == nullptr){
                    Node *temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr){
                    Node *temp = root->left;
                    delete root;
                    return temp;
                }
                else{
                    Node *temp = findSuccesor(root->right);
                    root->value = temp->value;
                    root->right = recursiveRemove(temp->value, root->right);
                }

                return root;
            }
        }

        bool recursiveSearch(int value, Node *root)
        {
            if (root == nullptr)
                return false;
            if (root->value == value)
                return true;

            if (root->value > value){
                return recursiveSearch(value, root->left);
            }
            else{
                return recursiveSearch(value, root->right);
            }
        }

        void inorderRecursive(Node *root){
            if (root == nullptr)
                return;
            inorderRecursive(root->left);
            cout << root->value << " ";
            inorderRecursive(root->right);
        }

        int countNodes(Node* root) {
            if (!root) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

        void inorderMedian(Node* node, int& count, int n, int& first, int& second) {
            if (!node) return;
            inorderMedian(node->left, count, n, first, second);
            count++;
            if (n % 2 != 0 && count == (n + 1) / 2) first = node->value;
            if (n % 2 == 0) {
                if (count == n / 2) first = node->value;
                if (count == n / 2 + 1) second = node->value;
            }
            inorderMedian(node->right, count, n, first, second);
        }

    public:
        BST(){
            root = nullptr;
        }

        ~BST(){
            clear(root);
        }

        void insert(int value){
            root = recursiveInsert(value, root);
        }

        void remove(int value){
            root = recursiveRemove(value, root);
        }

        bool search(int value){
            return recursiveSearch(value, root);
        }

        void inorder(){
            cout << endl;
            inorderRecursive(root);
        }

        double findMedian() {
            int n = countNodes(root);
            if (n == 0) return 0;

            int count = 0, first = 0, second = 0;
            inorderMedian(root, count, n, first, second);

            return (n % 2 != 0) ? first : (first + second) / 2.0;
        }
};

int main(void){
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    cout << "Median: " << tree.findMedian() << endl;
}