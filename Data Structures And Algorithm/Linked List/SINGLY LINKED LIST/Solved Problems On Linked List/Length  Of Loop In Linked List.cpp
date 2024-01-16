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
// BRUTE FORCE APPROACH
// Time Complexity:- O(n)*O(2log(n)), O(n) traverse the the linked list.
//                   O(2log(n)) to perform hashmap insertion and searches
//                   the node.
// Space Complexity:- O(n), to store all the nodes in the map. 
// int LengthOfLoopInLinkedList(struct Node *head){
//     map<Node*, int> mpp;
//     struct Node *temp=head;
//     int timer=0;
//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()){
//             int value=mpp[temp];
//             return(timer-value);
//         }
//         mpp[temp]=timer;
//         timer++;
//         temp=temp->next;
//     }
//     return 0;
// }

int FindLength(struct Node *slow, struct Node *fast){
    int count=1;
    fast=fast->next;
    while(fast!=slow){
        fast=fast->next;
        count++;
    }
    return count;
}
// OPTIMIZED APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int LengthOfLoopInLinkedList(struct Node *head){
    struct Node *fast=head, *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return FindLength(slow, fast);
        }
    }
    return 0;
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=head->next->next;
    cout<<LengthOfLoopInLinkedList(head);
    return 0;
}
