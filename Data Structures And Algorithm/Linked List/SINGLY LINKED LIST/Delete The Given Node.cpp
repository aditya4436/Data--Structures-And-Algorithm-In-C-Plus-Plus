#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    Node(){

    }
};
// Time Complexity:- O(1), because we are already given the node which is to
//                   be deleted so we don't need to traverse the entire linked list.
// Space Complexity:- O(1)
void DeleteTheGivenNode(struct Node *deleteNode){
    // The node to be deleted must not be the last node.
    deleteNode->data=deleteNode->next->data;
    deleteNode->next=deleteNode->next->next;
}
void Traverse(struct Node *head){
    struct Node *current=head;
    if(head==NULL){
        return;
    }
    else{
        while(current!=NULL){
            cout<<current->data<<"  ";
            current=current->next;
        }
    }
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    Traverse(head);
    struct Node *deleteNode=head->next->next;
    DeleteTheGivenNode(deleteNode);
    cout<<"\nAfter deleting the given node from the linked list:\n";
    Traverse(head);
    return 0;
}
