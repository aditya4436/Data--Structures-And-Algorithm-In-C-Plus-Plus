#include <iostream>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
int findCeil(BinaryTreeNode<T>* node, T x) {
    // Time Complexity: O(h), where h is the height of the binary search tree.
    // In the worst case, the height of the tree is h=log(n) (for a balanced tree),
    // where n is the number of nodes. Thus, the time complexity is O(log(n)).

    // Space Complexity: O(1)
    // The space complexity is constant as we are using only a constant amount of extra space.

    int ans = -1;
    while (node) {
        if (node->data == x) {
            ans = node->data;
            return ans;
        }
        if (x > node->data) {
            node = node->right;
        } else {
            ans = node->data;
            node = node->left;
        }
    }
    return ans;
}

int main() {
    // Example usage:
    // Assuming you have a Binary Search Tree (BST) as follows:
    //          8
    //        /   \
    //       3    10
    //      / \     \
    //     1   6    14
    //        / \   /
    //       4   7  13

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(8);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(10);
    root->left->left = new BinaryTreeNode<int>(1);
    root->left->right = new BinaryTreeNode<int>(6);
    root->left->right->left = new BinaryTreeNode<int>(4);
    root->left->right->right = new BinaryTreeNode<int>(7);
    root->right->right = new BinaryTreeNode<int>(14);
    root->right->right->left = new BinaryTreeNode<int>(13);

    int x = 5;
    int ceilValue = findCeil(root, x);
    
    std::cout << "Ceil of " << x << " is: " << ceilValue << std::endl;

    // Clean up the allocated memory (not shown in the original function)
    // Delete the tree nodes in a bottom-up manner.
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
