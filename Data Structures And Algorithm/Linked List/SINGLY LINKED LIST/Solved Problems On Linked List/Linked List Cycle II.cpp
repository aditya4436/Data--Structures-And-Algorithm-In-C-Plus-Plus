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
// BRUTE FORCE
// Time Complexity:- O(n)*O(log(n)), O(n) to traverse the
//                   linked list and O(log(n)) to  search
//                   the node where loop starts.
// Space Complexity:- O(n), because in the worst case 
//                    we have to insert all the elements
//                    in linked list.
// struct Node *StartingLoopOfLinkedList(struct Node *head){
//     if(head==NULL || head->next==NULL){
//         return NULL;
//     }
//     struct Node *temp=head;
//     map<Node*, int> mpp;
//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()){
//             return temp;
//         }
//         mpp[temp]=1;
//         temp=temp->next;
//     }
//     return NULL;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n), because we are traversing the entire linked list.
// Space Complexity:- O(1), because we are not using any extra space.
struct Node *FindStartingPointOfACircleInLinkedList(struct Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    struct Node *fast=head, *slow=head, *entry=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
             return entry;
        }
    }
    return NULL;
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=head->next->next;
    struct Node *ans=FindStartingPointOfACircleInLinkedList(head);
    cout<<ans->data;
    return 0;
}
