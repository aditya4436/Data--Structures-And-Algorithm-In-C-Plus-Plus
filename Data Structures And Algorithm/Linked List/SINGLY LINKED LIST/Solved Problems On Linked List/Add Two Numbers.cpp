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
// Time Complexity:- O(max(N, M)), where N and M are the lengths of the input
//                   linked lists l1 and l2. This is because the function iterates 
//                   through the linked lists once, and the number of iterations is
//                   determined by the length of the longer linked list.

// Space Complexity:- O(max(N, M)), primarily due to the creation of the new linked
//                    list to store the result. The space required for the new linked
//                    list is proportional to the length of the longer input list. 
//                    Additionally, the function uses a constant amount of extra space 
//                    for variables like temp, carry, sum, and node.
Node *AddTwoNumbers(Node *num1, Node *num2)
{
    Node *newList=new Node();
    Node *temp=newList;
    int carry=0;
    while(num1 || num2 || carry){
        int sum=0;
        if(num1){
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2){
            sum+=num2->data;
            num2=num2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node *node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return newList->next;
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

    struct Node *sum=AddTwoNumbers(head1, head2);
    cout<<"The sum of the two linked list is:\n";
    Traverse(sum);
    return 0;
}
