// Topological Sort using BFS (Kahn's Algorithm)

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adj;
    int V; // Number of nodes

public:
    Graph(int vertices) { 
        V = vertices;
    }

    void addEdge(int u, int v) { // Directed graph
        adj[u].push_back(v);
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

    int getVertices() {
        return V;
    }
};

// Function to perform Topological Sort using BFS (Kahn's Algorithm)
vector<int> Topological(Graph& g) {
    int V = g.getVertices();
    unordered_map<int, list<int>>& adj = g.getAdjList();
    vector<int> indegree(V+1, 0);
    vector<int> ans;

    // Step 1: Calculate in-degrees
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 2: Push nodes with in-degree 0 into the queue
    queue<int> q;
    for (int i = 1; i <= V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: Process nodes in BFS order
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Reduce in-degree of neighbors
        for (auto neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g(n);

    cout << "Enter the edges (u -> v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.print();

    vector<int> result = Topological(g);

    cout << "\nTopological Order: ";
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
