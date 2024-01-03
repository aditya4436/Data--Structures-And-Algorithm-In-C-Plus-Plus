#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
    Node(){
        this->data = 0;
        next = NULL;
    }
};
// Time Complexity:- O(n), since we have to reverse the entire 
//                   linked list.
// Space Complexity:- O(1)
struct Node *DeleteNthNodeFromTheLast(struct Node *head, int n){
    struct Node *start=new Node();
    start->next=head;
    struct Node *fast=start;
    struct Node *slow=start;
    for(int i=1; i<=n; i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return start->next;
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
    cout<<"Original Linked List:\n";
    Traverse(head);
    cout<<"\nAfter the deleting the nth node from end of the Linked List is:\n";
    struct Node *newHead=DeleteNthNodeFromTheLast(head, 3);
    Traverse(newHead);
    return 0;
}
