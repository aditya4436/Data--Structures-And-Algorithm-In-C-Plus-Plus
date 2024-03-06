#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] == 1) // Detected a cycle
            return false;

        if (color[node] == 2) // Already visited, safe node
            return true;

        color[node] = 1; // Mark as visiting

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, color))
                return false;
        }

        color[node] = 2; // Mark as visited, safe node
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0: not visited, 1: visiting, 2: visited

        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, color))
                result.push_back(i);
        }

        return result;
    }
};

int main() {
    // Example usage:
    Solution solution;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result = solution.eventualSafeNodes(graph);

    // Display the result
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
