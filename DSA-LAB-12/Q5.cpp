#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;
    
public:
    Graph(int v) : vertices(v) {
        adjList.resize(vertices);
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }
    
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
        
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
    
    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i + 1 << " -> ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] + 1;
                if (j < adjList[i].size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }
    
    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        cout << "  ";
        for (int i = 0; i < vertices; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        cout << "\nBFS Traversal: ";
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current + 1 << " ";
            
            for (int i = 0; i < adjList[current].size(); i++) {
                int neighbor = adjList[current][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;
        
        s.push(start);
        
        cout << "DFS Traversal: ";
        
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            
            if (!visited[current]) {
                visited[current] = true;
                cout << current + 1 << " ";
                
                for (int i = adjList[current].size() - 1; i >= 0; i--) {
                    int neighbor = adjList[current][i];
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 3); 
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    
    g.displayAdjList();
    g.displayAdjMatrix();
    
    g.BFS(0);
    g.DFS(0); 
    
    return 0;
}