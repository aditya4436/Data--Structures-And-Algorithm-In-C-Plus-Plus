#include<bits/stdc++.h>

using namespace std;

// Time Complexity: O(N*M) where N is the number of rows and M is the number of columns in the matrix.
// Space Complexity: O(N*M) as we use a 2D vector to keep track of visited cells, and the set stores distinct island shapes.

void dfs(int row, int col, int **arr, vector<vector<int>> &vis,
         vector<pair<int, int>> &vec, int baseRow, int baseCol, int n, int m) {
    vis[row][col] = 1;
    vec.push_back({row - baseRow, col - baseCol});
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    
    // Loop through all neighbors (up, left, down, right)
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        // Check if the neighbor is within bounds, not visited, and has a value of 1
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == 1) {
            // Recursive call to explore the connected island
            dfs(nrow, ncol, arr, vis, vec, baseRow, baseCol, n, m);
        }
    }
}

// Function to find the number of distinct islands
int distinctIslands(int** arr, int n, int m) {
    // Set to store distinct island shapes
    set<vector<pair<int, int>>> st;
    // 2D vector to keep track of visited cells
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    // Loop through all cells in the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is part of an unvisited island
            if (vis[i][j] == 0 && arr[i][j] == 1) {
                // Vector to store the shape of the current island
                vector<pair<int, int>> vec;
                // DFS to explore the connected cells of the island
                dfs(i, j, arr, vis, vec, i, j, n, m);
                // Insert the island shape into the set
                st.insert(vec);
            }
        }
    }
    
    // The size of the set represents the number of distinct islands
    return st.size();
}

int main() {
    // Example usage
    int n = 4;
    int m = 5;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    // Initialize the matrix (example)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Set values based on your requirements
            arr[i][j] = 1;  // For example, consider all cells as land
        }
    }

    // Call the function to get the number of distinct islands
    int result = distinctIslands(arr, n, m);

    // Output the result
    cout << "Number of distinct islands: " << result << endl;

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
