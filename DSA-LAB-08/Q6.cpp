#include <iostream>
using namespace std;

struct Product{
    int id;
    int quantity;
    Product(int id, int quantity) : id(id), quantity(quantity) {}
};

struct Node{
    Product value;
    Node *left;
    Node *right;
    Node(Product value, Node *left = nullptr, Node *right = nullptr) : value(value), left(left), right(right) {}
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

        Node *recursiveInsert(Product value, Node *root){
            if (root == nullptr)
                return new Node(value);

            if (value.id < root->value.id)
                root->left = recursiveInsert(value, root->left);
            else if (value.id > root->value.id)
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

            if (value > root->value.id){
                root->right = recursiveRemove(value, root->right);
            }
            else if (value < root->value.id){
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
                    root->right = recursiveRemove(temp->value.id, root->right);
                }

            }
            return root;
        }

        bool recursiveSearch(int value, Node *root)
        {
            if (root == nullptr)
                return false;
            if (root->value.id == value)
                return true;

            if (root->value.id > value){
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
            cout << "ID: " << root->value.id << endl;
            cout << "Quantity: " << root->value.quantity << endl;
            cout << endl;
            inorderRecursive(root->right);
        }

        void recursiveUpdate(Node* node, int id, int quantity){
            if(node == nullptr) return;

            if(id == node->value.id){
                node->value.quantity = quantity;
                return;
            }
            if(id > node->value.id){
                recursiveUpdate(node->right, id, quantity);
            }else{
                recursiveUpdate(node->left, id, quantity);
            }
        }

        Product* getMaxProductRecursive(Node* root, Product* currentMax) {
            if (root == nullptr) return currentMax;

            if (currentMax == nullptr || root->value.quantity > currentMax->quantity)
                currentMax = &(root->value);

            currentMax = getMaxProductRecursive(root->left, currentMax);
            currentMax = getMaxProductRecursive(root->right, currentMax);

            return currentMax;
        }

    public:
        BST(){
            root = nullptr;
        }

        ~BST(){
            clear(root);
        }

        void insert(Product value){
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

        void updateQuantity(int value, int quantity){
            recursiveUpdate(root, value, quantity);
        }

        Product* getMaxProduct(){
            return getMaxProductRecursive(root, nullptr);
        }
};

int main() {
    BST inventory;

    inventory.insert(Product(101, 50));
    inventory.insert(Product(102, 30));
    inventory.insert(Product(103, 75));
    inventory.insert(Product(104, 20));
    inventory.insert(Product(105, 60));

    cout << "Inventory in BST order:" << endl;
    inventory.inorder();

    int searchID = 103;
    if (inventory.search(searchID))
        cout << "Product with ID " << searchID << " found." << endl;
    else
        cout << "Product with ID " << searchID << " not found." << endl;

    inventory.updateQuantity(102, 80);
    cout << endl;
    cout << "After updating quantity of ID 102 to 80:" << endl;
    inventory.inorder();

    inventory.remove(104);
    cout << endl;
    cout << "After removing product with ID 104:" << endl;
    inventory.inorder();

    Product* maxProd = inventory.getMaxProduct();
    if (maxProd){
        cout << endl;
        cout << "Product with max quantity: ID " << maxProd->id << ", Quantity " << maxProd->quantity << endl;
    }

    return 0;
}