#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *previous;
    Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        newNode->previous=tail;
        tail=newNode;
        tail->next=NULL;

    }
}
void Traverse_The_List()
{
    Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
        cout<<"NULL.";
    }
}
void Count_The_Number_Of_Nodes()
{
    Node *temp=head;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    cout<<"\nThere are "<<i<<" nodes in the list.";
}
int main()
{
    Add_Nodes_To_The_List(99);
    Add_Nodes_To_The_List(81);
    Add_Nodes_To_The_List(88);
    Add_Nodes_To_The_List(44);
    Add_Nodes_To_The_List(36);
    Add_Nodes_To_The_List(63);
    Traverse_The_List();
    Count_The_Number_Of_Nodes();
    return 0;
}
