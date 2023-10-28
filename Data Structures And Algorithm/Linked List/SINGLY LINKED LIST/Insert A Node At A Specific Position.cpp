///A program to insert an element at a specific position
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
Node Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=new Node;
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
    return *head;
}
void Traverse_The_List()
{
    struct Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty...";
    }
    else
    {
        cout<<endl;
        while(current!=NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }
    }
}
void Add_Node_At_A_Specific_Position()
{
    int new_data, pos, i;
    cout<<"Enter the position to where you want insert a new data:\n";
    cin>>pos;
    if(pos==1)
    {
        cout<<"The new data cannot be inserted at the beginning because head is pointing to the "<<pos<<"st position.";
    }
    else
    {
        struct Node *temp=head;
        cout<<"Enter the new data to insert at a specific position:\n";
        cin>>new_data;
        i=0;
        while(i<pos-2)
        {
            temp=temp->next;
            i++;
        }
        struct Node *newNode=new Node;
        newNode->data=new_data;
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void Count_The_Numbers_Of_Nodes()
{
    int count=0;
    struct Node *current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    cout<<"\nThere are "<<count<<" nodes in the list.";
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
    cout<<"The list before insertion at a specific position:";
    Traverse_The_List();
    cout<<endl;
    Add_Node_At_A_Specific_Position();
    cout<<"The list after insertion at a specific position:";
    Traverse_The_List();
    Count_The_Numbers_Of_Nodes();
    return 0;
}
