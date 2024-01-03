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
struct Node *NthNodeFromEnd(Node *head, int n)
{
    // Write your code here
	Node *start=new Node(0);
	start->next=head;
	Node *fast=start;
	Node *slow=start;
	for(int i=1; i<=n; i++){
		fast=fast->next;
	}
	while(fast->next!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	return slow->next;
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
    cout<<"\nThe nth node from end of the Linked List is:\n";
    struct Node *ans=NthNodeFromEnd(head, 3);
    cout<<ans->data<<"  ";
    return 0;
}
