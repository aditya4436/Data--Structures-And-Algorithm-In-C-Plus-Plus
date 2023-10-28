///A program to insert an element or the data at the end
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=new Node(data_of_the_list);
    newNode->data=data_of_the_list;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
void Traverse_The_List()
{
    Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty!";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }
    }
}
void Add_New_Node_At_The_End()
{
    int new_data;
    Node *temp=head;
    cout<<"Enter the new data to be inserted at the end:\n";
    cin>>new_data;
    struct Node *newNode= new Node(new_data);
    newNode->data=new_data;
    newNode->next=NULL;
    if(head==NULL)
    {
        newNode->next=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
int main()
{
    int number_of_nodes_required, i;
    cout<<"Enter the number of nodes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    cout<<"The list before inserting a new element or the data at the end:\n";
    Traverse_The_List();
    cout<<endl;
    Add_New_Node_At_The_End();
    cout<<"The list after inserting a new element or the data end:\n";
    Traverse_The_List();
    return 0;
}

