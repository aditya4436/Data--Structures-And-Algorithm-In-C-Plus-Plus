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
struct Node *DeleteAllOccurencesOfK(struct Node *head, int k){
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            if(temp==head){
                head=head->next;
            }
            Node *nextNode=temp->next;
            Node *prevNode=temp->prev;
            if(nextNode){
                nextNode->prev=prevNode;
            }
            if(prevNode){
                prevNode->next=nextNode;
            }
            free(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
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
    struct Node *head = new Node(10);
    head->prev = NULL;
    head->next = new Node(4);
    head->next->prev = head;
    head->next->next = new Node(10);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(20);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    Traverse(head);
    cout<<endl;
    int k = 10;
    struct Node *newHead=DeleteAllOccurencesOfK(head, k);
    Traverse(newHead);
    return 0;
}
