#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
/*struct Node *newNode(int key)
{
    Node *node=new Node;
    node->data=key;
    node->left=node->right=NULL;
    return node;
}*/
Node *ConstructBST(int Postorder[], int start, int end)
{
    if(start>end)
    {
        return nullptr;
    }
    struct Node *newNode=new Node(Postorder[end]);
    int i;
    for(i=end;i>=start;i--)
    {
        if(Postorder[i]<newNode->data)
        {
            break;
        }
    }
    newNode->right=ConstructBST(Postorder, i+1, end-1);
    newNode->left=ConstructBST(Postorder, start, i);
    return newNode;
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
int main()
{
    Node *root=NULL;
    int Postorder[]={1, 7, 5, 50, 40, 10};
    int n=sizeof(Postorder)/sizeof(Postorder[0]);
    cout<<"Inorder Traversal of BST is:\n";
    root=ConstructBST(Postorder, 0, n-1);
    Inorder_Traversal(root);
    return 0;
}
