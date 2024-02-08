#include <iostream>
#include <algorithm>

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
int height(TreeNode<T>* root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = std::max(diameter, lh + rh);
    
    return 1 + std::max(lh, rh);
}

template<typename T>
int diameterOfBinaryTree(TreeNode<T>* root) {
    // Time complexity: O(N), where N is the number of nodes in the binary tree.
    // Each node is visited once.

    // Space complexity: O(H), where H is the height of the binary tree.
    // The space complexity is the maximum depth of the recursion stack,
    // which is equivalent to the height of the tree.

    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    // Example usage:
    // Construct a binary tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Calculate the diameter of the tree
    int treeDiameter = diameterOfBinaryTree(root);
    std::cout << "Diameter of the binary tree: " << treeDiameter << std::endl;

    // Clean up the allocated memory
    // (Note: In a real-world scenario, you might want to use smart pointers or a proper memory management approach.)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
