#include <bits/stdc++.h> 
using namespace std;

// Binary Tree node structure
template<typename T>
class BinaryTreeNode {
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// Iterator for Binary Search Tree
template<typename T>
class BSTIterator {
    stack<BinaryTreeNode<T>*> st;
    bool reverse;
    
    // Helper function to push all left or right nodes onto the stack
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h), where h is the height of the tree (stack space for recursion)
    void pushAll(BinaryTreeNode<T>* root) {
        while (root) {
            st.push(root);
            if (reverse == true) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

public:
    BSTIterator(BinaryTreeNode<T>* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    // Get the next element in the BST
    // Time Complexity: O(1) amortized (amortized because pushAll might be called occasionally)
    // Space Complexity: O(h), where h is the height of the tree (stack space for pushAll)
    T next() {
        BinaryTreeNode<T>* node = st.top();
        st.pop();
        if (!reverse) {
            pushAll(node->right);
        } else {
            pushAll(node->left);
        }
        return node->data;
    }
    
    // Check if there are more elements to iterate
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool hasNext() {
        return !st.empty();
    }
};

// Function to check if there exist two elements in the BST that sum up to k
// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(h), where h is the height of the tree (space used by iterators)
template<typename T>
bool twoSumInBST(BinaryTreeNode<T>* root, int k) {
    if (!root) {
        return false;
    }
    BSTIterator<T> l(root, false);
    BSTIterator<T> r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j) {
        if (i + j == k) {
            return true;
        } else if (i + j > k) {
            j = r.next();
        } else {
            i = l.next();
        }
    }
    return false;
}

// Example usage
int main() {
    // Construct a sample binary search tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(8);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(9);

    int targetSum = 11;

    // Check if there exist two elements in the BST that sum up to the targetSum
    bool result = twoSumInBST(root, targetSum);

    cout << "Existence of two elements with sum " << targetSum << " in BST: " << (result ? "true" : "false") << endl;

    return 0;
}
