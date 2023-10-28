/*In this program I have used Bottom Up Splaying*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return (temp);
}
Node *Right_Rotation(Node *temp)
{
    Node *temp_left_child=temp->left;
    temp->left=temp_left_child->right;
    temp_left_child->right=temp;
    return temp_left_child;
}
Node *Left_Rotation(Node *temp)
{
    Node *temp_right_child=temp->right;
    temp->right=temp_right_child->left;
    temp_right_child->left=temp;
    return temp_right_child;
}
Node *Splay_The_Tree(Node *root, int data)
{
    if(root==NULL||root->data==data)
    {
        return root;
    }
    if(root->data>data)
    {
        if(root->left==NULL)
        {
            return root;
        }
        if(root->left->data>data)
        {
            root->left->left=Splay_The_Tree(root->left->left, data);
            root=Right_Rotation(root);
        }
        else if(root->left->data<data)
        {
            root->left->right=Splay_The_Tree(root->left->right, data);
            if(root->left->right!=NULL)
            {
                root->left=Left_Rotation(root->left);
            }
        }
        return (root->left==NULL)?root:Right_Rotation(root);
    }
    else
    {
        if(root->right==NULL)
        {
            return root;
        }
        if(root->right->data>data)
        {
            root->right->left=Splay_The_Tree(root->right->left, data);
            if(root->right->left!=NULL)
            {
                root->right=Right_Rotation(root->right);
            }
        }
        else if(root->right->data<data)
        {
            root->right->right=Splay_The_Tree(root->right->right, data);
            root=Left_Rotation(root);
        }
        return(root->right==NULL)?root:Left_Rotation(root);
    }
}
Node *Insert_A_Node_In_Splay_Tree(Node *root, int data)
{
    Node *newNode= new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    if(root==NULL)
    {
        return newNode;
    }
    if(root->data>data)
    {
        root->left=Insert_A_Node_In_Splay_Tree(root->left, data);
    }
    else if(root->data<data)
    {
        root->right=Insert_A_Node_In_Splay_Tree(root->right, data);
    }
    root=Splay_The_Tree(root, data);
    return root;
}
void Preorder_Traversal(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"  ";
        Preorder_Traversal(root->left);
        Preorder_Traversal(root->right);
    }
}
/* We can implement this logic also to perform deletion in Splay Tree
Node *Delete(Node *root, int data)
{
    Node *temp;
    if(!root)
    {
        return NULL;
    }
    root=Splay_The_Tree(root, data);
    if(data!=root->data)
    {
        return root;
    }
    if(!root->left)
    {
        temp=root;
        root=root->right;
    }
    else
    {
        temp=root;
        root=Splay_The_Tree(root->left, data);
        root->right=temp->right;
    }
    free(temp);
    return root;
}*/
int getRightMin(Node *root)
{
    /// The first inorder successor of the root node is always the left node
    struct Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
Node *Delete(struct Node *root, int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data<data)
    {
        root->right=Delete(root->right, data);
    }
    else if(root->data>data)
    {
        root->left=Delete(root->left, data);
    }
    else
    {
        if(root->left==NULL &&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else
        {
            int rightMin=getRightMin(root->right);
            root->data=rightMin;
            root->right=Delete(root->right, rightMin);
        }
    }
    root=Splay_The_Tree(root, data);
    return root;
}
int main()
{
    Node *root=newNode(6);
    root->left=newNode(1);
    root->right=newNode(9);
    root->left->right=newNode(4);
    root->left->right->left=newNode(2);
    root->right->left=newNode(7);
    int key=4;
    cout<<"Splay Tree before deletion:\n";
    Preorder_Traversal(root);
    cout<<endl;
    root=Delete(root, key);
    cout<<"Splay Tree after deletion:\n";
    Preorder_Traversal(root);
    return 0;
}

