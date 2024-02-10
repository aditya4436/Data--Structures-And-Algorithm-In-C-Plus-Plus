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

// Time Complexity:- O(n), because in the worst case all the
//                   nodes can be traversed.
// Space Complexity:- O(W)+O(1)=O(n), W is the width of the binary tree.
//                    The map stores nodes based on their 
//                    horizontal positions, and in the worst case,
//                    it can store one node per horizontal position.
template <typename T>
vector<T> getTopView(TreeNode<T> *root) {
    vector<T> ans;
    if (!root) {
        return ans;
    }

    map<int, T> nodes;
    queue<pair<TreeNode<T>*, int>> q;
    q.push({root, 0});  // Push the root node into the queue

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<T> *node = it.first;
        int line = it.second;

        if (nodes.find(line) == nodes.end()) {
            nodes[line] = node->data;
        }

        if (node->left) {
            q.push({node->left, line - 1});
        }
        if (node->right) {
            q.push({node->right, line + 1});
        }
    }

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

    // Get the top view
    vector<int> result = getTopView(root);

    // Display the result
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
