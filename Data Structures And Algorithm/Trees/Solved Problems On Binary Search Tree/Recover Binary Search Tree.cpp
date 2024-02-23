#include <iostream>
#include <climits>

/************************************************************
    Following is the Binary Tree node structure
************************************************************/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/************************************************************
    Time Complexity: O(N)
    - N is the number of nodes in the binary tree.
    - Each node is visited exactly once during the inorder traversal.

    Space Complexity: O(H)
    - H is the height of the binary tree.
    - The maximum depth of the call stack during recursion is H.
    - In the worst case (skewed tree), H can be equal to N.
************************************************************/
class Solution {
private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;

private:
    // Inorder traversal to find the misplaced nodes
    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }

        inorder(root->left);

        // Check if the current node violates the BST property
        if (prev != NULL && (root->val < prev->val)) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    // Recover the BST by swapping misplaced nodes
    void recoverTree(TreeNode *root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); // Sentinel node to handle the edge case of the minimum integer value
        inorder(root);

        // Swap the values of misplaced nodes
        if (first && last) {
            std::swap(first->val, last->val);
        } else if (first && middle) {
            std::swap(first->val, middle->val);
        }
    }
};

/************************************************************
    Main function for testing
************************************************************/
int main() {
    // Example usage of the Solution class
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution solution;
    solution.recoverTree(root);

    // Cleanup allocated memory
    delete root;

    return 0;
}
