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
    AVL_Tree_Node *newNode=new AVL_Tree_Node;
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
AVL_Tree_Node *Get_Minimum(AVL_Tree_Node *root)
{
    AVL_Tree_Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
AVL_Tree_Node *Delete_A_Node_From_AVL_Tree(AVL_Tree_Node *root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data<root->data)
    {
        root->left=Delete_A_Node_From_AVL_Tree(root->left, data);
    }
    else if(data>root->data)
    {
        root->right=Delete_A_Node_From_AVL_Tree(root->right, data);
    }
    else if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return nullptr;
    }
    else
    {
        if(root->left==NULL)
        {
            AVL_Tree_Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            AVL_Tree_Node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            AVL_Tree_Node *temp=root->right;
            free(temp);
            return temp;
        }
        else
        {
            AVL_Tree_Node *minimum_node_at_right_subtree=Get_Minimum(root->right);
            root->data=minimum_node_at_right_subtree->data;
            root->right=Delete_A_Node_From_AVL_Tree(root->right, minimum_node_at_right_subtree->data);
        }
    }
    int balance=Get_Balance(root);
    root->height=1+Maximum_Height_Of_The_Tree(Height_Of_The_Subtree(root->left), Height_Of_The_Subtree(root->right));
    if(balance>1 && Get_Balance(root->left)>=0)
    {
        return Right_Rotation(root);
    }
    else if(balance>1 && Get_Balance(root->left)<0)
    {
        root->left=Left_Rotation(root->left);
        return Right_Rotation(root);
    }
    else if(balance<-1 && Get_Balance(root->right)<=0)
    {
        return Left_Rotation(root);
    }
    else if(balance<-1 && Get_Balance(root->right)>0)
    {
        root->right=Right_Rotation(root->right);
        return Left_Rotation(root);
    }
    return root;
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
    root=Insert_A_Node_In_AVL_Tree(root, 9);
    root=Insert_A_Node_In_AVL_Tree(root, 5);
    root=Insert_A_Node_In_AVL_Tree(root, 10);
    root=Insert_A_Node_In_AVL_Tree(root, 0);
    root=Insert_A_Node_In_AVL_Tree(root, 6);
    root=Insert_A_Node_In_AVL_Tree(root, 11);
    root=Insert_A_Node_In_AVL_Tree(root, -1);
    root=Insert_A_Node_In_AVL_Tree(root, 1);
    root=Insert_A_Node_In_AVL_Tree(root, 2);
    cout<<"Preorder Traversal of AVL Tree:\n";
    Preorder_Traversal(root);
    root=Delete_A_Node_From_AVL_Tree(root, 10);
    cout<<endl;
    cout<<"Preorder Traversal of AVL Tree after Deletion:\n";
    Preorder_Traversal(root);
    return 0;
}
