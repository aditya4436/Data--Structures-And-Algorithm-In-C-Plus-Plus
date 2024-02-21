#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper function to push all left nodes onto the stack
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h), where h is the height of the tree (stack space for recursion)
    void pushAll(TreeNode *root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    // Constructor to initialize the iterator with the leftmost node
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h), where h is the height of the tree (stack space for pushAll)
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    // Get the next smallest element in the BST
    // Time Complexity: O(1) amortized (amortized because pushAll might be called occasionally)
    // Space Complexity: O(h), where h is the height of the tree (stack space for pushAll)
    int next() {
        TreeNode *node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }

    // Check if there are more elements to iterate
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool hasNext() {
        return !st.empty();
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    cout << "BST Iterator: ";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}
