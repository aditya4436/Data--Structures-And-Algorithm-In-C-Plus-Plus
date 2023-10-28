/// A program to count the number of nodes in Singly Linked List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
void Traverse_The_List()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"Empty";
    }
    else
    {
        do
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        while(temp!=NULL);
        {
            cout<<"NULL";
        }
    }
}
int Count_The_Number_Of_Nodes()
{
    int i=0, count=0;
    Node* temp=head;
    if(head==NULL)
    {
        cout<<"Empty\n";
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    cout<<"\nThere are "<<count<<" nodes in the list.";
    return 0;
}
int main()
{
    Add_Nodes_To_The_List(1);
    Add_Nodes_To_The_List(2);
    Add_Nodes_To_The_List(3);
    Add_Nodes_To_The_List(4);
    Traverse_The_List();
    Count_The_Number_Of_Nodes();
    return 0;
}
