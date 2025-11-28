#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, weight>
    
public:
    Graph(int v) : vertices(v) {
        adjList.resize(vertices);
    }
    
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }
    
    void printPath(vector<int>& parent, int vertex) {
        if (parent[vertex] == -1) {
            cout << (char)('A' + vertex);
            return;
        }
        printPath(parent, parent[vertex]);
        cout << " -> " << (char)('A' + vertex);
    }
    
    void dijkstra(int start, int end) {
        vector<int> distance(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        distance[start] = 0;
        pq.push(make_pair(0, start));
        
        cout << "\nDijkstra's Algorithm - Finding shortest path from " 
             << (char)('A' + start) << " to " << (char)('A' + end) << "\n";
        cout << "\n===========================================\n";
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            
            cout << "\nVisiting vertex: " << (char)('A' + u) 
                 << " (Distance: " << distance[u] << ")\n";
            
            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i].first;
                int weight = adjList[u][i].second;
                
                if (!visited[v]) {
                    int newDist = distance[u] + weight;
                    if (newDist < distance[v]) {
                        cout << "  Update " << (char)('A' + v) 
                             << ": " << distance[v] << " -> " << newDist << "\n";
                        distance[v] = newDist;
                        parent[v] = u;
                        pq.push(make_pair(distance[v], v));
                    }
                }
            }
        }
        
        cout << "\n===========================================\n";
        cout << "\nFinal Distances from " << (char)('A' + start) << ":\n";
        for (int i = 0; i < vertices; i++) {
            cout << (char)('A' + start) << " to " << (char)('A' + i) << " = ";
            if (distance[i] == INT_MAX) {
                cout << "INF\n";
            } else {
                cout << distance[i] << "\n";
            }
        }
        
        cout << "\n===========================================\n";
        cout << "\nShortest path from " << (char)('A' + start) 
             << " to " << (char)('A' + end) << ":\n";
        
        if (distance[end] == INT_MAX) {
            cout << "No path exists!\n";
            return;
        }
        
        cout << "Path: ";
        printPath(parent, end);
        cout << "\n";
        cout << "Total Distance: " << distance[end] << "\n";
        cout << "===========================================\n";
    }
    
    void displayGraph() {
        cout << "\nGraph Edges:\n";
        for (int i = 0; i < vertices; i++) {
            cout << (char)('A' + i) << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << (char)('A' + adjList[i][j].first) 
                     << "(" << adjList[i][j].second << ")";
                if (j < adjList[i].size() - 1) cout << ", ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(6);
    
    // Adding edges based on the graph image
    g.addEdge(1, 0, 4);   // B-A: 4
    g.addEdge(0, 3, 8);   // A-D: 8
    g.addEdge(1, 2, 9);   // B-C: 9
    g.addEdge(2, 3, 6);   // C-D: 6
    g.addEdge(3, 5, 4);   // D-F: 4
    g.addEdge(2, 4, 14);  // C-E: 14
    g.addEdge(4, 5, 3);   // E-F: 3
    
    g.displayGraph();
    
    // Find shortest path from B (1) to E (4)
    g.dijkstra(1, 4);
    
    return 0;
}