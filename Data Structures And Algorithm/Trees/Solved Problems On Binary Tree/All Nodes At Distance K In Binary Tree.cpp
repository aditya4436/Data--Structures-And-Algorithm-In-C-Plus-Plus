#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to mark parents using BFS
void markParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode *target) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node->left) {
            parent_track[node->left] = node;
            q.push(node->left);
        }

        if (node->right) {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}

// Time Complexity:- O(n)+O(n)+O(log n), O(n),  to make the parent,
//                   another O(n), to traverse the nodes at the
//                   distance of k, and O(log n), because we are
//                   traversing in the hashmap to find the parent of
//                   the node. Overall the time complexity is O(n).
// Space Comlexity:- O(n)+O(n)+O(n), O(n) to store the parent, another
//                   O(n), to for the queue, and O(n) to mark the visited
//                   node. Overall Time Complexity O(n).
// Main function to find nodes at distance K from target
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // Create a map to track parent nodes
    unordered_map<TreeNode*, TreeNode*> parent_track;
    // Mark parents using BFS
    markParent(root, parent_track, target);

    // Create a map to track visited nodes
    unordered_map<TreeNode*, bool> visited;
    // Create a queue for BFS
    queue<TreeNode*> q;
    // Initialize with the target node
    q.push(target);
    // Mark the target node as visited
    visited[target] = true;

    int curr_level = 0;  // Current level in BFS

    while (!q.empty()) {
        int size = q.size();

        // Check if the current level is equal to K
        if (curr_level++ == k) {
            break;
        }

        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();

            // Explore left child
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }

            // Explore right child
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }

            // Explore parent
            if (parent_track[node] && !visited[parent_track[node]]) {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    // Extract values of nodes at distance K
    vector<int> ans;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        ans.push_back(node->val);
    }

    return ans;
}

int main() {
    // Example usage:
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;

    // Find nodes at distance K from the target
    vector<int> result = distanceK(root, target, 2);

    // Output the result
    cout << "Nodes at distance K from target: ";
    for (int val : result) {
        cout << val << " ";
    }

    // Don't forget to free the allocated memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
