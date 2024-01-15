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
// BRUTE FORCE APPROACH
// Time Complexity:- O(2n), because we are traversing the linked list
//                   twice, the first time we will traverse to count
//                   the number of nodes and second time we will traverse
//                   to updated the value.
// Space Complexity:- O(1)
// struct Node *Sort012(struct Node *head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     struct Node *temp=head;
//     int count0=0, count1=0, count2=0;
//     while(temp!=NULL){
//         if(temp->data==0){
//             count0++;
//         }
//         if(temp->data==1){
//             count1++;
//         }
//         if(temp->data==2){
//             count2++;
//         }
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=NULL){
//         while(count0!=0){
//             temp->data=0;
//             temp=temp->next;
//             count0--;
//         }
//         while(count1!=0){
//             temp->data=1;
//             temp=temp->next;
//             count1--;
//         }
//         while(count2!=0){
//             temp->data=2;
//             temp=temp->next;
//             count2--;
//         }
//     }
//     return head;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
struct Node *Sort012(struct Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node *dummy0=new Node(-1), *dummy1=new Node(-1), *dummy2=new Node(-1);
    struct Node *list0=dummy0, *list2=dummy2, *list1=dummy1;
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            list0->next=temp;
            list0=temp;
        }
        if(temp->data==1){
            list1->next=temp;
            list1=temp;
        }
        if(temp->data==2){
            list2->next=temp;
            list2=temp;
        }
        temp=temp->next;
    }
    list0->next=dummy1->next ? dummy1->next : dummy2->next;
    list1->next=dummy2->next;
    list2->next=NULL;
    struct Node *newHead=dummy0->next;
    delete(dummy0);
    delete(dummy1);
    delete(dummy2);
    return newHead;
}
void Traverse(struct Node *head){
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(0);
    head->next->next=new Node(1);
    head->next->next->next=new Node(2);
    head->next->next->next->next=new Node(0);
    head->next->next->next->next->next=new Node(2);
    head->next->next->next->next->next->next=new Node(1);
    Traverse(head);
    cout<<endl;
    struct Node *newHead=Sort012(head);
    Traverse(newHead);
    return 0;
}
