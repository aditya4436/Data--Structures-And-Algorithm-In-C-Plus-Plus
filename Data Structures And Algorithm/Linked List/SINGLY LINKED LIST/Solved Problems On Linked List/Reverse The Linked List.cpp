#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
// Time Complexity:- O(n), since we have to reverse the entire 
//                   linked list.
// Space Complexity:- O(1)
struct Node *ReversedLinkedList(struct Node *head){
    struct Node *newHead=NULL;
    while(head!=NULL){
        struct Node *next=head->next;
        head->next=newHead;
        newHead=head;
        head=next;
    }
    return newHead;
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
    cout<<"\nReversed Linked List is:\n";
    struct Node *newHead=ReversedLinkedList(head);
    Traverse(newHead);
    return 0;
}
