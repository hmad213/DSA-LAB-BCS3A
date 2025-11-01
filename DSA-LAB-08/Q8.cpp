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

        int recursiveCount(Node* node, int a, int b){
            if(!node) return 0;
            int count = recursiveCount(node->left, a, b);
            count += recursiveCount(node->right, a, b);

            if(node->value >= a && node->value <= b) return count + 1;
            else return count;
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

        int countInRange(int a, int b){
            return recursiveCount(root, a, b);
        }
};

int main(void){
    BST bst;

    int a = 5, b = 45;

    bst.insert(10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(50);
    bst.insert(40);
    bst.insert(100);

    cout << "Number of numbers within range [" << a << ", " << b << "]: " << bst.countInRange(a, b);
}