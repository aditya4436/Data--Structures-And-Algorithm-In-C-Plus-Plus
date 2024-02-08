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
int dfsHeight(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    int lh = dfsHeight(root->left);
    if (lh == -1) {
        return -1;
    }

    int rh = dfsHeight(root->right);
    if (rh == -1) {
        return -1;
    }

    if (std::abs(lh - rh) > 1) {
        return -1;
    }

    return std::max(lh, rh) + 1;
}

template<typename T>
bool isBalancedBT(TreeNode<T>* root) {
    // Time complexity: O(N), where N is the number of nodes in the binary tree.
    // Each node is visited once.

    // Space complexity: O(H), where H is the height of the binary tree.
    // The space complexity is the maximum depth of the recursion stack,
    // which is equivalent to the height of the tree.

    return dfsHeight(root) != -1;
}

int main() {
    // Example usage:
    // Construct a balanced binary tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Check if the tree is balanced
    if (isBalancedBT(root)) {
        std::cout << "The binary tree is balanced." << std::endl;
    } else {
        std::cout << "The binary tree is not balanced." << std::endl;
    }

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
