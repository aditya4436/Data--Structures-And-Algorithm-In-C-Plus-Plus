#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty()) {
        int currentRow = q.front().first;
        int currentCol = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                int nrow = currentRow + delrow;
                int ncol = currentCol + delcol;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numberOfIslands(vector<vector<int>> &grid, int n, int m) {
    // Time Complexity: O(n * m) - visiting each cell once
    // Space Complexity: O(n * m) - using a 2D array for visited cells

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == 1) {
                count++;
                bfs(row, col, vis, grid);
            }
        }
    }

    return count;
}

int main() {
    // Example usage
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    int n = grid.size();
    int m = grid[0].size();

    int result = numberOfIslands(grid, n, m);

    cout << "Number of islands: " << result << endl;

    return 0;
}
