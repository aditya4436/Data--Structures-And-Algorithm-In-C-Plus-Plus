/// Another way to construct BST from Postorder Traversal.
/// Time Complexity:- O(n), where 'n' is the number of nodes
/// Space Complexity:- O(h), where 'h' is the height of the tree.
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *Construct_BST_From_Postorder_Traversal(int Postorder[], int *pIndex, int data, int min, int max, int size)
{
    if(*pIndex<0)
    {
        return nullptr;
    }
    Node *root=nullptr;
    if(data>min && data<max)
    {
        Node *newNode=new Node;
        newNode->data=data;
        newNode->left=newNode->right=nullptr;
        root=newNode;
        *pIndex=*pIndex-1;
        if(*pIndex>=0)
        {
            root->right=Construct_BST_From_Postorder_Traversal(Postorder, pIndex, Postorder[*pIndex], data, max, size);
            root->left=Construct_BST_From_Postorder_Traversal(Postorder, pIndex, Postorder[*pIndex], min, data, size);
        }
    }
    return root;
}
void Inorder_Traversal(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        Inorder_Traversal(root->left);
        cout<<root->data<<"  ";
        Inorder_Traversal(root->right);
    }
}
void Preorder_Traversal(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        cout<<root->data<<"  ";
        Preorder_Traversal(root->left);
        Preorder_Traversal(root->right);
    }
}
void Postorder_Traversal(Node *root)
{
    if(root==NULL)
    {
        return ;
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
    Node *root=NULL;
    int Postorder[]={1, 7, 5, 50, 40, 10};
    int n=sizeof(Postorder)/sizeof(Postorder[0]);
    int pIndex=n-1;
    root=Construct_BST_From_Postorder_Traversal(Postorder, &pIndex, Postorder[pIndex], INT_MIN, INT_MAX, n);
    cout<<"Inorder Traversal of BST Constructed from Postorder Traversal:\n";
    Inorder_Traversal(root);
    cout<<"\nPreorder Traversal of BST Constructed from Postorder Traversal:\n";
    Preorder_Traversal(root);
    cout<<"\nPostorder Traversal of BST Constructed from Postorder Traversal:\n";
    Postorder_Traversal(root);
    return 0;
}

