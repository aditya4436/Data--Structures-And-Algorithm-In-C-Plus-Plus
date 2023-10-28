#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        data=data;
        left=NULL;
        right=NULL;
    }
};
Node *Construct_BST_From_Preorder_Traversal(vector<int> const &Preorder, int &preorder_index, int min, int max)
{
    if(preorder_index>=Preorder.size())
    {
        return nullptr;
    }
    int data=Preorder[preorder_index];
    if(data<min||data>max)
    {
        return nullptr;
    }
    Node *newNode=new Node(data);
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    preorder_index++;
    newNode->left=Construct_BST_From_Preorder_Traversal(Preorder, preorder_index, min, data-1);
    newNode->right=Construct_BST_From_Preorder_Traversal(Preorder, preorder_index, data+1, max);
    return newNode;
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
void Inorder_Traversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        Inorder_Traversal(root->left);
        cout<<root->data<<"  ";
        Inorder_Traversal(root->right);
    }
}
int main()
{
    vector<int> Preorder={10, 5, 1, 7, 40, 50};
    int preorder_index=0;
    Node *root=Construct_BST_From_Preorder_Traversal(Preorder, preorder_index, INT_MIN, INT_MAX);
    cout<<"Preorder Traversal of BST Constructed from Preorder Traversal:\n";
    Preorder_Traversal(root);
    cout<<endl;
    cout<<"Inorder Traversal of BST Constructed from Preorder Traversal:\n";
    Inorder_Traversal(root);
    return 0;
}
