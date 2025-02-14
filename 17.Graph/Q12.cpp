// Find out Strongly components in a graph (By, Kosaraju's Algo) :-

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adj; // node-> {node};
    int V;

    public:
    Graph(int n){
        V = n;
    }

    void createEdge(int u, int v){
        adj[u].push_back(v);
    }

    int getVertex(){
        return V;
    }

    unordered_map<int, list<int>>& getGraph(){
        return adj;
    }

    void print(){
        cout<<"\nGraph:- \n";
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j <<" ";
            }
            cout << endl;
        }
    }
};

void dfs(int i, unordered_map<int, list<int>> &adj, vector<bool> &visite, stack<int> &topoSort){
    visite[i] = true;
    for(auto j:adj[i]){
        if(!visite[j]){
            dfs(j, adj, visite, topoSort);
        }
    }
    topoSort.push(i);
}

unordered_map<int, list<int>> tranpose(unordered_map<int, list<int>> &adj, int V){
    unordered_map<int, list<int>> trans ;
    for(int i = 0; i<V; i++){
        for(auto nbr: adj[i]){
            trans[nbr].push_back(i);
        }
    }
    return trans;
}

void revDfs(unordered_map<int, list<int>>& trans, int i, vector<bool> &visite){
    visite[i] = true;
    for(auto j: trans[i]){
        if(!visite[j]){
            revDfs(trans, j, visite);
        }
    }
}

int Kosaraju(Graph& g){
    unordered_map<int, list<int>> &adj = g.getGraph();
    int V = g.getVertex();
    stack<int> topoSort;
    vector<bool> visite(V,0);
    for (int i = 0; i < V; i++) {
        if (!visite[i]) {
            dfs(i, adj, visite, topoSort);
        }
    }

    unordered_map<int, list<int>>trans = tranpose(adj, V);
    fill(visite.begin(), visite.end(), false);
    // cal Dfs
    int count = 0;
    while(!topoSort.empty()){
        int top = topoSort.top();
        topoSort.pop();
        if(!visite[top]){
            count++;
            revDfs(trans, top, visite);
        }
    }
    return count;
}


int main(){
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g(n);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v ;
        g.createEdge(u, v);
    }

    g.print();
    cout<<"\n====================\n";
    cout<<"Number :-"<< Kosaraju(g);
    return 0;
}
