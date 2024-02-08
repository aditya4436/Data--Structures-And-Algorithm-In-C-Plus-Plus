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
// Time Complexity:- O(n), n is the number of nodes.
// Space Complexity:- O(n), because we are using extra
//                    space to store element at each level.
// Store the elements in matrix order.
// vector<vector<int>> ZigZagLevelOrderTraversal(struct TreeNode *root){
//     vector<vector<int>> ans;
//     if(root==NULL){
//         return ans;
//     }
//     queue<TreeNode*> q;
//     q.push(root);
//     bool leftToRight=true;
//     while(!q.empty()){
//         int size=q.size();
//         vector<int> row(size);
//         for(int i=0; i<size; i++){
//             TreeNode *node=q.front();
//             q.pop();
//             int index=leftToRight ? i : size-1-i;
//             row[index]=node->data;
//             if(node->left){
//                 q.push(node->left);
//             }
//             if(node->right){
//                 q.push(node->right);
//             }
//         }
//         ans.push_back(row);
//         leftToRight=!leftToRight;
//     }
//     return ans;
// }

// Store the elements in a single array or list.
// Time Complexity:- O(n), n is the number of nodes.
// Space Complexity:- O(n), because we are using extra
//                    space to store element at each level.
vector<int> ZigZagLevelOrderTraversal(struct TreeNode *root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            TreeNode *node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        if(!leftToRight){
            reverse(level.begin(), level.end());
        }
        ans.insert(ans.end(), level.begin(), level.end());
        leftToRight=!leftToRight;
    }
    return ans;
}
int main(){
        // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Call the zigzagLevelOrder function
    // To print in matrix order.
    // vector<vector<int>> result = ZigZagLevelOrderTraversal(root);
    // cout << "Zigzag Level Order Traversal:\n";
    // for (const auto& row : result) {
    //     for (int val : row) {
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }

    // For single array or list.
    vector<int> result = ZigZagLevelOrderTraversal(root);
    cout << "Zigzag Level Order Traversal:\n";
    for(auto &it : result){
        cout<<it<<"  ";
    }
    return 0;
}
