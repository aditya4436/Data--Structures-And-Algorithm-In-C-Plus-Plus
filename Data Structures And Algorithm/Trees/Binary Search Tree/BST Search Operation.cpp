#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
struct Node *root=NULL;
Node *Insert(Node *root, int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    if(root==NULL)
    {
        return newNode;
    }
    if(data>root->data)
    {
        root->right=Insert(root->right, data);
    }
    if(data<root->data)
    {
        root->left=Insert(root->left, data);
    }
    return root;
}
void InorderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        InorderTraversal(root->left);
        cout<<root->data<<"  ";
        InorderTraversal(root->right);
    }
}
Node *search(Node *root, int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        return root;
    }
    if(root->data<data)
    {
        return search(root->right, data);
    }
    if(root->data>data)
    {
        return search(root->left, data);
    }
    return root;
}
int main()
{
    root=Insert(root, 50);
    root=Insert(root, 30);
    root=Insert(root, 70);
    root=Insert(root, 60);
    root=Insert(root, 10);
    root=Insert(root, 90);
    int data=40;
    cout<<"BST after Insertion\n";
    InorderTraversal(root);
    cout<<endl;
    if(search(root, data)==NULL)
    {
        cout<<data;
        cout<<" does not exist.";
    }
    else
    {
        cout<<data;
        cout<<" exist";
    }
    return 0;
}

