#include <iostream>
#include <climits>

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

template <typename T>
int floorInBST(TreeNode<T>* root, T X) {
    // Time Complexity: O(h), where h is the height of the binary search tree.
    // In the worst case, the height of the tree is h=log(n) (for a balanced tree),
    // where n is the number of nodes. Thus, the time complexity is O(log(n)).

    // Space Complexity: O(1)
    // The space complexity is constant as we are using only a constant amount of extra space.

    // Write your code here.
    int ans=INT_MAX;
    while(root){
        if(root->val==X){
            ans=root->val;
            return ans;
        }
        if(X<root->val){
            root=root->left;
        }
        else{
            ans=root->val;
            root=root->right;
        }
    }
    return ans;
}

int main() {
    // Example usage:
    // Assuming you have a Binary Search Tree (BST) as follows:
    //          8
    //        /   \
    //       3    10
    //      / \     \
    //     1   6    14
    //        / \   /
    //       4   7  13

    TreeNode<int>* root = new TreeNode<int>(8);
    root->left = new TreeNode<int>(3);
    root->right = new TreeNode<int>(10);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(6);
    root->left->right->left = new TreeNode<int>(4);
    root->left->right->right = new TreeNode<int>(7);
    root->right->right = new TreeNode<int>(14);
    root->right->right->left = new TreeNode<int>(13);

    int X = 5;
    int floorValue = floorInBST(root, X);

    std::cout << "Floor of " << X << " is: " << floorValue << std::endl;
  
    return 0;
}
