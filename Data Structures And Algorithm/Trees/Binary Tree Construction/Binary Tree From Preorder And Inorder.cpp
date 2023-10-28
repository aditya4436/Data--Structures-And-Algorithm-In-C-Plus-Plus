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
void createMap(vector<int> &in, unordered_map<int, int> &map, int &n)
{
    for(int i=0;i<n;i++)
    {
        map[in[i]]=i;
    }
}
Node *Build_Tree(vector<int> &pre, vector<int> &in, int &index, int inStart, int inEnd, int &n, unordered_map<int, int> &map)
{
    if(index>=n || inStart>inEnd)
    {
        return nullptr;
    }
    int element=pre[index++];
    Node *root=new Node(element);
    int pos=map[element];
    root->left=Build_Tree(pre, in, index, inStart, pos-1, n, map);
    root->right=Build_Tree(pre, in, index, pos+1, inEnd, n, map);
    return root;
}
Node *Construct(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex=0;
    int n=preorder.size();
    unordered_map<int, int>mapping;
    createMap(inorder, mapping, n);
    return Build_Tree(preorder, inorder, preIndex, 0, n-1, n, mapping);
}
int main()
{
    vector<int> inorder={4, 2, 1, 7, 5, 8, 3, 6};
    vector<int> preorder={1, 2, 4, 3, 5, 7, 8, 6};
    Node *root=Construct(preorder, inorder);
    cout<<"Inorder Traversal:\n";
    Inorder_Traversal(root);
    cout<<"\nPostorder Traversal:\n";
    Postorder_Traversal(root);
    cout<<"\nPreorder Traversal:\n";
    Preorder_Traversal(root);
    return 0;
}
