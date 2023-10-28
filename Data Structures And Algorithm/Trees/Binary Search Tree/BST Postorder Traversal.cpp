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
void Postorder_Traversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        Postorder_Traversal(root->left);
        Postorder_Traversal(root->right);
        cout<<root->data<<"  ";
    }
}
int main()
{
    struct Node *root=NULL;
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 30);
    root=Insert(root, 15);
    root=Insert(root, 5);
    root=Insert(root, 1);
    cout<<"\nPostorder Traversal of BST:\n";
    Postorder_Traversal(root);
    return 0;
}

