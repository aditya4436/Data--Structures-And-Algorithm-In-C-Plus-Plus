#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
struct Node *root=NULL;
struct Node *Create()
{
    int data;
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    cout<<"Enter the data (Enter -1 if you don't want to insert a node):\n";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    newNode->data=data;
    cout<<"Enter the left child:\n"<<data<<endl;
    newNode->left=Create();
    cout<<"Enter the right child:\n"<<data<<endl;
    newNode->right=Create();
    return newNode;
}
void Preorder_Traversal(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"  ";
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}
void Inorder_Traversal(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder_Traversal(root->left);
    cout<<root->data<<"  ";
    Inorder_Traversal(root->right);
}
void Postorder_Traversal(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder_Traversal(root->left);
    Postorder_Traversal(root->right);
    cout<<root->data<<"  ";
}
int main()
{
    root=Create();
    Preorder_Traversal(root);
    cout<<endl;
    Inorder_Traversal(root);
    cout<<endl;
    Postorder_Traversal(root);
    return 0;
}
