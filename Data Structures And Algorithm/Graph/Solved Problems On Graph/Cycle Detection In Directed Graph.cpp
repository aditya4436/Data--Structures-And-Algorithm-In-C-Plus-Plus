#include<bits/stdc++.h>
using namespace std;


// Time Complexity:- O(v+e)
// Space Complexity:- O(v), v is the number of vertices.
bool checkCycle(int node, vector<int> adj[], int vis[], int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycle(it, adj, vis, pathVis)==true){
                return true;
            }
        }

        else if(pathVis[it]){
            return true;
        }
    }

    pathVis[node]=0;
    return false;
}

bool isCyclic(int n, vector<int> adj[]){
    int vis[n]={0};
    int pathVis[n]={0};

    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(checkCycle(i, adj, vis, pathVis)==true){
                return true;
            }
        }
    }

    return false;
}

void addEdge(vector <int> adj[], int u, int v) {
  adj[u].push_back(v);
}

int main() {
    // Example usage:
    int numNodes=7;
    vector<int> adj[numNodes];

    // Assuming a directed graph represented by an adjacency list
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);

    if (isCyclic(numNodes, adj)) {
        cout << "The graph contains a cycle." << endl;
    } 

    else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
