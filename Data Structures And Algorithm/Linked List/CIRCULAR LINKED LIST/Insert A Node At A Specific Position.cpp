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
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data_of_the_list;
    newNode->next=NULL;
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
void Insert_At_The_Specific_Position()
{
    int new_data, pos, i=1;
    Node *temp;
    temp=tail->next;
    cout<<"\nEnter the new data to insert at the beginning:\n";
    cin>>new_data;
    cout<<"Enter the position where you wish to insert the data:\n";
    cin>>pos;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=new_data;
    newNode->next=NULL;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
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
int main()
{
    int number_of_nodes_required, i;
    cout<<"Enter the number of nodes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    cout<<"List before inserting the new node:\n";
    Traverse_The_List();
    Insert_At_The_Specific_Position();
    cout<<"List after inserting a new node at the beginning:\n";
    Traverse_The_List();
    return 0;
}


