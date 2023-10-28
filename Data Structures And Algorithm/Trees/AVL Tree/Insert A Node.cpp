#include<iostream>
using namespace std;
struct AVL_Tree_Node
{
    int data, height;
    AVL_Tree_Node *left, *right;
};
int Maximum_Height_Of_The_Tree(int a, int b)
{
    return (a>b)?a:b;
}
int Height_Of_The_Subtree(AVL_Tree_Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;
}
int Get_Balance(AVL_Tree_Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return Height_Of_The_Subtree(root->left)-Height_Of_The_Subtree(root->right);
}
AVL_Tree_Node *Left_Rotation(AVL_Tree_Node *root)
{
    AVL_Tree_Node *temp=root->right;
    AVL_Tree_Node *T2=temp->left;
    temp->left=root;
    root->right=T2;
    root->height=Maximum_Height_Of_The_Tree(Height_Of_The_Subtree(root->left), Height_Of_The_Subtree(root->right)) + 1;
    temp->height=Maximum_Height_Of_The_Tree(Height_Of_The_Subtree(temp->left), Height_Of_The_Subtree(temp->right)) + 1;
    return temp;
}
AVL_Tree_Node *Right_Rotation(AVL_Tree_Node *root)
{
    AVL_Tree_Node *temp=root->left;
    AVL_Tree_Node *T2=temp->right;
    temp->right=root;
    root->left=T2;
    root->height=Maximum_Height_Of_The_Tree(Height_Of_The_Subtree(root->left), Height_Of_The_Subtree(root->right)) + 1;
    temp->height=Maximum_Height_Of_The_Tree(Height_Of_The_Subtree(temp->left), Height_Of_The_Subtree(temp->right)) + 1;
    return temp;
}
AVL_Tree_Node *Insert_A_Node_In_AVL_Tree(AVL_Tree_Node *root, int data)
{
    AVL_Tree_Node *newNode=new AVL_Tree_Node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    if(root==NULL)
    {
        return newNode;
    }
    else if(data>root->data)
    {
        root->right=Insert_A_Node_In_AVL_Tree(root->right, data);
    }
    else if(data<root->data)
    {
        root->left=Insert_A_Node_In_AVL_Tree(root->left, data);
    }
    else
    {
        return root;
    }
    int balance=Get_Balance(root);
    root->height=1+Maximum_Height_Of_The_Tree(Height_Of_The_Subtree(root->left), Height_Of_The_Subtree(root->right));
    if(balance>1 && data<root->left->data)
    {
        return Right_Rotation(root);
    }
    else if(balance>1 && data>root->left->data)
    {
        root->left=Left_Rotation(root->left);
        return Right_Rotation(root);
    }
    else if(balance<-1 && data>root->right->data)
    {
        return Left_Rotation(root);
    }
    else if(balance<-1 && data<root->right->data)
    {
        root->right=Right_Rotation(root->right);
        return Left_Rotation(root);
    }
    return root;
}
int Get_Minimum(AVL_Tree_Node *root)
{
    AVL_Tree_Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
void Preorder_Traversal(AVL_Tree_Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"  ";
        Preorder_Traversal(root->left);
        Preorder_Traversal(root->right);
    }
}
int main()
{
    AVL_Tree_Node *root=NULL;
    root=Insert_A_Node_In_AVL_Tree(root, 10);
    root=Insert_A_Node_In_AVL_Tree(root, 20);
    root=Insert_A_Node_In_AVL_Tree(root, 30);
    root=Insert_A_Node_In_AVL_Tree(root, 40);
    root=Insert_A_Node_In_AVL_Tree(root, 50);
    root=Insert_A_Node_In_AVL_Tree(root, 25);
    cout<<"Preorder Traversal of AVL Tree:\n";
    Preorder_Traversal(root);
    return 0;
}
