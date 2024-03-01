#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
        // Space Complexity: O(V), where V is the number of vertices.

        int n = graph.size();
        vector<int> colors(n, 0);

        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                queue<int> q;
                q.push(i);
                colors[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (colors[neighbor] == 0) {
                            colors[neighbor] = -colors[node];
                            q.push(neighbor);
                        } else if (colors[neighbor] == colors[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    // Example usage:
    Solution solution;
    vector<vector<int>> exampleGraph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    bool result = solution.isBipartite(exampleGraph);

    if (result) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
