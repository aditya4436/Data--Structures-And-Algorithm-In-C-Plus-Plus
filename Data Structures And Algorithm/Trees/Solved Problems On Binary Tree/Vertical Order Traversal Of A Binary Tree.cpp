#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
//                  N nodes are traversed in the worst case.
// Space Complexity: O(N), where N is the number of nodes in the binary tree.
//                   The map and queue contribute to space complexity linearly
//                   with the number of nodes. The vector stores all the nodes
//                   in the worst case.
// vector<vector<int>> verticalTraversal(TreeNode* root) {
//     // Map to store nodes based on their x-coordinate and y-coordinate
//     map<int, map<int, multiset<int>>> nodes;

//     // Queue for level order traversal
//     queue<pair<TreeNode*, pair<int, int>>> todo;
//     todo.push({root, {0, 0}});

//     // Perform level order traversal
//     while (!todo.empty()) {
//         auto p = todo.front();
//         todo.pop();
//         TreeNode *node = p.first;
//         int x = p.second.first, y = p.second.second;

//         // Insert the node value into the multiset
//         nodes[x][y].insert(node->val);

//         // Enqueue left child with updated coordinates
//         if (node->left) {
//             todo.push({node->left, {x - 1, y + 1}});
//         }

//         // Enqueue right child with updated coordinates
//         if (node->right) {
//             todo.push({node->right, {x + 1, y + 1}});
//         }
//     }

//     // Prepare the final result vector
//     vector<vector<int>> ans;
//     for (auto& p : nodes) {
//         vector<int> col;
//         for (auto& q : p.second) {
//             col.insert(col.end(), q.second.begin(), q.second.end());
//         }
//         ans.push_back(col);
//     }

//     return ans;
// }

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
//                  N nodes are traversed in the worst case.
// Space Complexity: O(N), where N is the number of nodes in the binary tree.
//                   The map and queue contribute to space complexity linearly
//                   with the number of nodes. The vector stores all the nodes
//                   in the worst case.
vector<int> verticalOrderTraversal(TreeNode* root) {
    if (!root) {
        return {}; // Return an empty vector if the tree is empty
    }

    // Map to store nodes based on their x-coordinate and y-coordinate
    map<int, map<int, vector<int>>> nodes;

    // Queue for level order traversal
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});

    // Perform level order traversal
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;

        // Push the node data into the vector
        nodes[x][y].push_back(node->val);

        // Enqueue left child with updated coordinates
        if (node->left) {
            todo.push({node->left, {x - 1, y + 1}});
        }

        // Enqueue right child with updated coordinates
        if (node->right) {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }

    // Prepare the final result vector
    vector<int> result;
    for (auto& p : nodes) {
        for (auto& q : p.second) {
            result.insert(result.end(), q.second.begin(), q.second.end());
        }
    }

    return result;
}
int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // vector<vector<int>> result = verticalTraversal(root);

    // // Display the result
    // for (const auto& col : result) {
    //     for (int val : col) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    // cout<<endl;

    vector<int> result = verticalOrderTraversal(root);

    // Display the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
