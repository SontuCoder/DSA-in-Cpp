// Prims algo ( minimum Spining tree ) :-

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

class Graph{
    unordered_map<int, list<pair<int, int>>> adj;
    int V;

    public:
    Graph(int n){
        V = n;
    }

    void createEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int getVertex(){
        return V;
    }

    unordered_map<int, list<pair<int, int>>>& getGraph(){
        return adj;
    }

    void print(){
        cout<<"\nGraph:- \n";
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << "(" << j.first << ":" << j.second << ") ";
            }
            cout << endl;
        }
    }
};

void prim(Graph& g){
    unordered_map<int, list<pair<int, int>>> &adj = g.getGraph();
    int V = g.getVertex();
    vector<int> minCost(V, INT_MAX);
    vector<bool> mst(V, 0);
    vector<int> parent(V, -1);

    minCost[0] = 0;

    for(int k = 1; k<V; k++){
        int mini = -1, minValue = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (!mst[i] && minCost[i] < minValue) {
                minValue = minCost[i];
                mini = i;
            }
        }

        mst[mini]= true;
        for(auto j:adj[mini]){
            int node = j.first;
            int cost = j.second;
            if(mst[node]==false && cost < minCost[node]){
                minCost[node]= cost;
                parent[node] = mini;
            }
        }
    }
    cout << "\nMinimum Spanning Tree (MST) Edges:\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " (Cost: " << minCost[i] << ")\n";
            totalCost += minCost[i];
        }
    }
    cout << "Total Cost of MST: " << totalCost << endl;
}

int main(){
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g(n);

    cout << "Enter the edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cout<<endl;
        g.createEdge(u, v, w);
    }

    g.print();
    cout<<"\n====================\n";
    prim(g);
    return 0;
}
