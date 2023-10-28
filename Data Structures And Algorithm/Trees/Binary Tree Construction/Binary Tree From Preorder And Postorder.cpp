#include<iostream>
#include<vector>
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
int search(vector<int> &Postorder, int start, int end, int element)
{
    for(int i=start;i<=end;i++)
    {
        if(Postorder[i]==element)
        {
            return i;
        }
    }
    return -1;
}
int preIndex=0;
Node *Build_Tree(vector<int> &pre, vector<int> &post, int start, int end)
{
    if(start>end||preIndex>=pre.size())
    {
        return NULL;
    }
    Node *newNode=new Node(pre[preIndex++]);
    if(start==end)
    {
        return newNode;
    }
    int pos=search(post, start, end, pre[preIndex]);
    newNode->left=Build_Tree(pre, post, start, pos);
    newNode->right=Build_Tree(pre, post, pos+1, end-1);
    return newNode;
}
Node *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n=preorder.size();
    return Build_Tree(preorder, postorder, 0, n-1);
}
void printInorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printInorder(root->left);
        cout<<root->data<<"  ";
        printInorder(root->right);
    }
}

int main()
{
    vector<int> pre={1, 2, 4, 8, 9, 5, 3, 6, 7};
    vector<int> post={8, 9, 4, 5, 2, 6, 7, 3, 1};
    int n=post.size();
    Node *root=constructFromPrePost(pre, post);
    cout<<"Inorder traversal of the constructed tree:\n";
    printInorder(root);
    return 0;
}
