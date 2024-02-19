#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to perform an in-order traversal to find the kth smallest element
void inorder(TreeNode *root, int &k, int &count, int &ans) {
    // Base case: If the current node is null or k elements are already found, return.
    if (!root || count >= k) {
        return;
    }

    // Traverse left subtree
    inorder(root->left, k, count, ans);

    // Process current node
    count++;
    if (count == k) {
        ans = root->val;
        return;
    }

    // Traverse right subtree
    inorder(root->right, k, count, ans);
}

// Function to find the kth smallest element in a BST
int kthSmallest(TreeNode *root, int k) {
    // Time Complexity: O(h + k), where h is the height of the binary search tree.
    // In the worst case, the height of the tree is h=log(n) (for a balanced tree),
    // where n is the number of nodes. Thus, the time complexity is O(log(n) + k).

    // Space Complexity: O(h), where h is the height of the binary search tree.
    // The space complexity is determined by the recursion stack, which can go up
    // to the height of the tree. In the worst case, it's O(h).

    int count = 0, ans = -1;
    inorder(root, k, count, ans);
    return ans;
}

int main() {
    // Example usage:
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 2;
    int result = kthSmallest(root, k);

    std::cout << "The " << k << "th smallest element is: " << result << std::endl;

    // Clean up the allocated memory for the entire tree
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
