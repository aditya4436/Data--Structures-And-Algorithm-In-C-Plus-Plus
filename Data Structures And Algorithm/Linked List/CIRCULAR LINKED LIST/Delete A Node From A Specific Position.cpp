#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
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
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        newNode->next=NULL;
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
    struct Node *current=head;
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
            cout<<"HEAD.";
        }
    }
}
void Delete_A_Specific_Node()
{
    Node *temp, *temp1;
    int pos, i=0;
    cout<<"Enter the position of the data:\n";
    cin>>pos;
    temp=tail->next;
    while(i<pos-1)
    {
        temp1=temp;
        temp=temp->next;
        i++;
    }
    temp1->next=temp->next;
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
    Traverse_The_List();
    Delete_A_Specific_Node();
    Traverse_The_List();
    return 0;
}

