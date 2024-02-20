#include <iostream>
#include <vector>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to construct a Binary Search Tree from a given preorder traversal
TreeNode *ConstructBST(std::vector<int> &preorder, int &index, int maxVal) {
    // Time Complexity: O(n), where n is the number of nodes in the BST.
    // Each node in the preorder traversal is processed once.

    // Space Complexity: O(h), where h is the height of the BST.
    // The space complexity is determined by the recursion stack, which can go up
    // to the height of the tree. In the worst case, it's O(h).

    if (index == preorder.size() || preorder[index] > maxVal) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = ConstructBST(preorder, index, root->val);
    root->right = ConstructBST(preorder, index, maxVal);

    return root;
}

// Function to print the inorder traversal of a BST
void inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Example usage:
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};

    int index = 0;
    TreeNode *bstRoot = ConstructBST(preorder, index, INT_MAX);

    std::cout << "Inorder Traversal of Constructed BST: ";
    inorderTraversal(bstRoot);
    std::cout << std::endl;
    return 0;
}
