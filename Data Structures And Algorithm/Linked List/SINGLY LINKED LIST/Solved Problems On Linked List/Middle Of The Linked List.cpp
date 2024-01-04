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
// BRUTE FORCE APPROACH
// Time Complexity:- O(n+(n/2)), O(n) to calculate the number of nodes
//                   O(n/2) to traverse the nodes from middle to the end.
// Space Complexity:- O(1)
// int Count(struct Node *head){
//     struct Node *temp=head;
//     int count=0;
//     if(head==NULL){
//         return 0;
//     }
//     else{
//         while(temp!=NULL){
//             temp=temp->next;
//             count++;
//         }
//     }
//     return count;
// }
// struct Node *Middle(struct Node *head){
//     int i=0, count=Count(head); 
//     struct Node *temp=head;
//     if(head==NULL){
//         return NULL;
//     }
//     else{
//         while(i<(count/2)){
//             temp=temp->next;
//             i++;
//         }
//         return temp;
//     }
//     return NULL;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n/2), because the 'fast' pointer moves by two node amd 
//                   and we stop the traversal when 'fast' points to the NULL
//                   or 'fast' pointer's next points to NULL.
// Space Complexity:- O(1)
struct Node *Middle(struct Node *head){
    struct Node *fast=head;
    struct Node *slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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
    // head->next->next->next->next->next=new Node(6);
    struct Node *newHead=Middle(head);
    Traverse(newHead);
    return 0;
}
