#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(1)
struct Node *RemoveDuplicates(Node *head)
{
    Node *temp=head;
    while(temp && temp->next){
        Node *nextNode=temp->next;
        while(nextNode && temp->data==nextNode->data){
            Node *tempNext=nextNode->next;
            delete(nextNode);
            nextNode=tempNext;
        }
        temp->next=nextNode;
        if(nextNode){
            nextNode->prev=temp;
        }
        temp=temp->next;
    }
    return head;
}
void Traverse(struct Node *head){
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main() {
    struct Node *head = new Node(12);
    head->prev = NULL;
    head->next = new Node(12);
    head->next->prev = head;
    head->next->next = new Node(10);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(8);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->prev = head->next->next->next;
    Traverse(head);
    cout<<endl;
    struct Node *newHead=RemoveDuplicates(head);
    Traverse(newHead);
    return 0;
}
