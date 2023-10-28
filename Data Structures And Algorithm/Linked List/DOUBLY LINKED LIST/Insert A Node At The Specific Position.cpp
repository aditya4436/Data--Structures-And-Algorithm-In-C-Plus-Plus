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
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=new Node;
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
void Insert_At_Specific_Position()
{
  int new_data, pos, i=0;
  Node *temp, *temp1;
  temp=head;
  cout<<"Enter the new data to be inserted:\n";
  cin>>new_data;
  cout<<"Enter the position where you wish to insert anew node:\n";
  cin>>pos;
  struct Node *newNode=new Node;
  newNode->data=new_data;
  if(pos==1)
  {
        head->previous=newNode;
        newNode->next=head;
        newNode->previous=NULL;
        head=newNode;
  }
  else
  {
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    else
    {
        while(i<pos-2)
        {
            temp1=temp;
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode->previous;
        temp->next=newNode;
    }
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
    cout<<"Enter the nodes of nodes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    cout<<"List before inserting a node at a specific position of the list:\n";
    Traverse_The_List();
    cout<<endl;
    Insert_At_Specific_Position();
    cout<<"List after inserting a node at a specific position of the list:\n";
    Traverse_The_List();
    return 0;
}

