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
// Time Complexity:- O((n/k)*k), 'n' is the total number of nodes,
//                   'k' is the number nodes in a group. The outer
//                    loop runs for (n/k) times only and again we 
//                    are iterating to reverse the group.
//                    Therefore the overall time complexity is O(n).
// Space Complexity:- O(1)
struct Node *ReverseNodesInKGroup(struct Node *head, int k){
    if(head==NULL || k==1){
        return head;
    }
    int count=0;
    Node *updatedList=new Node();
    updatedList->next=head;
    Node *previous=updatedList, *following=updatedList, *current=updatedList;
    while(current->next){
        current=current->next;
        count++;
    }
    while(count>=k){
        current=previous->next;
        following=current->next;
        for(int i=1; i<k; i++){
            current->next=following->next;
            following->next=previous->next;
            previous->next=following;
            following=current->next;
        }
        previous=current;
        count-=k;
    }
    return updatedList->next;
}
void Traverse(struct Node *head){
    struct Node *current=head;
    if(head==NULL){
        cout<<"Underflow";
        return;
    }
    else{
        while(current!=NULL){
            cout<<current->data<<"  ";
            current=current->next;
        }
    }
    return;
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    struct Node *updatedList=ReverseNodesInKGroup(head, 2);
    Traverse(updatedList);
    return 0;
}
