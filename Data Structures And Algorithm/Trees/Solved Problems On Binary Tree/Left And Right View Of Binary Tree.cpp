#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity:- O(n), because each node is visited once.
// Space Complexity:- O(h), where 'h' is the maximum height.
// Right View
void RightView(BinaryTreeNode<int>* root, int level, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    if(root->right){
        RightView(root->right, level + 1, ans);
    }
    if(root->left){
        RightView(root->left, level + 1, ans);
    }
}

// Function to get the right view of the binary tree
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    int level = 0;
    RightView(root, level, ans);
    return ans;
}

// Left View
void LeftView(BinaryTreeNode<int> *root, int level, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    if(root->left){
        LeftView(root->left, level + 1, ans);
    }
    if(root->right){
        LeftView(root->right, level + 1, ans);
    }
}

// Function to get the left view of the binary tree
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    int level = 0;
    LeftView(root, level, ans);
    return ans;
}

int main() {
    // Construct a sample binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    // Get the left and right views
    vector<int> leftViewResult = printLeftView(root);
    vector<int> rightViewResult = printRightView(root);

    // Display the results
    cout << "Left View: ";
    for (int val : leftViewResult) {
        cout << val << " ";
    }

    cout << "\nRight View: ";
    for (int val : rightViewResult) {
        cout << val << " ";
    }

    return 0;
}
