#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next, *random;
    Node(int data){
        this->data=data;
        next=NULL;
        random=NULL;
    }
};
// Time Complexity:- O(2n), because we are traversing the entire linked
//                   list to store the nodes in the hash map. Since we are
//                   using unordered_map the time complexity of unordered map
//                   is O(1).
// Space Complexity:- O(n)+O(n), O(n) to store the nodes in the map and another
//                    O(n) to store the cloned linked list.
// Node *CloneLinkedList(Node *head){
// 	unordered_map<Node*, Node*> mpp;
// 	Node *temp=head;
//     // First pass: Create a mapping of original nodes to their corresponding new nodes.
// 	while(temp!=NULL){
// 		Node *newNode=new Node(temp->data);
// 		mpp[temp]=newNode;
// 		temp=temp->next;
// 	}
//     // Second pass: Update next and random pointers of the new nodes.
// 	temp=head;
// 	while(temp){
// 		Node *copyNode=mpp[temp];
// 		copyNode->next=temp->next;
// 		copyNode->random=temp->random;
// 		temp=temp->next;
// 	}
// 	return mpp[head];
// }

// Time Complexity:- O(3n), O(n) to insert the copyNode in between
//                   to nodes, O(n) to update the random pointer of
//                   of the linked list, O(n) to update the next pointer
// Space Complexity:- O(n), to create new list.
struct Node* CloneLinkedList(Node* head) {
    Node *temp=head;
    while(temp!=NULL){
        Node *nextElement=temp->next;
        Node *copyNode=new Node(temp->data);
        copyNode->next=nextElement;
        temp->next=copyNode;
        temp=nextElement;
    }
    temp=head;
    while(temp!=NULL){
        Node *copyNode=temp->next;
        if(temp->random!=NULL){
            copyNode->random=temp->random->next;
        }
        else{
            copyNode->random=NULL;
        }
        temp=temp->next->next; 
    }
    Node *newList=new Node(-1), *res=newList;
    temp=head;
    while(temp){
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return newList->next;
}
void Traverse(struct Node *head){
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;
    head->next->next->next->random = head->next->next;

    // Cloning the linked list
    Node *clonedHead = CloneLinkedList(head);

    // Printing the original and cloned linked lists
    cout << "Original Linked List:" << endl;
    Traverse(head);

    cout << "\nCloned Linked List:" << endl;
    Traverse(clonedHead);

    return 0;
}
