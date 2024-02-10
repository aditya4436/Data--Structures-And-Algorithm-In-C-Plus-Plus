#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat) {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

// Time Comlexity:- O(n), because we are comparing every node in
//                  the binary tree.
// Space Complexity:- O(1)
bool isSymmetricHelp(TreeNode<int> *left, TreeNode<int> *right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }
    return (left->data == right->data) && isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode<int> *root) {
    if (root == NULL) {
        return true;
    }
    return isSymmetricHelp(root->left, root->right);
}

int main() {
    // Example usage:
    // Constructing a symmetric tree
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(2);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->right->left = new TreeNode<int>(4);
    root->right->right = new TreeNode<int>(3);

    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    // Don't forget to free memory by deleting the allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
