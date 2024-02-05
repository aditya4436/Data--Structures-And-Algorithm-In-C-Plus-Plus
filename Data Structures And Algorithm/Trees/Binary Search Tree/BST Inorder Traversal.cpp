#include<iostream>
using namespace std;
struct BST
{
    int data;
    BST *left;
    BST *right;
};
struct BST *root=NULL;
BST *Insert_A_Node_In_BST(struct BST *root, int data_to_be_inserted)
{
    struct BST *newNode=new BST;
    newNode->data=data_to_be_inserted;
    newNode->left=NULL;
    newNode->right=NULL;
    if(root==NULL)
    {
        return newNode;
    }
    else if(root->data<data_to_be_inserted)
    {
        root->right=Insert_A_Node_In_BST(root->right, data_to_be_inserted);
    }
    else if(root->data>data_to_be_inserted)
    {
        root->left=Insert_A_Node_In_BST(root->left, data_to_be_inserted);
    }
    return root;
}
void Inorder_Traversal_Of_BST(struct BST *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
         Inorder_Traversal_Of_BST(root->left);
         cout<<root->data<<"  ";
         Inorder_Traversal_Of_BST(root->right);
    }
}

// Iterative Approach
// vector<int> getInOrderTraversal(TreeNode *root)
// {
//     // Write your code here.
//     vector<int> ans;
//     if(root==NULL){
//         return ans;
//     }
//     stack<TreeNode*> st;
//     TreeNode *node=root;
//     while(true){
//         if(node!=NULL){
//             st.push(node);
//             node=node->left;
//         }
//         else{
//             if(st.empty()==true){
//                 break;
//             }
//             node=st.top();
//             st.pop();
//             ans.push_back(node->data);
//             node=node->right;
//         }
//     }
//     return ans;
// }
int main()
{
    root=Insert_A_Node_In_BST(root, 50);
    root=Insert_A_Node_In_BST(root, 30);
    root=Insert_A_Node_In_BST(root, 70);
    root=Insert_A_Node_In_BST(root, 60);
    root=Insert_A_Node_In_BST(root, 10);
    root=Insert_A_Node_In_BST(root, 90);
    cout<<"Binary Search Tree after Insertion:\n";
    Inorder_Traversal_Of_BST(root);
    return 0;
}
