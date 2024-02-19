#include <iostream>

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to create a new node with the given data
TreeNode<int>* newNode(int data) {
    TreeNode<int>* node = new TreeNode<int>(data);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to insert a value into a Binary Search Tree (BST)
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val) {
    // Time Complexity: O(h), where h is the height of the binary search tree.
    // In the worst case, the height of the tree is h=log(n) (for a balanced tree),
    // where n is the number of nodes. Thus, the time complexity is O(log(n)).

    // Space Complexity: O(h), where h is the height of the binary search tree.
    // The space complexity is determined by the recursion stack, which can go up
    // to the height of the tree. In the worst case, it's O(h).

    if (!root) {
        return newNode(val);
    } else if (val < root->val) {
        root->left = insertionInBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertionInBST(root->right, val);
    }
    return root;
}

int main() {
    // Example usage:
    TreeNode<int>* root = nullptr;

    // Insert nodes into the BST
    root = insertionInBST(root, 5);
    root = insertionInBST(root, 3);
    root = insertionInBST(root, 7);
    return 0;
}
