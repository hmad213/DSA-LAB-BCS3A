#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left;
    Node *right;
    Node(T value, Node *left = nullptr, Node *right = nullptr) : value(value), left(left), right(right) {}
};

template <typename T>
class BST
{
private:
    Node<T> *root;

    void clear(Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        clear(root->left);
        clear(root->right);
        delete root;
    }

    Node<T> *recursiveInsert(T value, Node<T> *root)
    {
        if (root == nullptr)
            return new Node(value);

        if (value < root->value)
            root->left = recursiveInsert(value, root->left);
        else if (value > root->value)
            root->right = recursiveInsert(value, root->right);
        return root;
    }

    Node<T> *findSuccesor(Node<T> *root)
    {
        while (root && root->left)
            root = root->left;
        return root;
    }

    Node<T> *recursiveRemove(T value, Node<T> *root)
    {
        if (root == nullptr)
            return nullptr;

        if (value > root->value)
        {
            root->right = recursiveRemove(value, root->right);
        }
        else if (value < root->value)
        {
            root->left = recursiveRemove(value, root->left);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node<T> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node<T> *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node<T> *temp = findSuccesor(root->right);
                root->value = temp->value;
                root->right = recursiveRemove(temp->value, root->right);
            }

            return root;
        }
    }

    bool recursiveSearch(T value, Node<T> *root)
    {
        if (root == nullptr)
            return false;
        if (root->value == value)
            return true;

        if (root->value > value)
        {
            return recursiveSearch(value, root->left);
        }
        else
        {
            return recursiveSearch(value, root->right);
        }
    }

    void inorderRecursive(Node<T> *root)
    {
        if (root == nullptr)
            return;
        inorderRecursive(root->left);
        cout << root->value << " ";
        inorderRecursive(root->right);
    }

    void preorderRecursive(Node<T> *root)
    {
        if (root == nullptr)
            return;
        cout << root->value << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }

    void postorderRecursive(Node<T> *root)
    {
        if (root == nullptr)
            return;
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->value << " ";
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        clear(root);
    }

    void insert(T value)
    {
        root = recursiveInsert(value, root);
    }

    void remove(T value)
    {
        root = recursiveRemove(value, root);
    }

    bool search(T value)
    {
        return recursiveSearch(value, root);
    }

    void inorder()
    {
        cout << endl;
        inorderRecursive(root);
    }

    void preorder()
    {
        cout << endl;
        preorderRecursive(root);
    }

    void postorder()
    {
        cout << endl;
        postorderRecursive(root);
    }
};

int main()
{
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal:";
    tree.inorder();

    cout << endl;
    cout << "Preorder traversal:";
    tree.preorder();

    cout << endl;
    cout << "Postorder traversal:";
    tree.postorder();

    cout << endl;
    cout << endl;
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found");
    cout << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found");

    tree.remove(70);
    cout << endl;
    cout << endl;
    cout << "After removing 70, inorder:";
    tree.inorder();

    cout << endl;
    return 0;
}