#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
// Time Complexity:- O(n), to convert each element of an array
// 					 to linked list.
// Space Complexity:- O(1)
struct Node *ConvertArrayToLinkedList(vector<int> &arr){
	struct Node *head=new Node(arr[0]);
	if(head==NULL){
		return NULL;
	}
	struct Node *current=head;
	for(int i=1; i<arr.size(); i++){
		struct Node *temp=new Node(arr[i]);
		current->next=temp;
		current=temp;
	}
	return head;
}

// Time Complexity:- O(n), to traverse the entire linked list.
// Space Complexity:- O(1)
void Traverse(struct Node *head){
	struct Node *current=head;
	if(head==NULL){
		return;
	}
	else{
		while(current){
			cout<<current->data<<"  ";
			current=current->next;
		}
	}
}
int main(){
	vector<int> arr={2,5,8,7};
	struct Node *head=ConvertArrayToLinkedList(arr);
	Traverse(head);
	return 0;
}
