#include <iostream>
#include <algorithm>
#include <climits>

template<typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

template<typename T>
int MaximumSum(TreeNode<T>* root, int& maximum) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = std::max(0, MaximumSum(root->left, maximum));
    int rightSum = std::max(0, MaximumSum(root->right, maximum));

    maximum = std::max(maximum, leftSum + rightSum + root->val);

    return root->val + std::max(leftSum, rightSum);
}

template<typename T>
int maxPathSum(TreeNode<T>* root) {
    // Time complexity: O(N), where N is the number of nodes in the binary tree.
    // Each node is visited once.

    // Space complexity: O(H), where H is the height of the binary tree.
    // The space complexity is the maximum depth of the recursion stack,
    // which is equivalent to the height of the tree.

    int maximum = INT_MIN;
    MaximumSum(root, maximum);
    return maximum;
}

int main() {
    // Example usage:
    // Construct a binary tree
    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(10);
    root->left->left = new TreeNode<int>(20);
    root->left->right = new TreeNode<int>(1);
    root->right->right = new TreeNode<int>(-25);
    root->right->right->left = new TreeNode<int>(3);
    root->right->right->right = new TreeNode<int>(4);

    // Calculate the maximum path sum
    int maxSum = maxPathSum(root);
    std::cout << "Maximum Path Sum: " << maxSum << std::endl;

    // Clean up the allocated memory
    // (Note: In a real-world scenario, you might want to use smart pointers or a proper memory management approach.)
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
