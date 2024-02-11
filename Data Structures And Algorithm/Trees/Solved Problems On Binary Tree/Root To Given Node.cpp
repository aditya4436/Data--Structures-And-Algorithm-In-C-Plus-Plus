#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
// Time Complexity:- O(n), because we are visiting every node
//                   inthe tree.
// Space Complexity:- O(h), recursive stack space.
bool RootToNode(TreeNode *root, int &val, vector<int> &ans){
    if(!root){
        return false;
    }
    ans.push_back(root->data);
    if(root->data==val){
        return true;
    }
    if(root->left && RootToNode(root->left, val, ans)){
        return true;
    }
    if(root->right && RootToNode(root->right, val, ans)){
        return true;
    }
    ans.pop_back();
    return false;
}
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int targetValue = 7;
    vector<int> path;

    // Calling the function to find the path from root to the target value
    if (RootToNode(root, targetValue, path)) {
        cout << "Path to value " << targetValue << ": ";
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "Value " << targetValue << " not found in the tree." << endl;
    }

    // Deallocate memory (not shown in detail for simplicity)
    // ...

    return 0;
}
