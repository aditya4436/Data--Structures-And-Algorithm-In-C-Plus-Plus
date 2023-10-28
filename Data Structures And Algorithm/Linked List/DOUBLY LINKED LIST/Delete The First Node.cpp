
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
void Add_Nodes_To_The_List(int data_of_the_list)
{
   /* int data_of_the_list;
    cout<<"Enter the nodes to inserted in the list:\n";
    cin>>data_of_the_list;*/
    struct Node *newNode=new Node;
    newNode->data=data_of_the_list;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        newNode->previous=tail->next;
        tail=newNode;
        newNode->next=NULL;
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
void Delete_The_First_Node()
{
    Node *temp=head;
    cout<<"List after deleting the first node:\n";
    head=head->next;
    free(temp);
    temp=NULL;
    head->previous=NULL;
}
int main()
{
    Add_Nodes_To_The_List(1);
    Add_Nodes_To_The_List(9);
    Add_Nodes_To_The_List(8);
    cout<<"List before deleting the first node:\n";
    Traverse_The_List();
    cout<<endl;
    Delete_The_First_Node();
    Traverse_The_List();
    return 0;
}
