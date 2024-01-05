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
// Time Complexity:- O(M + N), where M and N are the lengths of the linked 
//                   lists head1 and head2. The function traverses both linked 
//                   lists in a loop until either the intersection point is found
//                   or both pointers reach the end of their respective lists. The 
//                   worst-case scenario is when there is no intersection, and both 
//                   pointers traverse the entire lengths of their lists.

// Space Complexity:- O(1). The function uses only a constant amount of extra space
//                    for the two pointers (a and b). It does not use any additional
//                    data structures that scale with the input size. Therefore, the 
//                    space complexity is constant.
struct Node *IntersectionOfTwoList(struct Node *head1, struct Node *head2){
    Node *a=head1, *b=head2;
    while(a!=b){
        a=a->next;
        b=b->next;
        if(a==NULL){
            a=head2;
        }
        if(b==NULL){
            b=head1;
        }
    }
    return a;
}
int main(){
    struct Node *head1=new Node(1);
    head1->next=new Node(2);
    head1->next->next=new Node(3);
    head1->next->next->next=new Node(4);
    head1->next->next->next->next=new Node(5);

    struct Node *head2=new Node(6);
    head2->next=new Node(7);
    head2->next->next=new Node(3);
    head2->next->next->next=new Node(8);
    head2->next->next->next->next=head1->next->next->next->next;

    struct Node *intersectionNode=IntersectionOfTwoList(head1, head2);
    cout<<"The intersection of the two linked list is:\n"<<intersectionNode->data<<endl;
    return 0;
}
