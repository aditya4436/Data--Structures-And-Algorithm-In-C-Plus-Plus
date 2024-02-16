#include <bits/stdc++.h>

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode()
    {
        if (left != nullptr)
        {
            delete left;
        }
        if (right != nullptr)
        {
            delete right;
        }
    }
};

int rightHeight(TreeNode<int> *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}

int leftHeight(TreeNode<int> *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}
// Time Complexity:- If we have a complete binary tree, where the height 'h' is O(log N), 
//                   then the time complexity would be O(log N) for traversing each side 
//                   (left and right) of the tree, leading to an overall time complexity 
//                   of O(log N). But if the tree is not a complete binary
// Space Complexity:- It's important to note that in a complete binary tree, the height 'h'
//                    is O(log N), where N is the number of nodes.
int countNodes(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }

    int lh = leftHeight(root->left);
    int rh = rightHeight(root->right);

    if (lh == rh)
    {
        return (2 << lh) - 1;
    }
    else
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main()
{
    // Create your binary tree and call countNodes function here
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Call countNodes function
    int result = countNodes(root);

    std::cout << "Total number of nodes in the binary tree: " << result << std::endl;

    // Don't forget to free the memory allocated for the binary tree
    // You can write a separate function for that

    return 0;
}
