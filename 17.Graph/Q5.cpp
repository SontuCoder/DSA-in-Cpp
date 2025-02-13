// Shortest path in a undirected graph

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adj;
    int V;

    public:
    Graph(int n){
        V = n;
    }

    void createEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int getVartex(){
        return V;
    }

    unordered_map<int, list<int>>& getGraph(){
        return adj;
    }

    void print(){
        cout<<"\nGraph:- \n";
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j:adj[i.first]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

vector<int> shortestPath(Graph& g, int s, int m){
    vector<int> ans;
    int V = g.getVartex();
    unordered_map<int, list<int>> &adj = g.getGraph();
    vector<int> visited(V+1, 0);
    vector<int> parent(V+1, -1);
    queue<int> q;

    q.push(s);
    visited[s]=true;

    // Make parent array
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(auto j:adj[i]){
            if(visited[j]==0){
                q.push(j);
                parent[j]=i;
                visited[j]=true;
            }
        }
    }

    // Shortest path
    int curr = m;
    ans.push_back(curr);
    while(curr!=s){
        curr=parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
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
        g.createEdge(u, v);
    }

    g.print();
    vector<int> ans = shortestPath(g,2,5);
    cout<<"\n path:- ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}