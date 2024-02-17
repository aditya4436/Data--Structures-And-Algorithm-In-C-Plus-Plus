#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Time complexity:-
//      Serialization:- O(N) where N is the number of nodes in the tree.
//      Deserialization:- O(N) where N is the number of nodes in the tree.

// Space complexity:
//      Serialization: O(N) where N is the number of nodes in the tree (queue storage).
//      Deserialization: O(N) where N is the number of nodes in the tree (queue storage).
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (!root) {
            return str;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL) {
                str.append("#,");
            } else {
                str.append(to_string(node->val) + ',');
            }
            if (node != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#") {
                node->left = NULL;
            } else {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if (str == "#") {
                node->right = NULL;
            } else {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Codec codec;
    
    // Serialize the tree
    string serialized = codec.serialize(root);

    // Deserialize the string back to a tree
    TreeNode* deserialized = codec.deserialize(serialized);

    return 0;
}
