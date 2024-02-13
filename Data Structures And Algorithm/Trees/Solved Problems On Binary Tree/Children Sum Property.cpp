#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Time Complexity:- O(n), because we are traversing the entire node
//                   in the tree.
// Space Complexity:- O(H), where H is the height of the tree (recursive stack space).
void changeTree(BinaryTreeNode<int> *root) {
    if(!root){
        return;
    }
    int childSum=0;
    if(root->left){
        childSum+=root->left->data;
    }
    if(root->right){
        childSum+=root->right->data;
    }
    if(childSum>=root->data){
        root->data=childSum;
    }
    else{
        if(root->left){
            root->left->data=root->data;
        }
        else if(root->right){
            root->right->data=root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    if(root->left){
        total+=root->left->data;
    }
    if(root->right){
        total+=root->right->data;
    }
    if(root->left || root->right){
        root->data=total;
    }
}

// Function to print the inorder traversal of the binary tree
void inorder(BinaryTreeNode<int> *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    // Example usage:
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(2);
    root->left = new BinaryTreeNode<int>(35);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(3);

    root->right = new BinaryTreeNode<int>(10);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(2);

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    changeTree(root);

    cout << "Modified Tree (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
