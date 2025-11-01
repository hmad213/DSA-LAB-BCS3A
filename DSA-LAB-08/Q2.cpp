#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0)
        : name(n), health(h), attack(a) {}
};

class Node {
public:
    Combatant c;
    Node* left;
    Node* right;

    Node(Combatant combatant) {
        c = combatant;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* root, Combatant c) {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->c.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* remove(Node* root, string name) {
        if (root == NULL) return root;

        if (name < root->c.name)
            root->left = remove(root->left, name);
        else if (name > root->c.name)
            root->right = remove(root->right, name);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->c = temp->c;
            root->right = remove(root->right, temp->c.name);
        }
        return root;
    }

    void remove(string name) {
        root = remove(root, name);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    Node* getFrontline() {
        if(root == nullptr) return nullptr;

        Node* temp = root;
        while(temp->left) temp = temp->left;
        return temp;
    }

    void display(Node* node) {
       cout << endl;
       cout << "Combatant name: " << node->c.name << endl;
       cout << "Health: " << node->c.health << endl;
       cout << "Attack: " << node->c.attack << endl;
    }

    void inorder(Node* root){
        if (root == nullptr) return;
        inorder(root->left);
        display(root);
        inorder(root->right);
    }

    void displayTeam() {
        inorder(root);
    }
};

class BattleQuest {
private:
    BST playerTeam;
    BST enemyTeam;

public:
    BattleQuest() {
        srand(time(0));
        initializeTeams();
    }

    void initializeTeams() {
        playerTeam.insert(Combatant("Hammad", 25, 6));
        playerTeam.insert(Combatant("Ali", 22, 7));
        playerTeam.insert(Combatant("Ahmed", 20, 8));
        playerTeam.insert(Combatant("Faran", 18, 9));
        playerTeam.insert(Combatant("Alyan", 30, 5));

        enemyTeam.insert(Combatant("EnemyA", 24, 5));
        enemyTeam.insert(Combatant("EnemyB", 21, 7));
        enemyTeam.insert(Combatant("EnemyC", 19, 8));
        enemyTeam.insert(Combatant("EnemyD", 23, 6));
        enemyTeam.insert(Combatant("EnemyE", 27, 4));
    }

    void displayTeams() {
        cout << endl;
        cout << "---------------------------" << endl;
        cout << "Current Team Status:" << endl;
        cout << "---------------------------" << endl;
        cout << "Player Team:" << endl;
        playerTeam.displayTeam();
        cout << endl;
        cout << "Enemy Team:" << endl;
        enemyTeam.displayTeam();
        cout << "---------------------------" << endl;
    }

    void attack(Node* attacker, Node* defender, BST& defenderTeam) {
       if (!attacker || !defender) return;

        int randomBonus = rand() % 5;
        int damage = attacker->c.attack + randomBonus;
        defender->c.health -= damage;

        cout << attacker->c.name << " attacks " << defender->c.name << " for " << damage << " damage!" << endl;

        if (defender->c.health <= 0) {
            cout << defender->c.name << " has been defeated!" << endl;
            defenderTeam.remove(defender->c.name);
        } else {
            cout << defender->c.name << "'s remaining HP: " << defender->c.health << endl;
        }
    }

    void start_battle() {
        cout << "Welcome to BattleQuest!" << endl;
        int round = 1;

        while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
            cout << endl;
            cout << "===== Round " << round << " =====" << endl;
            displayTeams();

            Node* playerFront = playerTeam.getFrontline();
            Node* enemyFront = enemyTeam.getFrontline();

            if (playerFront && enemyFront) {
                cout << endl;
                cout << "Player's Turn:" << endl;
                attack(playerFront, enemyFront, enemyTeam);
            }

            if (enemyTeam.isEmpty()) {
                cout << "Player wins!" << endl;
                break;
            }

            playerFront = playerTeam.getFrontline();
            enemyFront = enemyTeam.getFrontline();

            if (playerFront && enemyFront) {
                cout << endl;
                cout << "Enemy's Turn:" << endl;
                attack(enemyFront, playerFront, playerTeam);
            }

            if (playerTeam.isEmpty()) {
                cout << endl;
                cout << "Enemy Wins!" << endl;
                break;
            }

            round++;
        }
    }
};


int main() {
    BattleQuest game;
    game.start_battle(); 
    return 0;
}