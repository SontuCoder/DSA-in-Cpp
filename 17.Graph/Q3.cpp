// Topological Sort (Directed Acyclick Graph)Using DFS

#include <iostream>
#include <unordered_map>
#include <list>
#include<stack>
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

void DFSSort(int start, unordered_map<int,list<int>>& adj, unordered_map<int,bool>& visited, stack<int>& ans) {

    visited[start] = true;

    for(auto neighbour:adj[start]){
        if(!visited[neighbour]){
            DFSSort(neighbour, adj, visited, ans);
        }
    }
    ans.push(start);
}

stack<int> Topological(Graph& g, int V) {
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>>& adj = g.getAdjList();
    stack<int> ans;

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) { 
            DFSSort(i, adj, visited, ans);
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

    Graph g;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.print();

    stack<int> s = Topological(g,n);
    cout<<"ANS:- ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

