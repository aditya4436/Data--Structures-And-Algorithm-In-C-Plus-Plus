#include <bits/stdc++.h> 
struct Node{
    int key, value, count;
    Node *next, *prev;
    Node(int _key, int _value){
        key=_key;
        value=_value;
        count=1;
    }
};
struct List{
    int size;
    Node *head, *tail;
    List(){
        head=new Node(0, 0);
        tail=new Node(0, 0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void AddNode(Node *newNode){
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
        size++;
    }
    void RemoveNode(Node *deleteNode){
        Node *deletePrevious=deleteNode->prev;
        Node *deleteNext=deleteNode->next;
        deletePrevious->next=deleteNext;
        deleteNext->prev=deletePrevious;
        size--;
    }
};
// Get Operation (get method):- If the key is found in keyNode (constant time operation for map lookup),
//                              you need to perform updateFreqListMap operation, which involves erasing
//                              from a map, removing from a linked list, and adding to another linked list.
//                              In the worst case, these operations are O(log N), O(N), and O(N), respectively
//                              (assuming a balanced tree for the map and a doubly linked list for the linked list).
//                              Overall, the worst-case time complexity for get is O(log N + N).
// Put Operation (put method):- If the key is already present, you perform the same updateFreqListMap operation
//                              as in get. If the key is not present, you might need to remove the least frequently
//                              used element, which involves erasing from a map and removing from a linked list. In 
//                              the worst case, these operations are O(log N) and O(N), respectively. Overall, the
//                              worst-case time complexity for put is O(log N + N).
class LFUCache
{
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxSizeCache=capacity;
        minFreq=0;
        curSize=0;
    }
    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->count]->RemoveNode(node);
        if(node->count==minFreq && freqListMap[node->count]->size==0){
            minFreq++;
        }
        List *nextHigherFreqList=new List();
        if(freqListMap.find(node->count+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->count+1];
        }
        node->count+=1;
        nextHigherFreqList->AddNode(node);
        freqListMap[node->count]=nextHigherFreqList;
        keyNode[node->key]=node;
    }
    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key)!=keyNode.end()){
            Node *node=keyNode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxSizeCache==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end()){
            Node *node=keyNode[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else{
            if(curSize==maxSizeCache){
                List *list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->RemoveNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List *listFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            Node *node=new Node(key, value);
            listFreq->AddNode(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};
int main() {
    // Example usage:
    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl;  // returns 1
    cache.put(3, 3);                         // removes key 2
    std::cout << cache.get(2) << std::endl;  // returns -1 (not found)
    std::cout << cache.get(3) << std::endl;  // returns 3
    cache.put(4, 4);                         // removes key 1
    std::cout << cache.get(1) << std::endl;  // returns -1 (not found)
    std::cout << cache.get(3) << std::endl;  // returns 3
    std::cout << cache.get(4) << std::endl;  // returns 4

    return 0;
}
