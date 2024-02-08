#include <iostream>

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
bool identicalTrees(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
    // Time complexity: O(min(N1, N2)), where N1 and N2 are the number of nodes in the two trees.
    // In the worst case, we need to check all the nodes.

    // Space complexity: O(min(H1, H2)), where H1 and H2 are the heights of the two trees.
    // The space complexity is the maximum depth of the recursion stack,
    // which is equivalent to the height of the smaller tree.

    if (root1 == nullptr || root2 == nullptr) {
        return (root1 == root2);
    }

    return (root1->data == root2->data) &&
           identicalTrees(root1->left, root2->left) &&
           identicalTrees(root1->right, root2->right);
}

int main() {
    // Example usage:
    // Construct two identical binary trees
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);

    BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(1);
    root2->left = new BinaryTreeNode<int>(2);
    root2->right = new BinaryTreeNode<int>(3);
    root2->left->left = new BinaryTreeNode<int>(4);
    root2->left->right = new BinaryTreeNode<int>(5);

    // Check if the two trees are identical
    if (identicalTrees(root1, root2)) {
        std::cout << "The two binary trees are identical." << std::endl;
    } else {
        std::cout << "The two binary trees are not identical." << std::endl;
    }

    // Clean up the allocated memory
    // (Note: In a real-world scenario, you might want to use smart pointers or a proper memory management approach.)
    delete root1->left->right;
    delete root1->left->left;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->right;
    delete root2->left->left;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
