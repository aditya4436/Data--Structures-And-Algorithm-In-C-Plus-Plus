#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V) for the visited array and stack.

// DFS function for topological sort
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &graph) {
    vis[node] = 1;
    for (auto it : graph[node]) {
        if (!vis[it]) {
            dfs(it, vis, st, graph);
        }
    }
    st.push(node);
}

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Build the adjacency list
    vector<vector<int>> graph(v);
    for (const auto &edge : edges) {
        int from = edge[0];
        int to = edge[1];
        graph[from].push_back(to);
    }

    // Stack to store the topological order
    stack<int> st;

    // Visited array
    vector<int> vis(v, 0);

    // Perform DFS on each unvisited node
    for (int i = 0; i < v; i++) {
        if (vis[i] == 0) {
            dfs(i, vis, st, graph);
        }
    }

    // Create the result vector by popping elements from the stack
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main() {
    // Example usage
    int v = 6; // Number of vertices
    int e = 6; // Number of edges

    // Sample edges
    vector<vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};

    // Perform topological sort
    vector<int> result = topologicalSort(edges, v, e);

    // Output the result
    cout << "Topological Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
