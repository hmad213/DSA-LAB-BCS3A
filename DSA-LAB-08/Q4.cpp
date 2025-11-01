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
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Initial BST (in-order): ";
    bst.inorder();
    cout << endl;

    int value;
    cout << "Enter a value to search in BST: ";
    cin >> value;

    if (bst.search(value)) {
        cout << value << " exists in the BST." << endl;
    } else {
        cout << value << " does not exist in BST. Inserting it now..." << endl;
        bst.insert(value);

        cout << "New BST (in-order) after insertion: ";
        bst.inorder();
        cout << endl;
    }

    return 0;
}