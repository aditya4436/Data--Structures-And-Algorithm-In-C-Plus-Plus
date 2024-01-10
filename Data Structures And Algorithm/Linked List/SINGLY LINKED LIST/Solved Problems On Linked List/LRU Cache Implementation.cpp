#include <bits/stdc++.h>
class LRUCache
{
public:
    class Node
    {
    public:
        int value, key;
        Node *prev, *next;
        Node(int key_, int val_)
        {
            value = val_;
            key = key_;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    std::unordered_map<int, Node *> m;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void AddNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void DeleteNode(Node *deleteNode)
    {
        Node *deletePrevious = deleteNode->prev;
        Node *deleteNext = deleteNode->next;
        deletePrevious->next = deleteNext;
        deleteNext->prev = deletePrevious;
    }
    // Time Complexity:- O(1), for get() and put() 
    // Space Complexity:- O(capacity), because we are using unordered map
    //                    to strore the pair of key and nodes.
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int res = resNode->value;
            m.erase(key);
            DeleteNode(resNode);
            AddNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *existingNode = m[key];
            m.erase(key);
            DeleteNode(existingNode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            DeleteNode(tail->prev);
        }
        AddNode(new Node(key, value));
        m[key] = head->next;
    }
};
int main()
{
    // Example usage of LRUCache
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // returns 1
    cache.put(3, 3);                          // removes key 2
    std::cout << cache.get(2) << std::endl; // returns -1 (not found)
    cache.put(4, 4);                          // removes key 1
    std::cout << cache.get(1) << std::endl; // returns -1 (not found)
    std::cout << cache.get(3) << std::endl; // returns 3
    std::cout << cache.get(4) << std::endl; // returns 4
    return 0;
}
