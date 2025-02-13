// All Shortest path in a directed and weighted graph

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
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
        adj[u].push_back({v,w});
    }

    int getVertex(){
        return V;
    }

    unordered_map<int, list<pair<int, int>>>& getGraph(){
        return adj;
    }

    void print(){
        cout<<"\nGraph:- \n";
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j:adj[i.first]){
                cout<<"("<<j.first<<":"<<j.second<<") ";
            }
            cout<<endl;
        }
    }
};

void DFSSort(int start, unordered_map<int,list<pair<int, int>>>& adj, unordered_map<int,bool>& visited, stack<int>& ans) {

    visited[start] = true;

    for(auto neighbour:adj[start]){
        if(!visited[neighbour.first]){
            DFSSort(neighbour.first, adj, visited, ans);
        }
    }
    ans.push(start);
}

stack<int> Topological(unordered_map<int, list<pair<int, int>>> &adj, int V) {
    unordered_map<int, bool> visited;
    stack<int> ans;

    for (int i = 0; i <V; i++) {
        if (!visited[i]) { 
            DFSSort(i, adj, visited, ans);
        }
    }
    return ans;
}

vector<int> shortestPath(Graph& g, int s){
    unordered_map<int, list<pair<int, int>>> &adj = g.getGraph();
    int V = g.getVertex();
    vector<int> ans(V, INT_MAX);
    ans[s]=0;
    stack<int> sortedOrder = Topological(adj, V);

    while(!sortedOrder.empty()){
        int top = sortedOrder.top();
        sortedOrder.pop();

        if(ans[top] != INT_MAX){
            for(auto j:adj[top]){
                if(ans[j.first]> (ans[top]+j.second)){
                    ans[j.first] =(ans[top]+j.second);
                }
            }
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

    cout << "Enter the edges (u -> v):\n";
    for (int i = 0; i < m; i++) {
        int u, v,w;
        cin >> u >> v >>w;
        cout<<endl;
        g.createEdge(u, v,w);
    }

    g.print();
    vector<int> ans = shortestPath(g,1);
    cout<<"\n path:- ";
    for(auto i: ans){
        if(i == INT_MAX){
            cout<<" -- ";
        } else {
            cout<<i<<" ";
        }
    }
    return 0;
}