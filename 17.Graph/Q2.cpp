// Cycle Detect in directed graph

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include<stack>
#include<vector>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adj;

public:
    void addEdge(int u, int v) {
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
};

bool isCycleBFS( unordered_map<int, list<int>>& adj, int n) {
    vector<int> indegree(n+1, 0);
    int cnt = 0; // if in valid topological sort then cnt != n

    // Step 1: Calculate in-degrees
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 2: Push nodes with in-degree 0 into the queue
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: Process nodes in BFS order
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        // Reduce in-degree of neighbors
        for (auto neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    return cnt!=n;
}

bool isCycleDFS(int start, unordered_map<int,list<int>>& adj, unordered_map<int,bool>& visited, unordered_map<int, bool>& inStack) {

    visited[start] = true;
    inStack[start] = true;

    for(auto neighbour:adj[start]){
        if(!visited[neighbour]){
            if(isCycleDFS(neighbour, adj, visited, inStack))
                return true;
        } else if(inStack[neighbour])
            return true;
    }
    inStack[start] = false;
    return false;
}



bool detectCycle(Graph& g, int n) {
    // unordered_map<int, bool> visited;
    unordered_map<int, list<int>>& adj = g.getAdjList();
    // unordered_map<int, bool> inStack;

    // for (auto node : adj) {
        // if (!visited[node.first]) {
            if (isCycleBFS(adj, n)) {
                return true;
            }
        // }
    // }
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
