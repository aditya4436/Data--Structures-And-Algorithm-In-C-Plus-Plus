#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};
// Time Complexity:- O(n), because we are traversing the entire nodes.
// Space Complexity:- O(n), recursive stack space.
void BinaryTreePaths(TreeNode *root, vector<string> &ans, string currentPath = "") {
    if (!root) {
        return;
    }

    // Convert the integer value to a string before adding to the current path
    currentPath += to_string(root->val);

    // If the current node is a leaf node, add the current path to the result
    if (!root->left && !root->right) {
        ans.push_back(currentPath);
    } 
    else {
        // If not a leaf node, continue to the left and right subtrees
        if (root->left) {
            BinaryTreePaths(root->left, ans, currentPath + "->");
        }
        if (root->right) {
            BinaryTreePaths(root->right, ans, currentPath + "->");
        }
    }
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    BinaryTreePaths(root, ans, "");
    return ans;
}

// Example usage
int main() {
    // Constructing an arbitrary binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Get all root-to-leaf paths
    vector<string> paths = binaryTreePaths(root);

    // Print the paths
    cout << "Root-to-Leaf Paths:" << endl;
    for (const string &path : paths) {
        cout << path << endl;
    }

    // Deallocate memory (not shown in detail for simplicity)
    // ...

    return 0;
}
