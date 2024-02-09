#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
bool IsLeaf(TreeNode *root){
    return  !root->left && !root->right;
}

// Time Complexity:- O(H)+O(H)=O(n), one O(H), to put the elements of left boundary
//                   and another O(H) to put the elements of right boundary.
// Space Complexity:- O(n)
void LeftBoundary(TreeNode *root, vector<int> &res){
    TreeNode *cur=root->left;
    while(cur){
        if(!IsLeaf(cur)){
            res.push_back(cur->data);
        }
        if(cur->left){
            cur=cur->left;
        }
        else{
            cur=cur->right;
        }
    }
}
void RightBoundary(TreeNode *root, vector<int> &res){
    TreeNode *cur=root->right;
    vector<int> temp;
    while(cur){
        if(!IsLeaf(cur)){
            temp.push_back(cur->data);
        }
        if(cur->left){
            cur=cur->right;
        }
        else{
            cur=cur->left;
        }
    }
    for(int i=temp.size()-1; i>=0; i--){
        res.push_back(temp[i]);
    }
}

void AddLeaves(TreeNode *root, vector<int> &res){
    if(IsLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left){
        AddLeaves(root->left, res);
    }
    if(root->right){
        AddLeaves(root->right, res);
    }
}
int main(){
    TreeNode *root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(18);
    root->right->right=new TreeNode(25);
    vector<int> res;
    if(!root){
        return 0;
    }
    if(!IsLeaf(root)){
        res.push_back(root->data);
    }
    LeftBoundary(root, res);
    AddLeaves(root, res);
    RightBoundary(root, res);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<"  ";
    }
    return 0;
}
