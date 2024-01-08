#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->bottom=NULL;
    }
    Node(){

    }
};
// Time Complexity:- O(summation(all the nodes))
// Space Complexity:- O(1)
Node *Merge(Node *a, Node *b){
    Node *temp=new Node();
    Node *result=temp;
    while(a && b){
        if(a->data<b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
        else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    if(a){
        temp->bottom=a;
    }
    else{
        temp->bottom=b;
    }
    return result->bottom;
}
Node* FlattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	head->next=FlattenLinkedList(head->next);
	head=Merge(head, head->next);
	return head;
}
void Traverse(struct Node *head){
    struct Node *temp=head;
    if(head==NULL){
        return;
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->bottom;
        }
    }
}
int main() {
    struct Node* head = new Node(1);
    head->bottom = new Node(2);
    head->bottom->bottom = new Node(3);

    head->next = new Node(4);
    head->next->bottom = new Node(5);
    head->next->bottom->bottom = new Node(6);

    head->next->next = new Node(7);
    head->next->next->bottom = new Node(8);

    head->next->next->next = new Node(9);
    head->next->next->next->bottom = new Node(12);

    head->next->next->next->next = new Node(20);

    struct Node* newHead = FlattenLinkedList(head);

    // Traverse and print the bottom of the linked list
    Traverse(newHead);

    return 0;
}
