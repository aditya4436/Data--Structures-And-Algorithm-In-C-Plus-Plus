#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time Complexity: O(n) - Visiting each node once
// Space Complexity: O(1) - Constant space used for Morris traversal without recursion or additional data structures

// Morris Preorder Traversal
vector<int> MorrisPreorderTraversal(TreeNode* root) {
    vector<int> ans;

    // Check if the tree is empty
    if (!root) {
        return ans;
    }

    TreeNode *current = root;

    while (current) {
        if (!current->left) {
            // If there is no left child, visit the current node and move to the right
            ans.push_back(current->val);
            current = current->right;
        } else {
            // Find the predecessor in the left subtree
            TreeNode *predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                // If predecessor's right is NULL, link it to the current node and move to the left child
                predecessor->right = current;
                ans.push_back(current->val);
                current = current->left;
            } else {
                // If predecessor's right is not NULL, unlink and move to the right child
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }

    return ans;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = MorrisPreorderTraversal(root);

    // Output the result
    cout << "Morris Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
