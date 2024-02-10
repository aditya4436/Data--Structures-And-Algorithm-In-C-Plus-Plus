#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity:- O(n), because we are traversing the all the nodes
//                   binary tree.
// Space Complexity:- O(W), W is the width of binary tree and in the worst
//                    case both map and queue can store all the nodes.
template <typename T>
vector<T> bottomView(TreeNode<T> *root) {
    // Vector to store the bottom view nodes
    vector<T> ans;

    // Map to store the bottom-most node at each horizontal position
    map<int, T> nodes;

    // Queue for BFS traversal
    queue<pair<TreeNode<T>*, int>> q;
    q.push({root, 0});

    // BFS traversal
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<T> *node = it.first;
        int line = it.second;

        // Update the bottom-most node at each horizontal position
        nodes[line] = node->data;

        // Enqueue left child with adjusted horizontal position
        if (node->left) {
            q.push({node->left, line - 1});
        }

        // Enqueue right child with adjusted horizontal position
        if (node->right) {
            q.push({node->right, line + 1});
        }
    }

    // Populate the result vector from the map
    for (auto it : nodes) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    // Example usage
    // Construct a sample binary tree
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->right->right = new TreeNode<int>(5);
    root->left->right->right->right = new TreeNode<int>(6);

    // Get the bottom view
    vector<int> result = bottomView(root);

    // Display the result
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
