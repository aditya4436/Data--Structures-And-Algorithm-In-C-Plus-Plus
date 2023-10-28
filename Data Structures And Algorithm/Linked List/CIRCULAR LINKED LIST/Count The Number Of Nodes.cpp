/// A program to count the number of nodes in Circular Linked List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
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
        newNode->next=head;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
        tail->next=head;
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
        while(temp!=head);
        {
            cout<<"HEAD";
        }
    }
}
int Count_The_Number_Of_Nodes()
{
    int i=0, count=0;
    Node* temp=tail;
    if(head==NULL)
    {
        cout<<"Empty\n";
    }
    else
    {
        while(temp->next!=tail)
        {
            count++;
            temp=temp->next;
        }
        count=count+1;
    }
    cout<<"\nThere are "<<count<<" nodes in the list.";
    return 0;
}
int main()
{
    Add_Nodes_To_The_List(2);
    Add_Nodes_To_The_List(3);
    Add_Nodes_To_The_List(4);
    Add_Nodes_To_The_List(5);
    Add_Nodes_To_The_List(108);
    Traverse_The_List();
    Count_The_Number_Of_Nodes();
    return 0;
}

