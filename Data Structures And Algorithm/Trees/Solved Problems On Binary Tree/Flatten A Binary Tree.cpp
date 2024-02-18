#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time Complexity:- O(n), because we are visiting every node.
// Space Complexity: O(1), because we are not using any extra space.
// void flatten(TreeNode* root) {
//     TreeNode *current=root;
//     while(current){
//         if(current->left){
//             TreeNode *predecessor=current->left;
//             while(predecessor->right){
//                 predecessor=predecessor->right;
//             }
//             predecessor->right=current->right;
//             current->right=current->left;
//             current->left=NULL;
//         }
//         current=current->right;
//     }

/*
Time Complexity: O(n) - Visit each node once in the binary tree
Space Complexity: O(h) - Space used by the recursive call stack,
                         where h is the height of the binary tree.
                         In the worst case space complexity may
                         go upto O(n)
*/
// void flattenBinaryTree(TreeNode<int>* root){
//     stack<TreeNode<int>*>st;
//     st.push(root);
//     while(!st.empty()){
//         TreeNode<int> *current=st.top();
//         st.pop();
//         if(current->right){
//             st.push(current->right);
//         }
//         if(current->left){
//             st.push(current->left);
//         }
//         if(!st.empty()){
//             current->right=st.top();
//         }
//         current->left=NULL;
//     }
// }
/*
Time Complexity: O(n) - Visit each node once in the binary tree
Space Complexity: O(h) - Space used by the recursive call stack,
                         where h is the height of the binary tree.
                         In the worst case space complexity may
                         go upto O(n)
*/
// Helper function to flatten the binary tree
void flattenBinaryTree(TreeNode* root, TreeNode*& previous) {
    if (!root) {
        return;
    }
    flattenBinaryTree(root->right, previous);
    flattenBinaryTree(root->left, previous);

    root->right = previous;
    root->left = NULL;
    previous = root;
}

// Main function to initiate the flattening process
void flatten(TreeNode* root) {
    TreeNode* previous = NULL;
    flattenBinaryTree(root, previous);
}

// Utility function to print the flattened linked list
void printFlattenedList(TreeNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    // Print the flattened linked list
    cout << "Flattened Linked List: ";
    printFlattenedList(root);

    return 0;
}
