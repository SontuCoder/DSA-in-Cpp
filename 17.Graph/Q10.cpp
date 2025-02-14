// Find out Bridges in a graph :-

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
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
        adj[v].push_back(u);
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

void dfs(int i, vector<int> &dist, int parent, vector<int> &low, vector<bool> &visit, vector<pair<int,int>> &ans, int &time, unordered_map<int, list<int>> &adj){

    visit[i] = true;
    dist[i] = low[i] = time++;
    for(auto nbr: adj[i]){
        if(nbr == parent){
            continue;
        } 
        if(!visit[nbr]){
            dfs(nbr, dist, i, low, visit, ans, time, adj);
            low[i] = min(low[i], low[nbr]);
            if(low[nbr]>dist[i]){
                ans.push_back({i, nbr});
            }
        } else {
            // back edgs
            low[i] = min(low[i], dist[nbr]);
        }
    }
}

vector<pair<int, int>> bridgeFind(Graph& g){
    unordered_map<int, list<int>> &adj = g.getGraph();
    int V = g.getVertex();
    vector<int> dist(V, -1);
    int parent=-1;
    vector<int> low(V, -1);
    vector<bool> visit(V, 0);
    int time = 0;
    vector<pair<int, int>> ans;

    for(int i = 0; i<V; i++){
        if(!visit[i]){
            dfs(i, dist, parent, low, visit, ans, time, adj);
        }
    }
    return ans;
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
    vector<pair<int, int>> ans = bridgeFind(g);
    for(auto i: ans){
        cout<<i.first<<"--"<<i.second<<endl;
    }
    return 0;
}
