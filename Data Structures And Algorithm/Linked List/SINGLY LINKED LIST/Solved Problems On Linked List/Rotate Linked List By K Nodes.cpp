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
// BRUTE FORCE APPROACH
// Time Complexity:- O(k*n), because for 'k' rotation we are everytime
//                   time traversing the the linked list of size 'n'.
// Space Complexity:- O(1)
// int Count(struct Node* head) {
//     struct Node* counter=head;
//     int count=0;
//     if (head==NULL) {
//         return 0;
//     } 
//     else {
//         while (counter!=NULL) {
//             count++;
//             counter=counter->next;
//         }
//     }
//     return count;
// }
// struct Node *RotateLinkedListByKNodes(struct Node *head, int k){
//     if(head==NULL || head->next==NULL || k==0){
//         return head;
//     }
//     int count=Count(head);
//     if(k>count){
//         k=k%count;
//     }
//     for(int i=0; i<k; i++){
//         struct Node *p=head, *q=p->next;
//         while(q->next!=NULL){
//             p=p->next;
//             q=q->next;
//         }
//         q->next=head;
//         p->next=NULL;
//         head=q;
//     }
//     return head;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n)+O(n-(k%n)), O(n) to count the number of nodes
//                   O(n-(k%n)) to rotate the linked list.
// Space Complexity:- O(1)
struct Node *RotateLinkedListByKNodes(struct Node *head, int k){
    if(head==NULL || head->next==NULL || k==0){
        return head;
    }
    struct Node *current=head;
    int len=1;
    while(current->next!=NULL && ++len){
        current=current->next;
    }
    current->next=head;
    k=k%len;
    k=len-k;
    while(k--){
        current=current->next;
    }
    head=current->next;
    current->next=NULL;
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
            temp=temp->next;
        }
    }
}
int main() {
    struct Node *head=new Node(0);
    head->next=new Node(1);
    head->next->next=new Node(2);
    // head->next->next->next=new Node(4);
    // head->next->next->next->next=new Node(5);
    struct Node *newHead=RotateLinkedListByKNodes(head, 4);
    Traverse(newHead);
    return 0;
}
