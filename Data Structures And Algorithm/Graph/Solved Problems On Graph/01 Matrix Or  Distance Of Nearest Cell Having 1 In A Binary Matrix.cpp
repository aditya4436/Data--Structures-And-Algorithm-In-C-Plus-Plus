#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m) - each cell is visited once
// Space Complexity: O(n * m) - used for the visited array and distance array

vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m) {
    // Visited array to keep track of visited cells
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // Distance array to store the minimum distance to each cell
    vector<vector<int>> dist(n, vector<int>(m, 0));

    // Store the coordinates and the steps in the queue
    queue<pair<pair<int, int>, int>> q;

    // Initialize the queue with the positions of 1s in the matrix
    // Distance Of Nearest Cell Having 1 In A Binary Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else {
                vis[i][j] = 0;
            }
        }
    }

    // Distance Of Nearest Cell Having 0 In A Binary Matrix
    //   for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (mat[i][j] == 0) {
    //             q.push({{i, j}, 0});
    //             vis[i][j] = 1;
    //         } else {
    //             vis[i][j] = 0;
    //         }
    //     }
    // }
    // Possible directions to move (up, right, down, left)
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    // BFS traversal
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;

        // Explore all possible directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check if the new position is within the matrix bounds and not visited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    return dist;
}

int main() {
    // Example usage
    int n, m;
    cout << "Enter the number of rows (n) and columns (m): ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = nearest(matrix, n, m);

    // Output the result
    cout << "Distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
