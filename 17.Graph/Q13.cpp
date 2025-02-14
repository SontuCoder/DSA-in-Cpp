// Find out Strongly components in a graph (By, Kosaraju's Algo) :-

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

class Graph{
    unordered_map<int, list<pair<int, int>>> adj; // node-> {node, wight};
    int V;

    public:
    Graph(int n){
        V = n;
    }

    void createEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }

    int getVertex(){
        return V;
    }

    unordered_map<int, list<pair<int,int>>>& getGraph(){
        return adj;
    }

    void print(){
        cout<<"\nGraph:- \n";
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j.first <<" "<<j.second<<endl;
            }
            cout << endl;
        }
    }
};

vector<int> bellman(Graph& g){
    unordered_map<int, list<pair<int, int>>> &adj=g.getGraph();
    int V = g.getVertex();
    vector<int> dist(V, INT_MAX);
    int source = 0; 
dist[source] = 0;

    for(int i=0; i<V-1; i++){
        for(int j = 0; j<V; j++){
                for(auto k: adj[j]){
                    if (dist[j] != INT_MAX && dist[k.first] > dist[j] + k.second){
                        dist[k.first] = dist[j]+k.second;
                    }
                }
        }
    }
    bool flag = 0;
    for(int j = 0; j<V; j++){
        for(auto k: adj[j]){
            if(dist[k.first]> dist[j]+k.second){
                dist[k.first] = dist[j]+k.second;
                flag=1;
            }
        }
    }
    if(flag){
        cout<<"Negative cycle";
        fill(dist.begin(), dist.end(), 0);
        return dist;
    }
    return dist;
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
        cin >> u >> v >> w ;
        cout<<endl;
        g.createEdge(u, v, w);
    }

    g.print();
    cout<<"\n====================\n";
    vector<int> ans = bellman(g);
    for(int i = 0; i<n; i++){
        cout<<i<<":"<<ans[i]<<endl;
    }
    return 0;
}

