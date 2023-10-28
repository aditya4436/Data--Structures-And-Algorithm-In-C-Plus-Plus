///A program to delete a node or data from the specific position
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
    struct Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }
        cout<<"NULL.\n";
    }
}
void Delete_From_A_Specific_Position()
{
    struct Node *temp, *temp1;
    temp=head;
    int pos, i;
    cout<<"Enter the position of the node you wish to delete:\n";
    cin>>pos;
    i=0;
    while(i<pos-1)
    {
        temp1=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Desired node does not exist.\n";
        }
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
    cout<<"Before deleting a node from the specific position:\n";
    Traverse_The_List();
    cout<<endl;
    Delete_From_A_Specific_Position();
    cout<<"After deleting a node from the specific position:\n";
    Traverse_The_List();
    return 0;
}
