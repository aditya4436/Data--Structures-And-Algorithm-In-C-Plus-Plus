#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E) - calls detectCycle for each unvisited vertex
// Space Complexity: O(V + E) - adjacency list, visited array, and queue
bool detectCycle(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            } 
            
            else if (parent != adjacentNode) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycle(i, adj, vis)) {
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
