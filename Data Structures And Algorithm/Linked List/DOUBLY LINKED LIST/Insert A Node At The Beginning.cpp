#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *previous;
    Node *next;
    Node(int data)
    {
        this->data=data;
        previous=NULL;
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
void Insert_At_Beginning()
{
    int new_data;
    cout<<"Enter the new data to be inserted at the beginning:\n";
    cin>>new_data;
    struct Node *newNode=new Node(new_data);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        head->previous=NULL;
        tail->next=NULL;
    }
    else
    {
        newNode->next=head;
        head->previous=newNode;
        newNode->previous=NULL;
        head=newNode;
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
        cout<<"NULL.";
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
    cout<<"List before Insertion at the beginning:\n";
    Traverse_The_List();
    cout<<endl;
    Insert_At_Beginning();
    cout<<"List after insertion at the beginning:\n";
    Traverse_The_List();
    return 0;
}
