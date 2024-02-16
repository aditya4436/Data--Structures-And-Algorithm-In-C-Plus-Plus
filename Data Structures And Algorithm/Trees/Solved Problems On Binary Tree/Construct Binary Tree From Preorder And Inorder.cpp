#include <iostream>
#include <vector>
#include <map>

using namespace std;

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
};

// Time complexity: O(N), where N is the number of nodes in the binary tree
// Space complexity: O(N), for the map used to store indices in the inorder traversal
TreeNode<int>* ConstructBinaryTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numLeft = inRoot - inStart;

    root->left = ConstructBinaryTree(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = ConstructBinaryTree(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// Time complexity: O(N), where N is the number of nodes in the binary tree
// Space complexity: O(N), for the map used to store indices in the inorder traversal
TreeNode<int>* buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    TreeNode<int>* root = ConstructBinaryTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}

int main() {
    // Example usage:
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};

    // Time and space complexity for the buildBinaryTree function are O(N)
    TreeNode<int>* root = buildBinaryTree(inorder, preorder);

    // You can perform operations on the constructed binary tree here

    return 0;
}
