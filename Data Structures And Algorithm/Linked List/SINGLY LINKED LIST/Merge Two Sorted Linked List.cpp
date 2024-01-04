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
// Time Complexity:- O(n1+n2), 'n1' is the size of first linked list,
//                   'n2' is the size of second linked list.
// Space Complexity:- O(n1+n2)
// struct Node *MergeTwoSortedList(struct Node *head1, struct Node *head2){
//     struct Node *newHead=new Node(), *dd=newHead;
//     while(head1 && head2){
//         if(head1->data<head2->data){
//             dd->next=new Node();
//             dd=dd->next;
//             dd->data=head1->data;
//             head1=head1->next;
//         }
//         else{
//             dd->next=new Node();
//             dd=dd->next;
//             dd->data=head2->data;
//             head2=head2->next;
//         }
//     }
//     while(head1){
//         dd->next=new Node();
//         dd=dd->next;
//         dd->data=head1->data;
//         head1=head1->next;
//     }
//     while(head2){
//         dd->next=new Node();
//         dd=dd->next;
//         dd->data=head2->data;
//         head2=head2->next;
//     }
//     dd->next=NULL;
//     return newHead->next;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n1+n2), 'n1'is the size of the first linked list
//                   'n2' is the size of second linked list.
// Space Complexity:- O(1), there is no extra space that is used here.
struct Node *MergeTwoSortedList(struct Node *head1, struct Node *head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    if(head1->data>head2->data){
        swap(head1, head2);
    }
    Node *res=head1;
    while(head1 && head2){
        Node *temp=NULL;
        while(head1 && head1->data<=head2->data){
            temp=head1;
            head1=head1->next;
        }
        temp->next=head2;
        swap(head1,head2);
    }
    return res;
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
    struct Node *head1=new Node(1);
    head1->next=new Node(2);
    head1->next->next=new Node(3);
    head1->next->next->next=new Node(4);
    head1->next->next->next->next=new Node(5);

    struct Node *head2=new Node(1);
    head2->next=new Node(2);
    head2->next->next=new Node(3);
    head2->next->next->next=new Node(4);
    head2->next->next->next->next=new Node(5);

    struct Node *newHead=MergeTwoSortedList(head1, head2);
    Traverse(newHead);
    return 0;
}
