#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Time Complexity:- O(n), because we are visiting
//                   each node in the binary tree.
// Space Complexity:- O(1), because we are not using
//                    any extra space.
void morrisInorderTraversal(TreeNode* root) {
    TreeNode* current = root;

    while (current) {
        if (!current->left) {
            // If the current node has no left child
            cout << current->val << " ";
            current = current->right;
        } else {
            // Find the predecessor (rightmost node in the left subtree)
            TreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                // If the predecessor's right child is NULL
                predecessor->right = current;
                current = current->left;
            } else {
                // If the predecessor's right child is not NULL
                predecessor->right = NULL;  // Revert the changes made
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

// Example usage:
int main() {
    // Construct a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform Morris Inorder Traversal
    morrisInorderTraversal(root);

    return 0;
}
