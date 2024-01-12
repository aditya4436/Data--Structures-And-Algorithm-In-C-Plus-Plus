#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
// Time Complexity:- O(n), because in the worst case the node might
//                   be at the end of the linked list.
// Space Complexity:- O(1)
int Search(struct Node *head, int n){
	int i=0;
	struct Node *temp=head;
	while(temp){
		if(temp->data==n){
			return i;
		}
		temp=temp->next;
		i++;
	}
	return -1;
}
int main(){
	struct Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node (40);
	head->next->next->next->next=new Node (50);
	int index=Search(head, 20);
	cout<<index<<endl;
	return 0;
}
