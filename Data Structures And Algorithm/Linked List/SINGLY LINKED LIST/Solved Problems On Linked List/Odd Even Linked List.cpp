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
// Time Complexity:- O(2n)
// Space Complexity:- O(n)
// struct Node *OddEvenLinkedList(struct Node *head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     struct Node *temp=head;
//     vector<int> arr;
//     while(temp && temp->next){
//         arr.push_back(temp->data);
//         temp=temp->next->next;
//     }
//     if(temp){
//         arr.push_back(temp->data);
//     }
//     temp=head->next;
//     while(temp && temp->next){
//         arr.push_back(temp->data);
//         temp=temp->next->next;
//     }
//     if(temp){
//         arr.push_back(temp->data);
//     }
//     int i=0;
//     temp=head;
//     while(temp){
//         temp->data=arr[i];
//         i++;
//         temp=temp->next;
//     }
//     return head;
// }

// Time Complexity:- O(n)
// Space Complexity:- O(1)
struct Node *OddEvenLinkedList(struct Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node *odd=head, *even=head->next, *evenHead=head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
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
    struct Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    Traverse(head);
    cout<<endl;
    struct Node *newHead=OddEvenLinkedList(head);
    Traverse(newHead);
    return 0;
}
