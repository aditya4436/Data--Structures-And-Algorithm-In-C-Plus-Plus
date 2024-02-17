#include <bits/stdc++.h>
using namespace std;

/************************************************************
   
   Following is the TreeNode class structure
   
   template <typename T>
   class TreeNode 
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
 ************************************************************/

// Function to construct binary tree from postorder and inorder traversals
// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(N), for the map and recursive call stack
template <typename T>
TreeNode<T> *ConstructBinaryTree(vector<T> &postOrder, int postStart, int postEnd, vector<T> &inOrder, int inStart, int inEnd, map<T, int> &inMap) {
     if (postStart > postEnd || inStart > inEnd) {
          return NULL;
     }
     TreeNode<T> *root = new TreeNode<T>(postOrder[postEnd]);
     int rootIndex = inMap[postOrder[postEnd]];
     int leftSize = rootIndex - inStart;
     int rightSize = inEnd - rootIndex;
     root->left = ConstructBinaryTree(postOrder, postStart, postStart + leftSize - 1, inOrder, inStart, rootIndex - 1, inMap);
     root->right = ConstructBinaryTree(postOrder, postStart + leftSize, postEnd - 1, inOrder, rootIndex + 1, inEnd, inMap);
     return root;
}

// Function to get the binary tree from postorder and inorder traversals
// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(N), for the map and recursive call stack
template <typename T>
TreeNode<T> *getTreeFromPostorderAndInorder(vector<T> &postOrder, vector<T> &inOrder) {
     if (postOrder.size() != inOrder.size() || postOrder.empty() || inOrder.empty()) {
          return NULL; // Invalid input
     }
     
     int n = postOrder.size();
     map<T, int> inMap;
     for (int i = 0; i < n; i++) {
          inMap[inOrder[i]] = i;
     }
     return ConstructBinaryTree(postOrder, 0, n - 1, inOrder, 0, n - 1, inMap);
}

// Function for inorder traversal
// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(H), where H is the height of the tree (call stack space)
template <typename T>
void inorderTraversal(TreeNode<T> *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Example usage
    vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1};
    vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};

    // Construct the binary tree
    TreeNode<int> *root = getTreeFromPostorderAndInorder(postOrder, inOrder);

    // Inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
