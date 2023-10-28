#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
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
        cout<<"Empty.";
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
            cout<<"NULL";
        }
    }
}
void Search_An_Existing_Node(int data)
{
    Node *temp=head;
    int flag=1, i=0;
    if(head==NULL)
    {
        cout<<"Empty";
    }
    else
    {
        do
        {
            if(temp->data==data)
            {
                cout<<"\nThe entered data is at position "<<i+1<<endl;
                return;
            }
            else
            {
                flag=0;
            }
            i++;
            temp=temp->next;
        }
        while(temp!=head);
        {
            if(flag==0)
            {
                cout<<"\nData does not exist.\n";
                return;
            }
        }
    }
    return;
}
int main()
{
    Add_Nodes_To_The_List(21);
    Add_Nodes_To_The_List(2);
    Add_Nodes_To_The_List(3);
    Add_Nodes_To_The_List(4);
    Add_Nodes_To_The_List(5);
    Traverse_The_List();
    Search_An_Existing_Node(5);
    return 0;
}
