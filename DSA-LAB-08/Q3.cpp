#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int roll;
        int score;

        Student(string n, int r, int s) : name(n), roll(r), score(s) {}
};

struct Node{
    Student value;
    Node *left;
    Node *right;
    Node(Student value, Node *left = nullptr, Node *right = nullptr) : value(value), left(left), right(right) {}
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

        Node *recursiveInsert(Student& value, Node *root){
            if (root == nullptr)
                return new Node(value);

            if (value.name < root->value.name)
                root->left = recursiveInsert(value, root->left);
            else if (value.name > root->value.name)
                root->right = recursiveInsert(value, root->right);
            return root;
        }

        Node *findSuccesor(Node *root){
            while (root && root->left)
                root = root->left;
            return root;
        }

        Node *recursiveRemove(string value, Node *root){
            if (root == nullptr)
                return nullptr;

            if (value > root->value.name){
                root->right = recursiveRemove(value, root->right);
            }
            else if (value < root->value.name){
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
                    root->right = recursiveRemove(temp->value.name, root->right);
                }

                return root;
            }
        }

        bool recursiveSearch(string value, Node *root)
        {
            if (root == nullptr)
                return false;
            if (root->value.name == value)
                return true;

            if (root->value.name > value){
                return recursiveSearch(value, root->left);
            }
            else{
                return recursiveSearch(value, root->right);
            }
        }

        void filterStudentsRecursive(Node*& root){
            if(root == nullptr) return;

            filterStudentsRecursive(root->left);
            filterStudentsRecursive(root->right);
            if(root->value.score < 10){
                root = recursiveRemove(root->value.name, root);
            }
        }

        void inorderRecursive(Node *root){
            if (root == nullptr)
                return;
            inorderRecursive(root->left);
            cout << root->value.name << " ";
            inorderRecursive(root->right);
        }

        Student* getMaxScoreStudentRecursive(Node* root, Student* currentMax) {
            if (root == nullptr) return currentMax;

            if (currentMax == nullptr || root->value.score > currentMax->score)
                currentMax = &(root->value);

            currentMax = getMaxScoreStudentRecursive(root->left, currentMax);
            currentMax = getMaxScoreStudentRecursive(root->right, currentMax);

            return currentMax;
        }

    public:
        BST(){
            root = nullptr;
        }

        ~BST(){
            clear(root);
        }

        void insert(Student& value){
            root = recursiveInsert(value, root);
        }

        void remove(string value){
            root = recursiveRemove(value, root);
        }

        bool search(string value){
            return recursiveSearch(value, root);
        }

        void filterStudents(){
            filterStudentsRecursive(root);
        }

        void inorder(){
            cout << endl;
            inorderRecursive(root);
        }

        Student* getMaxScoreStudent(){
            return getMaxScoreStudentRecursive(root, nullptr);
        }
};

int main(){
    Student students[10] = {
        {"Ahmed", 101, 12},
        {"Ali", 102, 8},
        {"Hammad", 103, 15},
        {"Faran", 104, 7},
        {"Alyan", 105, 20},
        {"Ismail", 106, 18},
        {"Rafia", 107, 9},
        {"Hania", 108, 11},
        {"Nasir", 109, 14},
        {"Abdullah", 110, 6}
    };

    BST bst;

    bst.insert(students[0]);
    bst.insert(students[2]);
    bst.insert(students[4]);
    bst.insert(students[5]);
    bst.insert(students[7]);
    bst.insert(students[8]);
    bst.insert(students[1]);

    string searchName = "Hammad";

    if (bst.search(searchName)) {
        cout << searchName << " found in the BST." << endl;
    } else {
        cout << searchName << " not found in the BST." << endl;
    }

    bst.filterStudents();
    cout << "Students with score < 10 have been removed." << endl;

    bst.inorder();

    cout << endl;
    cout << endl;

    Student* topStudent = bst.getMaxScoreStudent();
    if (topStudent != nullptr) {
        cout << "Student with max score: "
             << topStudent->name << " - "
             << topStudent->roll << " - "
             << topStudent->score << endl;
    } else {
        cout << "No students in the BST." << endl;
    }

    return 0;
}