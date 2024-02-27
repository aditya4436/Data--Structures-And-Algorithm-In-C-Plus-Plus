#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<int> &vis) {
    vis[node] = 1;

    for (auto it : adjList[node]) {
        if (!vis[it]) {
            dfs(it, adjList, vis);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Time Complexity: O(n^2) - nested loops to build adjacency list
    // Space Complexity: O(n) - adjacency list and visited array

    vector<vector<int>> adjList(n);

    // Build the adjacency list
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (roads[i][j] == 1) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> vis(n, 0);
    int count = 0;

    // DFS to find connected components
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, adjList, vis);
        }
    }

    return count;
}

int main() {
    // Example usage
    vector<vector<int>> roads = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int n = 3;

    int result = findNumOfProvinces(roads, n);
    
    cout << "Number of provinces: " << result << endl;

    return 0;
}
