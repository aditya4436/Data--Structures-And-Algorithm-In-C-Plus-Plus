#include<bits/stdc++.h>

using namespace std;

// Function to calculate the minimum time to rot all oranges
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Visited array to keep track of the visited oranges
    int vis[n][m];

    // Count of fresh oranges
    int countFresh = 0;

    // Queue to perform BFS
    queue<pair<pair<int, int>, int>> q;

    // Initializing the queue and visited array
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                // If the orange is rotten, add it to the queue with time 0
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0;
            }

            if(grid[i][j] == 1) {
                // Counting the number of fresh oranges
                countFresh++;
            }
        }
    }

    // Time variable to store the final result
    int time = 0;

    // Arrays to represent possible movements: up, right, down, left
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    // Count variable to keep track of the number of fresh oranges rotten during BFS
    int count = 0;

    // Perform BFS
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        
        // Update time
        time = max(time, t);

        // Remove the front element from the queue
        q.pop();

        // Check all possible directions
        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check if the neighbor is within bounds, not visited, and is a fresh orange
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                // Add the neighbor to the queue with the next time step
                q.push({{nrow, ncol}, t + 1});

                // Mark the neighbor as visited
                vis[nrow][ncol] = 1;

                // Increment the count of rotten oranges
                count++;
            }
        }
    }

    // If the count of rotten oranges is not equal to the count of fresh oranges, return -1
    if(count != countFresh) {
        return -1;
    }

    // Return the final time required to rot all oranges
    return time;
} 

// Time Complexity: O(n * m), where n is the number of rows and m is the number of columns in the grid.
// Each cell is visited at most once in the worst case.

// Space Complexity: O(n * m), as we use a visited array of the same size as the input grid.

int main() {
    // Example usage
    int n = 3, m = 3;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    // Call minTimeToRot function
    int result = minTimeToRot(grid, n, m);

    // Display the result
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}
