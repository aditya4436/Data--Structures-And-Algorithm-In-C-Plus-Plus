#include <iostream>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the node with the minimum value in a BST
template <typename T>
BinaryTreeNode<T>* findMin(BinaryTreeNode<T>* root) {
    BinaryTreeNode<T>* current = root;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from a BST
template <typename T>
BinaryTreeNode<T>* deleteNode(BinaryTreeNode<T>* root, T key) {
    // Time Complexity: O(h), where h is the height of the binary search tree.
    // In the worst case, the height of the tree is h=log(n) (for a balanced tree),
    // where n is the number of nodes. Thus, the time complexity is O(log(n)).

    // Space Complexity: O(h), where h is the height of the binary search tree.
    // The space complexity is determined by the recursion stack, which can go up
    // to the height of the tree. In the worst case, it's O(h).

    // Base case: If the tree is empty, return nullptr.
    if (!root) {
        return root;
    }

    // Search for the node to be deleted in the left or right subtree.
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child.
        if (!root->left) {
            BinaryTreeNode<T>* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            BinaryTreeNode<T>* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree).
        BinaryTreeNode<T>* successor = findMin(root->right);

        // Copy the inorder successor's data to this node.
        root->data = successor->data;

        // Delete the inorder successor.
        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

// Function to deallocate memory for the entire tree
template <typename T>
void deleteTree(BinaryTreeNode<T>* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    // Example usage:
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(7);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(8);

    // Delete node with key 5
    root = deleteNode(root, 5);

    // Clean up the allocated memory for the entire tree
    deleteTree(root);

    return 0;
}
