#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Enqueue boundary cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextRow = row + delrow[i];
                int nextCol = col + delcol[i];

                // Check valid neighbor and unvisited '1'
                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m &&
                    vis[nextRow][nextCol] == 0 && grid[nextRow][nextCol] == 1) {
                    q.push({nextRow, nextCol});
                    vis[nextRow][nextCol] = 1;
                }
            }
        }

        // Count unvisited '1's
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    // Example usage:
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    Solution solution;
    int result = solution.numEnclaves(grid);
    cout << "Number of Enclaves: " << result << endl;

    return 0;
}
