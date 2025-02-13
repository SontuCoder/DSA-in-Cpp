// Create Graph and BFS & DFS traversal :-

#include <iostream>
#include <unordered_map>
#include <list>
#include<queue>
#include<map>
#include<stack>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adj;

    public:

    // If directed == true, it's a directed graph; otherwise, it's undirected.
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

    void BFS(int i){
        cout<<"\nBFS :- ";
        queue<int> q;
        map<int, bool> m;
        q.push(i);
        m[i]=1;
        while(!q.empty()){
            int j = q.front();
            q.pop();
            cout<<j<<" ";

            for(auto k:adj[j]){
                if(m.find(k)==m.end()){
                    q.push(k);
                    m[k]=1;
                }
            }
        }
    }
    
    void DFS(int i){
        cout<<"\nDFS :- ";

        stack<int> s;
        map<int, bool> m;
        s.push(i);
        m[i]=1;

        while(!s.empty()){
            int j = s.top();
            s.pop();
            cout<<j<<" ";

            for(auto k:adj[j]){
                if(m.find(k)==m.end()){
                    s.push(k);
                    m[k]=1;
                }
            }
        }
    }

};

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
    g.BFS(1);
    g.DFS(1);
    return 0;
}
