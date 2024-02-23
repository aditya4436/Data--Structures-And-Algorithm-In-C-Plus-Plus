#include <iostream>
#include <climits>

/************************************************************
    Following is the Binary Tree node structure
************************************************************/
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

/************************************************************
    NodeValue class to store information about a subtree
************************************************************/
class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
/************************************************************
    Time Complexity: O(N)
    - N is the number of nodes in the binary tree.
    - Each node is visited exactly once.

    Space Complexity: O(H)
    - H is the height of the binary tree.
    - The maximum depth of the call stack during recursion is H.
    - In the worst case (skewed tree), H can be equal to N.
************************************************************/
/************************************************************
    Recursive function to find the largest BST subtree
************************************************************/
NodeValue largestBSTSubtreeHelper(TreeNode<int> *root) {
    // Base case: if the node is null, return a NodeValue with invalid values
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // Recursively get information from the left and right subtrees
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // Check if the current subtree is a valid BST.
    // If the maximum node in the left subtree is less than current node(root->data)
    // and minimum node from right subtree is greater than current node or
    // current node(root->data) is less than the minimum node of right subtree than it is
    // a BST.
    if (left.maxNode < root->data && root->data < right.minNode) {
        // If valid, return information about the subtree
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    // If not a valid BST, return information about the larger subtree
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

/************************************************************
    Main function to find the size of the largest BST subtree
************************************************************/
int largestBST(TreeNode<int> *root) {
    // Call the helper function and return the size of the largest BST subtree
    return largestBSTSubtreeHelper(root).maxSize;
}

/************************************************************
    Main function for testing
************************************************************/
int main() {
    // Create a sample binary tree
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(8);
    root->right->right = new TreeNode<int>(7);

    // Call the function to find the size of the largest BST subtree
    int result = largestBST(root);

    // Print the result
    std::cout << "Size of the largest BST subtree: " << result << std::endl;

    // Cleanup allocated memory
    delete root;

    return 0;
}
