#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=new Node;
    newNode->data=data_of_the_list;
    newNode->next=head;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        newNode->next=head;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
        tail->next=head;
    }
}
void Traveres_The_List()
{
    Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty!";
    }
    else
    {
        do
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
        while(current!=head);
        {
            cout<<"NULL.";
        }
    }
}
int main()
{
    int number_of_nodes_required, i;
    cout<<"Enter number of nodes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    Traveres_The_List();
    return 0;
}

