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
// Time Complexity:- O(n), 'n' is the number nodes in the
//                   linked list.
// Space Complexity:- O(1)
bool DetectACycleInALinkedList(struct Node *head){
    if(!head && !head->next){
        return false;
    }
    struct Node *fast=head;
    struct Node *slow=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    // head->next->next->next->next=head->next->next;
    head->next->next->next->next=new Node(5);
    if(DetectACycleInALinkedList(head)==true){
        cout<<"The linked list has a cycle.";
    }
    else{
        cout<<"The linked list does not have linked list.";
    }
    return 0;
}
