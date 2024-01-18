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
// struct Node *ConvertArrayToLinkedList(vector<int> &arr){
//     struct Node *head=new Node(arr[0]);
//     struct Node *temp=head;
//     for(int i=1; i<arr.size(); i++){
//         temp->next=new Node(arr[i]);
//         temp=temp->next;
//     }
//     return head;
// }

// BRUTE FORCE APPROACH
// Time Complexity:- O(n)+O((n)log(n))+O(n), the first O(n) is to
//                   push the data of the linked list into array and
//                   O((n)log(n)), to sort the array and the second O(n)
//                   to convert the array to linked list.
// Space Complexity:- O(n), because we are using extra space to solve the
//                    problem.
// struct Node *SortLinkedList(struct Node *head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     vector<int> arr;
//     struct Node *temp=head;
//     while(temp!=NULL){
//         arr.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(arr.begin(), arr.end());
//     head=ConvertArrayToLinkedList(arr);
//     return head;
// }

// BRUTE FORCE APPROACH-2
// Time Complexity:- O(n)+O((n)log(n))+O(n), the first O(n) is to
//                   push the data of the linked list into array and
//                   O((n)log(n)), to sort the array and the second O(n)
//                   to convert the array to linked list.
// Space Complexity:- O(n), because we are using extra space to solve the
//                    problem.
// struct Node *SortLinkedList(struct Node *head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     vector<int> arr;
//     struct Node *temp=head;
//     while(temp!=NULL){
//         arr.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(arr.begin(), arr.end());
//     temp=head;
//     int i=0;
//     while(temp){
//         temp->data=arr[i];
//         temp=temp->next;
//         i++;
//     }
//     return head;
// }

Node *MergeSort(Node *list1, Node *list2){
	Node *dummy=new Node(-1);
	Node *temp=dummy;
	while(list1!=NULL && list2!=NULL){
		if(list1->data<list2->data){
			temp->next=list1;
			temp=list1;
			list1=list1->next;
		}
		else{
			temp->next=list2;
			temp=list2;
			list2=list2->next;
		}
	}
	if(list1){
		temp->next=list1;
	}
	if(list2){
		temp->next=list2;
	}
	return dummy->next;
}
Node *MiddleNode(Node *head){
	Node *slow=head, *fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

// OPTIMIZE APPROACH
// Time Complexity:- O((n)log(n))+O(n/2), O((n)log(n)) to perform merge sort
//                   O(n/2) to find the middle node.
// Space Complexity:- O(1)
Node *SortLinkedList(Node *head)
{
    if(head==NULL || head->next==NULL){
		return head;
	}
	Node *middle=MiddleNode(head);
	Node *right=middle->next;
	middle->next=nullptr;
	Node *left=head;
	left=SortLinkedList(left);
	right=SortLinkedList(right);
	return MergeSort(left, right);
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
int main(){
    struct Node *head=new Node(8);
    head->next=new Node(20);
    head->next->next=new Node(2);
    Traverse(head);
    cout<<endl;
    struct Node *newHead=SortLinkedList(head);
    Traverse(newHead);
    return 0;
}
