#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node (int data){
        this->data=data;
        next=NULL;
    }
};
struct Node *Reverse(struct Node *head){
    struct Node *newHead=NULL;
    while(head!=NULL){
        struct Node *next=head->next;
        head->next=newHead;
        newHead=head;
        head=next;
    }
    return newHead;
}

// BRUTE FORCE APPROACH
// Time Complexity:- O(3n)
// Space Complexity:- O(1)
// struct Node *PlusOneInLinkedList(struct Node *head){
//     head=Reverse(head);
//     struct Node *temp=head;
//     int carry=1;
//     while(temp!=NULL){
//         temp->data=temp->data+carry;
//         if(temp->data<10){
//             carry=0;
//             break;
//         }
//         else{
//             temp->data=0;
//             carry=1;
//         }
//         temp=temp->next;
//     }
//     if(carry==1){
//         struct Node *newNode=new Node(1);
//         head=Reverse(head);
//         newNode->next=head;
//         return newNode;
//     }
//     head=Reverse(head);
//     return head;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(n), for recursive stack space
//                    we are not using any extra space
//                    to solve the problem.
int PlusOne(struct Node *head){
    if(head==NULL){
        return 1;
    }
    int carry=PlusOne(head->next);
    head->data=head->data+carry;
    if(head->data<10){
        return 0;
    }
    head->data=0;
    return 1;
}
struct Node *PlusOneInLinkedList(struct Node *head)
{
    //Write your code here
    int carry=PlusOne(head);
    if(carry==1){
        struct Node *newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}
void Traverse(struct Node *head){
    if(head==NULL || head->next==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main(){
    struct Node *head=new Node(9);
    head->next=new Node(9);
    head->next->next=new Node(9);
    // head->next->next->next=new Node(2);
    // head->next->next->next->next=new Node(0);
    // head->next->next->next->next->next=new Node(2);
    // head->next->next->next->next->next->next=new Node(1);
    Traverse(head);
    cout<<endl;
    struct Node *newHead=PlusOneInLinkedList(head);
    Traverse(newHead);
    return 0;
}
