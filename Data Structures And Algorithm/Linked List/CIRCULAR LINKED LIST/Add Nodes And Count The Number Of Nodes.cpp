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
void Count_The_Numbers_Of_Nodes()
{
    int count;
    struct Node *current=head;
    do
    {
        count++;
        current=current->next;
    }
    while(current!=head);
    {
        cout<<"There are "<<count<<" nodes in the list.";
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
    Count_The_Numbers_Of_Nodes();
    return 0;
}

