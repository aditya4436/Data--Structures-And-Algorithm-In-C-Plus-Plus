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
// Time Complexity:- O(n/2)+O(n/2)+O(n/2), first O(n/2) is to
//                   find the middle, second O(n/2) to reverse
//                   the second half linked list and third O(n/2)
//                   is to compare the first half and second half
//                   of the linked list.
// Space Complexity:- O(1), because we are not using any extra space
//                    to solve the problem.
struct Node *ReverseTheLinkedList(struct Node *head){
    struct Node *previous=NULL, *next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=previous;
        previous=head;
        head=next;
    }
    return previous;
}
bool IsAPalindromeLinkedList(struct Node *head){
    if(!head || !head->next){
        return true;
    }
    struct Node *fast=head;
    struct Node *slow=head;
    struct Node *temp=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=ReverseTheLinkedList(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(temp->data!=slow->data){
            return false;
        }
        temp=temp->next;
        slow=slow->next;
    }
    return true;
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);
    head->next->next->next=new Node(1);
    // head->next->next->next->next=new Node(2);
    // head->next->next->next->next->next=new Node(1);
    if(IsAPalindromeLinkedList(head)){
        cout<<"The linked list is a palindromic linked list.";
    }
    else{
        cout<<"The linked list is not palindromic linked list.";
    }
    return 0;
}
