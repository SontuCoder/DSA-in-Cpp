// Cycle Detect in undirected graph

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include<stack>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adj;

public:
    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void print() {
        cout << "\nGraph adjacency list representation:\n";
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    unordered_map<int, list<int>>& getAdjList() {
        return adj;
    }
};

bool isCycleBFS(int start, unordered_map<int,list<int>>& adj, unordered_map<int,bool>& visited) {
    queue<pair<int, int>> q;  // (node, parent)
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            }
            else if (neighbor != parent) { 
                return true;
            }
        }
    }
    return false;
}

bool isCycleDFS(int start, unordered_map<int,list<int>>& adj, unordered_map<int,bool>& visited) {
    stack<pair<int, int>> s;  // (node, parent)
    s.push({start, -1});
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top().first;
        int parent = s.top().second;
        s.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push({neighbor, node});
            }
            else if (neighbor != parent) { 
                return true;
            }
        }
    }
    return false;
}



bool detectCycle(Graph& g, int V) {
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>>& adj = g.getAdjList();

    for (auto node : adj) {
        if (!visited[node.first]) {  // Check all components
            if (isCycleDFS(node.first, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.print();

    if (detectCycle(g, n))
        cout << "Cycle Detected!" << endl;
    else
        cout << "No Cycle Found." << endl;

    return 0;
}
