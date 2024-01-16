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
// Time Complexity:- O(n)*O(2logn), O(n) to traverse the linked list
//                   O(2log(n)), log(n) to check if the node is in the
//                   map or not and another log(n) to insert the nodes.
// Space Complexity: O(n), because we are storing the all elements in the map
//                   in the worst case.
// bool DetectACycleInALinkedList(struct Node *head){
//     if(head==NULL || head->next==NULL){
//         return false;
//     }
//     map<Node*, bool> mpp;
//     Node *temp=head;
//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()){
//             return true;
//         }
//         mpp[temp]=true;
//         mpp.insert({temp, true});
//         temp=temp->next;
//     }
//     return false;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n), 'n' is the number nodes in the
//                   linked list.
// Space Complexity:- O(1)
bool DetectACycleInALinkedList(struct Node *head){
    if(!head && !head->next){
        return false;
    }
    struct Node *fast=head;
    struct Node *slow=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main(){
    struct Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    // head->next->next->next->next=head->next->next;
    head->next->next->next->next=new Node(5);
    if(DetectACycleInALinkedList(head)==true){
        cout<<"The linked list has a cycle.";
    }
    else{
        cout<<"The linked list does not have linked list.";
    }
    return 0;
}
