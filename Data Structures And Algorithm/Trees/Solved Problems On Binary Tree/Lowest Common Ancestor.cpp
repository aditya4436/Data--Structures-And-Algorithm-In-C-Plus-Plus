#include <iostream>
using namespace std;

// Definition of TreeNode for a binary tree
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Time Complexity:- O(n), because in the worst case we may 
//                   have to traverse the entire the tree.
// Space Complexity:- O(n), recursive stack space
// Function to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(!root){
        return -1;
    }
    if(root->data==x || root->data==y){
        return root->data;
    }
    int leftLCA=lowestCommonAncestor(root->left, x, y);
    int rightLCA=lowestCommonAncestor(root->right, x, y);
    if(leftLCA!=-1 && rightLCA!=-1){
        return root->data;
    }
    if(leftLCA==-1){
        return rightLCA;
    }
    if(rightLCA==-1){
        return leftLCA;
    }
    return root->data;
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes in a binary search tree (BST)
TreeNode<int>* lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q) {
    if(!root || root==p || root==q){
        return root;
    }
    TreeNode<int> *leftLCA=lowestCommonAncestor(root->left, p, q);
    TreeNode<int> *rightLCA=lowestCommonAncestor(root->right, p, q);
    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA==NULL){
        return rightLCA;
    }
    if(rightLCA==NULL){
        return leftLCA;
    }
    return root;
}

// Example usage
int main() {
    // Constructing an arbitrary binary tree
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(1);
    root->left->left = new TreeNode<int>(6);
    root->left->right = new TreeNode<int>(2);
    root->right->left = new TreeNode<int>(0);
    root->right->right = new TreeNode<int>(8);
    root->left->right->left = new TreeNode<int>(7);
    root->left->right->right = new TreeNode<int>(4);

    int x = 5;
    int y = 1;

    // Find the Lowest Common Ancestor for binary tree
    int lcaValue = lowestCommonAncestor(root, x, y);
    cout << "Lowest Common Ancestor Value (Binary Tree): " << lcaValue << endl;

    // Find the Lowest Common Ancestor for binary search tree
    TreeNode<int> *pNode = root->left; // Node with value 5
    TreeNode<int> *qNode = root->right; // Node with value 1
    TreeNode<int> *lcaNode = lowestCommonAncestor(root, pNode, qNode);
    cout << "Lowest Common Ancestor Node Value (BST): " << lcaNode->data << endl;

    // Deallocate memory (not shown in detail for simplicity)
    // ...

    return 0;
}
