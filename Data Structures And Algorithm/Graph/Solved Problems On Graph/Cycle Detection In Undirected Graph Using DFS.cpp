#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E) - calls detectCycle for each unvisited vertex
// Space Complexity: The overall space complexity is O(V) due to the visited
//                   array and the recursive call stack.
bool detectCycle(int node, int parent, int vis[], vector<int> adj[]){
    vis[node]=1;

    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            if(detectCycle(adjacentNode, node, vis, adj)==true){
                return true;
            }
        }
        
        else if(adjacentNode != parent){
            return true;
        }
    }

    return true;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V]={0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycle(i, -1, vis, adj)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    if (isCycle(V, adj)) {
        cout << "The graph contains a cycle." << endl;
    } 
    else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
/*0 1
1 2
2 3
3 0*/
