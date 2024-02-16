#include<bits/stdc++.h>

using namespace std;

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* markParent(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &make_parent, int &start) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res = nullptr;
    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if (node->data == start) {
            res = node;
        }
        if (node->left) {
            make_parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            make_parent[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
// Time Complexity:- O(n)+O(n), the fist O(n) to mark the parent of each node,
//                   another O(n) t find the maximum time to burn the tree.
//                   The overall time complexity is O(n). Assuming the map works
//                   at O(1), if the map takes logn time then the overall time complexity
//                   will be O(nlogn)
// Space Complexity:- O(n)+O(n), the first O(n) to for the queue and another O(n)
//                    because we are using a hashmap.
//                    The overall space complexity is O(n).
int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &make_parent, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    map<BinaryTreeNode<int>*, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty()) {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if (node->left && !vis[node->left]) {
                flag = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right]) {
                flag = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (make_parent[node] && !vis[make_parent[node]]) {
                flag = 1;
                vis[make_parent[node]] = 1;
                q.push(make_parent[node]);
            }
        }
        if (flag) {
            maxi++;
        }
    }
    return maxi;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> make_parent;
    BinaryTreeNode<int>* target = markParent(root, make_parent, start);
    int maxi = findMaxDistance(make_parent, target);
    return maxi;
}

int main() {
    int main() {
    // Create a sample binary tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    int startNode = 5; // Node from where burning starts

    // Call the timeToBurnTree function
    int result = timeToBurnTree(root, startNode);

    cout << "Time to burn the tree starting from node " << startNode << ": " << result << endl;

    // Don't forget to free the memory allocated for the binary tree
    // You can write a separate function for that

    return 0;
}

    return 0;
}
