#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the Lowest Common Ancestor in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Time Complexity: O(h), where h is the height of the binary search tree.
    // In the worst case, the height of the tree is h=log(n) (for a balanced tree),
    // where n is the number of nodes. Thus, the time complexity is O(log(n)).

    // Space Complexity: O(h), where h is the height of the binary search tree.
    // The space complexity is determined by the recursion stack, which can go up
    // to the height of the tree. In the worst case, it's O(h).

    if (!root) {
        return nullptr;
    }

    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

int main() {
    // Example usage:
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode *p = root->left->left;   // Node with value 5
    TreeNode *q = root->left->right;  // Node with value 15

    TreeNode *lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "No common ancestor found." << std::endl;
    }

    // Clean up the allocated memory for the entire tree
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
