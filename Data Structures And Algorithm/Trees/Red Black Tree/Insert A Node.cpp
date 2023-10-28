#include <iostream>
using namespace std;
struct Red_Black_Tree_Node
{
    int data;
    Red_Black_Tree_Node *parent_node;
    Red_Black_Tree_Node *left_node;
    Red_Black_Tree_Node *right_node;
    int color;
};
typedef Red_Black_Tree_Node *NodePtr;
class Red_Black_Tree
{
private:
    NodePtr root;
    NodePtr TNULL;
    // balance the tree after insertion
    void Fix_Violations_After_Insertion(NodePtr node)
    {
        NodePtr uncle_node;
        while (node->parent_node->color == 1)
        {
            if (node->parent_node == node->parent_node->parent_node->right_node)
            {
                uncle_node = node->parent_node->parent_node->left_node;
                if (uncle_node->color == 1)
                {
                    uncle_node->color = 0;
                    node->parent_node->color = 0;
                    node->parent_node->parent_node->color = 1;
                    node = node->parent_node->parent_node;
                }
                else
                {
                    if (node == node->parent_node->left_node)
                    {
                        node = node->parent_node;
                        Right_Rotation(node);
                    }
                    node->parent_node->color = 0;
                    node->parent_node->parent_node->color = 1;
                    Left_Rotation(node->parent_node->parent_node);
                }
            }
            else
            {
                uncle_node = node->parent_node->parent_node->right_node;

                if (uncle_node->color == 1)
                {
                    uncle_node->color = 0;
                    node->parent_node->color = 0;
                    node->parent_node->parent_node->color = 1;
                    node = node->parent_node->parent_node;
                }
                else
                {
                    if (node == node->parent_node->right_node)
                    {
                        node = node->parent_node;
                        Left_Rotation(node);
                    }
                    node->parent_node->color = 0;
                    node->parent_node->parent_node->color = 1;
                    Right_Rotation(node->parent_node->parent_node);
                }
            }
            if (node == root)
            {
                break;
            }
        }
        root->color = 0;
    }

    void Preorder_Traversal(NodePtr root, string indent, bool last)
    {
        if (root != TNULL)
        {
        cout << indent;
        if (last)
        {
            cout << "R-----";
            indent += "    ";
            }
            else
            {
                cout << "L-----";
                indent += "|   ";
            }
            string sNodeColor = root->color ? "RED" : "BLACK";
            cout << root->data << "(" << sNodeColor << ")" << endl;
            Preorder_Traversal(root->left_node, indent, false);
            Preorder_Traversal(root->right_node, indent, true);
        }
    }
public:
    Red_Black_Tree()
    {
        TNULL = new Red_Black_Tree_Node;
        TNULL->color = 0;
        TNULL->left_node = nullptr;
        TNULL->right_node = nullptr;
        root = TNULL;
    }
    void Left_Rotation(NodePtr temp)
    {
        NodePtr temp_right_child = temp->right_node;
        temp->right_node = temp_right_child->left_node;
        if (temp_right_child->left_node != TNULL)
        {
            temp_right_child->left_node->parent_node = temp;
        }
        temp_right_child->parent_node = temp->parent_node;
        if (temp->parent_node == nullptr)
        {
            this->root = temp_right_child;
        }
        else if (temp == temp->parent_node->left_node)
        {
            temp->parent_node->left_node = temp_right_child;
        }
        else
        {
            temp->parent_node->right_node = temp_right_child;
        }
        temp_right_child->left_node = temp;
        temp->parent_node = temp_right_child;
    }
    void Right_Rotation(NodePtr temp)
    {
        NodePtr temp_left_child = temp->left_node;
        temp->left_node = temp_left_child->right_node;
        if (temp_left_child->right_node != TNULL)
        {
            temp_left_child->right_node->parent_node = temp;
        }
        temp_left_child->parent_node = temp->parent_node;
        if (temp->parent_node == nullptr)
        {
            this->root = temp_left_child;
        }
        else if (temp == temp->parent_node->right_node)
        {
            temp->parent_node->right_node = temp_left_child;
        }
        else
        {
            temp->parent_node->left_node = temp_left_child;
        }
        temp_left_child->right_node = temp;
        temp->parent_node = temp_left_child;
    }
  // Inserting a node
    void Insert_A_Node_In_RBTree(int key)
    {
        NodePtr newNode = new Red_Black_Tree_Node;
        newNode->parent_node = nullptr;
        newNode->data = key;
        newNode->left_node = TNULL;
        newNode->right_node = TNULL;
        newNode->color = 1;
        NodePtr temp1 = nullptr;
        NodePtr temp = this->root;
        while (temp != TNULL)
        {
            temp1 = temp;
            if (newNode->data < temp->data)
            {
                temp = temp->left_node;
            }
            else
            {
                temp = temp->right_node;
            }
        }
        newNode->parent_node = temp1;
        if (temp1 == nullptr)
        {
            root = newNode;
        }
        else if (newNode->data < temp1->data)
        {
            temp1->left_node = newNode;
        }
        else
        {
            temp1->right_node = newNode;
        }
        if (newNode->parent_node == nullptr)
        {
            newNode->color = 0;
            return;
        }
        if (newNode->parent_node->parent_node == nullptr)
        {
            return;
        }
        Fix_Violations_After_Insertion(newNode);
    }
    void Print_Tree()
    {
        if (root)
        {
            Preorder_Traversal(this->root, "", true);
        }
    }
};
int main()
{
    Red_Black_Tree RBTree;
    RBTree.Insert_A_Node_In_RBTree(10);
    RBTree.Insert_A_Node_In_RBTree(18);
    RBTree.Insert_A_Node_In_RBTree(7);
    RBTree.Insert_A_Node_In_RBTree(15);
    RBTree.Insert_A_Node_In_RBTree(16);
    RBTree.Insert_A_Node_In_RBTree(30);
    RBTree.Insert_A_Node_In_RBTree(25);
    RBTree.Insert_A_Node_In_RBTree(40);
    RBTree.Insert_A_Node_In_RBTree(60);
    RBTree.Insert_A_Node_In_RBTree(2);
    RBTree.Insert_A_Node_In_RBTree(1);
    RBTree.Insert_A_Node_In_RBTree(70);
    /*RBTree.Insert_A_Node_In_RBTree(51);
    RBTree.Insert_A_Node_In_RBTree(44);
    RBTree.Insert_A_Node_In_RBTree(62);
    RBTree.Insert_A_Node_In_RBTree(34);
    RBTree.Insert_A_Node_In_RBTree(85);
    RBTree.Insert_A_Node_In_RBTree(54);*/
    RBTree.Print_Tree();
    return 0;
}

