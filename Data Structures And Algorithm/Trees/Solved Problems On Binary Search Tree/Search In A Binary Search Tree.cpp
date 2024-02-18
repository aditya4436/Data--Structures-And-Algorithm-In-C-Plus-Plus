#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Time Complexity: O(h), where h is the height of the BST.
Space Complexity: O(h), due to the recursive call stack. In the worst case, the height of the BST could be equal to the number of nodes, resulting in O(n) space complexity.
*/

// Function to search for a value in a Binary Search Tree (BST)
TreeNode* searchBST(TreeNode* root, int val) {
    // Base case: if the tree is empty or the value is found
    if (!root || root->val == val) {
        return root;
    }

    // If the value is less than the current node's value, search in the left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }

    // If the value is greater than the current node's value, search in the right subtree
    return searchBST(root->right, val);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int target = 4;
    TreeNode* result = searchBST(root, target);

    // Output the result
    if (result) {
        cout << "Node with value " << target << " found in the BST." << endl;
    } else {
        cout << "Node with value " << target << " not found in the BST." << endl;
    }

    return 0;
}
