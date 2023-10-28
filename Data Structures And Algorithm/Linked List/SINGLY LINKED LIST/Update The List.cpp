/// A Program to the the Singly Linked List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node* head=NULL;
struct Node* tail=NULL;
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
        cout<<"Underflow";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
    }
}
void Update_First_Node(int data)
{
    Node *temp=head;
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    newNode->next=head;
    head=newNode;
    head->next=temp->next;
    free(temp);
    temp=NULL;
}
void Update_Last_Node(int data)
{
    struct Node *temp=head;
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    temp->next=newNode;
    temp=newNode;
}
void Update_Specific_Node(int data, int pos)
{
    struct Node *temp=head;
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    int i;
    while(i<pos-2)
    {
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next->next;
    free(temp->next);
    temp->next=NULL;
    temp->next=newNode;
}
int main()
{
    Add_Nodes_To_The_List(1);
    Add_Nodes_To_The_List(2);
    Add_Nodes_To_The_List(3);
    Add_Nodes_To_The_List(4);
    cout<<"List before updating:\n";
    Traverse_The_List();
    cout<<endl;
    cout<<"After updating the first node:\n";
    Update_First_Node(5);
    Traverse_The_List();
    cout<<endl;
    cout<<"After updating the last node:\n";
    Update_Last_Node(6);
    Traverse_The_List();
    cout<<endl;
    cout<<"After updating the specific node:\n";
    Update_Specific_Node(7, 3);
    Traverse_The_List();
    return 0;
}
