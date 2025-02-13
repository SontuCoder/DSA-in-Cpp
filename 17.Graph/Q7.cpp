// Dijkstra's algo in undirected ( using Set )


#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<set>
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

// **Dijkstra's Algorithm using Set**
vector<int> shortestPath(Graph& g, int src){
    unordered_map<int, list<pair<int, int>>>& adj = g.getGraph();
    int V = g.getVertex();

    // Distance array, initialized to INF
    vector<int> dist(V, INT_MAX);
    set<pair<int, int>> pairSort; // {distance, vertex}

    // Initialize source
    dist[src] = 0;
    pairSort.insert({0, src}); // Store {distance, node}

    while(!pairSort.empty()){
        // Get the closest vertex
        pair<int, int> top = *pairSort.begin();
        pairSort.erase(pairSort.begin());
        
        int node = top.second;
        int nodeDist = top.first;

        // Traverse all neighbors
        for(auto j : adj[node]){
            int adjNode = j.first;
            int edgeWeight = j.second;

            // If a shorter path is found
            if(dist[adjNode] > nodeDist + edgeWeight){
                // Remove old distance if exists
                pairSort.erase({dist[adjNode], adjNode});
                
                // Update distance
                dist[adjNode] = nodeDist + edgeWeight;

                // Insert new distance
                pairSort.insert({dist[adjNode], adjNode});
            }
        }
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
        cin >> u >> v >> w;
        cout<<endl;
        g.createEdge(u, v, w);
    }

    g.print();

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    vector<int> ans = shortestPath(g, src);

    cout << "\nShortest paths from node " << src << ":\n";
    for (int i = 0; i < ans.size(); i++){
        if (ans[i] == INT_MAX)
            cout << "Node " << i << " -> INF\n";
        else
            cout << "Node " << i << " -> " << ans[i] << endl;
    }

    return 0;
}
