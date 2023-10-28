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
void Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the nodes to inserted in the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=new Node;
    newNode->data=data_of_the_list;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        head->previous=NULL;
        head->next=NULL;
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
        cout<<"List is empty!";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }
        cout<<"NULL.";
    }
}
void Delete_The_Last_Node()
{
    Node *temp, *temp2;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->previous;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
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
    cout<<"List before deleting the last node:\n";
    Traverse_The_List();
    cout<<"\n";
    Delete_The_Last_Node();
    cout<<"List after deleting the last node:\n";
    Traverse_The_List();
    return 0;
}

