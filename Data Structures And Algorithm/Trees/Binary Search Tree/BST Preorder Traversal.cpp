#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *getNode(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node *Insert(struct Node *root, int data)
{
    if(root==NULL)
    {
        return getNode(data);
    }
    else if(root->data>data)
    {
        root->left=Insert(root->left, data);
    }
    else if(root->data<data)
    {
        root->right=Insert(root->right, data);
    }
    return root;
}
void Preorder_Traversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<"  ";
        Preorder_Traversal(root->left);
        Preorder_Traversal(root->right);
    }
}

// Iterative Preorder Traversal.
// vector<int> preorderTraversal(TreeNode* root)
// {
//     vector<int> ans;
//     if(root==NULL){
//         return ans;
//     }
//     stack<TreeNode*> st;
//     st.push(root);
//     while(!st.empty()){
//         TreeNode *node=st.top();
//         st.pop();
//         ans.push_back(node->val);
//         if(node->right){
//             st.push(node->right);
//         }
//         if(node->left){
//             st.push(node->left);
//         }
//     }
//     return ans;
// }
int main()
{
    struct Node *root=NULL;
    root=Insert(root, 100);
    root=Insert(root, 50);
    root=Insert(root, 200);
    root=Insert(root, 10);
    root=Insert(root, 60);
    root=Insert(root, 150);
    root=Insert(root, 300);
    cout<<"\nPreorder Traversal of BST:\n";
    Preorder_Traversal(root);
    return 0;
}

