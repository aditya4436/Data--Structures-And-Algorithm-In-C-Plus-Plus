/// Time complexity:- O(n log n), Because it finds the index of the node or element and in the worst case it may have to
                  /// traverse all the element in the Inorder array and the function is called for both root and left
                  /// recursively therefore recursive calls takes log n time therefore the time complexity is O(log n)
///Space Complexity:- O(n), Because it occupies space for each element.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data=data;
        this->left=this->right=nullptr;
    }
};
void Inorder_Traversal(Node *root)
{
    if(root!=nullptr)
    {
        Inorder_Traversal(root->left);
        cout<<root->data<<"  ";
        Inorder_Traversal(root->right);
    }
}
void Postorder_Traversal(Node *root)
{
    if(root!=nullptr)
    {
        Postorder_Traversal(root->left);
        Postorder_Traversal(root->right);
        cout<<root->data<<"  ";
    }
}
void Preorder_Traversal(Node *root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<"  ";
        Preorder_Traversal(root->left);
        Preorder_Traversal(root->right);
    }
}
Node *Build_Tree(vector<int> inorder, int inStart, int inEnd, vector<int> postorder, int postStart, int postEnd)
{
    if(inStart>inEnd)
    {
        return nullptr;
    }
    int rootVal=postorder[postEnd];
    Node *root=new Node(rootVal);
    int rootIndex=0;
    for(int i=inStart; i<=inEnd; i++)
    {
        if(inorder[i]==rootVal)
        {
            rootIndex=i;
            break;
        }
    }
    int leftSize=rootIndex-inStart;
    int rightSize=inEnd-rootIndex;
    root->left=Build_Tree(inorder, inStart, rootIndex-1, postorder, postStart, postStart+leftSize-1);
    root->right=Build_Tree(inorder, rootIndex+1, inEnd, postorder, postEnd-rightSize, postEnd-1);
    return root;
}
Node *Construct(vector<int> &inorder, vector<int> &postorder)
{
    return Build_Tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}
int main()
{
    vector<int> inorder={4, 2, 1, 7, 5, 8, 3, 6};
    vector<int> postorder={4, 2, 7, 8, 5, 6, 3, 1};
    Node *root=Construct(inorder, postorder);
    cout<<"Inorder Traversal:\n";
    Inorder_Traversal(root);
    cout<<"\nPostorder Traversal:\n";
    Postorder_Traversal(root);
    cout<<"\nPreorder Traversal:\n";
    Preorder_Traversal(root);
    return 0;
}
