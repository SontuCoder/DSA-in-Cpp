// Kruskal's algo ( minimum Spining tree ) :-

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class Graph{
    unordered_map<int, list<pair<int, int>>> adj; // node-> {node, dist};
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

void assignParent(vector<int> &parent){
    for(int i =0 ; i<parent.size(); i++){
        parent[i] = i;
    }
}

void costAssending(unordered_map<int, list<pair<int, int>>> &adj, int V, vector<pair<int, pair<int, int>>> &costArray){
    vector<bool> visited(V+1, 0);
    for(auto node:adj){
        int i = node.first;
        if(!visited[i]){
            for(auto j: node.second){
                if(!visited[j.first]){
                    costArray.push_back({j.second, {i,j.first}});
                }
            }
            visited[i]=true;
        }
    }
}

int findParent(vector<int> &parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}


void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u= findParent(parent, u);
    v= findParent(parent, v);

    if(rank[u]<rank[v]){
        parent[u]=v;
    } else if(rank[v]<rank[u]){
        parent[v]=u;
    } else {
        parent[u]=v;
        rank[u]++;
    }
}


Graph kruskal(Graph& g){
    int V = g.getVertex();
    unordered_map<int, list<pair<int, int>>> &adj = g.getGraph();
    vector<int> parent(V);
    assignParent(parent);
    vector<int> rank(V, 0);
    vector<pair<int, pair<int, int>>> costArray;
    costAssending(adj, V,  costArray);

    sort(costArray.begin(), costArray.end());E

    Graph ans(V);
    for(auto i: costArray){
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if(findParent(parent,u) != findParent(parent,v)){
            unionSet(u,v, parent, rank);
            ans.createEdge(u,v,w);
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

    cout << "Enter the edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.createEdge(u, v, w);
    }

    g.print();
    cout<<"\n====================\n";
    Graph ans = kruskal(g);
    ans.print();
    return 0;
}
