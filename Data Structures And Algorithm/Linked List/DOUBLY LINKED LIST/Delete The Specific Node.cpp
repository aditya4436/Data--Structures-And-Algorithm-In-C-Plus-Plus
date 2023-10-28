#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *previous, *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List()
{
    int data;
    cout<<"Enter the data of the list:\n";
    cin>>data;
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        head->previous=NULL;
        tail->next=NULL;
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
            cout<<current->data<<"  ";
            current=current->next;
        }
        cout<<"NULL.";
    }
}
void Delete_The_Specific_Node()
{
    Node *temp=head;
    int pos, i=0;
    cout<<"Enter position of the node which you wish to delete:\n";
    cin>>pos;
    if(pos==1)
    {
        cout<<"Node cannot be deleted.";
    }
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;
    free(temp);
    temp=NULL;
}
int main()
{
    int number_of_nodes_required, i, choice;
    cout<<"Enter the number of nodes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    cout<<"List before Deleting the Specific Node:\n";
    Traverse_The_List();
    cout<<endl;
    Delete_The_Specific_Node();
    cout<<"List before Deleting the Specific Node:\n";
    Traverse_The_List();
    return 0;
}
