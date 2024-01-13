#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
// Time Complexity:- O(n), because in the worst case we may have to delete
// 		     to delete the last node.
// Space Complexity:- O(1)
Node *DeleteNode(Node *head, int pos)
{
	if(head==NULL){
		return NULL;
	}
	if(pos==0){
		Node *temp=head;
		head=head->next;
		free(temp);
		return head;
	}
	Node *temp=head;
	Node *prev=NULL;
	int i=0;
	while(temp){
		if(i==pos){
			prev->next=temp->next;
			free(temp);
		}
		prev=temp;
		temp=temp->next;
		i++;
	}
	return head;
}
void Traverse(Node *head){
    if(head==NULL){
        return;
    }
    Node *current=head;
    while(current){
        cout<<current->data<<"  ";
        current=current->next;
    }
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    Traverse(head);
    Node *newHead=DeleteNode(head, 4);
    cout<<endl;
    Traverse(newHead);
    return 0;
}
