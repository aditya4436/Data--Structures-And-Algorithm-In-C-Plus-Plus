///A program to insert a new element or data at the beginning of the list
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
        cout<<"List is empty...\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
    }
    cout<<endl;
}
void Insert_At_The_Begining()
{
    int data;
    cout<<"Enter the data to be inserted at the beginning:\n";
    cin>>data;

    struct Node *newNode=new Node(data);
    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL)
    {
        cout<<"List is empty...\n";
    }

    else
    {
        newNode->next=head;
        head=newNode;
    }
}
int main()
{
    int number_nodes_required, i;
    cout<<"Enter the number of nodes required:\n";
    cin>>number_nodes_required;
    for(i=0;i<number_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    cout<<"The list before inserting an element or the data at the beginning:\n";
    Traverse_The_List();
    Insert_At_The_Begining();
    cout<<"The list after inserting an element or the data at the beginning:\n";
    Traverse_The_List();
    return 0;
}

