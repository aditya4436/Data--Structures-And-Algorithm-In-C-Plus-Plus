#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int m, int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int delrow[], int delcol[], int iniColor, int newColor) {
    ans[row][col] = newColor;

    // Explore neighbors in all four directions
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        // Check if the neighbor is within bounds and has the same initial color
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(n, m, nrow, ncol, image, ans, delrow, delcol, iniColor, newColor);
        }
    }
}

// Time Complexity: O(n * m), where n is the number of rows and m is the number of columns in the image.
// The DFS algorithm visits each pixel once, and in the worst case, it visits all pixels in the grid.

// Space Complexity: O(n * m + maxDepth), where maxDepth is at most O(n + m) in this case due to recursion stack.
// We create a copy of the image to store the result (ans), contributing O(n * m) to space complexity.
// The recursion stack depth is bounded by the maximum depth of the recursion, which is at most O(n + m).

vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    // Get the initial color of the starting pixel
    int iniColor = image[x][y];

    // Create a copy of the image to store the result
    vector<vector<int>> ans = image;

    // Define the possible movements: up, left, down, right
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};

    // Perform DFS to fill the region with the new color
    dfs(n, m, x, y, image, ans, delrow, delcol, iniColor, p);

    // Return the modified image
    return ans;
}

int main() {
    // Example usage
    int n = 3, m = 3;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int x = 1, y = 1, p = 2;

    // Call floodFill function
    vector<vector<int>> result = floodFill(image, n, m, x, y, p);

    // Display the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
